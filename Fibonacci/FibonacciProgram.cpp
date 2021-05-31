#include "Fibonacci.h"

int main(){
    auto fibonacciIterative = FibonacciIterative();
    auto fibonacciRecursive = FibonacciRecursive();
    fibonacciIterative.DisplayElapsedTimeFor(10);
    fibonacciRecursive.DisplayElapsedTimeFor(10);
    return 0;
}