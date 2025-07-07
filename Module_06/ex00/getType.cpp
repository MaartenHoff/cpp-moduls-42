#include "ScalarConverter.hpp"

bool	isChar( const std::string &literal );
bool	isInt( const std::string &literal );
bool	isFloat( const std::string &literal );
bool	isDouble( const std::string &literal );
bool	isPseudo( const std::string &literal );

ScalarConverter::ScalarType	ScalarConverter::getType(const std::string& literal) {
	if (literal.empty())
		return TYPE_INVALID;
	if (isChar(literal))
		return TYPE_CHAR;
	if (isInt(literal))
		return TYPE_INT;
	if (isFloat(literal))
		return TYPE_FLOAT;
	if (isDouble(literal))
		return TYPE_DOUBLE;
	if (isPseudo(literal))
		return TYPE_PSEUDO;
	return TYPE_INVALID;
}

bool	isChar( const std::string &literal ) {
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool	isInt( const std::string &literal ) {
	size_t i = 0;

	if (literal[i] == '-' || literal[i] == '+') i++;

	if (i == literal.length()) return false;

	for (; i < literal.length(); ++i) {
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool	isFloat(const std::string& literal) {
	if (literal.length() < 2 || literal.back() != 'f')
		return false;

	std::string core = literal.substr(0, literal.length() - 1);

	bool dot_found = false;
	bool digit_found = false;
	size_t i = 0;

	if (core[i] == '+' || core[i] == '-')
		i++;

	for (; i < core.length(); ++i) {
		if (core[i] == '.') {
			if (dot_found)
				return false;
			dot_found = true;
		}
		else if (std::isdigit(core[i])) {
			digit_found = true;
		}
		else {
			return false;
		}
	}

	return dot_found && digit_found;
}

bool	isDouble( const std::string &literal ) {
	bool dot_found = false;
	bool digit_found = false;
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	if (i == literal.length() || literal[i] == '.') return false;

	for (; i < literal.length(); ++i) {
		if (literal[i] == '.') {
			if (dot_found)
				return false;
			dot_found = true;
		}
		else if (std::isdigit(literal[i])) {
			digit_found = true;
		}
		else {
			return false;
		}
	}

	return dot_found;
}

bool isPseudo(const std::string& literal) {
	return (
		literal == "nan" || literal == "+inf" || literal == "-inf" ||
		literal == "nanf" || literal == "+inff" || literal == "-inff"
	);
}
