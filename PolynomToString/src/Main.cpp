#include <iostream>
#include <string>
#include <sstream>

template <typename ... Args>
std::string GetPolynomString(Args ... args)
{
	std::size_t s = sizeof ... (Args);
	int exp = s - 1;

	std::stringstream ss;
	ss << "f(x) = ";
	auto LogExponent = [&](const auto &singleArg)
	{
		if(exp != s - 1)
			ss << (singleArg < 0 ? " - " : " + ");
		ss << std::to_string(std::abs(singleArg)) << (exp != 0 ? ("*x^" + std::to_string(exp)) : ""); 
		exp--; 
	};
	(..., LogExponent(std::forward<Args>(args)));

	return ss.str();
}


int main()
{
	std::cout << GetPolynomString(4, 2, -1, 4, 5, -6, 6) << std::endl;
	std::cout << GetPolynomString(11, -4, 3, 7, 14, -9) << std::endl;
	std::cout << GetPolynomString(0, 1, -3, 4) << std::endl;

	return 0;
}