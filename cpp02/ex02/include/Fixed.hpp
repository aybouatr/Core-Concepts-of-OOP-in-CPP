/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:05:37 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/23 11:05:39 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		static Fixed& max(Fixed& First, Fixed& second);
		static const Fixed& max(const Fixed& First, const Fixed& second);

		static Fixed& min(Fixed& First, Fixed& second);
		static const Fixed& min(const Fixed& First, const Fixed& second);

		~Fixed();
		float toFloat(void)const;
		int toInt(void)const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

# endif
