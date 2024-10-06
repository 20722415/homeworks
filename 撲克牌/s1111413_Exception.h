#ifndef POKEREXCEPTION_H
#define POKEREXCEPTION_H

#include <stdexcept>

class Exception : public std::exception {

public:

    Exception(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return "No more cards in the deck.";
    }
private:
    string message;
};

#endif  // POKEREXCEPTION_H
