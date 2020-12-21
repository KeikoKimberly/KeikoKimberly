#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CRUD (create,read,update,delete)

struct Mentor{
    int ID;
    char name[255];
    int age;
    double gpa;
};

//function menerima parameter a dan b
int plus(int a,int b){
    return a+b;
}

//function menerima parameter nama,age,gpa
Mentor *createMentor(const char *name, int age, double gpa){
    Mentor *newMentor = (Mentor*)malloc(sizeof(Mentor));
//malloc return void* dicase jadi mentor*
//malloc sebesar ukuran struct mentor
    strcpy(newMentor->name,name);
    newMentor->age=age; // (*newMentor).age=age;
    newMentor->gpa=gpa; //pake -> karena dia pointer (bintang)
    return newMentor;
}

void printData(Mentor *m){ //wajib kasi * di m , biar tau m yg mana
    printf("Name: %s\n",m->name);
    printf("Age: %d\n",m->age);
    printf("GPA: %.2lf\n",m->gpa);
}

void deleteMentor(Mentor *m){
    free(m); //free allocated memory, setelah kita memory allocated, harus di free(bebaskan)
}

int main(){
    //static memory allocation
    //Mentor m;
    //m.age=10;
    //m.gpa=3.90;
    //strcpy(mentorStatic.name,"Elvan");
    //printf("%d",mentorStatic.age);

    //dynamic memory alloc
    Mentor *m= createMentor("Kevine",27,3.89);
    printData(m);
    deleteMentor(m);

    return 0;

}