#pragma once
#include "Movie.h"
#include "Customer.h"
#include "ostream"

class TicketType {
   public:
    virtual double getPrice(Movie*) = 0;
};

class TicketTypeWeekday : public TicketType {
   public:
    double getPrice(Movie*);
};

class TicketTypeWeekend : public TicketType {
   public:
    double getPrice(Movie*);
};

class TicketTypeNight : public TicketType {
   public:
    double getPrice(Movie*);
};

class Ticket {
   private:
    std::string _ticketId;
    Movie* _movie;
    Customer* _customer;
    TicketType* _ticketType;

   public:
    Ticket(std::string ticketId, Movie* movie, Customer* customer,
           TicketType* ticketType);
    double getPrice();
    std::string getTicketId();
    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
};
