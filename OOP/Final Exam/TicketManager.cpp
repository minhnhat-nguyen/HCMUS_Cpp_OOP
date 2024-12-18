#include "TicketManager.h"

Ticket* TicketManager::issueTicket(std::string ticketID, Customer* customer, Movie* movie, TicketType* ticketType) {
    Ticket* ticket = new Ticket(ticketID, movie, customer, ticketType);
    _tickets.push_back(ticket);
    return ticket;
}

Ticket* TicketManager::findTicketById(std::string id) {
    for (auto ticket : _tickets)
        if (ticket->getTicketId() == id)
            return ticket;
    return nullptr;
}

double TicketManager::getTotalValue() {
    double total = 0;
    for (auto ticket : _tickets) {
        total += ticket->getPrice();
    }
    return total;
}

std::vector<Ticket*> TicketManager::_tickets;