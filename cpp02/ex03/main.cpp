/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:45:21 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/25 11:45:23 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"
#include <iostream>

int main()
{
    Point a(4, 2);
    Point b(1,1);
    Point c(1,4);

    Point inside(2, 2);
    Point outside(1,3);
   

    std::cout << "Inside: " << bsp(a, b, c, inside) << "\n";
    std::cout << "Outside: " << bsp(a, b, c, outside) << "\n";
}
