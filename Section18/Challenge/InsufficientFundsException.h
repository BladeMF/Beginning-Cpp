#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__
#include <exception>

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() {}
    ~InsufficientFundsException() {}

    virtual const char *what() const noexcept override {
        return "Insufficient finds exception";
    };
};

#endif