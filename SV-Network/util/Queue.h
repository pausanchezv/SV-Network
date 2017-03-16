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

#ifndef SV_NETWORK_QUEUE_H
#define SV_NETWORK_QUEUE_H

#include "Frontier.h"

/**
 * Class Queue
 */
template <class T> class Queue : public Frontier<T>{

public:

    /**
     * Queue Constructor default
     */
    Queue() {}

    /**
     * Queue Constructor with Node
     */
    Queue(T);

    /**
     * Queue Constructor with vector of nodes
     */
    Queue(vector<T>);

    /**
     * Push node in queue
     */
    virtual void push(T);

    /**
     * Push node in queue
     */
    virtual const T pop();

    /**
     * Check if queue is empty or not
     */
    virtual const bool empty() const;

    /**
     * Returns the Queue's size
     */
    virtual const unsigned long int size() const;
};

/**
 * Queue Constructor with node
 */
template <typename T> Queue<T>::Queue(T item) {
    push(item);
}

/**
 * Queue Constructor with Nodes
 */
template <typename T> Queue<T>::Queue(vector<T> items) {
    for (T item: items) {
        this->data.push_back(item);
    }
}

/**
 * Queue Constructor with vector of nodes
 */
template <typename T> void Queue<T>::push(T item) {
    this->data.push_back(item);
}

/**
 * Push node in queue
 */
template <typename T> const T Queue<T>::pop() {
    if (this->empty()) throw IndexError("Queue");
    T item = this->data.front();
    this->data.erase(this->data.begin());
    return item;
}

/**
 * Check if queue is empty or not
 */
template <typename T> const bool Queue<T>::empty() const {
    return this->data.empty();
}

/**
 * Returns Queue's size
 */
template <typename T> const unsigned long int Queue<T>::size() const {
    return this->data.size();
}


#endif //SV_NETWORK_QUEUE_H
