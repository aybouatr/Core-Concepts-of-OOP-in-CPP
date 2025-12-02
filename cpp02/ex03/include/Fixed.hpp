# ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>



class Fixed
{
	private:
		int	_fp_value;
	 	static const int _fract_bits;

	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator>=(const Fixed& other);
		
		float operator+(const Fixed& other);
		

		float operator-(const Fixed& other);

		float operator*(const Fixed& other);

		float operator/(const Fixed& other);

		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed& max(Fixed& First,Fixed& second);
    	static const Fixed& max(const Fixed& a, const Fixed& b);
		~Fixed();
		float toFloat(void)const;
		int toInt(void)const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

# endif
