#include<iostream>

class Base{
    private:
    int size;
    int *data;

    public:
    Base(int s):size(s){
        std::cout <<"constructor called"<<std::endl;
        data = new int[size];
    }

    Base(const Base& other):size(other.size){
        std::cout<<"copy constructor called"<<std::endl;
        data = new int[size];
    }

    Base& operator=(const Base& other){
        std::cout<<"copy assignment called"<<std::endl;
        if(this != &other){
            delete[] data;
            size = other.size;
            data = new int[size];
        }
        return *this;
    }

    Base(Base&& other) noexcept : data(other.data),size(other.size){
        std::cout<<"Move constructor called"<<std::endl;
        other.data = nullptr;
        other.size = 0;
    }

    Base& operator=(Base&& other) noexcept{
        std::cout<<"Move assignment called"<<std::endl;
        if(this != &other){
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~Base(){
        std::cout<<"destructor called"<<std::endl;
        delete[] data;
    }

};

int main(){
    Base base(4);
    Base B2(std::move(base));
    B2 = std::move(base);

}