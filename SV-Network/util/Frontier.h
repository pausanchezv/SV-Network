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

#ifndef SV_NETWORK_FRONTIER_H
#define SV_NETWORK_FRONTIER_H


#include <vector>

using namespace std;

/**
 * Class Frontier
 *
 * This class is used as an interface.
 */
template <class T> class Frontier {

protected:

    vector<T> data;

public:

    /**
     * Frontier Constructor default
     */
    Frontier() {}

    /**
     * Frontier Constructor with Node
     */
    Frontier(T item) {}

    /**
     * Frontier Constructor with vector of nodes
     */
    Frontier(vector<T> items) {}

    /**
     * Frontier Destructor
     */
    virtual ~Frontier() {}

    /**
     * Push node in Frontier
     */
    virtual void push(T item) = 0;

    /**
     * Push node in queue
     */
    virtual const T pop() = 0;

    /**
     * Check if queue is empty or not
     */
    virtual const bool empty() const = 0;

    /**
     * Returns the Frontier's size
     */
    virtual const unsigned long int size() const = 0;
};

#endif //SV_NETWORK_FRONTIER_H
