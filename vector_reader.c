#include <stdio.h>
#include <stdlib.h>

int main(void) {

//declaração de variáveis
int *vetor_A, *vetor_B, *vetor_C, *vetor_D;
int cont_c = 0, cont_d = 0, cont=0;
int qtd_A, qtd_B, i, j;
  
  //requisição de dados pelo usuário
  printf("Digite a quantidade de elementos do vetor A: ");
  scanf("%d", &qtd_A);
  printf("\nDigite a quantidade de elementos do vetor B: ");
  scanf("%d", &qtd_B);
  
  //decidindo a quantidade de bytes
  vetor_A= (int*) malloc( qtd_A*sizeof(int));
  vetor_B= (int*) malloc( qtd_B*sizeof(int));
  vetor_C= (int*) malloc( (qtd_A+qtd_B)*sizeof(int));
  vetor_D= (int*) malloc( (qtd_A+qtd_B)*sizeof(int));
     
     //requisição do elemento correspondente ao A
    for (i = 0; i < qtd_A; i++){
		printf("Digite o elemento correspondente %d de A: ", i);
		scanf("%d", &vetor_A[i]);}

    //requisição do elemento correspondente ao B
    for (i = 0; i < qtd_B; i++) {
	printf("Digite o elemento correspondente %d de B: ", i);
	scanf("%d", &vetor_B[i]);}
    
    //considerando a quantidade de vezes que o vetor c será executado a partir da semelhança entre os valores dos vetores A e B
    for (i = 0; i < qtd_A; i++) {
		 for (j = 0; j < qtd_B; j++) {
			if (vetor_A[i] == vetor_B[j]) 
            {
				vetor_C[cont_c] = vetor_A[i];
				cont_c++;
			}
        }
    }

    //imprimindo o valor final de C
    for(i = 0; i < cont_c; i++) 
{
    printf("vetor C [%d] = %d\n", i, vetor_C[i]);
}
  
  //laços e condições para quando não tiver valores iguais entre os vetores A e B haverá o vetor D, diferente do vetor C que depende que eles sejam iguais
  for (i = 0; i < qtd_A; i++) 
{
	vetor_D[cont_d] = vetor_A[i];
	cont_d++;
}

    for (i=0 ;i<qtd_B;i++){
        for (j=0 ;j<qtd_A;j++){
            if (vetor_B[i]==vetor_A[j]){
                cont++;
                }
            }  

    if (cont==0){
      vetor_D[cont_d]=vetor_B[i];
      cont_d++;
      }
    cont=0;
  }
    
    //imprimindo o resultado final de D
    for (i=0 ;i<cont_d;i++){

      printf("O elemento respectivo %d do vetor D: %d\n",i,vetor_D[i]);
    }

    //evitando vazamento de memória
    free(vetor_A);
    free(vetor_B);
    free(vetor_C);
    free(vetor_D);

  return 0;
}