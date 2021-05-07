#include "CheckingAccount.h"
#include <cstdio>
#include <iostream>
 
using namespace std;

CheckingAccount:: CheckingAccount(double initialMoney, double initialFee): Account(initialMoney) {
    feechargedpertransaction = initialFee;
}

void CheckingAccount:: credit(double money) {
    balance += money;
    printf("$%.2lf transaction fee charged.\n",feechargedpertransaction);
    balance -= feechargedpertransaction;
}
void CheckingAccount:: debit(double money) {
    if(money > balance) {
        puts("Debit amount exceeded account balance.");
    } else {
        balance -= money;
        printf("$%.2lf transaction fee charged.\n",feechargedpertransaction);
        balance -= feechargedpertransaction;    
    }
}