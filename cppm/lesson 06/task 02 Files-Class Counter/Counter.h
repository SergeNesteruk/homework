#pragma once

class Counter
{
private:
    double x;
public:
    double inc();
    double dec();
    void view();
    Counter();
    Counter(double num);
    
};