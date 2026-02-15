/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:06 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/25 11:55:08 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    
    Point();

    
    Point(const float x, const float y);

    
    Point(const Point &other);

    
    Point &operator=(const Point &other);

    ~Point();

    Fixed getX(void) const;
    Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
