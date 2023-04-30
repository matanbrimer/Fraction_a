#include "Fraction.hpp"
#include <iostream>

#include <tuple>

using namespace  std;
using namespace  ariel;


Fraction::Fraction(int num1, int num2):number1(num1),number2(num2)
{
    if(num2 == 0){
        throw("ERROR: It is impossible to divide by zero");
    }
    Factorization();
}

Fraction ::Fraction (){
    this->number1 =0;
    this->number2 =1;
}

Fraction :: Fraction (float other){
       if(other > 0){
        int temp = (int)other;       
        float flo = other - temp;   
        string str = to_string(flo);

        int num1 = stoi(str.substr(str.find(".")+1,str.find(".")+2));
        temp *= 1000;
        num1 += temp;
        int num2 = 1000;
        this->number1 =num1;
        this->number2=num2;
        Factorization();
       }else{
        this->number1 = 0;
        this->number2 = 1;
       }
 
}

Fraction :: Fraction (const Fraction& copy):number1(copy.number1),number2(copy.number2){
    Factorization();
}

Fraction::~Fraction()
{
}


Fraction Fraction:: operator+(const Fraction& other)  {
    int num1,num2;
    if(number2 != other.number2){
        num1 =  (number1 * other.number2) + (other.number1 * number2);
        num2 = number2 * other.number2 ;

    }else{
        num1 =  number1  + other.number1 ;
        num2 = number2;
    }
    Fraction temp(num1,num2);
    temp.Factorization();
    return temp;
}
Fraction Fraction::operator+(const float& other) {
    int res1,res2;
    if(other > 0){
        int temp = (int)other;       
        float flo = other - temp;   
        string str = to_string(flo);

        int num1 = stoi(str.substr(str.find(".")+1,str.find(".")+2));
        temp *= 1000;
        num1 += temp;
        int num2 = 1000;
        if(number2 != num2){
            res1 =  (number1 * num2) + (num1 * number2);
            res2 = number2 * num2 ;
            
        }
        else{
            res1 =  number1  + num1 ;
             res2 = number2;
            
        }
        Fraction temp2(res1,res2);
        temp2.Factorization();
        return temp2;
    }    
    else{
        throw("ERROR!");
    }                    
 

}

Fraction Fraction:: operator-(const Fraction& other)  {
    int num1,num2;
    if(number2 != other.number2){
        num1 =  (number1 * other.number2) - (other.number1 * number2);
        num2 = number2 * other.number2 ;
    }else{
        num1 =  number1  - other.number1 ;
        num2 = number2;
    }

    Fraction temp(num1,num2);
    temp.Factorization();
    return temp;
}

Fraction Fraction::operator-(const float& other) {
    int res1,res2;
    if(other > 0){
        int temp = (int)other;       
        float flo = other - temp;   
        string str = to_string(flo);

        int num1 = stoi(str.substr(str.find(".")+1,str.find(".")+2));
        temp *= 1000;
        num1 += temp;
        int num2 = 1000;
        if(number2 != num2){
        res1 =  (number1 * num2) - (num1 * number2);
        res2 = number2 * num2 ;
                
        }
        else{
            res1 =  number1  + num1 ;
            res2 = number2;
            
        }
        Fraction temp2(res1,res2);
        temp2.Factorization();
        return temp2;
    }
    else{
        throw("ERROR!");
    }
        
}

Fraction Fraction:: operator*(const Fraction& other){

    int num1 = number1 * other.number1;
    int num2 = number2 * other.number2;
    Fraction temp(num1,num2);
    temp.Factorization();
    return temp;

}


Fraction ariel:: operator*(const float& other,const Fraction& fra){
    int res1,res2;
    
    int temp = (int)other;       
    float flo = (float)other - temp;   
    string str = to_string(flo);

    int num1 = stoi(str.substr(str.find(".")+1,str.find(".")+2));
    temp *= 1000;
    num1 += temp;
    int num2 = 1000;

    res1 = fra.number1 * num1;
    res2 = fra.number2 * num2;
    Fraction temp2(res1,res2);
    temp2.Factorization();
    return temp2;

  

}

