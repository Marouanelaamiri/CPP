/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:06:34 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/30 11:15:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapzombie = newZombie("Zombie on heap");
	heapzombie->announce();
	randomChump("Zombie on stack");
	
	delete heapzombie;
	return 0;
}