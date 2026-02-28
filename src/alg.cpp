// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	int count = 0;
	for (uint64_t i = value; i > 0; i--)
	{
		if (value % i == 0)
			count += 1;

	}
	if (count == 2)
		return true;
	else
		return false;
}

uint64_t nPrime(uint64_t n) {
	int count = 0;
	uint64_t primeNum = 0;
	for (uint64_t i = 1; count != n; i++)
	{
		if (checkPrime(i))
		{
			count++;
			primeNum = i;
		}
	}
	return primeNum;
}

uint64_t nextPrime(uint64_t value) {
	uint64_t primeNum = value+1;
	while (!checkPrime(primeNum))
	{
		primeNum++;
	}
	return primeNum;
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t result = 0;
	for (int i = 1; i != hbound; i++)
	{
		if (checkPrime(i))
		{
			result += i;
		}
	}
	return result;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	int result = 0;
	int count = 0;
	uint64_t mem = 0;
	for (uint64_t i = lbound+1; i < hbound; i++)
	{
		bool prime = checkPrime(i), prime1 = checkPrime(i - 2), prime2 = checkPrime(i + 2);
		if (prime)
		{
			if (prime1 or prime2)
			{
				result += 1;
			}
			if (prime1 and prime2)
			{
				result -= 1;
			}	
		}
	}
	return result;
}
