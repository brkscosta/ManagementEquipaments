/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



/*
 * File:   main.c
 * Author: Joanã Costa
 *
 * Created on 27 de May of 2018, 19:26
 */


/********************************
** Libraries Import **
*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <string.h>

//#define MAX_REQUISITION 4 //Maximum number of requests the user may have.
#define MAX_EQUIPAMENTS 10 //Maximum number of equipment
#define MAX_USERS 10 //Maximum number of users.


/*************************************
 ****** Definition of Structures *****
**************************************/


//Structure for user creation.
typedef struct {
    char name[50];
    char address[100];
    int id;
    int citizenCardNumber;
    int phone;
} users;
users usersList[MAX_USERS];

void readUsers() {

    int n = 0;

    FILE *fid = fopen("database.txt", "r");

    if (fid) {

        while (!feof(fid)) {
            fscanf(fid, "%d %d %d %s %s\n", &usersList[n].id, &usersList[n].citizenCardNumber, &usersList[n].phone,
                   usersList[n].name, usersList[n].address);
            //(k)++;
            n++;
        }

        fclose(fid);

    } else
        printf("User database is empty!\n");
}

void writeUser(int *k) {

    int n = 0;

    FILE *fid = fopen("database.txt", "w+");

    if (fid) {

        for (n = 0; n < (*k); n++) {
            fprintf(fid, "%d %d %d %s %s\n", usersList[n].id, usersList[n].citizenCardNumber, usersList[n].phone,
                    usersList[n].name, usersList[n].address);
        }

        fclose(fid);

    } else
        printf("Database not found!\n");
}

/// Function to view customer information
void showUserInformation(const int *k) {

    int id = 0, isExists = 0, i;

    printf("Write a user ID:\n");
    scanf("%d", &id);

    for (i = 0; i <= *k; i++) {

        if (id == usersList[i].id) {
            isExists = 1;
            printf("\t-------------------------------------------------------------------\n");
            printf("User Information:\n");
            printf("Username: %s\n", usersList[i].name);
            printf("Citizen Card: %d\n", usersList[i].citizenCardNumber);
            printf("User Address: %s\n", usersList[i].address);
            printf("Phone Number:%d\n", usersList[i].phone);
            printf("\t-------------------------------------------------------------------\n");
        }
    }

    if (isExists == 0)
        printf("User not exists!\n");
}


int questionInsertRecordsUsers() {
    int j;
    printf("Insert the number of records to do:\n");
    scanf("%d", &j);
    return j;
}

void showAllUserRecords(const int *k) {
    int i;
    for (i = 0; i < *k; i++) {
        printf("\t-------------------------------------------------------------------\n");
        printf("\n");
        printf("User ID: %d\n", usersList[i].id);
        printf("Username: %s\n", usersList[i].name);
        printf("Citizen Number: %d\n", usersList[i].citizenCardNumber);
        printf("Phone: %d\n\n", usersList[i].phone);
        printf("\t-------------------------------------------------------------------\n");
    }
}

void insertNewUser(int *k) {

    int i, j;
    j = questionInsertRecordsUsers();
    for (i = 1; i <= j; i++) {
        printf("Type a number for user:\n");
        scanf("%d", &usersList[*k].id);
        fflush(stdin);
        printf("Type a name:\n");
        fgets(usersList[*k].name, 200, stdin);
        fflush(stdin);
        printf("Type the citizen card:\n");
        scanf("%d", &usersList[*k].citizenCardNumber);
        fflush(stdin);
        printf("Type address:\n");
        fgets(usersList[*k].address, 200, stdin);
        fflush(stdin);
        printf("Type a phone number:\n");
        scanf("%d", &usersList[*k].phone);
        fflush(stdin);
        system("cls");
        printf("\t---------------------Resume of Record-----------------------------\n");
        printf("Record created with the follow data:\n\n");
        printf("User Number(ID): %d\n", usersList[*k].id);
        printf("Name: %s\n", usersList[*k].name);
        printf("Citizen Card number: %d\n", usersList[*k].citizenCardNumber);
        printf("Address: %s\n", usersList[*k].address);
        printf("Phone number: %d\n", usersList[*k].phone);
        printf("\t-------------------------------------------------------------------\n");
        (*k)++;
    }
}

