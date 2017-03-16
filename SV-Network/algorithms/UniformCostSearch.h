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

#ifndef SV_NETWORK_UNIFORMCOSTSEARCH_H
#define SV_NETWORK_UNIFORMCOSTSEARCH_H

#include "Paths.h"

/**
 * Class UniformCostSearch
 *
 * Solve search problems using uniform cost to achieve the final goal.
 * It is identical to Astar but without using heuristics.
 */
class UniformCostSearch : public Paths {

    /**
     * Uniform cost search
     */
    template <class TNode> static const NodeArray<Node<TNode> *> _uniformCostSearch(Graph<TNode> *, TNode , Node<TNode> *, Frontier<Node<TNode> *> *, string);

public:

    /**
     * Uniform Cost Search Path.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> ucsPath(Graph<TNode> *, TNode, TNode, string);

};

/**
 * Uniform Cost Search Path.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> UniformCostSearch::ucsPath(Graph<TNode> *graph, TNode start, TNode goal, string attr) {

    //All nodes must have the initial cost as infinity
    graph->addNodeAttributes("sv_cost_search", std::numeric_limits<double>::max());

    //The initial cost of start node must be zero
    graph->node(start)->set("sv_cost_search", 0);
    return _uniformCostSearch(graph, start, graph->node(goal), new PriorityQueue<Node<TNode> *>("sv_cost_search"), attr);
}

/**
 * Uniform cost search
 */
template<class TNode>
const NodeArray<Node<TNode> *> UniformCostSearch::_uniformCostSearch(Graph<TNode> *graph, TNode start, Node<TNode> *goal, Frontier<Node<TNode> *> *frontier, string attr) {

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

                //Compute the current cost
                double cost = node->get<double>("sv_cost_search") +
                        graph->edge(node->id(), nbr->id())->get<double>(attr);

                //Stop whether a negative cost is found
                if (cost < 0) throw UCSError();

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

#endif //SV_NETWORK_UNIFORMCOSTSEARCH_H
