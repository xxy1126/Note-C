


#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "Account.h"

class SavingsAccount: public Account 
{
    private:
        double interestrate;
    public:
        SavingsAccount(double initialMoney, double initialIn);
        virtual void credit(double money);
        double calculateInterest();
};

#endif