// Online C++ compiler to run C++ program online
#include <iostream>
    
int add(int a, int b){
    return a+b;
}

int multiply(int a,int b){
    return a*b;
}

void operate(int (*op)(int,int),int x,int y){
    std::cout<<op(x,y)<<std::endl;
}
int main() {
    int (*fptr1)(int,int) = add;
    int (*fptr2)(int,int) = multiply;
    operate(fptr1, 4,5);
    operate(fptr2, 4,5);

    return 0;
}