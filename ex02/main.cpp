#include "Base.hpp"

int main(void)
{

	srand(static_cast<unsigned>(time(0))); 
    Base* instance = generate();
    identify(instance);
    identify(*instance);

    delete instance;

	Base* instance2 = generate();
    identify(instance2);
    identify(*instance2);

    delete instance2;
    return 0;
}