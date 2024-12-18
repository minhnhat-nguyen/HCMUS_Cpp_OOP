#pragma once
#include <string>

class Customer {
    friend class Ticket;

   protected:
    double multiplier = 1;
    std::string _customerId;
    std::string _customerName;
    std::string _phone;
    std::string _seatId;
    std::string _showTime;  // 18h 25/12/2023
   public:
    Customer( std::string customerId, std::string phone, std::string customerName,
             std::string seatId, std::string showTime);
    std::string getId();
    std::string getMovieName();
    std::string getCustomerName();
    std::string getSeatId();
    std::string getShowTime();
};

class Student : public Customer {
    friend class Ticket;

   public:
    Student(std::string customerId, std::string phone,
            std::string customerName, std::string seatId, std::string showTime);
};

class VIPCustomer : public Customer {
    friend class Ticket;

   public:
    VIPCustomer(std::string customerId, std::string phone,
                std::string customerName, std::string seatId,
                std::string showTime);
};