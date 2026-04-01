#ifndef ARRAY_TPP
#define ARRAY_TPP

template <class T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template <class T>
Array<T>::Array(const Array &orig) : _elements(NULL), _size(0) {
    if (orig._size > 0) {
        _elements = new T[orig._size]();
        for (unsigned int i = 0; i < orig._size; i++) {
            _elements[i] = orig._elements[i];
        }
        _size = orig._size;
    }
}

template <class T>
Array<T>::~Array() {
    delete[] _elements;
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {
    if (this == &rhs)
        return *this;

    delete[] _elements;
    _elements = NULL;
    _size = 0;

    if (rhs._size > 0) {
        _elements = new T[rhs._size]();
        for (unsigned int i = 0; i < rhs._size; i++) {
            _elements[i] = rhs._elements[i];
        }
        _size = rhs._size;
    }

    return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw OutOfBoundsException();
    return _elements[index];
}

template <class T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw OutOfBoundsException();
    return _elements[index];
}

template <class T>
unsigned int Array<T>::size() const {
    return _size;
}

template <class T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index out of bounds!";
}

#endif
