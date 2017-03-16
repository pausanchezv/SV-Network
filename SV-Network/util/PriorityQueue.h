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

#ifndef SV_NETWORK_PRIORITYQUEUE_H
#define SV_NETWORK_PRIORITYQUEUE_H


#include "Heap.h"
#include "Queue.h"


/**
 * Priority Queue Class
 *
 * Priority Queue that uses a heap to sort the elements.
 * It always returns the object with a lower output value.
 */
template <class T> class PriorityQueue : public Queue<T> {

    //PriorityQueue uses a Heap data structure
    Heap<T> *heap;

public:

    /**
     * PriorityQueue Constructor 1
     */
    PriorityQueue(string attr);

    /**
     * PriorityQueue Constructor 2
     */
    PriorityQueue(Node<T> *start, string attr);

    /**
     * PriorityQueue Destructor
     */
    ~PriorityQueue();

    /**
     * Push an item to PriorityQueue
     */
    void push(T obj);

    /*
     * Returns the item with a lower output value
     */
    const T pop();

    /**
     * Check whether is empty or not
     */
    const bool empty() const;

    /**
     * Returns the PriorityQueue's size
     */
    const unsigned long int size() const;

};


/**
 * PriorityQueue Constructor 1
 */
template <class T> PriorityQueue<T>::PriorityQueue(string attr) {
    heap = new Heap<T>(attr);
}

/**
 * PriorityQueue Constructor 2
 */
template <class T> PriorityQueue<T>::PriorityQueue(Node<T> *start, string attr) {
    heap = new Heap<T>(attr);
    heap->heapPush(start);
}

/**
 * PriorityQueue Destructor
 */
template <class T> PriorityQueue<T>::~PriorityQueue() {
    delete heap;
}

/**
 * Push an item to PriorityQueue
 */
template <class T> void PriorityQueue<T>::push(T obj) {
    heap->heapPush(obj);
}

/*
 * Returns the item with a lower output value
 */
template <class T> const T PriorityQueue<T>::pop() {
    return heap->heapPop();
}

/**
 * Check whether is empty or not
 */
template <class T> const bool PriorityQueue<T>::empty() const {
    return heap->size() < 1;
}

/**
 * Returns the PriorityQueue's size
 */
template <class T> const unsigned long int PriorityQueue<T>::size() const {
    return heap->size() - 1;
}


#endif //SV_NETWORK_PRIORITYQUEUE_H
