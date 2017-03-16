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

#ifndef SV_NETWORK_EDGEARRAY_H
#define SV_NETWORK_EDGEARRAY_H

#include <sstream>
#include <vector>

using namespace std;

/**
 * Class EdgeArray
 *
 * Wrapper to print array of edges
 */
template <class TNode> class EdgeArray : public vector<TNode> {

public:

    /**
     * Operator ObjArray
     */
    friend ostream &operator << (ostream &stream, const EdgeArray array) {

        stream << "[";

        for (TNode obj : array) {
            stream << "(" << obj->getNode_S()->id() << ", " << obj->getNode_V()->id() << ")";
            if (obj != array.back())
                stream << ", ";
        }
        return stream  <<  "]";
    }
};


#endif //SV_NETWORK_EDGEARRAY_H
