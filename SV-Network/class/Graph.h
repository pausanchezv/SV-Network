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

#ifndef SV_NETWORK_GRAPH_H
#define SV_NETWORK_GRAPH_H

#include "Edge.h"

#include "../arrays/ObjArray.h"
#include "../arrays/NodeArray.h"
#include "../arrays/EdgeArray.h"

#include "../algorithms/UniformCostSearch.h"
#include "../algorithms/AstarSearch.h"
#include "../algorithms/Dijkstra.h"
#include "../algorithms/Properties.h"
#include "../algorithms/Kruskal.h"
#include "../algorithms/BreadthFirstSearch.h"
#include "../algorithms/DepthFirstSearch.h"
#include "../algorithms/Heuristic.h"
#include "../algorithms/BacktrackingMST.h"

/**
 * Class Graph
 */
template <class TNode> class Graph {

protected:

    //Indicates whether the graph is directed or not
    bool _isDirected;

    //Graph's nodes
    NodeArray<Node<TNode> *> _nodes;

    //Graph's edges
    EdgeArray<Edge<TNode> *> _edges;

    /**
     * Find and return (if any) the node, otherwise returns nullptr
     */
    Node<TNode> * _findNode(TNode) const;

    /**
     * Find and return (if any) the edge, otherwise returns nullptr
     */
    virtual Edge<TNode> *_findEdge(TNode, TNode) const;

    /**
     * Add edge to graph
     */
    virtual Edge<TNode> *_addEdge(TNode, TNode, string, double);


public:

    /**
     * Graph Constructor
     */
    Graph();

    /**
     * Graph Destructor
     */
    virtual ~Graph();

    /**
     * Removes all nodes and all edges from the Graph
     */
    void clear();

    /**
     * Returns the node
     */
    Node<TNode> *node(TNode);

    /**
     * Adds an node to the graph (Support method)
     */
    Node<TNode> *addNode(TNode);

    /**
     * Returns graph's nodes
     */
    const NodeArray<Node<TNode> *> &nodes() const;

    /**
     * Returns graph size
     */
    const unsigned long numberOfNodes() const;

    /**
     * Remove a node of the graph (Also deletes the edges connected to this node)
     */
    virtual void removeNode(TNode);

    /**
     * Returns the edge
     */
    Edge<TNode> *edge(TNode, TNode);

    /**
     * Add edge to graph
     */
    virtual Edge<TNode> *addEdge(TNode, TNode);

    /**
     * Add edge to graph
     */
    virtual Edge<TNode> *addEdge(TNode, TNode, string, double);

    /**
     * Returns graph's nodes
     */
    const EdgeArray<Edge<TNode> *> &edges() const;

    /**
     * Returns graph size
     */
    const unsigned long numberOfEdges() const;

    /**
     * Removes the edge that connects the nodes S & D
     */
    virtual void removeEdge(TNode, TNode);

    /**
     * Returns the neighbors of node
     */
    const NodeArray<Node<TNode> *> &neighbors(TNode) const;

    /**
     * Removes attribute from nodes
     */
    void removeNodeAttributes(string);

    /**
     * Removes attribute from edges
     */
    void removeEdgeAttributes(string);

    /**
     * Removes attribute from nodes
     */
    void renameNodeAttributes(string, string);

    /**
     * Removes attribute from edges
     */
    void renameEdgeAttributes(string, string);

    /**
     * Set attributes from nodes
     */
    template <typename T> void setNodeAttributes(string, T);

    /**
     * Set attributes from edges
     */
    template <typename T> void setEdgeAttributes(string, T);

    /**
     * Add attribute from nodes
     */
    template <typename T> void addNodeAttributes(string, T);

    /**
     * Add attribute from edges
     */
    template <typename T> void addEdgeAttributes(string, T);

    /**
     * Add nodes from vector
     */
    template <typename T> void addNodesFrom(const vector<T>);

    /**
     * Check whether node is in the graph
     */
    const bool hasNode(TNode) const;

    /**
     * Check whether edge is in the graph
     */
    const bool hasEdge(TNode, TNode) const;

    /**
     * Check whether the graph is directed or not
     */
    const bool &isDirected() const;

    /**
     * Graph Operator
     */
    friend ostream &operator<<(ostream &strm, const Graph *graph)  {
        return strm << "{" + to_string(graph->numberOfNodes()) << " nodes, " << to_string(graph->numberOfEdges()) << " edges}";
    }

    /**
     * Transpose the graph
     */
    virtual void transpose();

    /**
     * Returns the weight of the graph
     */
    const double weight(string);

};




