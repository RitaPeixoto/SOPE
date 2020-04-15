// PROGRAMA p02.c 
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#define STDERR 2 
#define NUMITER 10000 

int N = 50000;

void * thrfunc(void * arg) {   
    int i=0;   
    fprintf(stderr, "Starting thread %s\n", (char *) arg); 
    while(N>0){
        write(STDERR,arg,1);
        i++;
        N--;
    }
     void * res = malloc(sizeof(int));
    *(int *)res = i;
    return res;
} 
int main() {    
    pthread_t ta, tb;
    void *t1, *t2;   

    pthread_create(&ta, NULL, thrfunc, "1");   
    pthread_create(&tb, NULL, thrfunc, "2"); 

    pthread_join(ta, &t1);   
    pthread_join(tb, &t2); 

    fprintf(stderr,"\nThread 1 wrote %d characters\n",*(int*)ta);
    fprintf(stderr,"\nThread 2 wrote %d characters\n",*(int*)tb);

    return 0; 
}