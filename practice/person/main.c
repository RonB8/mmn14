#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
typedef struct{
    char name[10];
    int age;
    int id;
}Person;
char* findName(Person pers[], int N, int id);
void printPerson(Person*);
void printPersonsArr(Person[], int);
int main()
{
    Person p1; p1.id=14;
    Person pers[5];
    pers[0].id=400; pers[1].id=40; pers[2].id=450;
    pers[3].id=90; pers[4].id=300;
    strcpy(pers[0].name, "a"); strcpy(pers[1].name, "b");
    strcpy(pers[2].name, "c");
    strcpy(pers[3].name, "d"); strcpy(pers[4].name, "e");
    int i=0;
//    printf("%s\n%f\n", prods[i].name, prods[i].id);
//    printf("%s\n",(char*)((findName(pers, 5, 300))));
//    printf("%i\n", &prods[2].name);
    printPersonsArr(pers, 5);
    return 0;
}

char* findName(Person pers[], int N, int id)
{
    char name[20]={0};
    int i=0;
    while(i<N) {
//        printf("%s\n%f\n", prods[i].name, prods[i].id);
        if(id == pers[i].id){
            strcpy(name,  pers[i].name);
            return pers[i].name;
        }
        i++;
    }
//    printf("%s\n", name);
//    printf("%i\n", maxI);
    return 0;
}
void printPersonsArr(Person pers[], int size)
{
    int i=0;
    while(i<size)
    {
        printf("\nPerson %d:\n", i);
        printPerson(&pers[i++]);
    }
}
void printPerson(Person* p)
{
    printf("Name: %s\tage: %d\tid: %d\n", p->name, p->age, p->id);
}