/**
 * Find and return (if any) the node, otherwise returns nullptr
 */
template <typename TNode>  Node<TNode> * Graph<TNode>::_findNode(TNode id) const {
    for (Node<TNode> * node: _nodes) {
        if (node->id() == id) {
            return node;
        }
    }
    return nullptr;
}

/**
 * Find and return (if any) the edge, otherwise returns nullptr
 */
template <typename TNode> Edge<TNode> *Graph<TNode>::_findEdge(TNode SiD, TNode ViD) const {

    for (Edge<TNode> * edge : _edges) {

        TNode iSiD = edge->getNode_S()->id();
        TNode iViD = edge->getNode_V()->id();

        if ((iSiD == SiD && iViD == ViD) || (iSiD == ViD && iViD == SiD)) {
            return edge;
        }
    }
    return nullptr;
}

/**
 * Add edge to graph
 */
template <typename TNode> Edge<TNode> *Graph<TNode>::_addEdge(TNode SiD, TNode ViD, string key, double value) {

    Edge<TNode> *edge = _findEdge(SiD, ViD);

    if (!edge) {

        Node<TNode> *SNode = _findNode(SiD);
        Node<TNode> *VNode = _findNode(ViD);

        //Is a normal edge
        if (SiD != ViD) {

            if (!SNode) {
                SNode = new Node<TNode>(SiD);
                _nodes.push_back(SNode);
            }

            if (!VNode) {
                VNode = new Node<TNode>(ViD);
                _nodes.push_back(VNode);
            }

        //Is an auto edge
        } else {

            if (!SNode) {
                SNode = new Node<TNode>(SiD);
                _nodes.push_back(SNode);
            }

            VNode = SNode;
        }

        VNode->_addNeighbor(SNode);
        SNode->_addNeighbor(VNode);

        edge = new Edge<TNode>(SNode, VNode);

        if (key.compare("") != 0) {
            edge->add(key, value);
        }
        _edges.push_back(edge);
    }

    return edge;
}

/****** PUBLIC METHODS ******/

/**
 * Graph Constructor
 */
template <typename TNode> Graph<TNode>::Graph() : _isDirected(false) {}

/**
 * Graph Destructor
 */
template <typename TNode> Graph<TNode>::~Graph() {
    clear();
}

/**
 * Removes all nodes and all edges from the Graph
 */
template <typename TNode> void Graph<TNode>::clear() {
    for (Node<TNode> * node : _nodes) {
        delete node;
    }
    _nodes.clear();

    for (Edge<TNode> * edge : _edges) {
        delete edge;
    }
    _edges.clear();
}

/**
 * Returns the node
 */
template <typename TNode> Node<TNode> *Graph<TNode>::node(TNode id) {

    Node<TNode> * node = _findNode(id);

    if (!node) {
        clear();
        throw NodeError<TNode>(id);
    }
    return node;
}

/**
 * Adds an node to the graph (Support method)
 */
template <typename TNode> Node<TNode> *Graph<TNode>::addNode(TNode id) {

    Node<TNode> *node = _findNode(id);

    if (!node) {
        node = new Node<TNode>(id);
        _nodes.push_back(node);
    }

    return node;
}

/**
 * Returns graph's nodes
 */
template <typename TNode> const NodeArray<Node<TNode> *> &Graph<TNode>::nodes() const {
    return _nodes;
}

/**
 * Returns graph size
 */
template <typename TNode> const unsigned long Graph<TNode>::numberOfNodes() const {
    return _nodes.size();
}

/**
 * Add edge to graph
 */
template <typename TNode> Edge<TNode> *Graph<TNode>::addEdge(TNode SiD, TNode ViD)  {
    return _addEdge(SiD, ViD, "", 0);
}

/**
 * Add edge to graph
 */
template <typename TNode> Edge<TNode> *Graph<TNode>::addEdge(TNode SiD, TNode ViD, string key, double value) {
    return _addEdge(SiD, ViD, key, value);
}

/**
 * Returns the edge
 */
template <typename TNode> Edge<TNode> *Graph<TNode>::edge(TNode SiD, TNode ViD) {

    Edge<TNode> * edge = _findEdge(SiD, ViD);

    if (!edge) {
        clear();
        throw EdgeError<TNode>(SiD, ViD);
    }
    return edge;
}

/**
 * Returns graph's nodes
 */
template <typename TNode> const EdgeArray<Edge<TNode> *> &Graph<TNode>::edges() const {
    return _edges;
}

