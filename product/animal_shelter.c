/*
 * animal_shelter.c
 *
 *  Created on: August 31, 2016
 *      Author: Freddy Hurkmans
 * revised: october 2017 Ella vd Sanden
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "administration.h"
#include "file_element.h"
#include "animal.h"


static const char* SpeciesNames[] = {"Cat", "Dog", "Guinea pig", "Parrot"};

void printAnimals(const ANIMAL* animals, int nrAnimals);
//the first <nrAnimals> from the array animals are printed


void addTestData(ANIMAL* animals, int* nrAnimals);
// the array animals is filled with a number of animals; *nrAnimals contains this number


int main (void)
{
    const int MaxNrAnimals = 20;
    ANIMAL animals[MaxNrAnimals];
    int nrAnimals = 0;
    char name[MaxNameLength];
    char fileName[MaxNameLength];
    int age = 0;
    int type = 0;
    //addTestData(animals, &nrAnimals);
    printf ("PRC assignment 'Animal Shelter' (version oct 2017)\n");
    printf("Open a file of animals otherlise you may runn it to truble!");
    printf("Read animals from file: ");
    scanf("%s", fileName);
    nrAnimals = getNrAnimalsInFile(fileName);
    if (nrAnimals == -1)
    {
        printf("Error finding animals in file!\nTry with another file!\n");
        return -1;
    }
    readAnimals(fileName,animals,nrAnimals);
    printf("Success");
    int choice = -1;
    while (choice != 0)
    {
        ANIMAL animal;
        printf ("\n\nMENU\n====\n\n");
        printf ("1: Show Animals \n");
        printf ("2: Add Animal \n");
        printf ("3: Remove Animal \n");
        printf ("4: Sort Animal by name \n");
        printf ("5: Sort Animal by age \n");
        printf ("6: Find Animal by name \n");
        printf ("7: Write Animals to file \n");
        printf ("8: Rename animal in file \n");
        printf ("0: quit \n");
                
        scanf ("%d", &choice);
		
        switch (choice)
        {
            case 1: //Show Animals
                printAnimals(animals, nrAnimals);
                break;
            case 2: //Add Animal
                printf("Enter name for animal: ");
                scanf("%s", name);
                printf("Enter age of animal: ");
                scanf("%d", &age);
                printf("\nThe types of animals:\n0 for cat, 1 for dog, 2 for Guinea pig,3 for Parrot\nType: ");
                scanf("%d",&type);
                strcpy(animal.Name, name);
                animal.Age = age;
                animal.Species = type;
                if (nrAnimals < MaxNrAnimals)
                {
                    addAnimal(&animal,animals,nrAnimals);
                    nrAnimals++;
                } else printf("Array full");
                break;
            case 3: //Remove Animal
                printf("Remove animal by name. Enter animal name:  ");
                scanf("%s", name);
                nrAnimals -= removeAnimal(name,animals,nrAnimals);
                break;
            case 4://sort by name
                sortAnimalsByName(animals,nrAnimals); 
                break;
            case 5:// sort by age
                sortAnimalsByAge(animals,nrAnimals);
                break;
            case 6://find by name
                printf("Find animal: ");
                scanf("%s", name);
                findAnimalByName(name,animals,nrAnimals,&animal);
                printf("Name: %s, Age: %d and Species: %s",animal.Name, animal.Age, SpeciesNames[animal.Species]);
                break;
            case 7:
                printf("Write animals to file: ");
                scanf("%s", fileName);
                writeAnimals(fileName,animals,nrAnimals);
                break;
            case 8: 
                printf("Animal surname: ");
                scanf("%s", name);
                printf("Animal Nr: ");
                scanf("%d", &age);
                renameAnimalInFile(fileName,age,name);
                printf("\nSuccessfully renamed animal, open the file again to see the results");
                break;
            case 0:
                break;
            default:
                printf ("ERROR: invalid choice: %d\n", choice);
                break;
	    }
    }
    return 0;
}



void addTestData(ANIMAL* animals, int* nrAnimals)
{
    ANIMAL a1 = {"Max", Dog, 12};
    ANIMAL a2 = {"Kiekerjan", Cat, 4};
    ANIMAL a3 = {"Lorre", Parrot, 40};
    ANIMAL a4 = {"Fifi", Dog, 1};
    ANIMAL a5 = {"Piep", GuineaPig, 3};

    animals[(*nrAnimals)++] = a1;
    animals[(*nrAnimals)++] = a2;
    animals[(*nrAnimals)++] = a3;
    animals[(*nrAnimals)++] = a4;
    animals[(*nrAnimals)++] = a5;
}

void printAnimals(const ANIMAL* animals, int nrAnimals)
{
    if (animals == NULL)
    {
        printf("animals pointer is NULL\n"); return;
    }
    if (nrAnimals <= 0)
    {
        printf("Animal array is empty, or nrAnimals is less than 0\n"); return;
    }
	int i;
	printf("                  name:               Species:          Age: \n"); 
    for (i = 0; i < nrAnimals; i++)
    {
        printf("Animal %d: ", i+1);
        printf("%15s\t  %15s\t %d \n", 
                                        animals[i].Name, 
                                        SpeciesNames[animals[i].Species],
                                        animals[i].Age);
    }
}
