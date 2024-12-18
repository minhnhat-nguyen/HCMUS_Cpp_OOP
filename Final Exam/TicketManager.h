#include "Ticket.h"
#include "Customer.h"
#include "Movie.h"
#include <iostream>
#include <vector>

class TicketManager {
    friend class Ticket;
    private:
        static std::vector<Ticket*> _tickets;
    public:
        TicketManager() = default;
        Ticket* issueTicket(std::string ticketID, Customer* customer, Movie* movie, TicketType* ticketType);
        Ticket* findTicketById(std::string id);
        double getTotalValue();
        ~TicketManager() {
            for (auto ticket : _tickets)
                delete ticket;
        }
};