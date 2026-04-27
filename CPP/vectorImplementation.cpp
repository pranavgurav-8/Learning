#include <iostrea>

template <typename T>
class Vector{
    size_t size;
    size_t capacity;
    T* data;


    void grow(){
        int newCapacity = (capacity == 0) ? 1 : 2 * capacity;

        T* newData = new T[newCapacity];

        for(int i = 0; i<size; i++){
            newData[i] = data[i];
        }

        delete data[];
        data = newData;
        capacity = newCapacity;

    }

    public:
        Vector(): data(nullptr),size(0),capacity(0);

        ~Vector(){
            delete data[];
        }

        void push_back(const T& val){
            if(size == capacity){
                grow();
            }

            data[++size] = val;
        }

        void reserve(size_t newCapacity){
            if(newCapacity > capacity){
                grow();
            }
        }

        void pop_back(){
            if(size > 0){
                --size;
            }
        }

        T& operator[](size_t index){
            return data[index];
        }

        size_t size() const {
            return size;
        }

        size_t capacity() const {
            return capacity;
        }


}