void changeUserData(const int *k) {
    int id, i;

    printf("\t-------------------------------------------------------------------\n");
    printf("Which user do you want to change, enter the (ID)?\n");
    scanf("%d", &id);


    for (i = 0; i <= *k; i++) {

        if (id == usersList[i].id) {
            printf("\t-------------------------------------------------------------------\n");
            printf("User Information:\n");
            printf("Username: %s\n", usersList[i].name);
            printf("Citizen Card Number: %d\n", usersList[i].citizenCardNumber);
            printf("User Address: %s\n", usersList[i].address);
            printf("Phone Number:%d\n", usersList[i].phone);
            printf("\t-------------------------------------------------------------------\n");
            printf("\t-------------------------------------------------------------------\n");
            printf("\n[User registration number]- %d\n", id);
            printf("\n\n-Number: %d\n", id);
            printf("\n-Nome: ");
            fflush(stdin);
            fgets(usersList[i].name,200,stdin);
            printf("\n-Identity Card Number: ");
            scanf("%d", &usersList[i].citizenCardNumber);
            printf("\n-Address ");
            fflush(stdin);
            fgets(usersList[i].address, 200, stdin);
            printf("\n-Phone Number ");
            scanf("%d", &usersList[i].phone);
            getchar();
            printf("Record changed!");
            fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------------------\n");
        }
    }

}

/// Declaration of functions and structs of the equipment part in the program
typedef struct {
    int id;
    int sn;
    char name[50];
} equipaments;
equipaments equipamentsList[MAX_EQUIPAMENTS];


void readEquipaments(int *info) {

    int n = 0;

    FILE *fid2 = fopen("database2.txt", "r");

    if (fid2) {

        while (!feof(fid2)) {
            fscanf(fid2, "%d %d %s\n", &equipamentsList[n].id, &equipamentsList[n].sn, equipamentsList[n].name);
            (*info)++;
            n++;
        }

        fclose(fid2);

    } else
        printf("Error opening file!\n");
}

void writeEquipaments(int *info) {

    int n = 0;

    FILE *fid2 = fopen("database2.txt", "w+");

    if (fid2) {

        for (n = 0; n < (*info); n++) {
            fprintf(fid2, "%d %d %s\n", equipamentsList[n].id, equipamentsList[n].sn, equipamentsList[n].name);
        }

        fclose(fid2);

    } else
        printf("Error opening file!\n");
}


void showInfoEquipament(int info) {

    int i, data = 0, isExists = 0;

    printf("Enter the equipment number (ID):\n");
    scanf("%d", &data);

    for (i = 0; i <= info; i++) {
        if (data == equipamentsList[i].id) {
            isExists = 1;
            printf("\t-------------------------------------------------------------------\n");
            printf("Equipment Information:\n");
            printf("Name: %s\n", equipamentsList[i].name);
            printf("Serial Number: %d\n", equipamentsList[i].sn);
            printf("\t-------------------------------------------------------------------\n");
            break;
        }

    }

    if (isExists == 0) {
        printf("Equipament not found!\n");
    }

}

int questionInsertRecordsEquipaments(int info, int k) {

    int i;

    printf("Quantity of equipment to be registered\n");
    scanf("%d", &equipamentsList[info].id);

    for (i = 1; equipamentsList[info].id; i++) {

        if (equipamentsList[i].id == k) {
            printf("ID already registered!\n");
            break;
        }
    }
    return k;
}

void insertEquipament(int info) {

    int i, k = 0;

    k = questionInsertRecordsEquipaments(k, info);

    for (i = 1; i <= k; i++) {
        printf("\t-------------------------------------------------------------------\n");
        printf("Enter the ID for your equipament:\n");
        scanf("%d", &equipamentsList[info].id);
        fflush(stdin);
        printf("Type the S/N of equipament:\n");
        scanf("%d", &equipamentsList[info].sn);
        fflush(stdin);
        printf("Type o name do equipament:\n");
        fgets(equipamentsList[info].name, 200, stdin);
        scanf("%s", equipamentsList[info].name);
        fflush(stdin);
        system("cls");
        printf("\t----------------------Resume of Record-----------------------------\n");
        printf("Card created with the following data:\n\n");
        printf("Equipament ID: %d\n", equipamentsList[info].id);
        printf("Name: %s\n", equipamentsList[info].name);
        printf("S/N: %d\n", equipamentsList[info].sn);
        printf("\t-------------------------------------------------------------------\n");
        (info)++;
    }
}

void changeEquipamentsData(int info) {

    int data, i;

    printf("\t-------------------------------------------------------------------\n");
    printf("Enter the ID of the equipament you want to change\n");
    scanf("%d", &data);

    for (i = 0; i <= info; i++) {

        if (data == equipamentsList[i].id) {
            printf("\t-------------------------------------------------------------------\n");
            printf("Equipament Information:\n");
            printf("Name equipament: %s\n", equipamentsList[i].name);
            printf("Serial Number: %d\n", equipamentsList[i].sn);
            printf("\t-------------------------------------------------------------------\n");
            printf("\t-------------------------------------------------------------------\n");
            printf("\n[ID equipament to change]- %d\n", data);
            printf("\n\n-ID equipament: %d\n", data);
            printf("\n-Name equipament: ");
            fflush(stdin);
            fgets(equipamentsList[i].name, 200, stdin);
            printf("\n-Serial Number equipament: ");
            scanf("%d", &equipamentsList[i].sn);
            getchar();
            printf("Record changed");
            fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------------------\n");
        }
    }
}

