#pragma once
#include <exception>
#include <functional>
#include <string>
#include <unordered_map>

class InsufficientQuantityException : public std::exception {
   public:
    const char* what() const throw();
};

class PaymentMethod {
   public:
    virtual void pay(double totalValue) const = 0;
};

class CashMethod : public PaymentMethod {
   public:
    CashMethod() = default;
    void pay(double totalValue) const;
};

class AtmMethod : public PaymentMethod {
   public:
    AtmMethod() = default;
    void pay(double totalValue) const;
};

class MomoMethod : public PaymentMethod {
   public:
    MomoMethod() = default;
    void pay(double totalValue) const;
};

class ZaloMethod : public PaymentMethod {
   public:
    ZaloMethod() = default;
    void pay(double totalValue) const;
};

class Product {
   private:
    std::string _productId;
    std::string _productName;
    double _price;
    long _remainingQuantity;

   public:
    Product(std::string product_id, std::string productName, double price,
            long quantity);
    std::string getProductId();
    std::string getProductName();
    double getPrice();
    long getRemainingQuantity();
    void setRemainingQuantity(long quantity);
    bool operator==(const Product& other) const;
    struct ProductHash {
        std::size_t operator()(const Product& product) const;
    };
};

class Order {
   private:
    std::string _orderId;
    std::string _customerName;
    std::string _customerNumber;
    std::string _address;
    const PaymentMethod* _paymentMethod;
    std::unordered_map<Product, long, Product::ProductHash> _products;
    double _totalPrice;

   public:
    Order(std::string orderId, std::string customerName,
          std::string customerNumber, std::string address);
    void setPaymentMethod(const PaymentMethod& paymentMethod);
    void addProduct(Product* product, long quantity);
    void pay();
    std::string getOrderId();
    std::string getCustomerName();
    std::string getCustomerNumber();
    std::string getAddress();
    double getTotalPrice();
    struct Payment {
        const static CashMethod CASH_METHOD;
        const static AtmMethod ATM_METHOD;
        const static MomoMethod MOMO_METHOD;
        const static ZaloMethod ZALO_METHOD;
    };
};