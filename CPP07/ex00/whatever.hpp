/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamiri <malaamiri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:18:44 by malaamiri         #+#    #+#             */
/*   Updated: 2025/12/13 18:24:42 by malaamiri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>

// 1. Swap
// Must use references (&) to modify the original variables.
template <typename dataType>
void swap(dataType &a, dataType &b)
{
    dataType temp = a;
    a = b;
    b = temp;
}

// 2. Min
// Returns the smaller value.
// Note: If (a == b), logic dictates returning b (the second one).
// (a < b) is false if they are equal, so it returns b. Correct.
template <typename dataType>
dataType& min(dataType &a, dataType &b)
{
    if (a < b)
        return a;
    return b;
}
// 3. Max
// Returns the larger value.
// Note: If (a == b), logic dictates returning b.
// (a > b) is false if equal, so it returns b. Correct.
template <typename dataType>
dataType& max(dataType &a, dataType &b)
{
    if (a > b)
        return a;
    return b;
}

#endif