#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define MAX_SIZE 10
#define NUM_THREADS 16


void Bubble(int vet[]){
#pragma omp parallel num_threads(NUM_THREADS) shared(vet)
{	
	int j;
	int i;
	int aux;
#pragma omp for
        for(i = 0; i < MAX_SIZE ; i++){
        	for(j = 0; j < MAX_SIZE -1; j++){
			if(vet[j] > vet[j + 1]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
	 	
		}
   	}
} 
}

int main (void) {

	int vet[MAX_SIZE];

	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		vet[i] = rand()  % 100;	
	}
        double inicio = omp_get_wtime();
        Bubble(vet);
        double fim = omp_get_wtime();	
	double tempo = (double)(fim - inicio);
	printf("Tempo total Paralelo - %g", tempo);
	printf("\n\n");
		
	return 0;		
}


	
