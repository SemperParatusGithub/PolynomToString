#include <iostream>
#include <string>
#include <sstream>

template <typename ... Args>
std::string GetPolynomString(Args ... args)
{
	size_t s = sizeof ... (Args);
	int exp = s - 1;

	std::stringstream ss;
	ss << "f(x) = ";
	auto LogMessage = [&](const auto &singleArg)
	{
		if(exp != s -1)
			ss << (singleArg < 0 ? " - " : " + ");
		ss << std::to_string(std::abs(singleArg)) << "*x^" << exp; 
		exp--; 
	};
	(..., LogMessage(std::forward<Args>(args)));

	return ss.str();
}


int main()
{
	std::cout << GetPolynomString(4, 2, -1, 4, 5, -6, 6) << std::endl;

	return 0;
}