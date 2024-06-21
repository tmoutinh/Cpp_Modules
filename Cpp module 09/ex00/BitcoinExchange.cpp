/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:18:10 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/21 15:37:48 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() 
{
}

/*------ Exercise especific functions ------*/

bool    BitcoinExchange::ExchangeRates()
{
    std::ifstream   file;
    std::string     line;
    std::string     date, rates;

    file.open("data.csv", std::ifstream::in);
    if (file.fail())
        return (false);
    std::getline(file, line);
    while (1)
    {
        std::getline(file, line);
        std::istringstream  stream(line);
        std::getline(stream, date, ',');
        std::getline(stream, rates, ',');
        stream.clear();
        this->_data_base[date] = std::atof(rates.c_str());
        if (file.eof())
            break;
    }
    file.close();
    return (true);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMaxDay(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

std::string BitcoinExchange::find_closest(std::string date)
{
	std::map<std::string, float>::iterator current;
	std::map<std::string, float>::iterator previous;

	if (date < _data_base.begin()->first)
		return (0);
	if (date > _data_base.rbegin()->first)
		return (_data_base.rbegin()->first);

	previous = _data_base.begin();
	current = _data_base.begin();
	current++;
	while (current != _data_base.end())
	{
		if (current->first > date)
			return (previous->first);
		previous = current;
		++current;
	}
	return (0);	
}

//HAVE TO VERIFY THE DATE TO SEE IF IF CAN FIND IT IN THE MAP
void    BitcoinExchange::input_verif(std::string date, double amount)
{
    std::istringstream  stream(date);
    std::string         sday, smonth, syear;
    std::string         _date;
    int                 day, month, year;

    /*----- Date verification -----*/
    std::getline(stream, syear, '-');
    std::getline(stream, smonth, '-');
    std::getline(stream, sday, '-');
    day = std::atoi(sday.c_str());
    year = std::atoi(syear.c_str());
    month = std::atoi(smonth.c_str());
    
    /*----- Amount verification -----*/       
    if (amount < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else if (amount > 1000)
        std::cout << "Error: too large number." << std::endl;
    else if ((year < 1900 || year > 2100) || (month < 1 || month > 12) || (day < 1 || day > getMaxDay(month, year)))
        std::cout << "Error: Bad date format ==> " << date << std::endl;    
    else
    {
        if (_data_base.find(date) == _data_base.end())
            _date = find_closest(date);
        else
            _date = date;
        std::cout << date << " ==> " << amount << " = " << amount * this->_data_base[_date] << std::endl;
    }
}

bool    BitcoinExchange::ExchangeCalculator(const char *filename)
{
    std::ifstream       file;
    std::string         line;
    std::string         date, amount;
    double            amount_int;

    file.open(filename, std::ifstream::in);
    if (file.fail())
        return (false);
    std::getline(file, line);
    while(1)
    {
        std::getline(file, line);
        std::istringstream stream(line);
        std::getline(stream, date, '|');
        std::getline(stream, amount, '|');
        amount_int = std::atof(amount.c_str());
        input_verif(date, amount_int);
        stream.clear();
        if (file.eof())
            break;
    }
    file.close();
    return (true);
}

void    BitcoinExchange::run(const char *filename) 
{
    if (!ExchangeRates())
        throw InvalidExchange();
    if (!ExchangeCalculator(filename))
        throw WrongFormat();
}
