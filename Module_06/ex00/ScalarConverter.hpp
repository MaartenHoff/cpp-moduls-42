#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		enum ScalarType {
			TYPE_CHAR,
			TYPE_INT,
			TYPE_FLOAT,
			TYPE_DOUBLE,
			TYPE_PSEUDO,
			TYPE_INVALID = -1
		};

		static ScalarType	getType( const std::string& literal );

		static void printFromChar(char C);
		static void printFromInt(int I);
		static void printFromFloat(float F);
		static void printFromDouble(double D);
		static void printFromPseudo(const std::string& literal);
};