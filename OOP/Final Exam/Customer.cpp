#include "Customer.h"

Customer::Customer(std::string customerId,
                   std::string phone, std::string customerName,
                   std::string seatId, std::string showTime) {
    _customerId = customerId;
    _phone = phone;
    _customerName = customerName;
    _seatId = seatId;
    _showTime = showTime;
    multiplier = 1;
}

std::string Customer::getId() { return _customerId; }

std::string Customer::getCustomerName() { return _customerName; }

std::string Customer::getSeatId() { return _seatId; }

std::string Customer::getShowTime() { return _showTime; }

Student::Student(std::string customerId,
                 std::string customerName, std::string phone,
                 std::string seatId, std::string showTime)
    : Customer(customerId, customerName, phone, seatId, showTime) {
    multiplier = 0.7;
}

VIPCustomer::VIPCustomer(std::string customerId, std::string customerName,
                         std::string phone, std::string seatId,
                         std::string showTime)
    : Customer(customerId, customerName, phone, seatId, showTime) {
    multiplier = 0.85;
}