/**
 * Returns graph size
 */
template <typename TNode> const unsigned long Graph<TNode>::numberOfEdges() const {
    return _edges.size();
}

/**
 * Remove a node of the graph (Also deletes the edges connected to this node)
 */
template <typename TNode> void Graph<TNode>::removeNode(TNode id) {

    Node<TNode> * node = _findNode(id);

    if (node) {

        const vector<Node<TNode> *> tempNeighbors = Functions::makeArrayCopy(neighbors(id));

        for (Node<TNode> * neighbor : tempNeighbors) {
            removeEdge(node->id(), neighbor->id());
        }

        Functions::removeItem(&_nodes, node);
        delete node;
    }
}

/**
 *  Removes the edge that connects the nodes black & white
 */
template <typename TNode> void Graph<TNode>::removeEdge(TNode SiD, TNode ViD) {

    Edge<TNode> * edge = _findEdge(SiD, ViD);

    if (edge) {

        _findNode(SiD)->_removeNeighbor(_findNode(ViD));
        _findNode(ViD)->_removeNeighbor(_findNode(SiD));

        Functions::removeItem(&_edges, edge);
        delete edge;
    }
}

/**
 * Returns the neighbors of node
 */
template <typename TNode> const NodeArray<Node<TNode> *> &Graph<TNode>::neighbors(TNode id) const {
    Node<TNode> * node = _findNode(id);
    return node->neighbors();
}

/**
 * Remove attribute from nodes
 */
template <typename TNode> void Graph<TNode>::removeNodeAttributes(string key) {
    for (Node<TNode> * obj : _nodes)
        obj->removeAttr(key);
}

/**
 * Remove attribute from edges
 */
template <typename TNode>  void Graph<TNode>::removeEdgeAttributes(string key) {
    for (Edge<TNode> * obj : _edges)
        obj->removeAttr(key);
}

/**
 * Rename attribute from nodes
 */
template <typename TNode>  void Graph<TNode>::renameNodeAttributes(string oldKey, string newKey) {
    for (Node<TNode> * obj : _nodes)
        obj->rename(oldKey, newKey);
}

/**
 * Rename attribute from edges
 */
template <typename TNode>  void Graph<TNode>::renameEdgeAttributes(string oldKey, string newKey) {
    for (Edge<TNode> * obj : _edges)
        obj->rename(oldKey, newKey);
}

/**
 * Set attributes from nodes
 */
template <typename TNode> template <typename T> void Graph<TNode>::setNodeAttributes(string key, T value) {
    for (Node<TNode> * obj : _nodes)
        obj->set(key, value);
}

/**
 * Set attributes from edges
 */
template <typename TNode> template <typename T> void Graph<TNode>::setEdgeAttributes(string key, T value) {
    for (Edge<TNode> * obj : _edges)
        obj->set(key, value);
}

/**
 * Add attribute from nodes
 */
template <typename TNode> template <typename T> void Graph<TNode>::addNodeAttributes(string key, T value) {
    for (Node<TNode> * obj : _nodes)
        obj->add(key, value);
}

/**
 * Add attribute from edges
 */
template <typename TNode> template <typename T> void Graph<TNode>::addEdgeAttributes(string key, T value) {
    for (Edge<TNode> * obj : _edges)
        obj->add(key, value);
}

/**
 * Add nodes from vector
 */
template <typename TNode> template <typename T> void Graph<TNode>::addNodesFrom(const vector<T> array) {
    for (Node<TNode> *node : array) {
        addNode(node->id());
    }
}

/**
 * Check whether node is in the graph
 */
template <typename TNode> const bool Graph<TNode>::hasNode(TNode id) const {
    return _findNode(id) != nullptr;
}

/**
 * Check whether edge is in the graph
 */
template <typename TNode> const bool Graph<TNode>::hasEdge(TNode SiD, TNode ViD) const {
    return _findEdge(SiD, ViD) != nullptr;
}

/**
 * Check wheter the graph is directed or not
 */
template <typename TNode> const bool &Graph<TNode>::isDirected() const  {
    return _isDirected;
}

/**
 * Transpose the graph
 */
template <typename TNode> void Graph<TNode>::transpose() {}

/**
 * Returns the weight of the graph
 */
template <typename TNode> const double Graph<TNode>::weight(string attr) {

    double weight = 0.0;

    for (Edge<TNode> *edge : _edges) {
        weight += edge->get<double>(attr);
    }

    return weight;
}


#endif //SV_NETWORK_GRAPH_H
