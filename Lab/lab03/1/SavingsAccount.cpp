#include "SavingsAccount.h"
#include <cstdio>
#include <iostream>

using namespace std;

SavingsAccount:: SavingsAccount(double initialMoney, double initialIn): Account(initialMoney) {
    interestrate = initialIn;
}

double SavingsAccount:: calculateInterest() {
    return balance * interestrate;
}