#include "Serializer.hpp"

Serializer::Serializer()
{
	// std::cout << "Default constructor of Serializer is called" << std::endl;
}

Serializer::~Serializer()
{
	// std::cout << "Destructor of Serializer is called" << std::endl;
}

Serializer::Serializer(Serializer const &Serializer)
{
	// std::cout << "Copy constructor of Serializer is called" << std::endl;
	*this = Serializer;
}

Serializer &Serializer::operator=(Serializer const &Serializer)
{
	// std::cout << "Copy assignment operator of Serializer is called" << std::endl;
	if (this == &Serializer)
		return (*this);
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}