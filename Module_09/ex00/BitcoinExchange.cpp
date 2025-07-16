#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) 
	: _exchangeData(other._exchangeData) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_exchangeData = other._exchangeData;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::parseData( const std::string &dataFile ) {
	std::ifstream	readFile(dataFile.c_str());
	if (!readFile.is_open())
		throw std::runtime_error("Error: could not open data file.");
	
	std::string	line;
	std::getline(readFile, line);

	while (std::getline(readFile, line)) {
		size_t		delimiter = line.find(",");
		if (delimiter == std::string::npos)
			throw std::invalid_argument("Error: bad format in data file.");
		
		std::string	date = line.substr( 0, delimiter );
		double		rate = strtod(line.substr(delimiter + 1).c_str(), NULL);
		
		_exchangeData[date] = rate;
	}
}

void	BitcoinExchange::processInput( const std::string &inputFile ) const {
	std::ifstream	readFile(inputFile.c_str());
	if (!readFile.is_open())
		throw std::runtime_error("Error: could not open input file.");
	
	std::string	line;
	std::getline(readFile, line);

	while (std::getline(readFile, line)) {
		size_t		delimiter = line.find(" | ");
		if (delimiter == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr( 0, delimiter );
		double value;
		try {
			value = strtod(line.substr(delimiter + 3).c_str(), NULL);
		} catch (...) {
			std::cout << "Error: invalid number => " << line.substr(delimiter + 3) << std::endl;
			continue;
		}

		try {
			checkDate( date );
			checkValue( value );
			double rate = getExchangeRate( date );
			std::cout << date << " => " << value << " = " << rate * value << std::endl;
		}
		catch ( const std::exception &e) {
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}

double	BitcoinExchange::getExchangeRate( const std::string &date ) const {
	std::map<std::string, double>::const_iterator	it = _exchangeData.find(date);
	if (it != _exchangeData.end())
		return it->second;
	it = _exchangeData.lower_bound(date);
	if (it == _exchangeData.begin())
		throw std::runtime_error("Error: no exchange rate available before this date.");

	--it;
	return it->second;
}

void BitcoinExchange::checkDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Error: bad input => " + date);

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (!std::isdigit(yearStr[0]) || !std::isdigit(monthStr[0]) || !std::isdigit(dayStr[0]))
		throw std::invalid_argument("Error: bad input => " + date);

	int month = atoi(monthStr.c_str());
	int day = atoi(dayStr.c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw std::invalid_argument("Error: bad input => " + date);
}

void	BitcoinExchange::checkValue( double value ) const {
	if (value < 0)
		throw std::out_of_range("Error: not a positive number.");
	if (value > 1000)
		throw std::out_of_range("Error: too large a number.");
}