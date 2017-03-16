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

#ifndef SV_NETWORK_PATHS_H
#define SV_NETWORK_PATHS_H

#include <limits>

#include "../util/Stack.h"
#include "../util/PriorityQueue.h"


/**
 * Class Paths
 *
 * Base class for inheritance
 *
 * Depth First Search
 * The DFS path returns the first path it finds (between 2 nodes), searching in depth.
 *
 * Breadth First Search
 * The BFS path returns the shortest path between two nodes, in graphs without weights in the edges.
 *
 * Uniform Cost Search
 * The UCS path returns the shortest path between two nodes when the graph is weighted (edges contains a certain weight)
 */
class Paths {


protected:

    /**
     * Build the path from the links of a node
     */
    template <class TNode> static const NodeArray<Node<TNode> *> _constructPath(Graph<TNode> *, Node<TNode> *);

    /**
     * Global Search Algorithm
     */
    template <class TNode> static const NodeArray<Node<TNode> *> _searchPath(Graph<TNode> *, TNode, Node<TNode> *, Frontier<Node<TNode> *> *);


    /**
     * All possible paths between two nodes
     */
    template <class TNode> static const NodeArray<NodeArray<Node<TNode> *>> _allPathsSearch(Graph<TNode> *, TNode , Node<TNode> *, Frontier<pair<Node<TNode> *, NodeArray<Node<TNode> *>>> *);


public:

    /**
     * All possible paths between two nodes
     */
    template <typename TNode> static const vector<NodeArray<Node<TNode> *>> allPathsBFS(Graph<TNode> *, TNode, TNode);

};

/**
 * Build the path from the links of a node
 */
template<class TNode> const NodeArray<Node<TNode> *> Paths::_constructPath(Graph<TNode> *graph, Node<TNode> *goal)  {

    //Create a path to return
    NodeArray<Node<TNode> *> path;

    //Initialize the current node
    Node<TNode> *currentNode = goal;

    //Reassign the current node and push it to the path
    while (currentNode->has("sv_parent_search")) {
        currentNode = graph->node(currentNode->get<TNode>("sv_parent_search"));
        path.insert(path.begin(), currentNode);
    }

    //Clean all attributes
    graph->removeNodeAttributes("sv_cost_search");
    graph->removeNodeAttributes("sv_parent_search");
    graph->removeNodeAttributes("sv_visited_search");

    //Push goal node to the path and return it
    path.push_back(goal);
    return path;
}

/**
 * Global Search Algorithm
 */
template<class TNode>
const NodeArray<Node<TNode> *> Paths::_searchPath(Graph<TNode> *graph, TNode start, Node<TNode> *goal, Frontier<Node<TNode> *> *frontier) {

    //Push the start node to the frontier and initialize the attribute of nodes
    frontier->push(graph->node(start));
    graph->addNodeAttributes("sv_visited_search", false);

    while (!frontier->empty()) {

        //Pop the current node from the frontier
        Node<TNode> *node = frontier->pop();

        //Check if node isn't visited
        if (!node->get<bool>("sv_visited_search")) {

            //Check if this can stop or not
            if (node == goal) {
                delete frontier;
                return _constructPath(graph, goal);
            }
            node->set("sv_visited_search", true);

            //Explore all the neighbors of the current node and add it to the frontier if it has not been visited
            for (Node<TNode> *nbr : graph->neighbors(node->id())) {
                if (!nbr->get<bool>("sv_visited_search") && !nbr->has("sv_parent_search"))
                    nbr->add("sv_parent_search", node->id());
                frontier->push(nbr);
            }
        }
    }

    //Free memory and return
    delete frontier;
    return NodeArray<Node<TNode> *> ();
}



/**
 * All possible paths between two nodes
 */
template<class TNode>
const NodeArray<NodeArray<Node<TNode> *>> Paths::_allPathsSearch(Graph<TNode> *graph, TNode start, Node<TNode> *goal, Frontier<pair<Node<TNode> *, NodeArray<Node<TNode> *>>> *frontier) {

    //Create array that hold start node
    NodeArray<Node<TNode> *> initPath;

    //Push start node to array
    initPath.push_back(graph->node(start));

    //Push a pair that contains start node and path to the frontier
    frontier->push(make_pair(graph->node(start), initPath));

    //Create an array of arrays that hold all paths to return finally
    NodeArray<NodeArray<Node<TNode> *>> paths;

    if (graph->node(start) == goal) {
        paths.push_back(initPath);

    } else {

        while (!frontier->empty()) {

            //Get the current pair (Node and path)
            pair<Node<TNode> *, NodeArray<Node<TNode> *>> obj = frontier->pop();

            //The first obj of the pair represents the node
            for (Node<TNode> *nbr : graph->neighbors(obj.first->id())) {

                //The second obj of a pair represents the current path
                if (!Functions::contains(obj.second, nbr)) {
                    NodeArray<Node<TNode> *> newPath;

                    //Push the nodes and nbr to new path
                    //Foreach iteration a new path is created with a new pointer
                    for (Node<TNode> *nodePath : obj.second)
                        newPath.push_back(nodePath);
                    newPath.push_back(nbr);

                    //Check if this can finally or not
                    if (nbr->id() == goal->id())
                        paths.push_back(newPath);
                    else
                        frontier->push(make_pair(nbr, newPath));
                }
            }
        }
    }

    //Free memory and return
    delete frontier;
    return paths;
}

/**
 * All possible paths between two nodes
 */
template<typename TNode>
const vector<NodeArray<Node<TNode> *>> Paths::allPathsBFS(Graph<TNode> *graph, TNode start, TNode goal) {
    return _allPathsSearch(graph, start, graph->node(goal), new Queue<pair<Node<TNode> *, NodeArray<Node<TNode> *>>>());
}


#endif //SV_NETWORK_PATHS_H
