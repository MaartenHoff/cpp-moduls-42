#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_exchangeData;

		double	getExchangeRate( const std::string &date ) const;

		void	checkDate( const std::string &date ) const;
		void	checkValue( double value ) const;

	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &other );
		BitcoinExchange	&operator = ( const BitcoinExchange &other );
		~BitcoinExchange();

		void	parseData( const std::string &dataFile );
		void	processInput( const std::string &inputFile ) const;
};