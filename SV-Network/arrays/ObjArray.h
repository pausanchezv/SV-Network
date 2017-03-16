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

#ifndef SV_NETWORK_NODEARRAY_H
#define SV_NETWORK_NODEARRAY_H

#include <sstream>
#include <vector>

using namespace std;

/**
 * Class ObjArray
 *
 * Wrapper to print nodes or edges with all their attributes
 */
template <class TNode> class ObjArray : public vector<TNode> {

public:

    /**
     * Operator ObjArray
     */
    friend ostream &operator << (ostream &stream, const ObjArray array) {

        stream << "{";

        for (TNode obj : array) {
            stream << obj;
            if (obj != array.back())
                stream << ", ";
        }
        return stream  <<  "}";
    }
};

#endif //SV_NETWORK_NODEARRAY_H
