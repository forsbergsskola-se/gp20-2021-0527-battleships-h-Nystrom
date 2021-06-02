#include <iostream>
#include <time.h>

int main(){
    const int maxLength = 21;
    int randomNumbers[maxLength]{};
    int numberFrequency[maxLength]{};
    srand(static_cast<unsigned>(time(nullptr)));
    
    for (int i = 0; i < maxLength;i++){
        const int minValue = 1;
        const int maxValue = 20;
        const int tempRandom =  rand() % maxValue+minValue;
        randomNumbers[i] = tempRandom;
        numberFrequency[tempRandom]++;
    }
    for (int i = 0; i < maxLength;i++){
       std::cout << randomNumbers[i] << " " << std::flush;
    }
    std::cout << std::endl;
    for (int i = 0; i < maxLength; i++){
    if(numberFrequency[i] <= 0)
        continue;
    const float percentageChance = static_cast<float>(numberFrequency[i])/static_cast<float>(maxLength-1)*100;
    std::cout << "Frequency "<< i << ": " << numberFrequency[i] << "times " << percentageChance << "% " << std::endl;
    }
    return 0;
}