Fraction Fraction:: operator/(const Fraction& other){
    int num1 = number1 * other.number2;
    int num2 = number2 * other.number1;
    Fraction temp(num1,num2);
    temp.Factorization();
    return temp;

}

Fraction Fraction:: operator/(const float& other){
    int res1,res2;
    if(other > 0){
        int temp = (int)other;       
        float flo = other - temp;   
        string str = to_string(flo);

        int num1 = stoi(str.substr(str.find(".")+1,str.find(".")+2));
        temp *= 1000;
        num1 += temp;
        int num2 = 1000;

        res1 = number1 * num2;
        res2 = number2 * num1;
        Fraction temp2(res1,res2);
        temp2.Factorization();
        return temp2;

    }
    else{
        throw("ERROR!");
    }
}


std::istream& ariel::operator>>(std::istream& input, Fraction& fra){
    input >> fra.number1 >> fra.number2;
    return input;
}


std::ostream &ariel::operator<<(std::ostream &output, const Fraction &fraction)
{
    output << fraction.number1 << "/" << fraction.number2 << endl;
    return output;
}

Fraction Fraction:: operator++()
{   
    number1 += number2;
    Factorization();
    return *this;

}

Fraction Fraction:: operator++(int num)
{
    Fraction temp(*this);
    number1 += number2;
    Factorization();
    return temp;

}

Fraction Fraction:: operator--() {
    number1 -= number2;
    Factorization();
    return *this;
}
Fraction Fraction:: operator--(int){
    Fraction temp(*this);
    number1 -= number2;
    Factorization();
    return temp;
}
    
bool Fraction:: operator==(const Fraction& other) {
    if(number1 == other.number1 && number2 == other.number2){
        return true;
    }
    return false;
}
bool Fraction:: operator==(const float& other) {
   
    int temp = (int)other;       
    float flo = other - temp;   
    string str = to_string(flo);

    int num1 = stoi(str.substr(str.find(".")+1,str.find(".")+2));
    temp *= 1000;
    num1 += temp;
    int num2 = 1000;

    if(number1 == num1 && number2 == num2){
        return true;
    }
    return false;


}

bool Fraction:: operator<(const Fraction& other) {
    
  float flo = (float)number1/number2;
  float flo2 = (float) other.number1/other.number2;
  if(flo < flo2)return true;

  return false;

}
bool Fraction:: operator<(const float& other){
    float flo = (float)number1/number2;
    if(flo < other)return true;

    return false;

}

bool Fraction:: operator<=(const Fraction& other) {
    float flo = (float)number1/number2;
    float flo2 = (float) other.number1/other.number2;
    if(flo <= flo2)return true;

    return false;
}
bool Fraction:: operator<=(const float& other){
    float flo = (float)number1/number2;
    if(flo <= other)return true;

    return false;

}

bool Fraction:: operator>(const Fraction& other) {
    float flo = (float)number1/number2;
    float flo2 = (float) other.number1/other.number2;
    if(flo > flo2)return true;

    return false;
}
bool Fraction:: operator>(const float& other) {
    float flo = (float)number1/number2;
    if(flo > other)return true;

    return false;
}

bool Fraction:: operator>=(const Fraction& other) {
 float flo = (float)number1/number2;
    float flo2 = (float) other.number1/other.number2;
    if(flo >= flo2)return true;

    return false;
}
bool Fraction:: operator>=(const float& other){
    float flo = (float)number1/number2;
    if(flo >= other)return true;

    return false;
}



int Fraction:: gcd(int num1, int num2){
    int result = 0;
    while(num2 != 0){
        result = num1 % num2;
        num1 = num2;
        num2 = result;
    }
    return num1;
}


void Fraction:: Factorization(){

    int divide = gcd(number1,number2);
    number1 = number1 / divide; 
    number2 = number2 / divide;

}

