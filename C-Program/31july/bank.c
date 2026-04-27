#include<stddef.h>
#include<unistd.h>
int balance=0;
int read_balance(){
    usleep(120000);
    return balance;
}
void write_balance(int new_balamce){
    usleep(120000);
    balance=new_balamce;
}
