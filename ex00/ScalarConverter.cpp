#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "Default constructor of ScalarConverter is called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Destructor of ScalarConverter is called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &ScalarConverter)
{
	// std::cout << "Copy constructor of ScalarConverter is called" << std::endl;
	*this = ScalarConverter;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &ScalarConverter)
{
	// std::cout << "Copy assignment operator of ScalarConverter is called" << std::endl;
	return (*this);
}

static void convert(char *str)
{
	char *endptr;
	double v = std::strtod(str, &endptr);
	if(endptr == NULL)
	{
		if (v >= std::numeric_limits<int>::max() || v <= std::numeric_limits<int>::min())
			// SOSI
		static_cast<int>v
		// SUCCESS;
	}
	else{
		// SOSI?
	}
	
	
	
	
	switch (getType(str))
	{
	case INT:
		convertFromInt(str);
		break;
	case CHAR:
		convertFromChar(str[0]);
		break;
	case FLOAT:
		convertFromFloat(str);
		break;
	case DOUBLE:
		convertFromDouble(str);
		break;
	
	default:
		std::cout << "SOSI hui wrong input" << std::endl;
		break;
	}
}