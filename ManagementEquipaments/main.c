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

#define MAX_REQUISITION 4 //Maximum number of requests the user may have.
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
    int cityzenNumber;
    int phone;
} users;
users usersList[MAX_USERS];

void LerUtentes() {
    FILE *fid = fopen("database.txt", "r");
    int n = 0;
    if (fid) {
        while (!feof(fid)) {
            fscanf(fid, "%d %d %d %s %s\n", &usersList[n].id, &usersList[n].cityzenNumber, &usersList[n].phone,
                   usersList[n].name, usersList[n].address);
            //(k)++;
            n++;
        }
        fclose(fid);
    } else
        printf("User database is empty!\n");
}

void EscreverUtentes(int *k) {
    FILE *fid = fopen("database.txt", "w+");
    int n = 0;
    if (fid) {
        for (n = 0; n < (*k); n++) {
            fprintf(fid, "%d %d %d %s %s\n", usersList[n].id, usersList[n].cityzenNumber, usersList[n].phone,
                    usersList[n].name, usersList[n].address);
        }
        fclose(fid);
    } else
        printf("Database not found!\n");
}

///Função para ver informação do cliente
void VerInformacaoUtente(int *k) {
    int id = 0, existe;
    printf("Write a user ID:\n");
    scanf("%d", &id);
    int i;
    for (i = 0; i <= *k; i++) {

        if (id == usersList[i].id) {
            existe = 1;
            printf("\t-------------------------------------------------------------------\n");
            printf("User Information:\n");
            printf("Username: %s\n", usersList[i].name);
            printf("Cityzen Card: %d\n", usersList[i].cityzenNumber);
            printf("User Address: %s\n", usersList[i].address);
            printf("Phone Number:%d\n", usersList[i].phone);
            printf("\t-------------------------------------------------------------------\n");
        }
    }
    if (existe == 0)
        printf("User not exists!\n");
}

///Por estrutura for para incremento de utentes.
///Função para registo de utente
int pergunta() {
    int j;
    printf("Insert the number of records to do:\n");
    scanf("%d", &j);
    return j;
}

void ListarInformacao(int *k) {
    int i;
    for (i = 0; i < *k; i++) {
        printf("\t-------------------------------------------------------------------\n");
        printf("\n");
        printf("User ID: %d\n", usersList[i].id);
        printf("Username: %s\n", usersList[i].name);
        printf("Cityzen Number: %d\n", usersList[i].cityzenNumber);
        printf("Phone: %d\n\n", usersList[i].phone);
        printf("\t-------------------------------------------------------------------\n");
    }
}

void RegistaUtente(int *k) {

    int i, j;
    j = pergunta();
    for (i = 1; i <= j; i++) {
        printf("Type a number for user:\n");
        scanf("%d", &usersList[*k].id);
        fflush(stdin);
        printf("Type a name:\n");
        fgets(usersList[*k].name, 200, stdin);
        fflush(stdin);
        printf("Type the cityzen card:\n");
        scanf("%d", &usersList[*k].cityzenNumber);
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
        printf("Cityzen Card number: %d\n", usersList[*k].cityzenNumber);
        printf("Address: %s\n", usersList[*k].address);
        printf("Phone number: %d\n", usersList[*k].phone);
        printf("\t-------------------------------------------------------------------\n");
        (*k)++;
    }
}

void AlterarDadosUtente(int *k) {
    int id;
    printf("\t-------------------------------------------------------------------\n");
    printf("Qual utente que deseja alterar?\n");
    scanf("%d", &id);
    int i;
    for (i = 0; i <= *k; i++) {

        if (id == usersList[i].id) {
            printf("\t-------------------------------------------------------------------\n");
            printf("User Information:\n");
            printf("Username: %s\n", usersList[i].name);
            printf("Cityzen Card Number: %d\n", usersList[i].cityzenNumber);
            printf("User Address: %s\n", usersList[i].address);
            printf("Phone Number:%d\n", usersList[i].phone);
            printf("\t-------------------------------------------------------------------\n");
            printf("\t-------------------------------------------------------------------\n");
            printf("\n[Número de registo de Utente]- %d\n", id);
            printf("\n\n-Número de Utente: %d\n", id);
            printf("\n-Nome do Utente: ");
            fflush(stdin);
            fgets(usersList[i].name,200,stdin);
            printf("\n-Número do Bilhete de Identidade: ");
            scanf("%d", &usersList[i].cityzenNumber);
            printf("\n-Morada do Utente: ");
            fflush(stdin);
            fgets(usersList[i].address, 200, stdin);
            printf("\n-Numero de Telefone: ");
            scanf("%d", &usersList[i].phone);
            getchar();
            printf("Registo alterado com sucesso!");
            fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------------------\n");
        }
    }

}

