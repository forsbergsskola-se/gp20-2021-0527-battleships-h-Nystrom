using namespace std;
#include <string>
#include <chrono>
#include <iomanip>
#include <iostream>
#include "Fibonacci.h"


void BaseFibonacci::DisplayElapsedTimeFor(const int length){     
    const auto startTime = chrono::high_resolution_clock::now();
    for(int n = 0; n <= length; n++){
        cout << CalculateFibonacci(n) << fixed << ", ";
    }
    const auto finishTime = chrono::high_resolution_clock::now();
    cout << " " << endl;
#pragma warning(disable:4244)
    double elapsedTime = chrono::duration_cast<chrono::nanoseconds>(finishTime-startTime).count();
#pragma warning(default:4244)
    elapsedTime *= 1e-9;
    const string name = typeid(*this).name();
    cout << "Total time for " + name.substr(6, name.length()) + " function: " << fixed << elapsedTime << setprecision(9)<< "s" <<endl;
}
int FibonacciIterative::CalculateFibonacci(const int number){
        if(number <= 1)
            return number;
        int previousNumber = 0;
        int previousNumber2 = 1;
        for (int i = 1; i < number; i++){
            const int next = previousNumber + previousNumber2;
            previousNumber = previousNumber2;
            previousNumber2 = next;
        }
        return previousNumber2;
}
int FibonacciRecursive::CalculateFibonacci(const int number){
    if(number <= 1)
         return number;
    return CalculateFibonacci(number-1)+CalculateFibonacci(number-2);
}