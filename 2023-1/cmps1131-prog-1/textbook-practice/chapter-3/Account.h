#ifndef CHAPTER_3_ACCOUNT_H
#define CHAPTER_3_ACCOUNT_H

#include <string>

class Account {
public:
    // constructor
    Account(std::string accountName, int initialBalance)
        : name{accountName} {
        if (initialBalance > 0) {
            balance = {initialBalance};
        }
    }
    // function members
    // deposit setter
    void deposit(int depositAmount) {
        if (depositAmount > 0) {
            balance += {depositAmount};
        }
    }

    // withdraw setter
    void withdraw(int withdrawAmount) {
        if (withdrawAmount > 0) {
            if (withdrawAmount <= balance) {
                balance -= {withdrawAmount};
            } else {
                std::cout << "\nWithdrawal amount exceeded account balance.";
            }
        }
    }

    // balance getter
    int getBalance() const {
        return balance;
    }

    // name setter
    void setName(std::string accountName) {
        name = {accountName};
    }

    // name getter
    std::string getName() const {
        return name;
    }
private:
    // data members
    std::string name;
    int balance{0};
};

#endif //CHAPTER_3_ACCOUNT_H
