#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class Stack{
private:
    T* _array;
    size_t _size;
    size_t _top;
    bool _isEmpty = true;

    void Expand(){
        _size *= 2;
        T* new_arr = new T [_size];
        std::memcpy(new_arr, _array, (_size/2)*sizeof(T));
        delete [] _array;
        _array = new_arr;
    }

public:
    Stack(size_t size = 10){
        _array = new T [10];
        _size = size;
        _top = 0;
    }
    bool IsEmpty() const {
        return _isEmpty;
    }
    bool IsFull() const{
        return ((_size - 1) == _top) && (!_isEmpty);
    }


    void Push(T elem){
        if (IsFull())
            Expand();

        if (IsEmpty()){
            _isEmpty = false;
            
        }
        else {
            _top++;
        }
        _array[_top] = elem;
    }

    T Pop(){
        if (IsEmpty())
            throw "no";
        if (_top == 0){
            _isEmpty = true;
            return _array[_top];
        }
        return _array[_top--];
    }

    T Chech(){
        return _array[_top];
    }

    friend std::ostream& operator<< (std::ostream& os, const Stack tmp){
        for (size_t i = 0; i <= tmp._top; i ++){
            os << tmp._array[i] << " ";
        }
        return os;
    }

    ~Stack() {
        delete [] _array;
    }
};