#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "Default constructor of ScalarConverter is called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Destructor of ScalarConverter is called" << std::endl;
}

// ScalarConverter::ScalarConverter(ScalarConverter const &ScalarConverter)
// {
// 	// std::cout << "Copy constructor of ScalarConverter is called" << std::endl;
// 	*this = ScalarConverter;
// }

// ScalarConverter &ScalarConverter::operator=(ScalarConverter const &ScalarConverter)
// {
// 	// std::cout << "Copy assignment operator of ScalarConverter is called" << std::endl;
// 	return (*this);
// }

int getType(char *str)
{
	if (!std::isdigit(str[0]) && std::strlen(str) == 1)
		return (1);
	char *endptr;
	double v = std::strtod(str, &endptr);
	if (*endptr == '\0')
	{
		if (v >= std::numeric_limits<int>::max() || v <= std::numeric_limits<int>::min())
		{
			if (v >= std::numeric_limits<float>::max() || v <= std::numeric_limits<float>::min())
			{
				return(3);
			}
			else
			{
				return(2);
			}
		}
		else
			return(0);
	}
	return (40);
}

void convertFromInt(char *str)
{
	std::cout << "char: " << static_cast<int>(*str) << std::endl;
	std::cout << "int: " << static_cast<int>(*str) << std::endl;
	std::cout << "float: " << static_cast<float>(*str) << std::endl;
	std::cout << "double: " << static_cast<double>(*str) << std::endl;
}

void convertFromChar(char c)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: '" << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertFromFloat(char *str)
{
	std::cout << "char: " << static_cast<int>(*str) << std::endl;
	std::cout << "int: " << static_cast<int>(*str) << std::endl;
	std::cout << "float: " << static_cast<float>(*str) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(*str) << std::endl;
}

void convertFromDouble(char *str)
{
	std::cout << "char: " << static_cast<int>(*str) << std::endl;
	std::cout << "int: " << static_cast<int>(*str) << std::endl;
	std::cout << "float: " << static_cast<float>(*str) << std::endl;
	std::cout << "double: " << static_cast<double>(*str) << std::endl;
}

//check if char is displayable
//for in check if is in int
void ScalarConverter::convert(char *str)
{
		switch (getType(str))
		{
		case 0:
			// std::cout << "INT" << std::endl;
			convertFromInt(str);
			break;
		case 1:
			// std::cout << "CHAR" << std::endl;
			convertFromChar(str[0]);
			break;
		case 2:
			// std::cout << "Float" << std::endl;
			convertFromFloat(str);
			break;
		case 3:
			// std::cout << "Double" << std::endl;
			convertFromDouble(str);
			break;
		
		default:
			std::cout << "SOSI hui wrong input" << std::endl;
			break;
		}
}