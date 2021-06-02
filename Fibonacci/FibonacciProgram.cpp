#include "Fibonacci.h"

int main(){
    auto fibonacciIterative = FibonacciIterative();
    auto fibonacciRecursive = FibonacciRecursive();
    fibonacciIterative.DisplayElapsedTimeFor(30);
    fibonacciRecursive.DisplayElapsedTimeFor(30);
    return 0;
}