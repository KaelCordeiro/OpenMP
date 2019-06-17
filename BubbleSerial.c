#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void Bubble(int vet[]){
	int j;
	int i;
	int aux;
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

int main (void) {

	int vet[MAX_SIZE];

	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		vet[i] = rand()  % 100;	
	}	
	clock_t inicio = clock();
	Bubble (vet);	
	clock_t fim = clock();
	double tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
	printf("Tempo total Serial - %g", tempo);
	printf("\n\n");
	
		
	return 0;		
}
