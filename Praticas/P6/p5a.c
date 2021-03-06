// PROGRAMA p05a.c
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
/*Escreva um programa que leia 2 números do teclado e crie 4 threads que façam,respectivamente,a soma,a 
subtracção,o produto e o quociente dos números lidos.Os operandos devem ser passados como parâmetros às
threads(usar duas formas diferentes de o fazer,através de um array e de uma struct).O valor dos operandos
e o resultado de cada operação devem ser apresentados no ecrã pela thread que executou cada operação */

void *sum(void *arg) {
    int *aux = (int*)arg;
    printf("Sum = %d\n",aux[0]+aux[1]);
    return NULL;
}
void *sub(void *arg) {
    int *aux = (int*)arg;
    printf("Sub = %d\n",aux[0]- aux[1]);
    return NULL;   
}
void *mult(void *arg) {
    int *aux = (int*)arg;
    printf("Mult = %d\n",aux[0]*aux[1]);
    return NULL;
}
void *quo(void *arg) {
    int *aux = (int*)arg;
    printf("Quo = %d\n",aux[0]/aux[1]);
    return NULL;
}


int main(){
    int *args =(int*)malloc(sizeof(int)*2);
    pthread_t tsum, tsub, tmult, tquo;

    printf("Insert two numbers(format: num1 num2):");
    scanf("%d %d", &args[0],&args[1]);

    pthread_create(&tsum,NULL, sum, (void*)args);
    pthread_create(&tsub,NULL, sub, (void*)args);
    pthread_create(&tmult,NULL, mult,(void*)args);
    pthread_create(&tquo,NULL, quo, (void*)args);

    pthread_join(tsum, NULL);
    pthread_join(tsub, NULL);
    pthread_join(tmult, NULL);
    pthread_join(tquo, NULL);

    pthread_exit(0);
}