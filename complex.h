#ifndef MyComplex_H
#define MyComplex_H

#include <ostream>
#include <stdexcept>

class MyComplex
{
    public:
        MyComplex(double im, double re);

        double re() const;
        double im() const;

        void show(std::ostream &flux) const;

        bool isEqual(MyComplex b) const;

        void add(MyComplex b);
        void substract(MyComplex b);
        void multiply(MyComplex b);
        void divide(MyComplex b);

        MyComplex& operator+=(MyComplex b);
        MyComplex& operator+=(int b);
        MyComplex& operator-=(MyComplex b);
        MyComplex& operator*=(MyComplex b);
        MyComplex& operator/=(MyComplex b);


    private:
        double m_re; // Partie réelle
        double m_im; // Partie imaginaire
};

// Comparaison
bool operator==(MyComplex const& a, MyComplex const& b);
bool operator!=(MyComplex const& a, MyComplex const& b);

// Arithmétique
MyComplex operator+(MyComplex const& a, MyComplex const& b);
MyComplex operator+(MyComplex const& a, int const& b);
MyComplex operator-(MyComplex const& a, MyComplex const& b);
MyComplex operator*(MyComplex const& a, MyComplex const& b);
MyComplex operator-(MyComplex const& a, MyComplex const& b);

// Flux
std::ostream& operator<<(std::ostream &flux, MyComplex const& a);

#endif