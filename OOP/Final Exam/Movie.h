#pragma once
#include <string>

class Movie {
    private:
        std::string _movieId;
        std::string _movieName;
        std::string _director;
        int _duration;
        double _price;
    public:
        Movie(std::string movieId, std::string movieName, std::string director, int duration, double price);
        double getPrice();
        std::string getMovieName();
};