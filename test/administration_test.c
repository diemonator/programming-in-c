#include <string.h>
#include "unity.h"
#include "administration.h"


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 1);
}

void test_addAnimal(void)
{ 
	ANIMAL animals[20];
	ANIMAL a = {"Lucas", Cat, 6};
	int result = addAnimal (&a, animals, 0);
	TEST_ASSERT_EQUAL(0,result);
}

void test_removeAnimal(void)
{
    int nrAnimals = 0;
    ANIMAL animals[20];
    ANIMAL a1 = {"Max", Dog, 12};
    ANIMAL a2 = {"Max", Dog, 12};
    addAnimal(&a1, animals, nrAnimals++);
    addAnimal(&a2, animals, nrAnimals++);
    int result = removeAnimal("Max",animals,nrAnimals);
    TEST_ASSERT_EQUAL(2,result);
}

void test_findAnimalByName(void)
{
    int nrAnimals = 0;
    ANIMAL animals[20];
    ANIMAL a1 = {"Max", Dog, 12};
    ANIMAL a2 = {"Kiekerjan", Cat, 4};
    ANIMAL a3 = {"Lorre", Parrot, 40};
    ANIMAL a4 = {"Fifi", Dog, 1};
    ANIMAL a5 = {"Piep", GuineaPig, 3};

    animals[(nrAnimals)++] = a1;
    animals[(nrAnimals)++] = a2;
    animals[(nrAnimals)++] = a3;
    animals[(nrAnimals)++] = a4;
    animals[(nrAnimals)++] = a5;
    ANIMAL animal;
    int result = findAnimalByName("Max",animals,nrAnimals,&animal);
    TEST_ASSERT_EQUAL(1,result);
}

void test_sortByAge()
{
    int nrAnimals = 0;
    ANIMAL animals[20];
    int result = sortAnimalsByAge(animals,nrAnimals);
    TEST_ASSERT_EQUAL(-1,result);
}

void test_sortByName()
{
    int nrAnimals = 0;
    ANIMAL animals[20];
    ANIMAL a1 = {"Max", Dog, 12};
    ANIMAL a2 = {"Kiekerjan", Cat, 4};
    ANIMAL a3 = {"Lorre", Parrot, 40};
    ANIMAL a4 = {"Fifi", Dog, 1};
    ANIMAL a5 = {"Piep", GuineaPig, 3};

    animals[(nrAnimals)++] = a1;
    animals[(nrAnimals)++] = a2;
    animals[(nrAnimals)++] = a3;
    animals[(nrAnimals)++] = a4;
    animals[(nrAnimals)++] = a5;
    int result = sortAnimalsByName(animals,nrAnimals);
    TEST_ASSERT_EQUAL(0,result);
}

int main (int argc, char * argv[])
{
    
    UnityBegin();
    
    RUN_TEST(test_removeAnimal, 2);


    return UnityEnd();
}
