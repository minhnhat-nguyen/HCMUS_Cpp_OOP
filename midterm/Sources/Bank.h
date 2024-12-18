#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define deposit 50000
class BankAccount {
    private:
        std::string id;
        std::string name;
        double balance;
    public:
        BankAccount(std::string id, std::string name, double balance) {
            this->id = id;
            this->name = name;
            if (balance < deposit)
                throw "Insufficient ammount to open an account";
            this->balance = balance;
        }

        double getBalance() {
            return balance;
        }

        std::string getID() {
            return id;
        }

        bool addMoney(double money) {
            if (money < 0)
                return 0;
            balance += money;
            return 1;
        }

        bool withdrawMoney(double money) {
            if (money < 0)
                return 0;
            if (balance - deposit < money)
                return 0;
            balance -= money;
            return 1;
        }

        bool operator<(const BankAccount& other) {
            return balance < other.balance;
        }

        bool operator>(const BankAccount& other) {
            return balance > other.balance;
        }

        bool operator==(const BankAccount& other) {
            return balance == other.balance;
        }

        bool operator<=(const BankAccount& other) {
            return balance <= other.balance;
        }

        bool operator>=(const BankAccount& other) {
            return balance >= other.balance;
        }

        friend std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
            os << "ID: " << account.id << '\n';
            os << "Name: " << account.name << '\n';
            os << "Balance: " << account.balance << '\n';
            os << "--------------------------------------\n";
            return os;
        }

        std::string getName() {
            return name;
        }
};

class SubAccount {
    private:
        friend class Bank;
        std::string id;
        std::string name;
        double limit;
        double remainingBalance;
        BankAccount* sourceAccount;
    
    protected:
        void setSourceAccount(BankAccount* sourceAccount) {
            this->sourceAccount = sourceAccount;
        }

    public:
        SubAccount(std::string id, std::string name, double limit) {
            this->id = id;
            this->name = name;
            this->limit = limit;
            remainingBalance = limit;
        }

        double getSourceBalance() {
            return sourceAccount->getBalance();
        }

        void setLimit(double newLimit) {
            remainingBalance = newLimit - remainingBalance;
            if (remainingBalance < 0) remainingBalance = 0;
            this->limit = newLimit;
        }

        double canWithdraw() {
            return std::min(remainingBalance, sourceAccount->getBalance() - deposit);
        }

        void resetremainingBalance() {
            remainingBalance = limit;
        }

        bool withdrawMoney(double money) {
            if (money < 0) return 0;
            if (money > canWithdraw()) return 0;
            if (sourceAccount->withdrawMoney(money)) {
                remainingBalance -= money;
                return 1;
            }
            return 0;
        }

        bool addMoney(double money) {
            if (money < 0) return 0;
            if (sourceAccount->addMoney(money)) {
                remainingBalance += money;
                return 1;
            }
            return 0;
        }

        friend std::ostream& operator<<(std::ostream& os, const SubAccount& account) {
            os << "ID: " << account.id << '\n';
            os << "Name: " << account.name << '\n';
            os << "Limit: " << account.limit << '\n';
            os << "Remaining balance: " << account.remainingBalance << '\n';
            os << "Source account: " << account.sourceAccount->getName() << '\n';
            os << "--------------------------------------";
            return os;
        }

        BankAccount* getSourceAccount() {
            return sourceAccount;
        }
};

class Bank {
    private:
        std::string name;
        std::string address;
        std::vector<BankAccount> accounts;
        std::vector<SubAccount> subAccounts;
       public:
        Bank(std::string name, std::string address) {
            this->name = name;
            this->address = address;
        }

        void addAccount(BankAccount account) {
            accounts.push_back(account);
        }

        std::vector<BankAccount> listAccountDesending(bool print = 1) {
            std::vector<BankAccount> temp = accounts;
            std::sort(temp.begin(), temp.end(), [](BankAccount& a, BankAccount& b) {
                return a.getBalance() > b.getBalance();
            });
            if (!print) return temp;
            for (BankAccount account : temp)
                std::cout << account;
            return temp;
        }

        double getTotalHoldingValue() {
            double total = 0;
            for (BankAccount account : accounts)
                total += account.getBalance();
            return total;
        }

        int Size() {
            return accounts.size();
        }

        BankAccount& operator[](int index) {
            return accounts[index];
        }

        BankAccount* findAccountByID(std::string ID) {
            for (BankAccount& account : accounts)
                if (account.getID() == ID)
                    return &account;
            return nullptr;
        }

        void addSubAccount(SubAccount subAccount, BankAccount* sourceAccount) {
            subAccount.setSourceAccount(sourceAccount);
            subAccounts.push_back(subAccount);
        }

        SubAccount& findSubAccountByID(BankAccount* source, std::string ID) {
            for (SubAccount& subAccount : subAccounts)
                if (subAccount.id == ID && subAccount.sourceAccount == source)
                    return subAccount;
            throw "Sub account not found";
        }

        std::string getName() {
            return name;
        }
};