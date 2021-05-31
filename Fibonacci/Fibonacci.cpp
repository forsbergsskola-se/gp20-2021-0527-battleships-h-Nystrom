using namespace std;
#include <iostream>


int FibonacciRecursive(int);
int FibonacciIterative(int);


int main(){
    
    const int length = 10;
    for(int n = 0; n <= length; n++){
        cout << FibonacciIterative(n) << endl;
    }
    for (int n = 0; n <= length; n++){
        cout << FibonacciRecursive(n) << endl;
    }
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


