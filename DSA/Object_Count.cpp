// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
class Base{
    static std::unordered_map<std::string,int> objectCount;
    
    public:
    Base(std::string name){
        std::cout<<"base is called"<<std::endl;
        objectCount[name]++;
    }
    
    static void getNumberOfInstances(){
        for(const auto& pair: objectCount){
            std::cout<<pair.first<<" "<<pair.second<<std::endl;
        }
    }
};
std::unordered_map<std::string,int> Base::objectCount;

class Derived:public Base{
    public:
    Derived():Base("Derived1"){
        std::cout<<"Derived is called"<<std::endl;
    }
};

class Derived2:public Base{
    public:
    Derived2():Base("Derived2"){
        std::cout<<"Derived2 is called"<<std::endl;
    }
};


int main() {
    // Write C++ code here
        Derived d;
        Derived d1;
        Derived2 d2;
        Base::getNumberOfInstances();
    return 0;
}