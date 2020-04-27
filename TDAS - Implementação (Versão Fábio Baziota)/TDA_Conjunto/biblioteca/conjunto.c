/* -------------------------------------------------------------------------------------------------------
Especificação das Operações: conjunto.c
Objectivo: Implementação da TDA (conjunto) e Disponibilizar as operações de conjunto
Autor: BaziotaBeans++ (A.K.A Insonia)
Hora: 00:54
-------------------------------------------------------------------------------------------------------*/
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include “conjunto.h“

struct conjunto
{
  int* v; //vetor booleano que armazenará o conjunto sendo que
//o índice armazena o valor sendo true se o elemento está
// no conjunto, false caso contrário
};


void Destroi_Conj (Conjunto *A)
{
  free(A->v);
  free(A);
}

void uniao (Conjunto *A, Conjunto *B, Conjunto *C)
{
  int i;// variável auxiliar para realização do loop
  for(i = 0; i<TAM;i++)
  {
      if (A->v[i]==1) || (B->v[i]==1)
      {
        C->v[i]=1;
      }
  }
}


void interseccao(Conjunto *A, Conjunto *B, Conjunto *C)
{
  int i; // variável auxiliar para realização do loop
  for(i = 0; i<TAM;i++){
    if (A->v[i]==1) && (B->v[i]==1) {
      C->v[i]=1;
    }
}

/* faz o conjunto vazio ser o valor para a variável conjunto A. Deve ser
usado como primeira operação sobre um conjunto. Retorna erro = 0 se
sucesso e 1 se falhou.
*/



Conjunto* Cria_Conj_Vazio ( int *erro) {
int i; // variável auxiliar para realização do loop
Conjunto* conj = (Conjunto*) malloc(sizeof( Conjunto));
if (conj == NULL ) {
*erro= 1;
exit(1);
}
conj->v = ( int *) malloc( TAM* sizeof(int ));
for (i=0;i<TAM;i++){
conj->v[i]=0;
}
*erro = 0;
return conj;
}


int insere ( int x, Conjunto *A ) {
if (x>=TAM || x<0 ) {
return 0;
}
A->v[x]=1;
return 1;
}


int membro(int x, Conjunto *A) {
if (x>=TAM || x<0 ||(A->v[x]==0)) {
return 0;
}
return 1;
}




int remover ( int x, Conjunto *A ) {
if (x>=TAM || x<0 ||(A->v[x]==0)) {
return 0;
}
A->v[x]=0;
return 1;
}


void atribui (Conjunto *A, Conjunto *B ) {
int i; // variável auxiliar para realização do loop
for(i = 0; i<TAM;i++){
B->v[i]=A->v[i];
}
}



int min (Conjunto *A) {
int i;
for(i = 0; i<TAM;i++){
if (A->v[i]==1) {
return i;
}
}
return TAM; // condição de conjunto vazio
}


int max (Conjunto *A) {
int i;
for(i = TAM - 1; i>-1;i--){
if (A->v[i]==1) {
return i;
}
}
return TAM; // condição de conjunto vazio
}




void diferenca(Conjunto *A, Conjunto *B, Conjunto *C) {
int i; // variável auxiliar para realização do loop
for(i = 0; i<TAM;i++){
if (A->v[i]==1) && (B->v[i]==0) {
C->v[i]=1;
}
}


int igual( Conjunto *A, Conjunto *B) {
int i;
for(i = 0; i<TAM;i++){
if (A->v[i]!=B->v[i]) {
return 0;
}
}
return 1;
}



int tamanho( Conjunto *A) {
int i,tam; // variável auxiliar para realização do loop e para a
// verificação do tamanho do conjunto
tam = 0;
for(i = 0; i<TAM;i++){
if (A->v[i]==1) {
tam++;
}
}
return tam;
}


int testa_vazio( Conjunto *A); {
int i;
for(i = 0; i<TAM;i++){
if (A->v[i]==1) {
return 0;
}
}
return 1;
}
