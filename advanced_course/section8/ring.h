#pragma once
#include <iostream>

template <class T>
class ring{
private:
    int m_size;         // array size
    T *m_values;        // pointer to array of type T
    int m_pos;          // position

public:
    class iterator;     // nested class prototype

public:
    ring(int size): m_size(size), m_values(NULL), m_pos(0) {      
        // constructor, initialise all members
        m_values = new T[size];
    }
    // throw error if not enough memory

    ~ring(){
        delete [] m_values;
    }

    int size(){
        return m_size;
    }

    iterator begin(){
        return iterator(0, *this);
    }

    iterator end(){
        return iterator(m_size, *this);
    }

    void add(T value){
        m_values[m_pos%m_size] = value;
        m_pos++;
    }

    T &get(int pos){
        return m_values[pos];
        // throw error if position is invalid
    }

};

template <class T>
class ring<T>::iterator{     // nested class implementation
private:
    int m_pos;
    ring &m_ring;

public:
    iterator(int pos, ring &aRing): m_pos(pos), m_ring(aRing){
    }

    iterator &operator++(int){      // (int) to denote postfix increment
        m_pos++;
        return *this;
    }

    iterator &operator++(){         //prefix increment, not used here
        m_pos++;
        return *this;
    }

    T &operator*(){
        return m_ring.get(m_pos);
    }

    bool operator!=(const iterator &other) const {
        return m_pos != other.m_pos;
    }
};
