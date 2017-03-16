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

#ifndef SV_NETWORK_MAPARRAY_H
#define SV_NETWORK_MAPARRAY_H

#include <sstream>
#include <map>

using namespace std;

/**
 * Class MapArray
 *
 * Wrapper to print hast tables with pairs key-value
 */
template <typename TKey, typename TValue> class MapArray : public map<TKey, TValue> {

public:

    /**
     * Operator ObjArray
     */
    friend ostream &operator << (ostream &stream, MapArray<TKey, TValue> array) {

        stream << "{";

        unsigned int cont = 0;

        for (pair<TKey, TValue> obj : array) {
            stream << obj.first + ": " + obj.second;

            if (++cont < array.size()) {
                stream << ", ";
            }
        }

        return stream  <<  "}";
    }
};

#endif //SV_NETWORK_MAPARRAY_H
