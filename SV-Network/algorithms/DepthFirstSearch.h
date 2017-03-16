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

#ifndef SV_NETWORK_DEPTHFIRSTSEARCH_H
#define SV_NETWORK_DEPTHFIRSTSEARCH_H

#include "Traversal.h"
#include "Paths.h"

/**
 * DepthFirstSearch Class
 *
 * Includes the DFS traversal and the path found by a DFS
 *
 * Also includes an adapted DFS to check if a graph contains a cycle or not
 */
class DepthFirstSearch : public Traversal, public Paths {


public:

    /**
     * Depth First Search Traversal.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> depthFirstSearch(Graph<TNode> *, TNode );

    /**
     * Depth First Search Traversal.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> depthFirstSearchFull(Graph<TNode> *, TNode );

    /**
     * Check whether the undirected graph has cycle or not
     */
    template<typename TNode> static const bool hasCycleDFS(Graph<TNode> *, Node<TNode> *);


    /**
     * Check whether an undirected graph contains a cycle or not
     */
    template <typename TNode> static const bool _DFS_Cycle(Graph<TNode> *, Frontier<Node<TNode>*> *, Node<TNode> *);

    /**
     * Depth First Search Path.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> dfsPath(Graph<TNode> *, TNode, TNode);
};

/**
 * Depth First Search Traversal.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> DepthFirstSearch::depthFirstSearch(Graph<TNode> *graph, TNode start) {
    return _traversal(graph, start, new Stack<Node<TNode>*>());
}

/**
 * Depth First Search Traversal Full.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> DepthFirstSearch::depthFirstSearchFull(Graph<TNode> *graph, TNode start) {
    return _traversalFull(graph, start, new Stack<Node<TNode>*>());
}

/**
 * Check whether the graph contains a cycle or not
 */
template<typename TNode>
const bool DepthFirstSearch::hasCycleDFS(Graph<TNode> *graph, Node<TNode> *start) {
    return _DFS_Cycle(graph, new Stack<Node<TNode>*>(), start);
}

/**
 * Check whether the graph contains a cycle or not
 */
template<typename TNode>
const bool DepthFirstSearch::_DFS_Cycle(Graph<TNode> *graph, Frontier<Node<TNode> *> *frontier, Node<TNode> *start) {

    //Push start node to the frontier
    frontier->push(start);

    //Create an array of visited nodes to finally return it
    NodeArray<Node<TNode> *> visited;

    while (!frontier->empty()) {

        //Get the current node
        Node<TNode> *node = frontier->pop();

        //Check whether the node is not in visited and push it in
        if (!Functions::contains(visited, node)) {
            visited.push_back(node);

            //Iterate all neighbors of node, check whether the neighbor is not in visited, and
            //push it to the frontier
            for (Node<TNode> *nbr : graph->neighbors(node->id())) {
                if (!Functions::contains(visited, nbr)) {
                    frontier->push(nbr);

                    //Update node parent
                    if (!nbr->has("parent_sv_search")){
                        nbr->add("parent_sv_search", node->id());
                    }
                }

                    //If the node has a parent and the parent isn't this neighbor, then the graph
                    //contains a cycle
                else if (nbr->has("parent_sv_search") && node->get<TNode>("parent_sv_search") != nbr->id()) {
                    graph->removeNodeAttributes("parent_sv_search");
                    delete frontier;
                    return true;
                }
            }
        }
    }

    //Clear attrs and returns false
    graph->removeNodeAttributes("parent_sv_search");
    delete frontier;
    return false;
}

/**
 * Depth First Search Path.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> DepthFirstSearch::dfsPath(Graph<TNode> *graph, TNode start, TNode goal) {
    return _searchPath(graph, start, graph->node(goal), new Stack<Node<TNode> *>());
}

#endif //SV_NETWORK_DEPTHFIRSTSEARCH_H
