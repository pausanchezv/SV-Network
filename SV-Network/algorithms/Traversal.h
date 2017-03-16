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

#ifndef SV_NETWORK_TRAVERSAL_H
#define SV_NETWORK_TRAVERSAL_H

#include "../util/Stack.h"
#include "../util/Queue.h"

#include "../util/Functions.h"

/**
 * Class Traversal
 *
 * Base class for inheritance
 *
 * BFS and DFS traversal
 * The DFS path allows us to check if a graph is connected or not.
 * The BFS path allows us to know the distance of a node to all the other nodes of the graph
 */
class Traversal {


protected:

    /**
     * Search Traversal.
     *
     * When a BFS is needed, this function will be called with a Queue. Otherwise, if a DFS is
     * needed, the function will be called with a Stack.
     */
    template<typename TNode>
    static const NodeArray<Node<TNode> *> _traversal(Graph<TNode> *graph, TNode, Frontier<Node<TNode> *> *);

    /**
     * Search Traversal.
     *
     * When a BFS is needed, this function will be called with a Queue. Otherwise, if a DFS is
     * needed, the function will be called with a Stack.
     */
    template<typename TNode>
    static const NodeArray<Node<TNode> *> _traversalFull(Graph<TNode> *graph, TNode, Frontier<Node<TNode> *> *);
};

/**
 * Search Traversal.
 *
 * When a BFS is needed, this function will be called with a Queue. Otherwise, if a DFS is
 * needed, the function will be called with a Stack.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> Traversal::_traversal(Graph<TNode> *graph, TNode start, Frontier<Node<TNode> *> *frontier) {

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
        }
    }
    delete frontier;
    return visited;
}

/**
 * Search Traversal.
 *
 * When a BFS is needed, this function will be called with a Queue. Otherwise, if a DFS is
 * needed, the function will be called with a Stack.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> Traversal::_traversalFull(Graph<TNode> *graph, TNode start, Frontier<Node<TNode> *> *frontier) {

    //Push start node to the frontier
    frontier->push(graph->node(start));

    //Create an array of visited nodes to finally return it
    NodeArray<Node<TNode> *> visited;

    while (!frontier->empty() || visited.size() != graph->numberOfNodes()) {

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
        }

        //Find nodes that are not visited and push them to the frontier
        if (frontier->empty()) {
            for (Node<TNode> *n : graph->nodes()) {
                if (!Functions::contains(visited, n)) {
                    frontier->push(n);
                }
            }
        }
    }
    delete frontier;
    return visited;
}





#endif //SV_NETWORK_TRAVERSAL_H
