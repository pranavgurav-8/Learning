#include <iostream>

template <typename T>

class SharePointer{
    private:
    int *refCounter;
    T* ptr;

    public:
        explicit SharePointer(T* p = nullptr):ptr(p){
            if(p){
                refCounter = new int(1);
            }
            else{
                refCounter = nullptr;
            }
        }

        SharedPointer(const SharedPointer<T>& sp){
            ptr = sp.ptr;
            refCounter = sp.refCounter;

            if(refCounter){
                ++(*refCounter);
            }
        }

        SharedPointer<T>& operator=(const SharedPointer<T>& sp){
            if(this == &sp) return *this;

            release();

            ptr = sp.ptr;
            refCounter = sp.refCounter;

            if(refCount) {
                ++(*refCounter);
            }

            return *this;
        }

        ~SharedPointer() {
            release();
        }

        T& operator*(){return *ptr;}
        T* operator->(){return ptr;}

        int use_count() const { return (refCounter) ? *refCounter : 0;}

        private:
            void release(){
                if(refCounter){
                    --(*refCounter);
                }
                if(*refCounter == 0){
                    delete ptr;
                    delete refCounter;
                    ptr = nullptr;
                    refCounter = nullptr;
                }
            }
};

int main() {
    SharedPointer<int> sp1(new int(42));
    std::cout << "sp1 count: " << sp1.use_count() << "\n";

    SharedPointer<int> sp2 = sp1; // Copy
    std::cout << "sp1 count: " << sp1.use_count() << "\n";
    std::cout << "sp2 count: " << sp2.use_count() << "\n";

    SharedPointer<int> sp3;
    sp3 = sp1; // Assignment
    std::cout << "sp1 count: " << sp1.use_count() << "\n";
    std::cout << "sp3 count: " << sp3.use_count() << "\n";

    std::cout << "Value: " << *sp1 << "\n";

    return 0;
}
