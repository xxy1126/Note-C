

#ifndef ACCOUNT_H_
#define ACCOUNT_H_ 

class Account
{
    public:
        double balance;

        Account(double initialMoney);
        virtual void credit(double money);
        virtual void debit(double money);
        double getBalance();
};

#endif
