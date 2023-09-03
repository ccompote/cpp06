#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->name = "Bob";
	if (data == Serializer::deserialize(Serializer::serialize(data)))
		std::cout << "Serialized successfully" << std::endl;
	std::cout << data->name << std::endl;
	delete data;
	return (0);
}