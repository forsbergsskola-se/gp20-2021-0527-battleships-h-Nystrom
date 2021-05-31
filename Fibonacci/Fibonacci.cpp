

#include <iomanip>
using namespace std;
#include <chrono>
#include <string>
#include <iostream>


int FibonacciRecursive(int);
int FibonacciIterative(int);


//TODO: Refactor...
void CalculateElapsedTimeForNFibonacciSequenceRecursive(const int length){
    
    const auto startTime = chrono::high_resolution_clock::now();
    for(int n = 0; n <= length; n++){
        cout << FibonacciRecursive(n) << endl;
    }
    const auto finishTime = chrono::high_resolution_clock::now();
    double elapsedTime = chrono::duration_cast<chrono::nanoseconds>(finishTime-startTime).count();
    elapsedTime *= 1e-9;
    cout << "Total time for iterative fibonacci function: " << fixed << elapsedTime << setprecision(9);
    cout << "s" << endl;
}
void CalculateElapsedTimeForNFibonacciSequenceIterative(const int length){
    
    const auto startTime = chrono::high_resolution_clock::now();
    for(int n = 0; n <= length; n++){
        cout << FibonacciIterative(n) << endl;
    }
    const auto finishTime = chrono::high_resolution_clock::now();
    double elapsedTime = chrono::duration_cast<chrono::nanoseconds>(finishTime-startTime).count();
    elapsedTime *= 1e-9;
    cout << "Total time for iterative fibonacci function: " << fixed << elapsedTime << setprecision(9);
    cout << "s" << endl;
}

int main(){
    
    CalculateElapsedTimeForNFibonacciSequenceIterative(10);
    CalculateElapsedTimeForNFibonacciSequenceRecursive(10);
    return 0;
}
int FibonacciRecursive(const int n){
    if(n <= 1)
        return n;
    return FibonacciRecursive(n-1)+FibonacciRecursive(n-2);
}

int FibonacciIterative(const int n){
    if(n <= 1)
        return n;
    int previousNumber = 0;
    int previousNumber2 = 1;
    for (int i = 1; i < n; i++){
        const int next = previousNumber + previousNumber2;
        previousNumber = previousNumber2;
        previousNumber2 = next;
    }
    return previousNumber2;
}


