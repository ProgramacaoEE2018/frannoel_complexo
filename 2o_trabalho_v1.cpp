#include <iostream>
#include <cmath>

using namespace std;

class Complexo {
private:
    float real, imag;
public:
    Complexo(float _real = 0.0, float _imag = 0.0) : real(_real), imag(_imag) {}
    ~Complexo() {}

    float getReal() { return real; }
    float getImag() { return imag; }
    void setReal(float _real) { this->real = _real; }
    void setImag(float _imag) { this->imag = _imag; }

    float modulo();
    Complexo soma(Complexo);
    Complexo dif(Complexo);
    Complexo mult(Complexo);
    Complexo div(Complexo);
    Complexo conj(Complexo);

    Complexo& operator+(const Complexo& c) {
        this->real += c.real;
        this->imag += c.imag;
        return *this;
    }

};

float Complexo::modulo() {
    return sqrt(real*real + imag*imag);
}

Complexo Complexo::soma(Complexo c) {
    this->real += c.real;
    this->imag += c.imag;
    return *this;
}

Complexo Complexo:: conj(Complexo c) {
    this->real = real;
    this->imag = -imag;
    return *this;
}

Complexo Complexo::dif(Complexo c) {
    this->real -= c.real;
    this->imag -= c.imag;
    return *this;
}

Complexo Complexo::mult(Complexo c) {
    this->real = this->real*c.real - this->imag*c.imag;
    this->imag = this->real*c.imag + this->imag*c.real;
    return *this;
}

Complexo Complexo::div(Complexo c) {
    this->real = (this->real*c.real + this->imag*c.imag)/(c.real*c.real + c.imag*c.imag);
    this->real = (this->imag*c.real - this->real*c.imag)/(c.real*c.real + c.imag*c.imag);
    return *this;
}

int main() {

    cout << "Digite o numero complexo: " << endl;

    float real, imag;

    cin >> real >> imag;

    Complexo c1(real, imag);

    cout << c1.getReal() << " " << c1.getImag() << endl;

    cout << c1.modulo() << endl;




    cout<< c1.div()<< endl;

    return 0;
}
