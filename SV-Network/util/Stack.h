//////////////////////////////////////////////////
//                                              //
// SV-Network                                   //
// Created by startVal                          //
//                                              //
// Twitter: @startval                           //
// Facebook: https://www.facebook.com/startval  //
// Website: http://www.startval.com             //
//                                              //
//////////////////////////////////////////////////
//                                              //
// Developer: Pau Sanchez                       //
//                                              //
// Twitter: @pausanchezv                        //
// Website: http://www.pausanchezv.com          //
//                                              //
//////////////////////////////////////////////////
//                                              //
// startVal © 2017 - All Rights Reserved        //
//                                              //
//////////////////////////////////////////////////

#ifndef SV_NETWORK_STACK_H
#define SV_NETWORK_STACK_H

#include "Frontier.h"

/**
 * Class Stack
 */
template <typename T> class Stack : public Frontier<T>{

public:

    /**
     * Stack Constructor default
     */
    Stack() {}

    /**
     * Stack Constructor with Node
     */
    Stack(T);

    /**
     * Stack Constructor with vector of nodes
     */
    Stack(vector<T>);

    /**
     * Push node in stack
     */
    void push(T);

    /**
     * Remove and return node from stack
     */
    const T pop();

    /**
     * Check if queue is empty or not
     */
    const bool empty() const;

    /**
     * Returns the Queue's size
     */
    const unsigned long int size() const;
};


/**
 * Stack Constructor with Node
 */
template <typename T> Stack<T>::Stack(T item) {
    push(item);
}

/**
 * Stack Constructor with vector of nodes
 */
template <typename T> Stack<T>::Stack(vector<T> items) {
    for (T item: items) {
        this->data.push_back(item);
    }
}

/**
 * Push node in stack
 */
template <typename T> void Stack<T>::push(T item) {
    this->data.push_back(item);
}

/**
 * Remove and return node from stack
 */
template <typename T> const T Stack<T>::pop() {
    if (this->empty()) {
        throw IndexError("Stack");
    }

    T item = this->data.back();
    this->data.pop_back();
    return item;
}

/**
 * Check if queue is empty or not
 */
template <typename T> const bool Stack<T>::empty() const {
    return this->data.empty();
}

/**
 * Returns Stack's size
 */
template <typename T> const unsigned long int Stack<T>::size() const {
    return this->data.size();
}

#endif //SV_NETWORK_STACK_H
