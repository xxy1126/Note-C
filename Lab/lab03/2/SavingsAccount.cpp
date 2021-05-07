#include "SavingsAccount.h"
#include <cstdio>
#include <iostream>

using namespace std;

SavingsAccount:: SavingsAccount(double initialMoney, double initialIn): Account(initialMoney) {
    interestrate = initialIn;
}

void SavingsAccount::credit(double money) {
    balance += money;
    printf("Adding $%.2lf interest (a SavingsAccount)\n",calculateInterest());
    balance += calculateInterest();
}

double SavingsAccount:: calculateInterest() {
    return balance * interestrate;
}