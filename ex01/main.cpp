#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	if (data == Serializer::deserialize(Serializer::serialize(data)))
		std::cout << "Serialized successfully" << std::endl;
	delete data;
	return (0);
}