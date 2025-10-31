/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:46:14 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 14:53:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <new>

class Zombie
{
private:
	std::string name;
	
public:

	Zombie();
	~Zombie();
	
	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif 