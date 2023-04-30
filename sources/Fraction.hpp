
#ifndef Fraction_H
#define Fraction_H
#include <iostream>


namespace  ariel{
    
    class Fraction
    {
    private:
        
    public:
    int number1, number2;
        Fraction(int,int);
        Fraction(float);
        Fraction(const Fraction& other);
        Fraction();
        ~Fraction();


 
    Fraction operator+(const Fraction& other) ;
    Fraction operator+(const float& other) ;

    Fraction operator-(const Fraction& other) ;
    Fraction operator-(const float& other) ;


    Fraction operator/(const Fraction &other);
    Fraction operator/(const float& other) ;

    bool operator==(const Fraction& other) ;
    bool operator==(const float& other) ;

    bool operator<(const Fraction& other) ;
    bool operator<(const float& other) ;

    bool operator<=(const Fraction& other) ;
    bool operator<=(const float& other) ;

    bool operator>(const Fraction& other) ;
    bool operator>(const float& other) ;

    bool operator>=(const Fraction& other) ;
    bool operator>=(const float& other) ;
    
    Fraction operator*(const Fraction& other);
    friend Fraction operator*(const float& other,const Fraction& fra) ;

    Fraction operator++() ;// for ++a
    Fraction operator++(int) ;// for a++

    Fraction operator--() ;// for --a
    Fraction operator--(int) ;// for a--
   
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);


    void Factorization();
    int gcd(int,int);
    };

}
#endif