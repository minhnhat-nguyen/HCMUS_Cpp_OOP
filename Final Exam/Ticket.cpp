#include "Ticket.h"

double TicketTypeWeekday::getPrice(Movie* _movie) {
    return (_movie->getPrice() + 0.1 * _movie->getPrice()) * 0.7;
}

double TicketTypeWeekend::getPrice(Movie* _movie) {
    return _movie->getPrice() + 0.3 * _movie->getPrice();
}

double TicketTypeNight::getPrice(Movie* _movie) {
    return _movie->getPrice() + 0.1 * _movie->getPrice();
}

Ticket::Ticket(std::string ticketId, Movie* movie, Customer* customer,
               TicketType* ticketType) {
    _ticketId = ticketId;
    _movie = movie;
    _customer = customer;
    _ticketType = ticketType;
}

double Ticket::getPrice() {
    return _ticketType->getPrice(_movie) * _customer->multiplier;
}

std::string Ticket::getTicketId() { return _ticketId; }

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
    os << "Mã vé: " << ticket._customer->getId() << '\n';
    os << "Tên khách hàng: " << ticket._customer->getCustomerName() << '\n';
    os << "Tên phim: " << ticket._movie->getMovieName() << '\n';
    os << "Mã số ghế ngồi: " << ticket._customer->getSeatId() << '\n';
    os << "Ngày và giờ xem: " << ticket._customer->getShowTime() << '\n';
    return os;
}