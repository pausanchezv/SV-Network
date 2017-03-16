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

#ifndef SV_NETWORK_DIJKSTRA_H
#define SV_NETWORK_DIJKSTRA_H

#include <limits>

/**
 * Class Dijkstra
 *
 * For a specific node of the graph, called 'start', the algorithm finds the shortest path between this
 * and the other nodes of the graph.
 *
 * Note that to find the shortest path between two nodes (start and goal) in a weighted graph, it's much better
 * to use the UniformCostSearch algorithm.
 *
 * The algorithm returns all possible paths. It doesn't return anything for nodes that are isolated or that
 * are not connected to the node 'start'
 */
class Dijkstra {

    /**
     * Dijkstra Algorithm
     */
    template <typename TNode> static void _dijkstra(Graph<TNode> *, TNode, string);


public:

    /**
     * Constructs and returns all Dijkstra's Paths
     */
    template <class TNode> static const vector<NodeArray<Node<TNode> *>> dijkstraAllPaths(Graph<TNode> *, TNode, string);
};

/**
 * Dijkstra Algorithm
 */
template<typename TNode> void
Dijkstra::_dijkstra(Graph<TNode> * G, TNode start, string attr) {

    //Prepare the attributes of the nodes
    G->addNodeAttributes("sv_cost_search", numeric_limits<double>::max());
    Node<TNode> *node = G->node(start);
    node->set("sv_cost_search", 0);

    //Array that holds the graph's nodes
    vector<Node<TNode> *> nodeList = G->nodes();

    while (!nodeList.empty()) {

        //Find the node
        node = nullptr;
        double min = numeric_limits<double>::max();

        for (Node<TNode> *current : nodeList) {
            if (current->get<double>("sv_cost_search") < min) {
                node = current;
                min = current->get<double>("sv_cost_search");
            }
        }

        //Remove node from nodeList
        Functions::removeItem(&nodeList, node);

        //Iterate all neighbors of the node and apply dijkstra
        for (Node<TNode> *nbr : G->neighbors(node->id())) {

            //Stop whether a negative cost is found
            if (G->edge(node->id(), nbr->id())->get<double>(attr) < 0) throw DijkstraErrorN();

            //Value is the sum of node's current cost and the weight of the edge between node and neighbor
            double value = node->get<double>("sv_cost_search") + G->edge(node->id(), nbr->id())->get<double>(attr);

            //Update the attributes if clause is true
            if (nbr->get<double>("sv_cost_search") > value) {
                nbr->set("sv_cost_search", value);
                nbr->add("sv_parent_search", node->id());
            }
        }
    }
}

/**
 * Constructs and returns all Dijkstra's Paths
 */
template <class TNode>
const vector<NodeArray<Node<TNode> *>> Dijkstra::dijkstraAllPaths(Graph<TNode> *G, TNode start, string attr) {

    //Apply the dijkstra algorithm
    _dijkstra(G, start, attr);

    //Create the vector that will holds all the paths
    vector<NodeArray<Node<TNode> *>> paths;

    for (Node<TNode> *node : G->nodes()) {

        //Check if the current node is different at start and then create a path
        if (node->id() != start) {
            Node<TNode> *parent = node;
            NodeArray<Node<TNode> *> path;

            //Update the node's parent and insert it to the path
            while (parent->has("sv_parent_search")) {
                path.insert(path.begin(), parent);
                parent = G->node(parent->get<TNode>("sv_parent_search"));
            }

            //If path not exist then push the start node to path to return it
            if (!path.empty()) {
                path.insert(path.begin(), G->node(start));
                paths.push_back(path);
            }
        }
    }

    //Remove the attributes of nodes
    G->removeNodeAttributes("sv_cost_search");
    G->removeNodeAttributes("sv_parent_search");
    return paths;
}


#endif //SV_NETWORK_DIJKSTRA_H
