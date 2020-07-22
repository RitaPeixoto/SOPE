// PROGRAMA p03a.c 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define NUM_THREADS 10 

void *PrintHello(void *threadnum) {    
    printf("Hello from thread no. %d!\n", *(int *) threadnum);    
    pthread_exit(NULL); 
} 
int main() {    
    pthread_t threads[NUM_THREADS];    
    int t;    
    for(t=0; t< NUM_THREADS; t++){       
        printf("Creating thread %d\n", t);       
        pthread_create(&threads[t], NULL, PrintHello, (void *)&t);    
    }    
    pthread_exit(0); 
}
// O resultado nao é o esperado porque não há nada que fique à espera que o thread anterior termine e portanto
//printe o hello from thread...