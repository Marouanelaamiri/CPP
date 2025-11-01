/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:14:07 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/01 17:26:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
public :
	Harl();
	~Harl();

	void complain(std::string level);

private :
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};
#endif