///Declara��o de fun��es e estruturas da parte dos equipamentos no programa
typedef struct {
    int id;
    int sn;
    char name[50];
} equipaments;
equipaments equipamentsList[MAX_EQUIPAMENTS];

void LerEquipamentos(int *info) {
    FILE *fid2 = fopen("database2.txt", "r");
    int n = 0;
    if (fid2) {
        while (!feof(fid2)) {
            fscanf(fid2, "%d %d %s\n", &equipamentsList[n].id, &equipamentsList[n].sn, equipamentsList[n].name);
            (*info)++;
            n++;
        }
        fclose(fid2);
    } else printf("Erro na abertura do ficheiro!\n");
}

void EscreverEquipamentos(int *info) {
    FILE *fid2 = fopen("database2.txt", "w+");
    int n = 0;
    if (fid2) {
        for (n = 0; n < (*info); n++) {
            fprintf(fid2, "%d %d %s\n", equipamentsList[n].id, equipamentsList[n].sn, equipamentsList[n].name);
        }
        fclose(fid2);
    } else printf("Erro na abertura do ficheiro!\n");
}


void VerInformacaoEquipamento(int info) {
    int i, dados = 0, existe;
    printf("Digite o numero do equipamento:\n");
    scanf("%d", &dados);
    for (i = 0; i <= info; i++) {
        if (dados == equipamentsList[i].id) {
            existe = 1;
            printf("\t-------------------------------------------------------------------\n");
            printf("Informação do equipamento:\n");
            printf("Nome do equipamento: %s\n", equipamentsList[i].name);
            printf("Serial Number do equipamento: %d\n", equipamentsList[i].sn);
            printf("\t-------------------------------------------------------------------\n");
            break;
        }

    }
    if (existe == 0) {
        printf("Equipamentos não existe!\n");
    }

}

int perguntaEquipamentos(int info, int k) {
    int i;
    printf("Introduza o número de registos a efetuar\n");
    scanf("%d", &equipamentsList[info].id);
    for (i = 1; equipamentsList[info].id; i++) {
        if (equipamentsList[i].id == k) {
            printf("Número de ID já registado!\n");
            break;
        }
    }
    return k;
}

void RegistaEquipamento(int info) {
    int i, k;
    k = perguntaEquipamentos(k, info);
    for (i = 1; i <= k; i++) {
        printf("\t-------------------------------------------------------------------\n");
        printf("Digite ID para o equipamento:\n");
        scanf("%d", &equipamentsList[info].id);
        fflush(stdin);
        printf("Digite o S/N do equipamento:\n");
        scanf("%d", &equipamentsList[info].sn);
        fflush(stdin);
        printf("Digite o name do equipamento:\n");
        //fgets(listaEquipamentos[info].nome);
        scanf("%d", equipamentsList[info].name);
        fflush(stdin);
        system("cls");
        printf("\t---------------------Resumo da Criação-----------------------------\n");
        printf("Ficha criada com os seguintes dados:\n\n");
        printf("ID do equipamento: %d\n", equipamentsList[info].id);
        printf("Número S/N: %d\n", equipamentsList[info].sn);
        printf("Nome: %s\n", equipamentsList[info].name);
        printf("\t-------------------------------------------------------------------\n");
        (info)++;
    }
}

void AlteraDadosEquipamentos(int info) {
    int dados;
    printf("\t-------------------------------------------------------------------\n");
    printf("Digite o ID do equipamento que deseja alterar\n");
    scanf("%d", &dados);
    int i;
    for (i = 0; i <= info; i++) {
        if (dados == equipamentsList[i].id) {
            printf("\t-------------------------------------------------------------------\n");
            printf("Informação do Equipamento:\n");
            printf("Nome do equipamento: %s\n", equipamentsList[i].name);
            printf("Serial Number: %d\n", equipamentsList[i].sn);
            printf("\t-------------------------------------------------------------------\n");
            printf("\t-------------------------------------------------------------------\n");
            printf("\n[ID do equipamento a alterar]- %d\n", dados);
            printf("\n\n-ID do equipamento: %d\n", dados);
            printf("\n-Nome do equipamento: ");
            fflush(stdin);
            fgets(equipamentsList[i].name, 200, stdin);
            printf("\n-Serial Number do equipamento: ");
            scanf("%d", &equipamentsList[i].sn);
            getchar();
            printf("Registo alterado com sucesso!");
            fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------------------\n");
        }
    }
}

