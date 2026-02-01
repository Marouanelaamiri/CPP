/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:30:37 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/01 19:33:24 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// static helpers , pure logic

// trim

std::string BitcoinExchange::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

// wach sana kabissa

bool BitcoinExchange::isleapyear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// is valid date

bool BitcoinExchange::isvalidDate(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;
	int dayseachmonth[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isleapyear(year))
		dayseachmonth[2] = 29;
	return day <= dayseachmonth[month];
}

// parse date string
bool BitcoinExchange::parsedate(const std::string &date, int &year, int &month, int &day)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::string yearstr = date.substr(0, 4);
	std::string monthstr = date.substr(5, 2);
	std::string daystr = date.substr(8, 2);

	// we validate the substr are acctully digits before we call atoi

	year = std::atoi(yearstr.c_str());
	month = std::atoi(monthstr.c_str());
	day = std::atoi(daystr.c_str());

	return isvalidDate(year, month, day);
}

// string to float

float BitcoinExchange::strtofloat(const std::string &str)
{
	return static_cast<float>(std::atof(str.c_str()));
}

// class implemntation

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database) {};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		database = other.database;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {};

// internal logic : find exchange rate
float BitcoinExchange::getexchangevalue(const std::string &date) const
{
}

void loaddatabase(const std::string &filename)
{
	
}
void processinputfile(const std::string &filename) const
{
	
}