#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void * compute(void *ptr){
    long sum=0;

    long *add=(long*)(ptr);
    printf("ADD: %ld\n",*add);

    for(long i=0;i<1000000000;i++){
        sum+=*add;
    }
    // printf("Hello\n");
}
int main(){
    pthread_t thread1;
    pthread_t thread2;
    
    long a=1;
    long b=2;

pthread_create(&thread1,NULL,compute,(void*)&a);    
    
    pthread_join(thread1,NULL);

    
    pthread_create(&thread2,NULL,compute,(void*)&b);
    
    pthread_join(thread2,NULL);

    // compute((void *)&a);
    // compute((void *)&b);

    
    return 0;
}