#pragma once

#include <iostream>
#include <cstdint>

struct Data
{
	std::string name;
	int			id;

};

class Serializer
{
	private:

		Serializer();
		Serializer(Serializer const &);
		Serializer &operator=(Serializer const &);
		virtual ~Serializer();

		public:

			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);

};