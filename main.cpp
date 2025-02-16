#include "Complex.h"

int main()
{
	Complex a(1.0, 1.0);
	Complex b(2.0, 2.0);
	Complex c;
	c = a+b;
	std::cout << c << '\n';
	c = a-b;
	std::cout << c << '\n';
	c = a*b;
	std::cout << c << '\n';
	c = a/b;
	std::cout << c << '\n';
	c.setreal(4);
	c.setimag(3);
	std::cout << c.getAbs() << " " << c.getArg() << '\n'; //"5 0.643501" - верно
	c.setAbs(5);
	c.setArg(0.643501);
	std::cout << c.getreal() << " " << c.getimag() << '\n'; //"4 3" - верно
	std::cout << c + 2 << " " << c - 2 << " " << c * 2 << " " << c / 2 << '\n';
	c += 2;
	std::cout << c << '\n';
	c -= 2;
	std::cout << c << '\n';
	c *= 2;
	std::cout << c << '\n';
	c /= 2;
	std::cout << c << '\n';
	std::cout << (a == b) << '\n';
	std::cout << (a != b) << '\n';
	return 0;
}
