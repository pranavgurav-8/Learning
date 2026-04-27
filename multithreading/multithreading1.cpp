#include <iostream>
#include <thread>
void task(){
    std::cout<<"hello"<<std::endl;
}
int main(){
    std::thread t(task);
    t.join();

}