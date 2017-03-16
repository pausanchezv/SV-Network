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

#ifndef SV_NETWORK_DIGRAPH_H
#define SV_NETWORK_DIGRAPH_H

#include "Graph.h"

template <class TNode> class DiGraph: public Graph<TNode> {

    /**
     * Find and return (if any) the edge, otherwise returns nullptr
     */
    Edge<TNode> *_findEdge(TNode, TNode) const;

    /**
     * Add edge to graph
     */
    Edge<TNode> *_addEdge(TNode, TNode, string, double);


public:

    /**
     * Graph Constructor
     */
    DiGraph();

    /**
     * Add edge to graph
     */
    virtual Edge<TNode> *addEdge(TNode, TNode);

    /**
     * Add edge to graph with an attribute
     */
    virtual Edge<TNode> *addEdge(TNode, TNode, string, double);

    /**
     * Removes the edge that connects the nodes S & D
     */
    virtual void removeEdge(TNode, TNode);

    /**
     * Obtain transposed graph
     */
    void transpose();

    /**
     * Remove a node of graph
     */
    void removeNode(TNode);

};


/**
 * Remove a node of the graph (Also deletes the edges connected to this node)
 */
template <typename TNode> void DiGraph<TNode>::removeNode(TNode id) {

    Node<TNode> * node = this->_findNode(id);

    if (node) {

        vector<Node<TNode> *> tempNeighbors = Functions::makeArrayCopy(this->neighbors(id));

        for (Node<TNode> * neighbor : tempNeighbors) {
            removeEdge(node->id(), neighbor->id());
        }
        transpose();

        tempNeighbors = Functions::makeArrayCopy(this->neighbors(id));

        for (Node<TNode> * neighbor : tempNeighbors) {
            removeEdge(node->id(), neighbor->id());
        }
        transpose();

        Functions::removeItem(&this->_nodes, node);
        delete node;
    }
}

template <typename TNode> DiGraph<TNode>::DiGraph() {
    this->_isDirected = true;
}

/**
 * Find and return (if any) the edge, otherwise returns nullptr
 */
template <typename TNode> Edge<TNode> *DiGraph<TNode>::_findEdge(TNode SiD, TNode ViD) const {

    for (Edge<TNode> * edge : this->_edges) {

        TNode iSiD = edge->getNode_S()->id();
        TNode iViD = edge->getNode_V()->id();

        if ((iSiD == SiD && iViD == ViD)) {
            return edge;
        }
    }
    return nullptr;
}

/**
 * Add edge to graph
 */
template <typename TNode> Edge<TNode> *DiGraph<TNode>::_addEdge(TNode SiD, TNode ViD, string key, double value) {

    Edge<TNode> *edge = _findEdge(SiD, ViD);

    if (!edge) {

        Node<TNode> *SNode = this->_findNode(SiD);
        Node<TNode> *VNode = this->_findNode(ViD);

        //Is a normal edge
        if (SiD != ViD) {

            if (!SNode) {
                SNode = new Node<TNode>(SiD);
                this->_nodes.push_back(SNode);
            }

            if (!VNode) {
                VNode = new Node<TNode>(ViD);
                this->_nodes.push_back(VNode);
            }

            //Is an auto edge
        } else {

            if (!SNode) {
                SNode = new Node<TNode>(SiD);
                this->_nodes.push_back(SNode);
            }

            VNode = SNode;
        }

        SNode->_addOutLink(VNode);
        VNode->_addInLink(SNode);

        edge = new Edge<TNode>(SNode, VNode);

        if (key.compare("") != 0) {
            edge->add(key, value);
        }
        this->_edges.push_back(edge);
    }

    return edge;
}

/**
 * Add edge to graph
 */
template <typename TNode> Edge<TNode> *DiGraph<TNode>::addEdge(TNode SiD, TNode ViD)  {
    return _addEdge(SiD, ViD, "", 0);
}

/**
 * Add edge to graph with an attribute
 */
template <typename TNode> Edge<TNode> *DiGraph<TNode>::addEdge(TNode SiD, TNode ViD, string key, double value) {
    return _addEdge(SiD, ViD, key, value);
}

/**
 *  Removes the edge that connects the nodes black & white
 */
template <typename TNode> void DiGraph<TNode>::removeEdge(TNode SiD, TNode ViD) {

    Edge<TNode> * edge = _findEdge(SiD, ViD);

    if (edge) {

        this->_findNode(SiD)->_removeOutLink(this->_findNode(ViD));
        this->_findNode(ViD)->_removeInLink(this->_findNode(SiD));

        Functions::removeItem(&this->_edges, edge);
        delete edge;
    }
}

/**
 * Graph to transposed
 */
template <typename TNode> void DiGraph<TNode>::transpose() {

    for (Edge<TNode> *edge : this->_edges) {

        if (!_findEdge(edge->getNode_V()->id(), edge->getNode_S()->id())) {

            edge->swap();

            if (Functions::contains(edge->getNode_S()->neighbors(), edge->getNode_V())) {
                edge->getNode_S()->_removeNeighbor(edge->getNode_V());
                edge->getNode_V()->_addNeighbor(edge->getNode_S());
            }

            if (Functions::contains(edge->getNode_V()->neighbors(), edge->getNode_S())) {
                edge->getNode_V()->_removeNeighbor(edge->getNode_S());
                edge->getNode_S()->_addNeighbor(edge->getNode_V());
            }
        }
    }
}


#endif //SV_NETWORK_DIGRAPH_H
