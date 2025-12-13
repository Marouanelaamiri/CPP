/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamiri <malaamiri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:26:42 by malaamiri         #+#    #+#             */
/*   Updated: 2025/12/13 18:30:49 by malaamiri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

// 1. T* array: Matches "Address of an array" rule.
// 2. const size_t length: Matches "const value" rule.
// 3. T_func: Matches "function" rule (handles pointers and functors).

template <typename T_type, typename T_func>
void iter(T_type *array, const size_t length, T_func func)
{
    // Safety check for NULL pointer
    if (array == NULL)
        return;

    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif