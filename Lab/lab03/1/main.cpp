#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    Account account(50.00);
    SavingsAccount accountSaving(50.00, 0.1);
    CheckingAccount accountChecking(50.00, 10.00);
    
    printf("account balance: %.2lf\n", account.getBalance());
    printf("accountSaving balance: %.2lf\n", accountSaving.getBalance());
    printf("accountChecking balance: %.2lf\n", accountChecking.getBalance());

    double creditMoney = 10.00;
    double debitMoney = 20.00;
    account.credit(creditMoney);
    printf("account credit: %.2lf\n",creditMoney);
    printf("account balance: %.2lf\n",account.getBalance());
    printf("\n\n");

    accountSaving.debit(debitMoney);
    printf("accountSaving debit: %.2lf\n",debitMoney);
    printf("accountSaving balance: %.2lf\n",accountSaving.getBalance());
    printf("Now add %.2lf interest to accountSaving\n",accountSaving.calculateInterest());
    accountSaving.credit(accountSaving.calculateInterest());
    printf("accountSaving balance: %.2lf\n",accountSaving.getBalance());
    printf("\n\n");

    debitMoney = 100.00;
    accountChecking.debit(debitMoney);
    accountChecking.credit(creditMoney);
    printf("accountChecking balance: %.2lf\n",accountChecking.getBalance());
}