#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<Account *> account;
    SavingsAccount accountSaving1(50.00,0.1);
    SavingsAccount accountSaving2(100.00,0.2);
    CheckingAccount accountChecking1(50.00,10.00);
    CheckingAccount accountChecking2(100.00,20.00);
    account.push_back(&accountSaving1);
    account.push_back(&accountSaving2);
    account.push_back(&accountChecking1);
    account.push_back(&accountChecking2);

    for(int i = 0; i < 4; i++) {
        printf("Account %d balance: $%.2lf\n",i+1, account[i]->getBalance());
        printf("Enter an amount to withdraw from Account %d: ",i+1);
        double withdraw,deposit;
        
        scanf("%lf",&withdraw);
        account[i]->debit(withdraw);

        printf("Enter an amout to deposit into Account %d: ",i+1);
        
        scanf("%lf",&deposit);
        account[i]->credit(deposit);

        printf("Updated Account %d balance: %.2lf\n",i+1, account[i]->getBalance());
        printf("\n\n");
    }
}