void AbateEquipamento(int info) {
    int i, dados, verdade;
    printf("Digite o ID do equipamento a abater:\n");
    scanf("%d", &dados);
    for (i = 0; i <= info; i++) {
        if (dados == equipamentsList[i].id) {
            verdade = 1;
            equipamentsList[i].id = 0;
            printf("Equipamento abatido com sucesso!\n");
            break;
        }
    }
    if (verdade == 0)
        printf("Equipamento não consta nos registos!\n");
}

void ListagemDeEquipamentos(int info) {
    int i;
    for (i = 0; i < info; i++) {
        if (equipamentsList[i].id >= 1) {
            printf("\t-------------------------------------------------------------------\n");
            printf("\n");
            printf("Nome do equipamento: %s\n", equipamentsList[i].name);
            printf("Serial number do equipamento: %d\n", equipamentsList[i].sn);
            printf("\t-------------------------------------------------------------------\n");
        } else
            printf("Não há equipamenetos!\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese"); ///Serve para identificar os caracteres com acentos.
    int op, op2, op3, op4, k = 0, info = 0; ///Declaração das variáveis
    LerUtentes(&k);
    LerEquipamentos(&info);
    ///Ciclo do while no menu de gestão.
    do {
        printf("\t------------------Welcome To Main Menu----------------------\n"); ///printsf's para exebir o menu
        printf("\t\t            1. Management Users\n");
        printf("\t\t            2. Management Equipaments\n");
        printf("\t\t            3. Management Requistions\n");
        printf("\t\t            4. Quit\n");
        printf("\t-------------------------------------------------------------------\n");
        printf("Choice a option:\n");
        scanf("%d", &op);
        system("cls");
        switch (op) {
            case 1: ///Condição se a opção selecionada for 1 aparecerá os seguintes submenus do menu clientes
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
                            VerInformacaoUtente(&k);
                            break;
                        case 2:
                            RegistaUtente(&k);
                            break;
                        case 3:
                            AlterarDadosUtente(&k);
                            break;
                        case 4:
                            ListarInformacao(&k);
                            break;
                        default :
                            system("cls");
                            printf("Invalid option!\n");
                            break;
                    }
                } while (op2 != 5);
                system("cls");
                break;
            case 2: ///Caso n�o for 1 mas sim 2, ir�  aparecer o segundo menu e as seguintes mensagens abaixo do menu equipamentos
                do {
                    printf("\t--------------------------Equipment Menu--------------------\n");
                    printf("\t\t    1. See Equipment Information\n");
                    printf("\t\t    2. Register new equipment\n");
                    printf("\t\t    3. Change information of an equipment\n");
                    printf("\t\t    4. Shoot down an equipment\n");
                    printf("\t\t    5. Equipment Listing\n");
                    printf("\t\t    6. Back to previous menu\n");
                    printf("\t-------------------------------------------------------------------\n");
                    printf("Escolha sua opção:\n");
                    scanf("%d", &op3);
                    switch (op3) {
                        case 1:
                            VerInformacaoEquipamento(info);
                            break;
                        case 2:
                            RegistaEquipamento(info);
                            break;
                        case 3:
                            AlteraDadosEquipamentos(info);
                            break;
                        case 4:
                            AbateEquipamento(info);
                            break;
                        case 5:
                            ListagemDeEquipamentos(info);
                            break;
                        default :
                            system("cls");
                            printf("Invalid Option!\n");
                            break;
                    }
                } while (op3 != 6);
                system("cls");
                break;

            case 3: ///Caso não for o primeiro ou segundo menu aparece os submenus das requisições
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
            EscreverEquipamentos(&info);
            EscreverUtentes(&k);
            printf("See You Later!\n\a"); /// Mensagem exibida quando o usu�rio sair do programa.
            system("pause");
            op2 = 0;
            break;
        }
    } while(op2!= 0);
    return 0;
}
