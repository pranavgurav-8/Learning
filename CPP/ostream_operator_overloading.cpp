#include <iostream>
class MyClass{
    int a;
    public:
        MyClass(int x): a(x){}
        friend std::ostream& operator<<(std::ostream& os,const MyClass& other);
};

std::ostream& operator<<(std::ostream& os,const MyClass& other){
    os<<other.a;
    return os;
}
        
int main(){
    MyClass obj(4);
    MyClass obj3(8);
    
    std::cout<<obj<<obj<<std::endl;
    return 0;
 }