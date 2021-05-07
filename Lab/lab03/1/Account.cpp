#include "Account.h"
#include <cstdio>
#include <iostream>

Account:: Account(double initialMoney) {
    if(initialMoney >= 0) {
        balance = initialMoney;
    }
    else {
        balance = 0;
    }       
}

void Account:: credit(double money) {
    balance += money;
}

bool Account:: debit(double money) {
    if(money > balance) {
        puts("Debit amount exceeded account balance.");
        return 0;
    } else {
        balance -= money;
        return 1;
    }
}

double Account:: getBalance() {
    return balance;
}