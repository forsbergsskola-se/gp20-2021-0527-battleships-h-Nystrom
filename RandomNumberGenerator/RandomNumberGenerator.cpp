#include <algorithm>
#include <iostream>

int main(){
    const int maxValue = 20;
    const int minValue = 1;
    const int maxLength = 20;
    int randomNumbers[maxLength];
    int numberFrequency[maxLength];
    std::fill_n(numberFrequency, maxLength,0);
    
    for (int i = 0; i < maxLength;i++){
        const int tempRandom =  rand() % maxValue+minValue;
        randomNumbers[i] = tempRandom;
        numberFrequency[tempRandom]++;
    }
    for (int i = 0; i < maxLength;i++){
       std::cout << randomNumbers[i] << " ";
    }
    std::cout << " " << std::endl;
    for (int i = 0; i < maxLength; i++){
    if(numberFrequency[i] <= 0)
        continue;
    const float percentageChance = static_cast<float>(numberFrequency[i])/static_cast<float>(maxLength)*100;
    std::cout << "Frequency "<< i << ": " << numberFrequency[i] << "times " << percentageChance << "% " << std::endl;    
    }
    return 0;
}
