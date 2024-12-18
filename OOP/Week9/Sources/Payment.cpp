#include "Payment.h"

#include <iostream>

const char* InsufficientQuantityException::what() const throw() {
    return "Số lượng sản phẩm không đủ.";
}

void CashMethod::pay(double totalValue) const {
    std::cout << "Thanh toán " << totalValue << " bằng tiền mặt.\n";
}

void AtmMethod::pay(double totalValue) const {
    std::cout << "Thanh toán " << totalValue << " bằng thẻ ATM.\n";
}

void MomoMethod::pay(double totalValue) const {
    std::cout << "Thanh toán " << totalValue << " bằng ví điện tử Momo.\n";
}

void ZaloMethod::pay(double totalValue) const {
    std::cout << "Thanh toán " << totalValue << " bằng ví điện tử ZaloPay.\n";
}

Product::Product(std::string product_id, std::string productName, double price,
                 long quantity)
    : _productId(product_id),
      _productName(productName),
      _price(price),
      _remainingQuantity(quantity) {}

std::string Product::getProductId() { return _productId; }

std::string Product::getProductName() { return _productName; }

double Product::getPrice() { return _price; }

long Product::getRemainingQuantity() { return _remainingQuantity; }

void Product::setRemainingQuantity(long quantity) {
    _remainingQuantity = quantity;
}

bool Product::operator==(const Product& other) const {
    return _productId == other._productId;
}

std::size_t Product::ProductHash::operator()(const Product& product) const {
    return std::hash<std::string>()(product._productId);
}

Order::Order(std::string orderId, std::string customerName,
             std::string customerNumber, std::string address)
    : _orderId(orderId),
      _customerName(customerName),
      _customerNumber(customerNumber),
      _address(address),
      _paymentMethod(&Payment::CASH_METHOD),
      _totalPrice(0) {}

void Order::setPaymentMethod(const PaymentMethod& paymentMethod) {
    _paymentMethod = &paymentMethod;
}

void Order::addProduct(Product* product, long quantity) {
    if (quantity > product->getRemainingQuantity())
        throw InsufficientQuantityException();
    product->setRemainingQuantity(product->getRemainingQuantity() - quantity);
    _products[*product] += quantity;
    _totalPrice += product->getPrice() * quantity;
}

std::string Order::getOrderId() { return _orderId; }

std::string Order::getCustomerName() { return _customerName; }

std::string Order::getCustomerNumber() { return _customerNumber; }

std::string Order::getAddress() { return _address; }

double Order::getTotalPrice() { return _totalPrice; }

void Order::pay() { _paymentMethod->pay(_totalPrice); }

const CashMethod Order::Payment::CASH_METHOD = CashMethod();
const AtmMethod Order::Payment::ATM_METHOD = AtmMethod();
const MomoMethod Order::Payment::MOMO_METHOD = MomoMethod();
const ZaloMethod Order::Payment::ZALO_METHOD = ZaloMethod();