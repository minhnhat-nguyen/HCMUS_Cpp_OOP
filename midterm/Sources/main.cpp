#include "Bank.h"
#include <iostream>

int main() {
    BankAccount* pcurr;
     BankAccount account1("123456789", "Huy", 1e6);
    Bank bank("ACB", "227 Nguyen Van Cu");
    bank.addAccount(account1);
    pcurr = bank.findAccountByID("123456789");
    if (!pcurr) {
        std::cout << "Account not found!\n";
        return 0;
    }
    BankAccount & curr = *pcurr;
    if (curr.addMoney(1e6)) {
        std::cout << "Succesfully added 1 mil to account1!\n";
        std::cout << "New balance: " << curr.getBalance() << '\n';
    }
    else 
        std::cout << "Failed to add 1 mil to account1!\n";
    if (curr.withdrawMoney(5e6)) {
        std::cout << "Succesfully withrawed 5 mils from account1!\n";
        std::cout << "Remaining balance: " << curr.getBalance() << '\n';
    }
    if (curr.withdrawMoney(500000)) {
        std::cout << "Succesfully withrawed 500000 from account1!\n";
        std::cout << "Remaining balance: " << curr.getBalance() << '\n';
    }
    else
        std::cout << "Withraws unsuccesfully";

    std::cout << curr;

    BankAccount guest("987654321", "_randomperson", 1e6);
    bank.addAccount(guest);
    pcurr = bank.findAccountByID("987654321");
    if (!pcurr) {
        std::cout << "Account not found!\n";
        return 0;
    }
    BankAccount& curr1 = *pcurr;
    if (curr1.addMoney(5e6)) {
        std::cout << "Succesfully added 5 mils to guest\n";
        std::cout << "New balance: " << curr1.getBalance() << '\n';
    } else
        std::cout << "Failed to add 5 mils to guest\n";
    std::cout << curr1;

    std::cout << "Total holding value of " << (bank.getName() + " : ") << bank.getTotalHoldingValue() << "\n\n";

    std::cout << "List accounts from bank decensdently sorted by balance:\n";
    std::vector<BankAccount> sorted = bank.listAccountDesending();
    std::cout << "The wealthiest person is: \n" << sorted[0] << '\n';


    SubAccount sister("4321", "Thu", 3e6);
    bank.addSubAccount(sister, bank.findAccountByID("123456789"));
    SubAccount sis = bank.findSubAccountByID(bank.findAccountByID("123456789"), "4321");
    std::cout << sis;
    if (sis.addMoney(200000)) {
        std::cout << "Succesfully added 200000 to sister!\n";
        std::cout << "New balance: \n" << sis << '\n';
    }
    else
        std::cout << "Failed to add 200000 to sister!\n";
    if (sis.withdrawMoney(300000)) {
        std::cout << "Succesfully withdrawed 300000 from sister!\n";
        std::cout << "New balance: \n" << sis << '\n';
    }
    else
        std::cout << "Failed to withdraw 300000 from sister!\n";
    std::cout << "The remaining balance of source account: \n";
    std::cout << (*sis.getSourceAccount()).getName() << " "
              << (*sis.getSourceAccount()).getBalance() << '\n';

    if (sis.withdrawMoney(7e7)) {
        std::cout << "Succesfully withdrawed 70 mils from sister!\n";
        std::cout << "New balance: \n" << sis << '\n';
    } else
        std::cout << "Failed to withdraw 70 mils from sister!\n";
    std::cout << "The remaining balance of source account: \n";
    std::cout << (*sis.getSourceAccount()).getName() << " "
              << (*sis.getSourceAccount()).getBalance() << '\n';
    return 0;
}