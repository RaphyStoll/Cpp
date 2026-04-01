#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array {
private:
    T *_elements;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &orig);
    ~Array();

    Array &operator=(const Array &rhs);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#include "Array.tpp"

#endif
