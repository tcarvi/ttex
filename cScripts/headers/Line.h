#include <iostream>

namespace linear_algebra {
class Line
{
    public:
        Line(unsigned long long int, unsigned long long int, unsigned long long int);
        Line(unsigned long long int, unsigned long long int);
        unsigned long long int getA();
        unsigned long long int getB();
        unsigned long long int getC();
    private:
        unsigned long long int A;
        unsigned long long int B;
        unsigned long long int C;
        void setA(unsigned long long int parA);
        void setB(unsigned long long int parB);
        void setC(unsigned long long int parC);
}; // class Line
}  // namespace algebra