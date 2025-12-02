/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:58:27 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/23 10:58:29 by aybouatr         ###   ########.fr       */
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
		~Fixed();
		float toFloat(void)const;
		int toInt(void)const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

# endif
