#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *func(void* arg){
    pthread_detach(pthread_self());
    printf("Inside the thread\n");
    pthread_exit(NULL);
}

void fun(){
    pthread_t ptid;
    pthread_create(&ptid,NULL,&func,NULL);
    printf("This line may be printed before thread terminates\n");

    //pthread_cancel(ptid)    manual termination
    
    //compare the two threads created
    if(pthread_equal(ptid,pthread_self())){
        printf("Threads are equal\n");
    }
    else{
        printf("Threads are not equal\n");
    }

    //waiting for the created thread to terminate
    pthread_join(ptid,NULL);
    printf("This line will be printed after thread ends\n");
    pthread_exit(NULL);

}

int main(){
    fun();
    return 0;
}
