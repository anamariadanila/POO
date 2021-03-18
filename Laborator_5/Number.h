#pragma once
class Number

{private:

    const char* value;
    int base;

    // add data members

public:

    Number(const char* value, int base); // where base is between 2 and 16

    Number(const Number& x);

    Number(const Number&& x);

    ~Number(); 



    // add operators and copy/move constructor

    Number operator+(Number number);
    Number operator+(int number);
    Number operator-(Number number);
    Number operator-(int number);

    //friend const Number operator+ (const Number& n1, const Number& n2);
    //friend const Number operator- (const Number& n1, const Number& n2);

    void operator++(); 
    void operator++(int numar); 
    void operator--(); 
    void operator--(int numar); 

    bool operator!();
    char operator[](int index);

    Number& operator=(Number&& ex);

    bool operator<(Number ex);
    bool operator>(Number ex);
    bool operator<=(Number ex);
    bool operator>=(Number ex);
    bool operator==(Number ex);
    bool operator<(int numar);
    bool operator>(int numar);
    bool operator<=(int numar);
    bool operator>=(int numar);
    bool operator==(int numar);


    void SwitchBase(int newBase);

    void Print();

    int  GetDigitsCount(); // returns the number of digits for the current number

    int  GetBase(); // returns the current base

};