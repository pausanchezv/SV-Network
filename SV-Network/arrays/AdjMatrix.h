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

#ifndef SV_NETWORK_ADJMATRIX_H
#define SV_NETWORK_ADJMATRIX_H

#include <sstream>
#include <vector>

using namespace std;

/**
 * Class AdjMatrix
 *
 * Wrapper to print matrix
 */
class AdjMatrix : public vector<vector<bool>> {

public:

    /**
     * Operator ObjArray
     */
    friend ostream &operator << (ostream &stream, const AdjMatrix matrix) {

        for (vector<bool> row : matrix) {
            for (bool col : row) {
                stream << col << " ";
            }
            stream << endl;
        }
        return stream;
    }
};

#endif //SV_NETWORK_ADJMATRIX_H
