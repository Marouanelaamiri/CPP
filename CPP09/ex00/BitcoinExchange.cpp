/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:30:37 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/02 15:16:41 by malaamir         ###   ########.fr       */
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
	return str.substr(first, (last - first + 1)); // why +1
}

// wach sana kabissa

bool BitcoinExchange::isleapyear(int year)
{
    if (year % 4 != 0) return false; // every 4 years is a leap year
    if (year % 100 != 0) return true; // unless its 100 years
    if (year % 400 == 0) return true; // if its 400 years then its leapyear again
    return false;
}
// is valid date

bool BitcoinExchange::isvalidDate(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;
	int dayseachmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isleapyear(year))
		dayseachmonth[2] = 29;
	return day <= dayseachmonth[month]; // what does this return means
}

// parse date string
bool BitcoinExchange::parsedate(const std::string &date, int &year, int &month, int &day)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	//extracting data
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
    // lower_bound returns the first element that is Greater-Than or Equal-To (>=) the date.
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);

    // CASE 1: Exact Match
    // If we are not at the end, and the key is exactly the date we wanted.
    if (it != database.end() && it->first == date)
		return it->second;
    
    // CASE 2: No Exact Match (it points to a later date)
    // We need to look at the previous date.
    
    // Safety Check: If it == begin(), it means ALL dates in the DB are bigger than our input.
    // There is no "previous" date to fall back on. Error.
    if (it == database.begin())
    	return -1.0f;
    
    // Fallback: Decrement to find the closest date that is strictly LOWER.
    --it;
    return it->second;
}

//load database
//std::ifstream file(filename.c_str()): Opens file for reading. 
//c_str() is needed because fstream constructors in C++98 take const 
//char*, not std::string.

void BitcoinExchange::loaddatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
		throw std::runtime_error("Error: could not open the file !");
	
	std::string line;
	std::getline(file, line); // skip the first line "date, exchabge rate"
	
	while(std::getline(file, line))
	{
		if(line.empty())
			continue;
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		
		std::string date = trim(line.substr(0, commaPos));
		std::string rate = trim(line.substr(commaPos + 1));
		
		database[date] = strtofloat(rate); //whats happening here exactly ?
	}
	file.close();
}

// proccess input
void BitcoinExchange::processinputfile(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: can't open the file !" << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line); // same as before we skip first line
	
	// If the file is just one line (header) or empty, we handle it gracefully.
    // Ideally check if first line matches "date | value" but subject doesn't enforce strict header check.

	while(std::getline(file, line))
	{
		if(line.empty())
			continue;
		size_t pipePos = line.find('|');
		if(pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, pipePos));
		std::string value = trim(line.substr(pipePos + 1));

		// we validate date
		int y, m, d;
		if(!parsedate(date, y, m, d))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		// validate value
		float validvalue = strtofloat(value);
		if (validvalue < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		 if (validvalue > 1000.0f)
		 {
			std::cerr << "Error: too large" << std::endl;
			continue;
		}
		//find rate
		float rate = getexchangevalue(date);
		if(rate < 0.0f)
		{
			std::cerr << "Error: no data availabe at this date." << std::endl;
			continue;
		}
		std::cout << date << " => " << validvalue << " = " << (validvalue * rate) << std::endl;
	}
	file.close();
}