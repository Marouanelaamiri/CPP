/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:46:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 14:52:31 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie* horde = zombieHorde(N, "HordeZombie");
	
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	
	delete [] horde;
	horde = NULL;
	return 0;
}