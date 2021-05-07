

#ifndef ACCOUNT_H_
#define ACCOUNT_H_ 

class Account
{
    public:
        double balance;

        Account(double initialMoney);
        void credit(double money);
        bool debit(double money);
        double getBalance();
};

#endif
