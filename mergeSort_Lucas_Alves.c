	/* Merge Sort */
	#include<stdlib.h>
	#include<stdio.h>
	
 /* criando vetores temporarios e um contador de forma global*/
   int *temp_L, *temp_R, cont=0;
 /*****************************************/  
void printArray(int *vetor,int size);

  /*função para trocar e mudar valores de lugar dentro do vetor principal.
   utilizo como base, dois vetores auxiliares para comparação dos dados*/  
void merge(int *vetor, int inicio, int meio, int fim){
	    int i, j, k;
	    int n1 = meio - inicio + 1;// recebe o tamanho de uma metade do array
	    int n2 =  fim - meio;// recebe o tamanho da outra metade do array
	    
	    /*Dois vetores auxiliares definidos de forma global.
		 Cada um dos vetores recebe o tamanho exato de cada metade de forma dinâmica*/
	    temp_L = (int*)malloc(n1*sizeof(int));
	    temp_R = (int*)malloc(n2*sizeof(int));
	      if(!temp_L || !temp_R){
	      	printf("SEM MEMORIA DISPONIVEL!\n\n");
	      	exit(1);
		  }
	    	temp_L[n1], temp_R[n2];
	 
	    /* copiando os dados da primeira parte do vetor para o vetor auxiliar*/
	    for (i = 0; i < n1; i++){
	    	temp_L[i] = vetor[inicio + i];
		}
	        /*copiando a segunda metade do vetor para o segundo vetor auxiliar*/
	    for (j = 0; j < n2; j++){
	    	 temp_R[j] = vetor[meio + 1+ j];
		}
	       
	 
	    /* reiniciando as variaveis*/
	    i = 0; 
	    j = 0;
	    k = inicio; 
	    
	    /*Momento da troca de valores onde comparo se o valor de um lado do vetor é menor ou igual
		ao valor do outro lado do vetor*/
	    while (i < n1 && j < n2) {
	        if (temp_L[i] <= temp_R[j]){
	            vetor[k] = temp_L[i];// depois da comparação jogo os valores menores dentro do vetor original
	            i++;// avanço para o meio
	        }
	        else
	        {
	            vetor[k] = temp_R[j];// jogo sempre o valor menor dentro do vetor original
	            j++; // avanço para o fim 
	        }
	        k++;// sobe uma posição
	    }
	 
	    /* copio o restante dos elementos "caso houver" do primeiro vetor auxiliar para o vetor original */
	    while (i < n1){
	        vetor[k] = temp_L[i];
	        i++;
	        k++;
	    }
	 
	    /* copiando valores do outro vetor auxiliar para o vetor original */
	    while (j < n2){
	        vetor[k] = temp_R[j];
	        j++;
	        k++;
	    }
	 
}
	
	/* (inicio) é a posição inicial do vetor, (fim) é a ultima posição do vetor
	 e '*vetor' é o nosso vetor passado como referencia */
	void mergeSort(int *vetor, int inicio, int fim){
	    if (inicio < fim){
	        int meio = inicio+(fim-inicio)/2;
	 
	       
	        mergeSort(vetor, inicio, meio);// ordena do inicio até o meio do vetor
	        mergeSort(vetor, meio+1, fim);// ordena apartir do meio até o final vo vetor
	        cont++;/*contar os rounds de recursão*/
	        merge(vetor, inicio, meio, fim);// muda os indices e valores de posição
	    }
	}
	 
	
	/* imprimir o array */
	void printArray(int *vetor, int size){
	    int i;
	    for (i=0; i <= size; i++){
	    	printf("[%d]", vetor[i]);
	    	 if(i < size){
	    	 	printf("_");		
			 }
			  
		}
	        
	    printf("\n");
	}
	 
	
	int main(int argc, char *argv[]) {
		int tam;
		int i;
		
		printf("\t\tMergeSort!\n\nDigite o tamanho do vetor a ser ordenado\n->. ");
		scanf("%d",&tam);
		
		int vetor[tam];
		   for(i=0; i<=tam-1; i++){
		    	printf("digite o valor da posicao[%d]: ",i);
		    	scanf("%d",&vetor[i]);
		   }
		   int size = sizeof(vetor)/sizeof(vetor[0]);// calcular o tamaho do vetor;
		   
		   mergeSort(vetor, 0, size-1);
		   printf("*___________________________ROUNDS->>(%d)<<-__________________________________*\n",cont);// quantos rounds de recursão
		   printArray(vetor, tam-1);
		free(temp_L);
	    free(temp_R);
		return 0;
	}
