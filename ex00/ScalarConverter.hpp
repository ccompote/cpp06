#pragma once

#include <cstdlib>
#include <limits>
#include  <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter &operator=(ScalarConverter const &);
		virtual ~ScalarConverter();

		public:

			static void convert(char *str);
};