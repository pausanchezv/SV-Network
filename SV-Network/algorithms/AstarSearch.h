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

#ifndef SV_NETWORK_ASTARSEARCH_H
#define SV_NETWORK_ASTARSEARCH_H

#include "Paths.h"

/**
 * Astar Class
 *
 * Solves search problems by using a heuristic
 */
class AstarSearch : public Paths {

    /**
     * Astar search
     */
    template<class TNode>
    static const NodeArray<Node<TNode> *> _aStarSearch(Graph<TNode> *, TNode, Node<TNode> *, Frontier<Node<TNode> *> *, string, double (*)(Node<TNode> *, Node<TNode> *));

public:

    /**
     * Astar Search Path.
     */
    template<typename TNode>
    static const NodeArray<Node<TNode> *> astarPath(Graph<TNode> *, TNode, TNode, string, double (*)(Node<TNode> *, Node<TNode> *));

};

/**
* Astar Search Path.
*/
template<typename TNode>
const NodeArray<Node<TNode> *> AstarSearch::astarPath(Graph<TNode> *graph, TNode start, TNode goal, string attr, double (*heuristic)(Node<TNode> *, Node<TNode> *)) {

    //All nodes must have the initial cost as infinity
    graph->addNodeAttributes("sv_cost_search", std::numeric_limits<double>::max());

    //The initial cost of start node must be zero
    graph->node(start)->set("sv_cost_search", 0);
    return _aStarSearch(graph, start, graph->node(goal), new PriorityQueue<Node<TNode> *>("sv_cost_search"), attr, heuristic);
}

/**
* Astar search
*/
template<class TNode>
const NodeArray<Node<TNode> *> AstarSearch::_aStarSearch(Graph<TNode> *graph, TNode start, Node<TNode> *goal, Frontier<Node<TNode> *> *frontier, string attr, double (*heuristic)(Node<TNode> *, Node<TNode> *)) {

    //Push the start node to the frontier
    frontier->push(graph->node(start));

    //Initialize visited attribute for each node
    graph->addNodeAttributes("sv_visited_search", false);

    while (!frontier->empty()) {

        //Get the current node
        Node<TNode> *node = frontier->pop();

        //Check if node has been visited or not
        if (!node->get<bool>("sv_visited_search")) {
            if (node == goal) {
                delete frontier;
                return _constructPath(graph, goal);
            }
            node->set("sv_visited_search", true);

            //Explore all the neighbors of the node
            for (Node<TNode> *nbr : graph->neighbors(node->id())) {

                //Compute the current cost with the heuristic between the node and nbr
                double cost = node->get<double>("sv_cost_search") +
                        graph->edge(node->id(), nbr->id())->get<double>(attr) +
                        heuristic(nbr, goal);

                //Stop whether a negative cost has been found
                if (cost < 0) throw AStarError();

                //Update info if cost is lower than neighbor's cost
                if (cost < nbr->get<double>("sv_cost_search")) {
                    nbr->set("sv_cost_search", cost);
                    nbr->add("sv_parent_search", node->id());
                }

                //Push the neighbor to the frontier
                frontier->push(nbr);
            }
        }
    }

    //Free memory and return
    delete frontier;
    return NodeArray<Node<TNode> *>();
}

#endif //SV_NETWORK_ASTARSEARCH_H
