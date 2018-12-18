#include <stdio.h>
#include "file_element.h"
#include <string.h>

int readAnimals(const char* filename, ANIMAL* animalPtr, int nrAnimals)
{
    int position = 0;
    for (int i = 0; i < nrAnimals; i++)
    {
        if (readAnimalFromFile(filename, position, animalPtr) == 0)
            position += sizeof(ANIMAL);
        else return -1;
    }
    return 0;
}

int writeAnimals(const char* filename, const ANIMAL* animalPtr, int nrAnimals)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
        return -1;
    for (int i = 0; i < nrAnimals; i++)
    {
        writeAnimalToFile(filename,i,&animalPtr[i]);
    }
    fclose(fp);
    return 0;
}

int getNrAnimalsInFile(const char* filename)
{
    FILE *fp; int res, counter = -1; ANIMAL animal;
    fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;
    do
    {
        counter++;
        res = fread(&animal,sizeof(ANIMAL),1,fp);
    } while (res != 0);
    printf("%d", counter);
    fclose(fp);
    return counter;
}

int readAnimalFromFile(const char* filename, int filePosition, ANIMAL* animalPtr)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;
    fseek(fp, filePosition, SEEK_SET);
    fread(&animalPtr[filePosition/sizeof(ANIMAL)],sizeof(ANIMAL),1,fp);
    fclose(fp);
    return 0;
}

int writeAnimalToFile(const char* filename, int filePosition, const ANIMAL* animalPtr)
{
    FILE *fp;
    fp = fopen(filename,"a");
    if (fp == NULL)
        return -1;
    fseek(fp, filePosition, SEEK_SET);
    fwrite(animalPtr,sizeof(ANIMAL),1,fp);
    fclose(fp);
    return 0;
}
 
int renameAnimalInFile(const char* filename, int filePosition, const char* animalSurname)
{
    FILE *fp;
    ANIMAL animal;
    fp = fopen(filename,"r+");
    filePosition = sizeof(ANIMAL)*filePosition;
    fseek(fp,filePosition,SEEK_SET);
    fread(&animal,sizeof(ANIMAL),1,fp);
    char name[15];
    strcpy(name,animalSurname);
    strcat(name," ");
    strcat(name,animal.Name);
    strcpy(animal.Name,name);
    fseek(fp,filePosition,SEEK_SET);
    fwrite(&animal,sizeof(ANIMAL),1,fp);
    fclose(fp);
    return 1;
}
