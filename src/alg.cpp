// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    if (value > 2 && value % 2 == 0) {
        return false;
    }
    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }
    uint64_t count = 1;
    uint64_t currentNum = 3;
    while (count < n) {
        if (checkPrime(currentNum)) {
            count++;
            if (count == n) {
                return currentNum;
            }
        }
        currentNum += 2;
    }
}

uint64_t nextPrime(uint64_t value) {
    if (value < 2)return 2;

    uint64_t candidate = value + 1;

    if (candidate % 2 == 0)candidate++;

    while (true) {
        if (checkPrime(candidate))return candidate;
        candidate += 2;
    }
}

uint64_t sumPrime(uint64_t hbound) {

    int64_t sum = 0;

    if (hbound <= 2) sum = 0;
    if (2 < hbound) sum = 2;

    for (int i = 3; i <= hbound - 1; i += 2) {
        if (checkPrime(i))sum += i;
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (lbound < 2) lbound = 2;

    uint64_t previous = -1; //
    uint64_t count = 0;
    uint64_t current = lbound;

    while (current < hbound) {
        if (checkPrime(current)) {
            if (previous != -1 && current - previous == 2) {
                count++;
            }
            previous == current;
        }
        current++;
    }
    return count;

}
