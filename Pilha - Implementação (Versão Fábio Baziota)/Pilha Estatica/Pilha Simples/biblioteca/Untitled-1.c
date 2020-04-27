#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *ant;
}node;

typedef struct Pilha{
    node *topo;
}Pilha;

Pilha *P;

void cria(Pilha *P){
    P->topo = NULL;
}

void push(Pilha *P, int x){
    node *p;
    node *aux;
    node *proximo;

    proximo = NULL;
    aux = NULL;

    p =(node*)malloc(sizeof(node));

    if(p == NULL){
        printf("Erro de alocacao!");
        exit(1);
        }
    else{
        p->info = x;

        if(P->topo == NULL){
            p->ant = NULL;
            P->topo = p;
       }
        else{
            aux = P->topo;

            while(aux != NULL && aux->info > x ){
                proximo = aux;
                aux = aux->ant;
            }

            proximo->ant = p;
            p->ant = aux;

        }
    proximo = NULL;
    aux = NULL;
    }
}

void converte(char string[], Pilha *P){
    char *pch;
    int x;

    pch = strtok(string," ");
    while (pch != NULL){

        x = atoi(pch);
        push(P, x);
        pch = strtok (NULL, " ");
    }
}

void imprime(Pilha *P){
    node *p;

    if(P->topo == NULL){
        printf("A Pilha esta vazia!");
        exit(1);
    }
    else{
        p = P->topo;

        while(p!=NULL){
            printf("%d ", p->info);
            p = p->ant;
        }
    }
}

void esvazia(Pilha *P){
    node *p, *aux;

    p = P->topo;


    while(p != NULL){
        aux = p;
        p = p->ant;
        free(aux);
    }
    free(P);
}

int main(){

    char string[6000];

    Pilha *P = (Pilha*) malloc (sizeof(Pilha));
    cria(P);

    printf("Informe os valores da pilha: ");
    fgets(string, 6000, stdin);
    converte(string, P);

    imprime(P);
    esvazia(P);

    return 0;

}


