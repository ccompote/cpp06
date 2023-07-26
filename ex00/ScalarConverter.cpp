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
	if (this == &ScalarConverter)
		return (*this);
	return (*this);
}

int ScalarConverter::getType(char *str)
{
	if (!std::isdigit(str[0]) && std::strlen(str) == 1)
		return (1);
	if (isinf(std::strtod(str, NULL)))
		return(2);
	std::string s = str;
	int len = std::strlen(str);
	if (str[len - 1] == 'F' || str[len - 1] == 'f')
		str[len - 1] = '\0';
	char *endptr;
	double v = std::strtod(str, &endptr);
	if (*endptr == '\0')
	{
		std::size_t founddot = s.find('.');
		std::size_t foundf = s.find('f');
		if (v >= std::numeric_limits<int>::max() || v <= std::numeric_limits<int>::min() || founddot != std::string::npos)
		{
			if ((v <= -std::numeric_limits<float>::max() || v >= std::numeric_limits<float>::max()) && !isinf(v))
				return(3);
			else
			{
				if (foundf != std::string::npos)
					return(2);
				return(3);
			}
		}
		else
		{	
			if(isnan(v))
				return(3);
			if (foundf != std::string::npos)
				return(2);
			else
				return (0);
		}
	}
	return (40);
}

void ScalarConverter::convertFromInt(char *str)
{
	int i = std::atoi(str);
	if (i < 33 || i > 176)
	{
		if (i < 0 || i > 177)
			std::cout << "char: Impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFromChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char : Non displayable" << std::setprecision(1);

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromFloat(char *str)
{
	float f = std::strtof(str, NULL);
	if (f < 33 || f > 176 || isnan(f) || isinf(f))
	{
		if (f < 0 || f > 177 || isnan(f) || isinf(f))
			std::cout << "char: Impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	if (f >= std::numeric_limits<int>::max() || f <= std::numeric_limits<int>::min() || isnan(f) || isinf(f))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(char *str)
{
	double d = std::strtod(str, NULL);
	if (d < 33 || d > 176 || isnan(d) || isinf(d))
	{
		if (d < 0 || d > 177 || isnan(d) || isinf(d))
			std::cout << "char: Impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	if (d >= std::numeric_limits<int>::max() || d <= std::numeric_limits<int>::min() || isnan(d) || isinf(d))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	if (d >= std::numeric_limits<float>::max() || d <= -std::numeric_limits<float>::max())
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" <<std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(char *str)
{
		switch (getType(str))
		{
		case 0:
			convertFromInt(str);
			break;
		case 1:
			convertFromChar(str[0]);
			break;
		case 2:
			convertFromFloat(str);
			break;
		case 3:
			convertFromDouble(str);
			break;
		
		default:
			std::cout << "Wrong input" << std::endl;
			break;
		}
}