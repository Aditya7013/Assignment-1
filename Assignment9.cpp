#include <iostream>

using namespace std; 

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    
    friend ComplexNumber operator+(const ComplexNumber& num1, const ComplexNumber& num2);

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};


ComplexNumber operator+(const ComplexNumber& num1, const ComplexNumber& num2) {
    return ComplexNumber(num1.real + num2.real, num1.imag + num2.imag);
}

int main() {
    ComplexNumber c1(2, 3);
    ComplexNumber c2(4, 5);

    ComplexNumber c3 = c1 + c2;  

    cout << "Result: ";
    c3.display();

    return 0;
}
