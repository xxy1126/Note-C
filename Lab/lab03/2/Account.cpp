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

void Account:: debit(double money) {
    if(money > balance) {
        puts("Debit amount exceeded account balance.");
        return ;
    } else {
        balance -= money;
        return ;
    }
}

double Account:: getBalance() {
    return balance;
}