/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Joanã Costa
 *
 * Created on 27 de Maio de 2018, 19:26
 */
/********************************
** Libraries Import **
*********************************/
#include <stdio.h> ///Biblioteca onde contém as funções básicas do programa.
#include <stdlib.h> ///
#include <string.h> ///Bibliotecas de operações com strings.
#include <locale.h> ///Biblioteca onde caracteres com acentos são reconhecidos.
#include <string.h> ///Biblioteca para funções com strings.
#define MAX_REQUISICOES 4 ///Máximo de requisições que o usuário pode ter.
#define MAX_EQUIPAMENTOS 10 ///Numero maximo de equipamentos
#define MAX_UTENTES 10 ///Número máximo de utentes.

/*************************************
 ****** Definição de Estruturas******
**************************************/

///Estrutura para criação de utente.
typedef struct {
    char nome[50];
    char morada[100];
    int id;
    int numero_bi;
    int telefone;
} utentes;
utentes listaUtentes[MAX_UTENTES];

void LerUtentes() {
    FILE *fid = fopen("database.txt", "r");
    int n = 0;
    if (fid) {
        while (!feof(fid)) {
            fscanf(fid, "%d %d %d %s %s\n",&listaUtentes[n].id,&listaUtentes[n].numero_bi,&listaUtentes[n].telefone,listaUtentes[n].nome,listaUtentes[n].morada);
            //(k)++;
            n++;
        }
        fclose(fid);
    } else
        printf("Erro na abertura do ficheiro!\n");
}

void EscreverUtentes(int *k) {
    FILE* fid = fopen("database.txt","w+");
    int n = 0;
    if (fid) {
        for (n=0; n < (*k); n++) {
            fprintf(fid,"%d %d %d %s %s\n",listaUtentes[n].id,listaUtentes[n].numero_bi,listaUtentes[n].telefone,listaUtentes[n].nome,listaUtentes[n].morada);
        }
        fclose(fid);
    } else printf("Erro na abertura do ficheiro!\n");
}

///Função para ver informação do cliente
void VerInformacaoUtente(int *k) {
    int id=0, existe;
    printf("Digite o número do utente:\n");
    scanf("%d",&id);
    int i;
    for(i=0; i <= *k; i++) {

        if(id == listaUtentes[i].id) {
            existe = 1;
            printf("\t-------------------------------------------------------------------\n");
            printf("Informação do utente:\n");
            printf("Nome do utente: %s\n",listaUtentes[i].nome);
            printf("Número BI do utente: %d\n",listaUtentes[i].numero_bi);
            printf("Morada do utente: %s\n",listaUtentes[i].morada);
            printf("Número de contacto:%d\n",listaUtentes[i].telefone);
            printf("\t-------------------------------------------------------------------\n");
        }
    }
    if(existe == 0)
        printf("Utente não existe!\n");
}

///Por estrutura for para incremento de utentes.
///Função para registo de utente
int pergunta() {
    int j;
    printf("Introduza o numero de registos a efetuar\n");
    scanf("%d",&j);
    return j;
}

void ListarInformacao(int *k) {
    int i;
    for(i=0; i < *k; i++) {
        printf("\t-------------------------------------------------------------------\n");
        printf("\n");
        printf("Id do Utente: %d\n",listaUtentes[i].id);
        printf("Nome do utente: %s\n",listaUtentes[i].nome);
        printf("Número BI: %d\n",listaUtentes[i].numero_bi);
        printf("Telefone: %d\n\n",listaUtentes[i].telefone);
        printf("\t-------------------------------------------------------------------\n");
    }
}

