/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:24:18 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 12:38:21 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
    Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
    virtual ~Animal();
	
    virtual void makeSound() const;
    std::string getType() const;
};

#endif