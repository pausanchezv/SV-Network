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

#ifndef SV_NETWORK_NODEPATHARRAY_H
#define SV_NETWORK_NODEPATHARRAY_H

#include <sstream>
#include <vector>

using namespace std;

/**
 * Class NodeArray
 *
 * Wrapper no print array of nodes
 */
template <class TNode> class NodeArray : public vector<TNode> {

public:

    /**
     * Operator NodeArray
     */
    friend ostream &operator << (ostream &stream, const NodeArray array) {

        stream << "[";

        for (TNode obj : array) {
            stream << obj->id();
            if (obj != array.back())
                stream << ", ";
        }
        return stream  <<  "]";
    }
};


#endif //SV_NETWORK_NODEPATHARRAY_H
