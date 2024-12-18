#include "Movie.h"

Movie::Movie(std::string movieId, std::string movieName, std::string director, int duration, double price) {
    _movieId = movieId;
    _movieName = movieName;
    _director = director;
    _duration = duration;
    _price = price;
}

double Movie::getPrice() {
    return _price;
}

std::string Movie::getMovieName() {
    return _movieName;
}
