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

#ifndef SV_NETWORK_NODE_H
#define SV_NETWORK_NODE_H


#include <algorithm>
#include "Data.h"

//Forward ObjArray declaration
template <class TNode>  class ObjArray;

//Forward Graph declaration
template <class TNode>  class Graph;

//Forward Graph declaration
template <class TNode>  class DiGraph;

//Forward ObjArray declaration
template <class TNode>  class NodeArray;

/**
 * Class Node
 *
 * This class contains the specific methods and attributes of the nodes
 */
template <class TNode> class Node : public Data{

    //Friend class Graph can use <Node>'s private methods
    friend class Graph<TNode>;
    friend class DiGraph<TNode>;


    //Node ID
    TNode _id;

    //Neighbors of node
    NodeArray<Node<TNode> *> _neighbors; //out-links in directed graphs

    //InLinks of node
    NodeArray<Node<TNode> *> _inLinks;


    /**
     * Add a neighbor to node
     */
    const void _addNeighbor(Node<TNode> *);

    /**
     * Add an inLink to node
     */
    const void _addInLink(Node<TNode> *);

    /**
     * Add an outLink to node
     */
    const void _addOutLink(Node<TNode> *);

    /**
     * Remove a neighbor from node
     */
    const void _removeNeighbor(Node<TNode> *);

    /**
     * Remove an inLink from node
     */
    const void _removeInLink(Node<TNode> *);

    /**
     * Remove aa inLink from node
     */
    const void _removeOutLink(Node<TNode> *);


public:

    /**
     * Node Constructor
     */
    Node(TNode);

    /**
     * Returns node's ID
     * Each node of the graph has a unique identifier to describes it
     */
    TNode id() const;

    /**
     * Returns the vector of neighbors
     */
    const NodeArray<Node<TNode> *> &neighbors() const;

    /**
     * Returns the vector of inLinks
     */
    const NodeArray<Node<TNode> *> &inLinks() const;

    /**
     * Returns the vector of outLinks
     */
    const NodeArray<Node<TNode> *> &outLinks() const;

    /**
     * Operator Node. Used to print the node on the screen.
     */
    friend ostream &operator << (ostream &stream, const Node<TNode> *node) {

        map<string, string> attrs = node->attrs();
        string str ="";

        for (map<string, string>::iterator it=attrs.begin(); it!=attrs.end(); it++)
            str += "'" + it->first + "': " + it->second + ", ";

        str = attrs.size() ? str.substr(0, str.length() - 2) + "}" : str + "}";
        return stream  << node->id() << ": {" + str;
    }

    /**
     * Degree of node
     *
     * The degree of a node is the number of edges connecting it, i.e. the number of adjacent nodes. Loops are counted
     * double, i.e. every occurrence of nodes in the list of adjacent nodes.
     */
    const unsigned long degree() const;
    const unsigned long inDegree() const;
    const unsigned long outDegree() const;

    /**
     * Returns whether node is isolated or not.
     * A node is isolated when it hasn't any neighbor
     */
    const bool isIsolated() const;

    /**
     * Adds an attribute to the node
     */
    template <typename T> Node<TNode> *add(string, T);

};


/**
 * Add a neighbor to node
 */
template <typename TNode> const void Node<TNode>::_addNeighbor(Node<TNode> * neighbor) {
    if (find(_neighbors.begin(), _neighbors.end(), neighbor) == _neighbors.end())
        _neighbors.push_back(neighbor);
}

/**
 * Add an inLink to node
 */
template <typename TNode> const void Node<TNode>::_addInLink(Node<TNode> * neighbor) {
    if (find(_inLinks.begin(), _inLinks.end(), neighbor) == _inLinks.end())
        _inLinks.push_back(neighbor);
}

/**
 * Add an outLink to node
 */
template <typename TNode> const void Node<TNode>::_addOutLink(Node<TNode> * neighbor) {
    if (find(_neighbors.begin(), _neighbors.end(), neighbor) == _neighbors.end())
        _neighbors.push_back(neighbor);
}

/**
 * Remove a neighbor from node
 */
template <typename TNode> const void Node<TNode>::_removeNeighbor(Node<TNode> * node) {
    _neighbors.erase(remove(_neighbors.begin(), _neighbors.end(), node), _neighbors.end());
}

/**
 * Remove aninLink from node
 */
template <typename TNode> const void Node<TNode>::_removeInLink(Node<TNode> * node) {
    _inLinks.erase(remove(_inLinks.begin(), _inLinks.end(), node), _inLinks.end());
}

/**
 * Remove an outLink from node
 */
template <typename TNode> const void Node<TNode>::_removeOutLink(Node<TNode> * node) {
    _neighbors.erase(remove(_neighbors.begin(), _neighbors.end(), node), _neighbors.end());
}

/**
 * Node Constructor
 */
template <typename TNode> Node<TNode>::Node(TNode id) : _id(id) {}

/**
 * Returns node's ID
 */
template <typename TNode> TNode Node<TNode>::id() const  {
    return _id;
}

/**
 * Returns node's neighbors
 */
template <typename TNode> const NodeArray<Node<TNode> *> &Node<TNode>::neighbors() const {
    return _neighbors;
}

/**
 * Returns node's inLinks
 */
template <typename TNode> const NodeArray<Node<TNode> *> &Node<TNode>::inLinks() const {
    return _inLinks;
}

/**
 * Returns node's outLinks
 */
template <typename TNode> const NodeArray<Node<TNode> *> &Node<TNode>::outLinks() const {
    return _neighbors;
}

/**
 * Degree of node
 */
template <typename TNode> const unsigned long Node<TNode>::degree() const {
    return neighbors().size();
}

/**
 * Degree of node
 */
template <typename TNode> const unsigned long Node<TNode>::inDegree() const {
    return _inLinks.size();
}

/**
 * Degree of node
 */
template <typename TNode> const unsigned long Node<TNode>::outDegree() const {
    return degree();
}

/**
 * Returns whether node is isolated or not
 */
template <typename TNode> const bool Node<TNode>::isIsolated() const {
    return !degree();
}

/**
 * Adds an attribute to the node
 */
template <typename TNode> template <typename T> Node<TNode> *Node<TNode>::add(string key, T value) {
    Data::_add(key, value);
    return this;
}

#endif //SV_NETWORK_NODE_H
