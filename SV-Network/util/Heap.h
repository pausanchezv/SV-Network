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

#ifndef SV_NETWORK_HEAP_H
#define SV_NETWORK_HEAP_H

#include <math.h>
#include <algorithm>
#include <typeinfo>

#include "../exceptions/Exceptions.h"

/**
 * Class Heap
 *
 * The Heap is the data structure used to implement a Priority Queue.
 *
 * The Heap class has two templates, the first one represents the object's type (node or edge).
 * The second template is the type of attribute that used to sort the Heap.
 */
template <class Obj> class Heap {

    //Attribute used to sort the heap
    string attr;

    //Heap Array
    vector<Obj> heap;

    /**
     * Checks whether Heap has been created with Node or Edge classes
     */
    void _checkHeapObj(Obj item);

    /**
     * Reset the heap order by swapping the items up until the heap order property is restored
     */
    void _upHeap(unsigned long int index);

    /**
     * Lower the root element down as much as necessary
     */
    void _downHeap(unsigned long int index);

    /**
     * Returns the index of heap that has the smallest item associated
     */
    const unsigned long int _minChild(unsigned long i) const;

public:

    /**
     * Heap Constructor
     */
    Heap(string attr) : attr(attr) {
        heap.push_back(nullptr);
    }

    /**
     * Insert an item to heap
     */
    void heapPush(Obj item);

    /**
     * Removes the smallest item and returns it
     */
    const Obj heapPop();

    /**
     * Creates a Heap from a vector of objects
     */
    void heapify(vector<Obj> array);

    /**
     * Returns Heap size
     */
    const unsigned long int size() const;

};


/**
 * Reset the heap order by swapping the items up until the heap order property is restored
 */
template <class Obj> void Heap<Obj>::_upHeap(unsigned long int index) {

    while (floor(index / 2)) {

        if (heap[index]->get<double>(attr) < heap[floor(index / 2)]->get<double>(attr)) {
            Obj temp = heap[floor(index / 2)];
            heap[floor(index / 2)] = heap[index];
            heap[index] = temp;
        }
        index = (unsigned long int) floor(index / 2);
    }
}

/**
 * Insert an item to heap
 */
template <class Obj> void Heap<Obj>::heapPush(Obj item) {

    _checkHeapObj(item);

    heap.push_back(item);
    _upHeap(heap.size() - 1);
}

/**
 * Lower the root element down as much as necessary
 */
template <class Obj> void Heap<Obj>::_downHeap(unsigned long int index) {

    while ((index * 2) <= heap.size() - 1) {
        unsigned long int mc = _minChild(index);

        if (heap[index]->get<double>(attr) > heap[mc]->get<double>(attr)) {
            Obj temp = heap[index];
            heap[index] = heap[mc];
            heap[mc] = temp;
        }
        index = mc;
    }
}

/**
 * Returns the index of heap that has the smallest item associated
 */
template <class Obj> const unsigned long int Heap<Obj>::_minChild(unsigned long i) const {
    if ((i * 2) + 1 >  heap.size() - 1)
        return i * 2;
    return (heap[i * 2]->get<double>(attr) < heap[i * 2 + 1]->get<double>(attr)) ? i * 2 : i * 2 + 1;
}

/**
 * Removes the smallest item and returns it
 */
template <class Obj> const Obj Heap<Obj>::heapPop() {
    if (heap.size() > 1) {
        Obj retVal = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        _downHeap(1);
        return retVal;
    }
    throw IndexError("Heap");
}

/**
 * Creates a Heap from a vector of objects
 */
template <class Obj> void Heap<Obj>::heapify(vector<Obj> array) {
    unsigned long int index = (unsigned long int) floor(array.size() / 2);

    for (Obj obj: array) {
        heap.push_back(obj);
    }
    while (index) {
        _downHeap(index--);
    }
}

/**
 * Returns Heap size
 */
template <class Obj> const unsigned long int Heap<Obj>::size() const {
    return heap.size() - 1;
}

/**
 * Checks whether Heap has been created with Node or Edge classes
 */
template <class Obj> void Heap<Obj>::_checkHeapObj(Obj item) {

    string typeObj = typeid(item).name();

    if (typeObj.find("Node") == string::npos && typeObj.find("Edge") == string::npos) {
        throw HeapTypeError();
    }
}


#endif //SV_NETWORK_HEAP_H
