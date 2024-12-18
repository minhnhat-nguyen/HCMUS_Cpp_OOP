#include <iostream>

#include "Dragon.h"
#include "Payment.h"

int main() {
    // bai 1
    Product p1("1", "Sữa tắm", 1000, 100);
    Product p2("2", "Xà phòng", 5000, 100);
    Product p3("3", "Dầu gội", 20000, 100);
    Product p4("4", "Kem đánh răng", 15000, 100);
    Product p5("5", "Kem ủ tóc", 30000, 100);
    Order o1("1", "Nguyễn Văn A", "0123456789", "Hà Nội");
    o1.addProduct(&p1, 1);
    o1.addProduct(&p2, 1);
    o1.addProduct(&p3, 20);
    o1.addProduct(&p4, 1);
    o1.addProduct(&p5, 1);
    o1.pay();
    o1.setPaymentMethod(Order::Payment::MOMO_METHOD);
    o1.pay();
    o1.setPaymentMethod(Order::Payment::ATM_METHOD);
    o1.pay();
    o1.addProduct(&p1, 99);
    o1.setPaymentMethod(Order::Payment::ZALO_METHOD);
    o1.pay();
    // bai 2
    Dragon d("ABC", 1, 100, 100, 100);
    d.attack();
    d.move();
    std::cout << "Sát thương: " << d.getAtkDamage() << "\n";
    d.setState(Dragon::RAMPAGE_STATE);
    d.attack();
    d.move();
    std::cout << "Sát thương: " << d.getAtkDamage() << "\n";
    d.setState(Dragon::DEFENSE_STATE);
    d.attack();
    d.move();
    std::cout << "Sát thương: " << d.getAtkDamage() << "\n";
    return 0;
}