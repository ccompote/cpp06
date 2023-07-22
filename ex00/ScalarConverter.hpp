#pragma once

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