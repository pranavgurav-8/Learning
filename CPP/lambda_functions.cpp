#include <iostream>

int main(){
    int a =3;
     auto f = [](int x) mutable{
         return ++a;
     };
     std::cout<<f(1)<<std::endl;
     return 0;
 }