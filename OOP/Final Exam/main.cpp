#include <iostream>

#include "Customer.h"
#include "Movie.h"
#include "Ticket.h"
#include "TicketManager.h"

TicketTypeWeekday weekdayTicket;
TicketTypeWeekend weekendTicket;
TicketTypeNight nightTicket;

int main() {
    TicketManager ticketManager;
    Movie movie1("1", "Avengers", "Russo Brothers", 180, 100);
    Movie movie2("2", "Spiderman", "Russo Brothers", 120, 80);
    Movie movie3("3", "Ironman", "Russo Brothers", 150, 90);
    Customer customer1("1", "0101", "Tony Stark", "A1", "18h 25/12/2023");
    Customer customer2("2", "0102", "Peter Parker", "B1", "18h 25/12/2023");
    Customer customer3("3", "0103", "Tony Stark", "C1", "18h 25/12/2023");
    Ticket* ticket1 =
        ticketManager.issueTicket("1", &customer1, &movie1, &weekdayTicket);
    Ticket* ticket2 =
        ticketManager.issueTicket("2", &customer2, &movie2, &weekendTicket);
    Ticket* ticket3 =
        ticketManager.issueTicket("3", &customer3, &movie3, &nightTicket);
    Student student1("4", "0104", "Alux", "A1", "18h 25/12/2023");
    VIPCustomer vipCustomer1("5", "0105", "Thor", "A1", "18h 25/12/2023");
    Ticket* ticket4 =
        ticketManager.issueTicket("4", &student1, &movie1, &weekdayTicket);
    std::cout << "vé 1 : " << ticket1->getPrice() << '\n';
    std::cout << "vé 2: " << ticket2->getPrice() << '\n';
    std::cout << "vé 3: " << ticket3->getPrice() << '\n';
    std::cout << "vé 4 học sinh: " << ticket4->getPrice() << '\n';
    std::cout << "vé 5 khách VIP: "
              << ticketManager
                     .issueTicket("5", &vipCustomer1, &movie1, &weekdayTicket)
                     ->getPrice()
              << '\n';
    std::cout << "Tổng doanh thu: " << ticketManager.getTotalValue() << "\n\n";
    Ticket* ticket = ticketManager.findTicketById("1");
    if (ticket != nullptr) {
        std::cout << *ticket;
        std::cout << "Giá vé: " << ticket->getPrice() << '\n';
    } else
        std::cout << "Không tìm thấy vé!" << '\n';
    ticket = ticketManager.findTicketById("4");
    if (ticket != nullptr) {
        std::cout << *ticket;
        std::cout << "\nGiá vé: " << ticket->getPrice() << '\n';
    } else
        std::cout << "Không tìm thấy vé!" << '\n';
    return 0;
}