void RegistaUtente(int *k) {

    int i,j;
    j = pergunta();
    for( i = 1; i <= j; i++) {
        printf("Digite o número para o utente:\n");
        scanf("%d", &listaUtentes[*k].id);
        fflush(stdin);
        printf("Digite o nome do utente:\n");
        gets(listaUtentes[*k].nome);
        fflush(stdin);
        printf("Digite o número do BI:\n");
        scanf("%d", &listaUtentes[*k].numero_bi);
        fflush(stdin);
        printf("Digite a morada:\n");
        gets(listaUtentes[*k].morada);
        fflush(stdin);
        printf("Digite um número para contato:\n");
        scanf("%d", &listaUtentes[*k].telefone);
        fflush(stdin);
        system("cls");
        printf("\t---------------------Resumo da Cria��o-----------------------------\n");
        printf("Ficha criada com os seguintes dados:\n\n");
        printf("Número utente(ID): %d\n",listaUtentes[*k].id);
        printf("Nome: %s\n", listaUtentes[*k].nome);
        printf("Número BI: %d\n", listaUtentes[*k].numero_bi);
        printf("Morada: %s\n", listaUtentes[*k].morada);
        printf("Número de telefone: %d\n", listaUtentes[*k].telefone);
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
    for(i=0; i <= *k; i++) {

        if(id == listaUtentes[i].id) {
            printf("\t-------------------------------------------------------------------\n");
            printf("Informação do utente:\n");
            printf("Nome do utente: %s\n",listaUtentes[i].nome);
            printf("Número BI do utente: %d\n",listaUtentes[i].numero_bi);
            printf("Morada do utente: %s\n",listaUtentes[i].morada);
            printf("Número de contacto:%d\n",listaUtentes[i].telefone);
            printf("\t-------------------------------------------------------------------\n");
            printf("\t-------------------------------------------------------------------\n");
            printf("\n[Número de registo de Utente]- %d\n",id);
            printf("\n\n-Número de Utente: %d\n",id);
            printf("\n-Nome do Utente: ");
            fflush(stdin);
            gets(listaUtentes[i].nome);
            printf("\n-Número do Bilhete de Identidade: ");
            scanf("%d",&listaUtentes[i].numero_bi);
            printf("\n-Morada do Utente: ");
            fflush(stdin);
            gets(listaUtentes[i].morada);
            printf("\n-Numero de Telefone: ");
            scanf("%d",&listaUtentes[i].telefone);
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
    char nome[50];
} equipamentos;
equipamentos listaEquipamentos[MAX_EQUIPAMENTOS];

void LerEquipamentos(int *info) {
    FILE *fid2 = fopen("database2.txt", "r");
    int n =0;
    if (fid2) {
        while (!feof(fid2)) {
            fscanf(fid2,"%d %d %s\n",&listaEquipamentos[n].id,&listaEquipamentos[n].sn,listaEquipamentos[n].nome);
            (*info)++;
            n++;
        }
        fclose(fid2);
    } else printf("Erro na abertura do ficheiro!\n");
}

void EscreverEquipamentos(int *info) {
    FILE* fid2 = fopen("database2.txt","w+");
    int n = 0;
    if (fid2) {
        for (n=0; n < (*info); n++) {
            fprintf(fid2,"%d %d %s\n",listaEquipamentos[n].id,listaEquipamentos[n].sn,listaEquipamentos[n].nome);
        }
        fclose(fid2);
    } else printf("Erro na abertura do ficheiro!\n");
}


void VerInformacaoEquipamento(int *info) {
    int i,dados=0,existe;
    printf("Digite o numero do equipamento:\n");
    scanf("%d",&dados);
    for(i=0; i <= *info; i++) {
        if(dados == listaEquipamentos[i].id) {
            existe = 1;
            printf("\t-------------------------------------------------------------------\n");
            printf("Informação do equipamento:\n");
            printf("Nome do equipamento: %s\n",listaEquipamentos[i].nome);
            printf("Serial Number do equipamento: %d\n",listaEquipamentos[i].sn);
            printf("\t-------------------------------------------------------------------\n");
            break;
        }

    }
    if(existe == 0) {
        printf("Equipamentos não existe!\n");
    }

}

int perguntaEquipamentos(int info, int k) {
    int i;
    printf("Introduza o número de registos a efetuar\n");
    scanf("%d",&listaEquipamentos[info].id);
    for(i=1; listaEquipamentos[info].id; i++){
        if(listaEquipamentos[i].id == k) {
            printf("Número de ID já registado!\n");
            break;
        }
    }
    return k;
}

void RegistaEquipamento(int *info) {
    int i,k;
    k = perguntaEquipamentos(k, info);
    for(i=1; i<=k; i++) {
        printf("\t-------------------------------------------------------------------\n");
        printf("Digite ID para o equipamento:\n");
        scanf("%d", &listaEquipamentos[*info].id);
        fflush(stdin);
        printf("Digite o S/N do equipamento:\n");
        scanf("%d", &listaEquipamentos[*info].sn);
        fflush(stdin);
        printf("Digite o nome do equipamento:\n");
        //fgets(listaEquipamentos[info].nome);
        scanf("%d", listaEquipamentos[*info].nome);
        fflush(stdin);
        system("cls");
        printf("\t---------------------Resumo da Criação-----------------------------\n");
        printf("Ficha criada com os seguintes dados:\n\n");
        printf("ID do equipamento: %d\n",listaEquipamentos[*info].id);
        printf("Número S/N: %d\n",listaEquipamentos[*info].sn);
        printf("Nome: %s\n", listaEquipamentos[*info].nome);
        printf("\t-------------------------------------------------------------------\n");
        (*info)++;
    }
}

void AlteraDadosEquipamentos(int *info) {
    int dados;
    printf("\t-------------------------------------------------------------------\n");
    printf("Digite o ID do equipamento que deseja alterar\n");
    scanf("%d", &dados);
    int i;
    for(i=0; i <= *info; i++) {
        if(dados == listaEquipamentos[i].id) {
            printf("\t-------------------------------------------------------------------\n");
            printf("Informação do Equipamento:\n");
            printf("Nome do equipamento: %s\n",listaEquipamentos[i].nome);
            printf("Serial Number: %d\n",listaEquipamentos[i].sn);
            printf("\t-------------------------------------------------------------------\n");
            printf("\t-------------------------------------------------------------------\n");
            printf("\n[ID do equipamento a alterar]- %d\n",dados);
            printf("\n\n-ID do equipamento: %d\n",dados);
            printf("\n-Nome do equipamento: ");
            fflush(stdin);
            gets(listaEquipamentos[i].nome);
            printf("\n-Serial Number do equipamento: ");
            scanf("%d",&listaEquipamentos[i].sn);
            getchar();
            printf("Registo alterado com sucesso!");
            fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------------------\n");
        }
    }
}

void AbateEquipamento(int *info) {
    int i,dados,verdade;
    printf("Digite o ID do equipamento a abater:\n");
    scanf("%d",&dados);
    for(i=0; i <= *info; i++) {
        if(dados == listaEquipamentos[i].id) {
            verdade = 1;
            listaEquipamentos[i].id = 0;
            printf("Equipamento abatido com sucesso!\n");
            break;
        }
    }
    if(verdade == 0)
        printf("Equipamento não consta nos registos!\n");
}

void ListagemDeEquipamentos(int *info) {
    int i;
    for(i=0; i < *info; i++) {
        if(listaEquipamentos[i].id >= 1) {
            printf("\t-------------------------------------------------------------------\n");
            printf("\n");
            printf("Nome do equipamento: %s\n",listaEquipamentos[i].nome);
            printf("Serial number do equipamento: %d\n",listaEquipamentos[i].sn);
            printf("\t-------------------------------------------------------------------\n");
        } else
            printf("Não há equipamenetos!\n");
    }
}
int main() {
    setlocale(LC_ALL,"portuguese"); ///Serve para identificar os caracteres com acentos.
    int op, op2, op3, op4, k=0, info = 0; ///Declaração das variáveis
    LerUtentes(&k);
    LerEquipamentos(&info);
    ///Ciclo do while no menu de gestão.
    do {
        printf("\t------------------Bem-vindo ao Menu Principal----------------------\n"); ///printsf's para exebir o menu
        printf("\t\t            1. Gestão de clientes\n");
        printf("\t\t            2. Gestão de equipamentos\n");
        printf("\t\t            3. Gestão de requisições\n");
        printf("\t\t            4. Sair do programa\n");
        printf("\t-------------------------------------------------------------------\n");
        printf("Escolha sua op��o:\n");
        scanf("%d", &op);
        system("cls");
        switch(op) {
        case 1: ///Condição se a opção selecionada for 1 aparecerá os seguintes submenus do menu clientes
            do {
                printf("\t---------------------Menu de Utentes-------------------------------\n");
                printf("\t\t    1. Ver informação de um utente\n");
                printf("\t\t    2. Registar novo utente\n");
                printf("\t\t    3. Alterar dados de um utente\n");
                printf("\t\t    4. Listar infomação de utentes\n");
                printf("\t\t    5. Voltar ao menu anterior\n");
                printf("\t-------------------------------------------------------------------\n");
                printf("Escolha sua opção:\n");
                scanf("%d", &op2);
                switch(op2) {
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
                    printf("Opção inválida!\n");
                    break;
                }
            } while(op2 != 5);
            system("cls");
            break;
        case 2: ///Caso n�o for 1 mas sim 2, ir�  aparecer o segundo menu e as seguintes mensagens abaixo do menu equipamentos
            do {
                printf("\t--------------------------Menu dos Equipamentos--------------------\n");
                printf("\t\t    1. Ver Informação de um equipamento\n");
                printf("\t\t    2. Registar novo equipamento\n");
                printf("\t\t    3. Alterar informação de um equipamento\n");
                printf("\t\t    4. Abater um equipamento\n");
                printf("\t\t    5. Listagem de equipamentos\n");
                printf("\t\t    6. Voltar ao menu anterior\n");
                printf("\t-------------------------------------------------------------------\n");
                printf("Escolha sua opção:\n");
                scanf("%d", &op3);
                switch(op3) {
                case 1:
                    VerInformacaoEquipamento(&info);
                    break;
                case 2:
                    RegistaEquipamento(&info);
                    break;
                case 3:
                    AlteraDadosEquipamentos(&info);
                    break;
                case 4:
                    AbateEquipamento(&info);
                    break;
                case 5:
                    ListagemDeEquipamentos(&info);
                    break;
                default :
                    system("cls");
                    printf("Opção inválida!\n");
                    break;
                }
            } while(op3 != 6);
            system("cls");
            break;

        case 3: ///Caso não for o primeiro ou segundo menu aparece os submenus das requiso��es
            do {
                printf("\t-------------------------------------------------------------------\n");
                printf("\t\t    1. Registar requisição de equipamento\n");
                printf("\t\t    2. Registar entrega de equipamento\n");
                printf("\t\t    3. Listagem de equipamentos requisitados\n");
                printf("\t\t    4. Listagem de Equipamentos disponíveis\n");
                printf("\t\t    5. Listagem de equipamentos\n");
                printf("\t\t    6. Voltar ao menu anterior\n");
                printf("\t-------------------------------------------------------------------\n");
                printf("Escolha sua opção:\n");
                scanf("%d", &op4);
                switch(op4) {
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
                    printf("Opção Inválida!\n");
                    break;
                }
            } while(op4 != 6);
            system("cls");
            break;
        case 4:
            EscreverEquipamentos(&info);
            EscreverUtentes(&k);
            printf("Até breve!\n\a"); /// Mensagem exibida quando o usu�rio sair do programa.
            system("pause");
            op2 = 0;
            break;
        }
    } while(op2!= 0);
    return 0;
}
