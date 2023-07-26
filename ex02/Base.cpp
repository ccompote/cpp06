#include "Base.hpp"

Base* createA() 
{
	return new A; 
}

Base* createB() 
{
	return new B; 
}
Base* createC()
{
	return new C; 
}

enum ClassType
{
	TYPE_A,
	TYPE_B,
	TYPE_C,
	NUM_TYPES
};

Base * generate(void)
{
	
	int randomValue = rand() % NUM_TYPES;

	switch (randomValue)
	{
		case TYPE_A:
			return new A();
		case TYPE_B:
			return new B();
		case TYPE_C:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
	try 
	{
        A &a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try 
		{
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
			{
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch(std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}