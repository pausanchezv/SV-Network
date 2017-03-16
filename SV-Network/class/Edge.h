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

#ifndef SV_NETWORK_EDGE_H
#define SV_NETWORK_EDGE_H

#include "Node.h"

/**
 * Class Edge
 *
 * This class contains the specific methods and attributes of the edges
 */
template <class TNode> class Edge : public Data{

    //Both nodes of the edge
    Node<TNode> *_SNode;
    Node<TNode> *_VNode;


public:

    /**
     * Returns S node's adress
     */
    Node<TNode> * getNode_S() const;

    /**
     * Returns V node's adress
     */
    Node<TNode> * getNode_V() const;

    /**
     * Edge Constructor
     */
    Edge<TNode>(Node<TNode> *, Node<TNode> *);

    /**
     * Check whether edge contains this node
     */
    bool contains(Node<TNode> *) const;

    /**
     * Returns the other edge node
     */
    const Node<TNode> * neighbor(Node<TNode> *);

    /**
     * Adds an attribute to the edge
     */
    template <typename T> Edge<TNode> *add(string, T);

    /**
     * Swap nodes of edge
     */
    void swap();

    /**
     * Edge to String
     */
    friend ostream &operator << (ostream &strm, const Edge<TNode> * edge) {

        map<string, string> attrs = edge->attrs();
        string str = "";

        for (map<string, string>::iterator it=attrs.begin(); it!=attrs.end(); it++)
            str += "'" +  it->first + "': " + it->second + ", ";

        str = attrs.size() ? str.substr(0, str.length() - 2) + "}" : str + "}";
        return strm << "(" << edge->getNode_S()->id() << ", " << edge->getNode_V()->id() << "): {" + str;
    }

};

/**
 * Edge Constructor
 */
template <class TNode> Edge<TNode>::Edge(Node<TNode> * SNode, Node<TNode> * VNode) {
    _SNode = SNode;
    _VNode = VNode;
}


/**
 * Swap nodes of edge
 */
template <class TNode> void Edge<TNode>::swap() {
    Node<TNode> *temp;
    temp = _SNode;
    _SNode = _VNode;
    _VNode = temp;
}

/**
 * Returns the 'S' node's adress
 */
template <class TNode> Node<TNode> *Edge<TNode>::getNode_S() const {
    return _SNode;
}

/**
 * Returns the 'V' node's adress
 */
template <class TNode> Node<TNode> *Edge<TNode>::getNode_V() const {
    return _VNode;
}

/**
 * Check whether edge contains this node
 */
template <class TNode> bool Edge<TNode>::contains(Node<TNode> * node) const {
    return _SNode == node || _VNode == node;
}

/**
 * Returns the other edge node
 */
template <class TNode> const Node<TNode> *Edge<TNode>::neighbor(Node<TNode> * node) {
    return node == _SNode ? _VNode : _SNode;
}

/**
 * Adds an attribute to the node
 */
template <typename TNode> template <typename T> Edge<TNode> *Edge<TNode>::add(string key, T value) {
    Data::_add(key, value);
    return this;
}


#endif //SV_NETWORK_EDGE_H
