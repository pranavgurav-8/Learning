#include <iostream>
#include <mutex>
#include <thread>
std::mutex m;
int x = 0;

void increment(){
    std::lock_guard<std::mutex> lock(m);
    x++;
}

int main(){
    std::thred t1(increment);
    t1.join();
    return 0;
}