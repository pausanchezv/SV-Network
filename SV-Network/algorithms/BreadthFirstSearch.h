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

#ifndef SV_NETWORK_BREADTHFIRSTSEARCH_H
#define SV_NETWORK_BREADTHFIRSTSEARCH_H

#include "Traversal.h"
#include "Paths.h"

/**
 * BreadthFirstSearch Class
 *
 * Includes the BFS traversal and the shortest path found by a BFS.
 * It also includes a BFS adapted to check if a directed graph is a tree or not.
 */
class BreadthFirstSearch : public Traversal, public Paths {

public:

    /**
     * Breadth First Search Traversal.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> breadthFirstSearch(Graph<TNode> *, TNode);

    /**
     * Breadth First Search Traversal.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> breadthFirstSearchFull(Graph<TNode> *, TNode);

    /**
     * Check whether a directed graph is tree or not
     */
    template <typename TNode> static const bool _BFS_Tree(Graph<TNode> *, Frontier<Node<TNode> *> *, TNode);

    /**
     * Check whether the directed graph is tree or not
     */
    template<typename TNode> static const bool isTreeBFS(Graph<TNode> *, TNode);

    /**
     * Breadth First Search Path.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> bfsPath(Graph<TNode> *, TNode, TNode);
};

/**
 * Breadth First Search Traversal.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> BreadthFirstSearch::breadthFirstSearch(Graph<TNode> *graph, TNode start) {
    return _traversal(graph, start, new Queue<Node<TNode>*>());
}

/**
 * Breadth First Search Traversal.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> BreadthFirstSearch::breadthFirstSearchFull(Graph<TNode> *graph, TNode start) {
    return _traversalFull(graph, start, new Queue<Node<TNode>*>());
}

/**
 * Check whether the graph contains a cycle or not
 */
template<typename TNode>
const bool BreadthFirstSearch::isTreeBFS(Graph<TNode> *graph, TNode start) {
    return _BFS_Tree(graph, new Queue<Node<TNode>*>(), start);
}

/**
 * Check whether a directed graph is tree or not
 */
template<typename TNode>
const bool BreadthFirstSearch::_BFS_Tree(Graph<TNode> * graph, Frontier<Node<TNode> *> *frontier, TNode start) {

    //Push start node to the frontier
    frontier->push(graph->node(start));

    //Create an array of visited nodes to finally return it
    NodeArray<Node<TNode> *> visited;

    while (!frontier->empty()) {

        //Get the current node
        Node<TNode> *node = frontier->pop();

        //Check whether the node is in visited and push it in
        if (!Functions::contains(visited, node)) {
            visited.push_back(node);

            //Iterate all neighbors of the node, check whether the neighbor is not in visited and push it
            //to the frontier
            for (Node<TNode> *neighbor : graph->neighbors(node->id())) {
                if (!Functions::contains(visited, neighbor)) {
                    frontier->push(neighbor);
                }
            }

        //If a visited node has been encountered, then the graph isn't a tree
        } else {
            delete frontier;
            return false;
        }
    }
    delete frontier;
    return true;
}

/**
 * Breadth First Search Path.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> BreadthFirstSearch::bfsPath(Graph<TNode> *graph, TNode start, TNode goal) {
    return _searchPath(graph, start, graph->node(goal), new Queue<Node<TNode> *>());
}

#endif //SV_NETWORK_BREADTHFIRSTSEARCH_H
