#include "Stack.h"

int main(){
    Stack <int>array(10);
    array.Push(10);
    array.Push(15);
    array.Push(20);
    std::cout << array << std::endl;
    std::cout << array << std::endl;
    int res = array.Pop();
    
    std::cout << res << std::endl;
};