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

#ifndef SV_NETWORK_KRUSKAL_H
#define SV_NETWORK_KRUSKAL_H

#include "../util/Heap.h"

/**
 * Class Kruskal
 *
 * The Kruskal algorithm return the Minumum Spanning Tree of a connected Graph.
 * To return the Maximum Spanning Tree it's only necessary complement the weight attribute value.
 */
class Kruskal {


    /**
     * Initialize a node
     */
    template <typename TNode> static void _makeSet(Node<TNode> *node);

    /**
     * Look for the node until it's the same as the parent
     */
    template <typename TNode> static Node<TNode> *_find(Graph<TNode> *G, Node<TNode> *node);

    /**
     * This is the 'union' function but 'union' is a reserved word in c++, so now this
     * function is called 'fusion'
     */
    template <typename TNode> static void _fusion(Graph<TNode> *G, Node<TNode> *x, Node<TNode> *y);

    /**
     * Reverse value of attribute
     */
    template <typename TNode> static void _reverseValues(Graph<TNode> *, string);

public:

    /**
     * Kruskal Algorithm
     * Adds the minimum edge while the graph is'n connected
     */
    template <typename TNode> static Graph<TNode> *kruskal(Graph<TNode> *G, string attr, bool);
};

/**
 * Initialize a node
 */
template<typename TNode> void Kruskal::_makeSet(Node<TNode> *node)  {

    node->add("sv_kruskal_parent", node->id());
    node->add("sv_kruskal_rank", 0);
}

/**
 * Look for the node until it's the same as the parent
 */
template<typename TNode> Node<TNode> *Kruskal::_find(Graph<TNode> *G, Node<TNode> *node) {

    while (node->id() != node->get<TNode>("sv_kruskal_parent"))
        node = G->node(node->get<TNode>("sv_kruskal_parent"));
    return node;
}

/**
 * This is the 'union' function but 'union' is a reserved word in c++, so now this
 * function is called 'fusion'
 */
template<typename TNode> void Kruskal::_fusion(Graph<TNode> *G, Node<TNode> *x, Node<TNode> *y) {

    //Find the nodes x and y
    Node<TNode> *fX = _find(G, x);
    Node<TNode> *fY = _find(G, y);

    if (fX != fY) {

        //Update the parent if clause is certain
        if (fX->get<double>("sv_kruskal_rank") > fY->get<double>("sv_kruskal_rank")) {
            fY->set("sv_kruskal_parent", fX->id());
        }

        else {
            fX->set("sv_kruskal_parent", fY->id());

            if (fX->get<double>("sv_kruskal_rank") == fY->get<double>("sv_kruskal_rank")) {
                fY->set("sv_kruskal_rank", fY->get<double>("sv_kruskal_rank") + 1);
            }
        }
    }
}

/**
 * Kruskal Algorithm
 * Adds the minimum edge while the graph is'n connected
 */
template<typename TNode> Graph<TNode> *Kruskal::kruskal(Graph<TNode> *G, string attr, bool reverse) {

    //Can't be obtained MST if graph is not connected
    if (!Properties::isConnected(G)) {
        return new Graph<TNode>();
    }

    //Only is called whether is Maximum Spanning Tree
    if (reverse) {
        _reverseValues(G, attr);
    }

    //Initialize all nodes oh the graph
    for (Node<TNode> *node : G->nodes()) {
        _makeSet(node);
    }

    //Create an empty graph for using as a mst
    Graph<TNode> *mst = new Graph<TNode>();
    mst->addNodesFrom(G->nodes());

    //Create a heap with the edges of the graph
    Heap<Edge<TNode> *> *heap = new Heap<Edge<TNode> *>(attr);
    heap->heapify(G->edges());

    while (!Properties::isConnected(mst)) {

        //The current edge is the priority element of the heap
        Edge<TNode> *edge = heap->heapPop();

        //Add edge to the mst and call fusion function
        if (_find(G, edge->getNode_S()) != _find(G, edge->getNode_V())) {
            mst->addEdge(edge->getNode_S()->id(), edge->getNode_V()->id());
            _fusion(G, edge->getNode_S(), edge->getNode_V());
        }
    }

    //Only is called whether is Maximum Spanning Tree
    if (reverse) {
        _reverseValues(G, attr);
    }

    delete heap;
    return mst;
}

/**
 * Reverse value of attribute
 */
template<typename TNode> void Kruskal::_reverseValues(Graph<TNode> * G, string attr) {

    //Complement the values
    for (Edge<TNode> *edge : G->edges()) {
        edge->set(attr, - edge->get<double>(attr));
    }
}


#endif //SV_NETWORK_KRUSKAL_H
