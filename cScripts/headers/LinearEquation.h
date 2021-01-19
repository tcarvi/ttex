#include <iostream>

namespace linear_algebra {
class LinearEquation
{
    public:
        LinearEquation(unsigned long long int, unsigned long long int, unsigned long long int, unsigned long long int, unsigned long long int);
        LinearEquation(unsigned long long int, unsigned long long int, unsigned long long int, unsigned long long int);
        LinearEquation(unsigned long long int, unsigned long long int, unsigned long long int);
        LinearEquation(unsigned long long int, unsigned long long int);
        LinearEquation(unsigned long long int);
        unsigned long long int getC1();
        unsigned long long int getC2();
        unsigned long long int getC3();
        unsigned long long int getC4();
        unsigned long long int getC5();
    private:
        unsigned long long int C1;
        unsigned long long int C2;
        unsigned long long int C3;
        unsigned long long int C4;
        unsigned long long int C5;
        void setC1(unsigned long long int parC1);
        void setC2(unsigned long long int parC2);
        void setC3(unsigned long long int parC3);
        void setC4(unsigned long long int parC4);
        void setC5(unsigned long long int parC5);
}; // class LinearEquation
}  // namespace algebra