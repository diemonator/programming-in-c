#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "administration.h"


int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int position)
{
    animalArray[position] = *animalPtr;
    return 0;
}

int removeAnimal(const char* name, ANIMAL* animalArray, int length)
{
    if (length <= 0)
        return -1;
    int counter = 0;
    for (int i=0; i<length; i++)
    {
        if (strcmp(name, animalArray[i].Name) == 0)
        {
            counter++;
            length--;
            for (int j = i; j<length; j++)
            {
                animalArray[j] = animalArray[j+1];
            }
            i--;
        }
    } 
    return counter;
}

int cmpAge (const void * a, const void * b)
{
    const int l = ((ANIMAL *)a)->Age; 
    const int r = ((ANIMAL *)b)->Age;  
    return (l - r);
}

int cmpName (const void * a, const void * b)
{
    const char *l = ((ANIMAL *)a)->Name; 
    const char *r = ((ANIMAL *)b)->Name;
    return strcmp(l,r);
}

int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength)
{	
    qsort(animalArray, animalArrayLength, sizeof(ANIMAL), cmpAge);
    return 0;
}
 
int sortAnimalsByName(ANIMAL* animalArray, int animalArrayLength)
{	
    qsort(animalArray, animalArrayLength, sizeof(ANIMAL), cmpName);
    return 0;
}


int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr)
{
    for (int i=0; i<animalArrayLength; i++) 
    {
        if (strcmp(name, animalArray[i].Name) == 0)
        {
            *animalPtr = animalArray[i];
            return 1;
        }
    }
    return 0;
}
