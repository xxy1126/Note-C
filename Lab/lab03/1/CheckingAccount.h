
#include "Account.h"

#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_

class CheckingAccount: public Account
{
    private:
        double feechargedpertransaction;
    public:
        CheckingAccount(double initialMoney,double initalFee);
        void credit(double money);
        void debit(double money);
};

#endif