#include "ScalarConverter.hpp"

void	ScalarConverter::convert( const std::string& literal ) {
	ScalarType	type = getType( literal );
	switch (type)
	{
		case TYPE_CHAR:
			printFromChar(literal[0]);
			break;

		case TYPE_INT:
			printFromInt(std::atoi(literal.c_str()));
			break;

		case TYPE_FLOAT:
			printFromFloat(std::strtof(literal.c_str(), NULL));
			break;

		case TYPE_DOUBLE:
			printFromDouble(std::strtod(literal.c_str(), NULL));
			break;

		case TYPE_PSEUDO:
			printFromPseudo(literal);
			break;
		
		default:
				std::cerr << "Invalid." << std::endl;
	}
	return ;
}

void	printFromChar(char C) {
	int		I = static_cast<int>(C);
	float	F = static_cast<float>(C);
	double	D = static_cast<double>(C);

	std::cout << "Char: '" << C << "'" << std::endl;
	std::cout << "Int: " << I << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << F << "f" << std::endl;
	std::cout << "Double: " << D << std::endl;
}

void	printFromInt(int I) {
	char	C = static_cast<char>(I);
	float	F = static_cast<float>(I);
	double	D = static_cast<double>(I);

	std::cout << "Char: '" << C << "'" << std::endl;
	std::cout << "Int: " << I << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << F << "f" << std::endl;
	std::cout << "Double: " << D << std::endl;
}

void	printFromFloat(float F) {
	char	C = static_cast<char>(F);
	int		I = static_cast<int>(F);
	double	D = static_cast<double>(F);

	std::cout << "Char: '" << C << "'" << std::endl;
	std::cout << "Int: " << I << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << F << "f" << std::endl;
	std::cout << "Double: " << D << std::endl;
}

void	printFromDouble(double D) {
	char	C = static_cast<char>(D);
	int		I = static_cast<int>(D);
	float	F = static_cast<float>(D);

	std::cout << "Char: '" << C << "'" << std::endl;
	std::cout << "Int: " << I << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << F << "f" << std::endl;
	std::cout << "Double: " << D << std::endl;
}

void printFromPseudo(const std::string& literal) {
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	if (literal.back() == 'f') {
        std::cout << "Float: " << literal << std::endl;
        std::cout << "Double: " << literal.substr(0, literal.size() - 1) << std::endl;
    }
	else {
        std::cout << "Float: " << literal << "f" << std::endl;
        std::cout << "Double: " << literal << std::endl;
    }
}
