#include <iostream>

namespace linear_algebra {
class Plane
{
    public:
        Plane(unsigned long long int, unsigned long long int, unsigned long long int, unsigned long long int);
        Plane(unsigned long long int, unsigned long long int, unsigned long long int);
        unsigned long long int getA();
        unsigned long long int getB();
        unsigned long long int getC();
        unsigned long long int getD();
    private:
        unsigned long long int A;
        unsigned long long int B;
        unsigned long long int C;
        unsigned long long int D;
        void setA(unsigned long long int parA);
        void setB(unsigned long long int parB);
        void setC(unsigned long long int parC);
        void setD(unsigned long long int parD);
}; // class Plane
}  // namespace algebra