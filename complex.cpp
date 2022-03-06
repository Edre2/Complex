#include "complex.h"

MyComplex::MyComplex(double im, double re) : m_re(re), m_im(im)
{

}

double MyComplex::re() const
{
    return m_re;
}

double MyComplex::im() const
{
    return m_im;
}

void MyComplex::show(std::ostream &flux) const
{
    flux << m_im << "i + " << m_re;
}

bool MyComplex::isEqual(MyComplex b) const
{
    return m_re == b.m_re && m_im == b.m_im;
}

void MyComplex::add(MyComplex b)
{
    this->m_re += b.m_re;
    this->m_im += b.m_im;
}

void MyComplex::substract(MyComplex b)
{
    this->m_re -= b.m_re;
    this->m_im -= b.m_im;
}

void MyComplex::multiply(MyComplex b)
{
    double temp_re = this->m_re;
    this->m_re = this->m_re * b.m_re - this->m_im * b.m_im;
    this->m_im = temp_re * b.m_im + this->m_im * b.m_re;
}

void MyComplex::divide(MyComplex b)
{
    if(b.m_im == 0 && b.m_re == 0)
        throw std::invalid_argument("Division by 0");
    MyComplex inv_b(- b.m_re / (b.m_re * b.m_re - b.m_im * b.m_im), b.m_im / (b.m_re * b.m_re - b.m_im * b.m_im));
    this->multiply(inv_b);
}


// Operators :

// Arithmétique :
MyComplex& MyComplex::operator+=(MyComplex b)
{
    this->add(b);
    return *this;
}
MyComplex& MyComplex::operator+=(int b)
{
    m_re += b;
    return *this;
}
MyComplex& MyComplex::operator-=(MyComplex b)
{
    this->substract(b);
    return *this;
}
MyComplex& MyComplex::operator*=(MyComplex b)
{
    this->multiply(b);
    return *this;
}
MyComplex& MyComplex::operator/=(MyComplex b)
{
    this->divide(b);
    return *this;
}

MyComplex operator+(MyComplex const& a, MyComplex const& b)
{
    MyComplex result(a);
    result += b;
    return result;
}
MyComplex operator+(MyComplex const& a, int const& b)
{
    MyComplex result(a);
    result += b;
    return result;
}
MyComplex operator-(MyComplex const& a, MyComplex const& b)
{
    MyComplex result(a);
    result -= b;
    return result;
}
MyComplex operator*(MyComplex const& a, MyComplex const& b)
{
    MyComplex result(a);
    result *= b;
    return result;
}
MyComplex operator/(MyComplex const& a, MyComplex const& b)
{
    MyComplex result(a);
    result /= b;
    return result;
}

// Comparaison :
bool operator==(MyComplex const& a, MyComplex const& b)
{
    return a.isEqual(b);
}
bool operator!=(MyComplex const& a, MyComplex const& b)
{
    return !a.isEqual(b);
}

// Flux: 
std::ostream& operator<<(std::ostream &flux, MyComplex const& a)
{
    a.show(flux);
    return flux;
}
