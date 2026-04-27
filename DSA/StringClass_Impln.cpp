#include<iostream>
#include<cstring>
class String{
    char *data;
    int len;
    
    public:
    String():data(nullptr),len(0){}
    ~String(){
        delete[] data;
    }
    String(const char* str){
        std::cout<<"parameterized constructor called"<<std::endl;
        if(!str){
            data = nullptr;
            len = 0;
            return;
        }
        len = std::strlen(str)+1;
        data = new char[len];
        strcpy(data,str);
    }
    
    String(const String& other):len(other.len){
        std::cout<<"copy constructor called"<<std::endl;
        data = new char[len];
        strcpy(data,other.data);
    }
    
    String& operator=(const String& other){
        std::cout<<"copy assignment called"<<std::endl;
        if(this == &other){
            return *this;
        }
        
        delete[] data;
        len = other.len;
        data = new char[len];
        strcpy(data,other.data);
        return *this;
    }
    
    String(String&& other) noexcept:len(other.len),data(other.data){
        std::cout<<"move constructor called"<<std::endl;
        other.len = 0;
        other.data = nullptr;
    }
    
    String& operator=(String&& other) noexcept{
        std::cout<<"move assignment called"<<std::endl;
        if(this == &other){
            return *this;
        }
        delete[] data;
        len = other.len;
        data=other.data;
        
        other.len = 0;
        other.data = nullptr;
        return *this;
    }
    
    
    String operator+(String& other){
        std::cout<<"operator is called"<<std::endl;
        int newlen = (len ? len - 1 : 0) + other.len;
        char *buffer = new char[newlen];
        
        if(data){
            strcpy(buffer,data);
        }
        else{
            buffer[0]='\0';
        }
        
        if(other.data){
            strcat(buffer,other.data);
        }
        
        
        String result;
        result.data = buffer;
        result.len = newlen;
        
        return result;
    }
    
    
};

int main(){
String a("Hello");
String b(" World");
String c;
c = a + b + a;

}