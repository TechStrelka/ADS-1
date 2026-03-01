// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
uint64_t count = 0;
  for (uint64_t i = value; i > 0; i--) {
    if (value % i == 0) {
      count += 1;
    }
  }
  if (count == 2) {
    return true;
  } else {
    return false;
  }
}

uint64_t nPrime(uint64_t n) {
uint64_t count = 0;
  uint64_t primeNum = 0;
  for (uint64_t i = 1; count != n; i++) {
    if (checkPrime(i)) {
      count++;
      primeNum = i;
    }
  }
  return primeNum;
}

uint64_t nextPrime(uint64_t value) {
uint64_t primeNum = value + 1;
  while (!checkPrime(primeNum)) {
    primeNum++;
  }
  return primeNum;
}

uint64_t sumPrime(uint64_t hbound) {
uint64_t result = 0;
  for (uint64_t i = 1; i < hbound; i++) {
    if (checkPrime(i)) {
      result += i;
    }
  }
  return result;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound < 5 || lbound >= hbound) return 0;
    uint64_t count = 0;
    for (uint64_t i = lbound; i + 2 < hbound; ++i) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            count++;
        }
    }
    return count;
}
