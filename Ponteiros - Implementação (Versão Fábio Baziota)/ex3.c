#include <stdio.h>
#include <stdlib.h>



int somaElementos(int A[], int ultPos);

int main()
{
	int a[7] = {1,2,3,4,5,6,7};
	printf("\n%d\n",somaElementos(a,4));
	return 0;
}

/*
int somaElementos(int A[], int ultPos)
{
  int soma = 0;
  for(int i=0; i<= ultPos; i++) soma += A[i];
  return soma;
}*/


int somaElementos(int A[], int ultPos)
{
  int soma = 0, *pta = A;
  for(int i=0; i<= ultPos; i++) soma += *pta;
  return soma;
}


char *diaSemana ( int n)
{
static char *d[ ] = { "erro", "domingo", "segunda-feira", "terça-feira",
"quarta-feira", "quinta-feira", "sexta-feira", "sábado" };
return d [ 1<=n && n<=7 ? n : 0 ];
}




int comparar(char st1[], char st2[])
{
  for(int i=0; st1[i] == st[i]; i++)
    if(st1[i] == '\0') return 0;
  return st1[i] - st2[i];
}



void msgErro ( int codigo )
{
static char * Erro[ ] = { "Posicao Inicial Inválida",
"Posicao Final Nao Encontrada",
"Posicao Final Encontrada" };
printf ( "\n "%s", Erro[codigo] );
}
