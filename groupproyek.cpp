#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void Register(int M){
  char name[100];
  char pass[100];
 
  printf("-----------------------------------------\n");
  printf("Please type in your username [lowercase || 1..24]:");
    scanf("%[^\n]",name);getchar();
  printf("\nPlease type in your password [lowercase || 1..24]:");
    scanf("%[^\n]",pass);getchar();
  printf("\n--- Registration Successfull ---\n");
  printf("Press enter to continue!");
  getch();
}

void LoginMenu(int N) {
  char uname[100];
  char password[100];
  printf("-----------------------------------------\n");
  printf("Username:");
    scanf("%[^\n]",uname);getchar();
  printf("\nPassword:");getchar();
    scanf("%[^\n]",password);getchar();
  printf("\n");
  printf("\n");
  printf("--- Login Successfull ---\n");
  printf("Press enter to continue!");
  getch();
}

void Login(int M) {
  int N;
  printf("Oo=====================================oO\n");
  printf("              STUDY NEWTWORK             \n");
  printf("Oo=====================================oO\n");
  printf("\n");
  printf("[All User]\n");
  printf("No.    Username\n");
  // print nama temen-temennya dari friend management
  printf("-----------------------------------------\n");
  printf("[1]Register\n");
  printf("[2]Login\n");
  printf("[3]Exit\n");
  printf("-----------------------------------------\n");
  printf("Press 0 and enter to abort an operation\n");
  printf("-----------------------------------------\n");
  printf(">>");
    scanf("%d",&N);getchar();
    if(N==1){
      Register(N);
    } else if(N==2){
       LoginMenu(N);
    } else {
      system("cls");
    }
}

int main() {
  int M;
  //Main Menu
  printf("Oo=====================================oO\n");
  printf("              STUDY NEWTWORK             \n");
  printf("Oo=====================================oO\n");
  printf("\n");
  printf("[All User]\n");
  printf("No.    Username\n");
  printf("-----------------------------------------\n");
  printf("[1]Register\n");
  printf("[2]Login\n");
  printf("[3]Exit\n");
  printf("-----------------------------------------\n");
  printf("Press 0 and enter to abort an operation\n");
  printf("-----------------------------------------\n");
  printf(">>");

  scanf("%d",&M);getchar();
  if(M==1){
    Register(M);
  } else if(M==2){
    Login(M);
  } else {
    system("cls");
  }
  
  return 0;
}