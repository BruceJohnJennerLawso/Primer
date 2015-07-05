// prime.cpp ///////////////////////////////////////////////////////////////////
// a program to calculate prime factors ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"
//#include "Headers.hpp"
//#include "Source.cpp"
#include <iostream>
#include <string>
#include <vector>

// currently works just fine, no bugs that I have noticed just yet
// ran quite slow on 2147483647, but that would seem to be normal enough,
// given that most other values converge back quite quickly once one or more
// primes are found and the number we are working with becomes much smaller
// its a long loop, no way around that

// might be interesting to try this in FORTRAN and compare results

typedef long long int integer;
typedef long double number;


void print(std::string output);
void print(std::string text, integer value);
void print(std::string text, number value);

void Find_primes(long double value);
bool Is_integer(number value);
bool Is_prime(number value);
integer Find_prime_of(long double value);


int main(int argc, char* argv[])
{	
	if(argc == 2)
	{	std::string input = argv[1];
		
		number value = std::stold(input);
		// this needs a try catch block to handle inputs that are not numbers
		if(Is_integer(value))
		{	if(value > 1)
			{
				//std::cout << "Is prime " << Is_prime(number);
				Find_primes(value);
			}	// otherwise we dont care
			// you dont need a program to find prime factors of 1 :p
		}
		else
		{	print("Input is not an integer number, please try an integer");
			return -3;
		}
	}
	else
	{	print("Not enough arguments");
		print("Please try primer <number>");
		return -2;
	}
}

void print(std::string output)
{	
	std::cout << output << std::endl;
}

void print(std::string text, integer value)
{	
	std::cout << output << value << std::endl;
}


void print(std::string text, number value)
{
	std::cout << output << value << std::endl;
}



void Find_primes(long double value)
{	std::cout << (int)value << " = "; 
	if(Is_prime(value) == true)
	{	std::cout << "(" << (int)value << ") " << "(" << (int)value << " is a prime)" << std::endl;
	}
	else
	{	long double prime = Find_prime_of(value);
		std::cout << "(" << (int)prime << ")";
		value /= prime;
		while(true)
		{	if(!Is_prime(value))
			{	prime = Find_prime_of(value);
				std::cout << " * (" << (int)prime << ")";
				value /= prime;
			}
			else
			{	std::cout << " * (" << (int)value << ")" << std::endl;
				// value becomes our last prime, and we move on
				break;
			}
		}		
	}
}

integer Find_prime_of(long double value)
{	if(Is_prime(value) == true)
	{	return (int)value;
	}
	else
	{	for(int cy = 2; cy != value; ++cy)
		{	long double factor = cy;
			long double compare = value/factor;
			if(Is_integer(compare))
			{	// hurrr
				if(Is_prime(compare))
				{	return (int)compare;
					// we look at the remainder
				}	
			}
		}
	}
}



bool Is_integer(number value)
{	number comparison = (integer)value;
	if(value == comparison)
	{	return true;
	}
	else
	{	return false;
	}
	// take a long double and see if its value is equivalent to what it would
	// be if we did a nasty cast to int.
}

bool Is_prime(number value)
{	if(Is_integer(value))
	{	for(integer cy = 2; cy != (integer)value; ++cy)
		{	// we start at two, since one will obviously work on everything
			number factor = cy;
			number compare = value/factor;
			// we divide our original value by the current cy, and check if the
			// result is an integer
			if(Is_integer(compare))
			{	return false;
				// if it is, it isnt a prime
			}
			// otherwise we continue on to the next value to see if that one
			// is a prime
		}
		return true;
		// if we checked every int value up to the value itself, and we couldnt
		// divide by it to get a integer, its a prime, so true
	}
	else
	{	return false;
	}	// cant really be a prime if its not an integer number. At least I dont
		// think it can
}
