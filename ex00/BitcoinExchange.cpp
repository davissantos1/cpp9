/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:32:10 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/05 12:49:33 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool isValidDate(std::string value)
{
	bool		status = true;
	int			year, month, day;	
	std::string yearString, monthString, dayString;
	std::stringstream ss(value);

	std::getline(ss, yearString, '-');
	std::getline(ss, monthString, '-');
	std::getline(ss, dayString, '-');

	year = std::atoi(yearString.c_str());
	month = std::atoi(monthString.c_str());
	day = std::atoi(dayString.c_str());

	if (year < 2009 || month <= 0 || month > 12 || day <= 0 || day > 31)
		status = false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1]) 
		status = false;

	if (!status)
	{
		std::cout	<< "Error: bad input => "
					<< value
					<< std::endl;
	}
	return (status);
}

static bool	isValidFloat(float value)
{
	if (value < 0)
	{
		std::cout	<< "Error: not a positive number"
					<< std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cout	<< "Error: too large a number"
					<< std::endl;
		return (false);
	}
	return (true);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() 
{
	std::string		tmp_db;
	std::ifstream	file_db(PATH_DB);

	if (!file_db.is_open())
		throw (NoDatabaseException());

	std::getline(file_db, tmp_db);
	while (std::getline(file_db, tmp_db))
	{
		std::size_t pos = tmp_db.find(",");
		if (pos != std::string::npos && tmp_db.size() > pos + 1)
		{
			std::string	key = tmp_db.substr(0, 10);
			std::string	value = tmp_db.substr(pos + 1);
			float value_f = std::atof(value.c_str());
			this->_db[key] = value_f;
		}
	}
	file_db.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
{
	if (this != &other)
		*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if (this != &other)
		this->_db = other._db;
	return (*this);
}

void				BitcoinExchange::showRates(std::string file)
{
	std::string		inputLine;
	std::ifstream	input(file.c_str());

	std::getline(input, inputLine);
	while (std::getline(input, inputLine))
	{
		std::size_t pos = inputLine.find('|');
		std::string key = inputLine.substr(0, 10);
		float value = std::atof((inputLine.substr(pos + 1)).c_str());

		std::map<std::string, float>::iterator it_db = this->_db.lower_bound(key);

		if (!isValidDate(key) || !isValidFloat(value))
			continue ;
		
		if (it_db != this->_db.begin() && (it_db == this->_db.end() || it_db->first != key))
			it_db--;
			
		std::cout	<< key
					<< " => " 
					<< value
					<< " = " 
					<<  (value * it_db->second)
					<<  std::endl;
	}
	input.close();
}

const char *	BitcoinExchange::InvalidFileException::what() const throw()
{
	return ("Error: could not open file.");
}

const char *	BitcoinExchange::NoDatabaseException::what() const throw()
{
	return ("Error: could not find database file in PATH_DB.");
}
