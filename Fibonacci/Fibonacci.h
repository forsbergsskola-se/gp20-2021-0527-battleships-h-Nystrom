#pragma once

class BaseFibonacci{
protected:
    ~BaseFibonacci() = default;
public:
    virtual int CalculateFibonacci(int number) = 0;
    void DisplayElapsedTimeFor(int length);
};

class FibonacciIterative final : public BaseFibonacci{
public:
    virtual ~FibonacciIterative() = default;
    int CalculateFibonacci(int number) override;
};

class FibonacciRecursive final : public BaseFibonacci{
public:
    virtual ~FibonacciRecursive() = default;
    int CalculateFibonacci(int number) override;
};
