#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
    int fnumber;
    static const int frac = 8;
public:
    /*************-- Ex00 --***************/
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    int     getRawBits() const;
    void    setRawBits (int const raw);
    /*************-- Ex01 --***************/
    Fixed(int number);
    Fixed(float numberf);
    float   toFloat(void) const;
    int     toInt (void) const;
    /*************-- Ex02 --***************/
    bool    operator>(const Fixed& num);
    bool    operator<(const Fixed& num);
    bool    operator==(const Fixed& num);
    bool    operator>=(const Fixed& num);
    bool    operator<=(const Fixed& num);
    bool    operator!=(const Fixed& num);
    Fixed   operator+(const Fixed& num);
    Fixed   operator-(const Fixed& num);
    Fixed   operator*(const Fixed& num);
    Fixed   operator/(const Fixed& num);
    Fixed   operator++(void);
    Fixed   operator--(void);
    Fixed   operator++(int num);
    Fixed   operator--(int num);
    static Fixed&   max(Fixed& num1, Fixed& num2);
    static Fixed&   min(Fixed& num1, Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif