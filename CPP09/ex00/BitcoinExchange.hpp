/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:30:34 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/01 16:26:24 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
		static std::string trim(const std::string& str);
		static bool isleapyear(int year);
		static bool isvalidDate(int year, int month, int day);
		static bool parsedate(const std::string& date, int& year, int& month, int& day);
		static float strtofloat(const std::string& str);
		float getexchangevalue(const std::string& date) const;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		void loaddatabase(const std::string& filename);
		void processinputfile(const std::string& filename) const;
};

#endif