void deleteEquipament(int info) {

    int i, data, isExists = 0;

    printf("Enter the ID of the equipament to be deleted:\n");
    scanf("%d", &data);

    for (i = 0; i <= info; i++) {

        if (data == equipamentsList[i].id) {
            isExists = 1;
            equipamentsList[i].id = 0;
            printf("Equipament successfully deleted\n");
            break;
        }
    }

    if (isExists == 0)
        printf("Equipament not found!\n");
}

void showAllEquipaments(int info) {

    int i;

    for (i = 0; i < info; i++) {

        if (equipamentsList[i].id >= 1) {
            printf("\t-------------------------------------------------------------------\n");
            printf("\n");
            printf("Equipaments Info: %s\n", equipamentsList[i].name);
            printf("Serial number equipament: %d\n", equipamentsList[i].sn);
            printf("\t-------------------------------------------------------------------\n");
        } else
            printf("There are no equipaments!\n");
    }
}

int main() {

    int op, op2 = 0, op3, op4, k = 0, info = 0;
    setlocale(LC_ALL, "");
    readUsers();
    readEquipaments(&info);

    do {
        printf("\t------------------Welcome To Main Menu----------------------\n");
        printf("\t\t            1. Management Users\n");
        printf("\t\t            2. Management Equipaments\n");
        printf("\t\t            3. Management Requistions\n");
        printf("\t\t            4. Quit\n");
        printf("\t-------------------------------------------------------------------\n");
        printf("Choice a option:\n");
        scanf("%d", &op);
        system("cls");
        switch (op) {
            case 1:
                do {
                    printf("\t------------------------- User Menu -------------------------------\n");
                    printf("\t\t    1. See a user information\n");
                    printf("\t\t    2. Add a new user\n");
                    printf("\t\t    3. Change user data\n");
                    printf("\t\t    4. List user information\n");
                    printf("\t\t    5. Back to previous menu\n");
                    printf("\t-------------------------------------------------------------------\n");
                    printf("Choose your option:\n");
                    scanf("%d", &op2);
                    switch (op2) {
                        case 1:
                            showUserInformation(&k);
                            break;
                        case 2:
                            insertNewUser(&k);
                            break;
                        case 3:
                            changeUserData(&k);
                            break;
                        case 4:
                            showAllUserRecords(&k);
                            break;
                        default :
                            system("cls");
                            printf("Invalid option!\n");
                            break;
                    }
                } while (op2 != 5);
                system("cls");
                break;
            case 2:
                do {
                    printf("\t--------------------------Equipment Menu--------------------\n");
                    printf("\t\t    1. See Equipment Information\n");
                    printf("\t\t    2. Register new equipment\n");
                    printf("\t\t    3. Change information of an equipment\n");
                    printf("\t\t    4. Shoot down an equipment\n");
                    printf("\t\t    5. Equipment Listing\n");
                    printf("\t\t    6. Back to previous menu\n");
                    printf("\t-------------------------------------------------------------------\n");
                    printf("Choose your option:\n");
                    scanf("%d", &op3);
                    switch (op3) {
                        case 1:
                            showInfoEquipament(info);
                            break;
                        case 2:
                            insertEquipament(info);
                            break;
                        case 3:
                            changeEquipamentsData(info);
                            break;
                        case 4:
                            deleteEquipament(info);
                            break;
                        case 5:
                            showAllEquipaments(info);
                            break;
                        default :
                            system("cls");
                            printf("Invalid Option!\n");
                            break;
                    }
                } while (op3 != 6);
                system("cls");
                break;

            case 3:
                do {
                    printf("\t-------------------------- Requisition Menu -----------------------\n");
                    printf("\t\t    1. Register Equipment Requisition\n");
                    printf("\t\t    2. Register Equipment Delivery\n");
                    printf("\t\t    3. List of equipment required\n");
                    printf("\t\t    4. Available Equipment Listing\n");
                    printf("\t\t    5. Equipment Listing\n");
                    printf("\t\t    6. Back to previous menu\n");
                    printf("\t-------------------------------------------------------------------\n");
                    printf("Choose your option:\n");
                    scanf("%d", &op4);
                    switch (op4) {
                /*case 1:
                    RegistarRequisicaoEquipamento();
                    break;*/


                /*case 2:
                    RegistaEntregaEquipamento();
                    break;*/


                /*case 3:
                    ListagemEquipamentosRequisitados();
                    break;*/


                /*case 4:
                    ListagemdeEquipamentosDiponiveis();
                    break;*/


                /*case 5:
                    ListagemEquipamentos();
                    break;*/

                default :
                    system("cls");
                    printf("Invalid Option!\n");
                    break;
                }
            } while(op4 != 6);
            system("cls");
            break;
        case 4:
            writeEquipaments(&info);
                writeUser(&k);
            printf("See You Later!\n\a");
            system("pause");
            op2 = 0;
            break;
            default:break;
        }
    } while(op2!= 0);
    return 0;
}
