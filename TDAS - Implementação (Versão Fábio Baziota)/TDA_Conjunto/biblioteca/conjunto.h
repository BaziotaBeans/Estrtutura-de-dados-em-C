/* -------------------------------------------------------------------------------------------------------
Especificação do Interface : conjunto.h
Objectivo: Implementação da TDA (conjunto) e Disponibilizar as operações de conjunto
Autor: BaziotaBeans++ (A.K.A Insonia)
Hora: 00:54
--------------------------------------------------------------------------------------------------------*/
#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

/* Tipo e Tamanho Exportados */
#define TAM 10 // trabalha com elementos do universo 0..TAM -1
typedef struct conjunto Conjunto;

/* Funções Exportadas */

/* Função união – Une os elementos do conjunto A e B em um conjunto C. */
void uniao (Conjunto *A, Conjunto *B, Conjunto *C);
void interseccao (Conjunto *A, Conjunto *B, Conjunto *C);
/* Função Destroi_Conj – Libera a memória de um conjunto */
void Destroi_Conj (Conjunto *A);
/* Função diferença – atribui ao conjunto C a diferença entre os conjuntos A e B */
void diferença(Conjunto *A, Conjunto *B, Conjunto *C);
/* Função membro – verifica se o elemento elem está no Conjunto A. Retorna 1 se está e 0 caso não esteja. */
int membro(int x, Conjunto *A);
/* Função Cria_Conj_Vazio – Cria um conjunto vazio e retorna o conjunto criado. A variável erro retorna 0 se o conjunto foi
criado corretamente e 0 caso contrario. Deve ser usado como primeira operação sobre um conjunto. */
Conjunto *Cria_Conj_Vazio (int *erro);
/* Função insere – insere o elemento elem no conjunto A e retorna se a execução foi realizada com sucesso(1) ou não(0)*/
int insere(int x, Conjunto *A);
/* Função remove (diferente da de PASCAL) – remove o elemento elem do Conjunto A, retorna 1 se o elemento
foi retirado e 0 se o elemento não está no conjunto */
int remover(int x, Conjunto *A);
/* Função Atribui – faz a copia do conjunto A para o B*/
void atribui( Conjunto *A, Conjunto *B);
/* Função min – retorna o menor elemento do conjunto A –
se o conjunto está vazio retorna TAM */
int min( Conjunto *A);

/* Função max – retorna o maior elemento do conjunto A - se o
conjunto está vazio retorna TAM */
int max( Conjunto *A);
/* Função igual – verifica se o conjunto A é igual a
Conjunto B. Retorna 1 se igual e 0 se diferente.
*/
int igual( Conjunto *A, Conjunto *B);
/* Função tamanho – retorna o tamanho do conjunto A (0..TAM-1)
*/
int tamanho( Conjunto *A);
/* Função testa_vazio – verifica se o conjunto A é vazio.
Retorna 1 se for vazio e 0 caso contrario*/
int testa_vazio( Conjunto *A);

#endif
