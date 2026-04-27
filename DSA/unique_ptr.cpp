#include<iostream>

template <typemame T>

class unique_ptr{
    T* ptr;
    public:
        explicit unique_ptr(T *p = nullptr):ptr(p){}

        ~unique_ptr(){delete ptr;}

        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;

        unique_ptr(unique_ptr&& other) noexcept: ptr(other.ptr){
            other.ptr = nullptr;
        }

        unique_ptr& operator=(unique_ptr&& other) noexcept {
            if(this != &other){
                delete ptr;
                ptr = other.ptr;
                other.ptr = nullptr;

            }
            return *this;
        }

        T* get() const{
            return ptr;
        }

        T& operator*() const{
            return *ptr;
        }

        T* operator->() const{
            return ptr;
        }

        explicit operator bool() const noexcept{
            return ptr != nullptr;
        }

        T* release(){
            T* tmp = ptr;
            delete ptr;
            return tmp;
        }
        void reset(T *p = nullptr) noexpect {
            delete ptr;
            ptr  = p;
        } 


};