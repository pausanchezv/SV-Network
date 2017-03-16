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


#ifndef GRAPHS_EXCEPTIONS_H
#define GRAPHS_EXCEPTIONS_H

#include <cstdlib>
#include <exception>
#include <string>
#include "../util/Functions.h"

/**
 * Base Exception Class
 */
class SV_Exception : public exception {

protected:

    string msg;

public:

    SV_Exception(string in) : msg(in) {}

    virtual const char * what() const throw() {
        return msg.c_str();
    }
};



/**
 * Node Error Handler
 */
template <class TNode> class NodeError : public SV_Exception {

public:

    NodeError(const TNode &id)
        : SV_Exception(string("Node " + Functions::getString(id) + " is not in the graph!\n"))
    {}
};

/**
 * Edge Error Handler
 */
template <class TNode> class EdgeError : public SV_Exception {

public:

    EdgeError(const TNode &SiD, const TNode &ViD)
        : SV_Exception(string("\nEdge (" + Functions::getString(SiD) +", " + Functions::getString(ViD) + ") is not in the graph!\n"))
    {}
};

/**
 * Key Error Handler
 */
class KeyError : public SV_Exception {

public:

    KeyError(const string &key)
        : SV_Exception(string("\nAttribute '" + key + "' is not in attributes!\n"))
    {}
};

/**
 * Conversion Error Handler
 */
class ConversionError : public SV_Exception {

public:

    ConversionError(const string &key)
        : SV_Exception(string("\nThe '" + key + "' attribute can't be converted to the desired type!\n"))
    {}
};

/**
 * Heap Error Handler
 */
class IndexError : public SV_Exception {

public:

    IndexError(string type)
        : SV_Exception(string("\n" + type + " index out of range!\n"))
    {}
};

/**
 * Heap Error Handler
 */
class HeapTypeError : public SV_Exception {

public:

    HeapTypeError()
            : SV_Exception(string("\nThe heap can only be created with Node or Edge objects!\n"))
    {}
};

/**
 * Kruskal Error Handler
 */
class MSTError : public SV_Exception {

public:

    MSTError()
            : SV_Exception(string("\nCan't be obtained the 'Spanning Tree' tree because the graph is not connected!\n"))
    {}
};

/**
 * MST Error Handler
 */
class MstError : public SV_Exception {

public:

    MstError()
            : SV_Exception(string("\nMST in a directed graphs is not yet available. We are working hard on future upgraded versions!\n"))
    {}
};

/**
 * Kruskal Error Handler
 */
class DijkstraError : public SV_Exception {

public:

    DijkstraError()
            : SV_Exception(string("\nCan't be obtained Dijkstra paths because the graph is not connected!\n"))
    {}
};

/**
 * IO Error Handler
 */
class IOError : public SV_Exception {

public:

    IOError(unsigned long expectedCols, unsigned long currentCols)
            : SV_Exception(string("\nError reading file graph! " + to_string(expectedCols) + " columns are expected in the file but there are " + to_string(currentCols) + "!\n"))
    {}
};

/**
 * File Error Handler
 */
class IOFileError : public SV_Exception {

public:

    IOFileError(const string file)
            : SV_Exception(string("\nThe file '" + file + "' does not exist!\n"))
    {}
};

/**
 * Kruskal Error Handler
 */
class AStarError : public SV_Exception {

public:

    AStarError()
            : SV_Exception(string("\nA negative cost was encountered while executing AStar Search Algorithm!\n"))
    {}
};

/**
 * Kruskal Error Handler
 */
class UCSError : public SV_Exception {

public:

    UCSError()
            : SV_Exception(string("\nA negative cost was encountered while executing Uniform Cost Search Algorithm!\n"))
    {}
};

/**
 * Kruskal Error Handler
 */
class DijkstraErrorN : public SV_Exception {

public:

    DijkstraErrorN()
            : SV_Exception(string("\nA negative weight was encountered while executing Dijkstra Algorithm!\n"))
    {}
};

/**
 * Diameter Error Handler
 */
class DiameterError : public SV_Exception {

public:

    DiameterError()
            : SV_Exception(string("\nCan't compute the diameter of an unconnected graph!\n"))
    {}
};

/**
 * Radius Error Handler
 */
class RadiusError : public SV_Exception {

public:

    RadiusError()
            : SV_Exception(string("\nCan't compute the radius of an unconnected graph!\n"))
    {}
};

/**
 * CenterError Handler
 */
class CenterError : public SV_Exception {

public:

    CenterError()
            : SV_Exception(string("\nCan't compute the center of an unconnected graph!\n"))
    {}
};

/**
 * EulerError Handler
 */
class EulerError : public SV_Exception {

public:

    EulerError()
            : SV_Exception(string("\nCan't compute 'Euler' of an unconnected graph!\n"))
    {}
};

/**
 * EulerError Handler
 */
class PeripheryError : public SV_Exception {

public:

    PeripheryError()
            : SV_Exception(string("\nCan't compute the periphery of an unconnected graph!\n"))
    {}
};

/**
 * EulerError Handler
 */
class TransposeGraphError : public SV_Exception {

public:

    TransposeGraphError()
            : SV_Exception(string("\nIt doesn't make sense to transpose an undirected graph. Try a directed graph!\n"))
    {}
};


#endif //GRAPHS_EXCEPTIONS_H
