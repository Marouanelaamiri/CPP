/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:20 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/30 11:21:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
	private:
	std::string name;
	
	public:
	Zombie(std::string name);
	~Zombie();
	
	
	
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif 