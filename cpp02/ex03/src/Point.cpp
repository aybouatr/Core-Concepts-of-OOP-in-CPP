/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:41 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/25 11:55:43 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Point.hpp"


Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point &Point::operator=(const Point &other)
{
    (void)other; 
    std::cerr << "Warning: Point is immutable; assignment has no effect.\n";
    return *this;
}


Point::~Point()
{
}

Fixed Point::getX(void) const
{
    return _x;
}

Fixed Point::getY(void) const
{
    return _y;
}

std::ostream	&operator<<(std::ostream &o, Point const point)
{
	o << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (o);
}

