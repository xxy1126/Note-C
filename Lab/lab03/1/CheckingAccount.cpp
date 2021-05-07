#include "CheckingAccount.h"
#include <cstdio>
#include <iostream>
 
using namespace std;

CheckingAccount:: CheckingAccount(double initialMoney, double initialFee): Account(initialMoney) {
    feechargedpertransaction = initialFee;
}

void CheckingAccount:: credit(double money) {
    balance += money;
    balance -= feechargedpertransaction;
}
void CheckingAccount:: debit(double money) {
    if(Account::debit(money)) {
        money -= feechargedpertransaction;
    }
}