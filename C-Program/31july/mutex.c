#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#include "bank.h"

pthread_mutex_t mutex;

void* deposit(void *amount){

    //create lock
    pthread_mutex_lock(&mutex);
    int account_balance=read_balance();
    account_balance += *((int *)amount);
    write_balance(account_balance);
    pthread_mutex_unlock(&mutex);
    //release lock
    return NULL;
}

int main(){
    int before=read_balance();
    printf("Before: %d\n",before);

    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&mutex,NULL);

    int deposit1=300;
    int deposit2=100;

    pthread_create(&thread1,NULL,deposit,(void*)&deposit1);
    pthread_create(&thread2,NULL,deposit,(void*)&deposit2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);  

    pthread_mutex_destroy(&mutex);
    int after=read_balance();
    printf("After: %d\n",after);

}
