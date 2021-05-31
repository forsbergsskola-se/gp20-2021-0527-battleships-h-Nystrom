#include <iostream>

int FibonacciRecursive(int);


int main(){
    
    const int number = 7;
    std::cout << FibonacciRecursive(number) << std::endl;
    
    return 0;
}
int FibonacciRecursive(const int n){
    if(n <= 1)
        return n;
    return FibonacciRecursive(n-1)+FibonacciRecursive(n-2);
}

