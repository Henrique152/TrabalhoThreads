#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <pthread.h>

using namespace std;

#define TAM 150
//#define TAM 250
//#define TAM 350

double tempo, timedif;

int array[TAM];

void * load (void * arg)
{
    for(int i = 0; i< TAM; i++)
    {
        array[i] = i;
    } 

    return NULL;
}

int main(){

    tempo = (double) clock();
    tempo = tempo / CLOCKS_PER_SEC;

    pthread_t t1;
    int a1 = 1;

    pthread_create(&t1, NULL, load, (void *)(&a1)); //cria thread 1
    pthread_join(t1,NULL);
    pthread_exit(NULL);
    cout << " Vetor carregado sequencialmente";
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo;
            printf("\nTempo executado: %f segundos em single thread", timedif);
    return 0;
}