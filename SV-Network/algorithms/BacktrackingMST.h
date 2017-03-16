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

#ifndef SV_NETWORK_BACKTRACKINGMST_H
#define SV_NETWORK_BACKTRACKINGMST_H

#include <set>
#include "Properties.h"


using namespace std;

/**
 * BacktrackingMST Class
 *
 * Solves the MST problem in directed graphs by using the backtracking technique.
 * Node that this solution is based on brute force so it can be quiet slow i large graphs.
 */
class BacktrackingMST {

    /**
     * Altitude ceil of branch and bound
     */
    static double _altitudeCeil;

    /**
     * Compute the ceil altitude that allows the pruning partial solutions
     */
    template <typename TNode> static double _altitudeFloor(Graph<TNode> *, vector<Edge<TNode> *>, double, string);

    /**
     * Get weight of edges
     */
    template <typename TNode> static const double _weightOfEdges(vector<Edge<TNode> *>, string);

    /**
     * Check if any node has many parents or not
     */
    template <typename TNode> static const bool _checkIfAnyNodeHasManyParents(vector<Edge<TNode> *>);

    /**
     * Exhaustive solution using backtracking technique with branch and bound
     */
    template <typename TNode> static vector<Edge<TNode> *> _backtrackingMST(Graph<TNode> *, string, Edge<TNode> *, vector<Edge<TNode> *>);

    /**
     * Reverse value of attribute
     */
    template<typename TNode> static void _reverseValues(Graph<TNode> *, string );


public:

    /**
     * Returns the minimum or maximum spanning tree
     */
    template <typename TNode> static Graph<TNode> *directedMST(Graph<TNode> *, string, Edge<TNode> *, vector<Edge<TNode> *>, bool);

};


/**
 * Greater Altitude starts as infinity
 */
double BacktrackingMST::_altitudeCeil = numeric_limits<double>::max();

/**
 * Returns the minimum or maximum spanning tree
 */
template<typename TNode>
Graph<TNode> *BacktrackingMST::directedMST(Graph<TNode> *G, string attr, Edge<TNode> *edge, vector<Edge<TNode> *> edges, bool reverse) {


    //Only is called whether is Maximum Spanning Tree
    if (reverse) {
        _reverseValues(G, attr);
    }

    //Altitude ceil starts as infinity at each call
    _altitudeCeil = numeric_limits<double>::max();

    //Vector that hold the edges of mst
    vector<Edge<TNode> *> edgesMST = _backtrackingMST(G, attr, edge, edges);

    //Create a graph to return mst
    Graph<TNode> *mst = new DiGraph<TNode>();

    //Fill the graph mst
    for (Edge<TNode> *obj : edgesMST) {
        mst->addEdge(obj->getNode_S()->id(), obj->getNode_V()->id());
        mst->edge(obj->getNode_S()->id(), obj->getNode_V()->id())->add(attr, obj->get<double>(attr));
    }

    //Only is called whether is Maximum Spanning Tree
    if (reverse) {
        _reverseValues(mst, attr);
        _reverseValues(G, attr);
    }

    return mst;
}

/**
 * Compute the ceil altitude that allows the pruning partial solutions
 */
template<typename TNode>
double BacktrackingMST::_altitudeFloor(Graph<TNode> *G, vector<Edge<TNode> *> edges, double currentWeight, string attr) {

    //Altitude starts as the current weight
    double _altitude = currentWeight;

    //Number of missing edges to complete the tree
    unsigned long int differenceNumEdges = (G->numberOfNodes() - 1) - edges.size();

    //Create a heap to holding unvisited edges
    Heap<Edge<TNode> *> *unvisited = new Heap<Edge<TNode> *>(attr);

    //Iterate the graph's edges and push it to heap whether it's not in current edges
    for (Edge<TNode> *obj : G->edges()) {
        if (!Functions::contains(edges, obj)) {
            unvisited->heapPush(obj);
        }
    }

    //Sum the minimum of the edges to the altitude
    while (differenceNumEdges--) {
        _altitude += unvisited->heapPop()->get<double>(attr);
    }

    //Delete heal and return altitude
    delete unvisited;
    return _altitude;
}

/**
 * Exhaustive solution using backtracking technique with branch and bound
 */
template<typename TNode>
vector<Edge<TNode> *> BacktrackingMST::_backtrackingMST(Graph<TNode> *G, string attr, Edge<TNode> *edge, vector<Edge<TNode> *> edges) {

    //Create a vector that returns as a solution
    vector<Edge<TNode> *> best;

    //Add the edge to the vector of edges
    if (edge != nullptr) {
        edges.push_back(edge);
    }

    //Get the current weight of edges
    double currentWeight = _weightOfEdges(edges, attr);

    //Pruning if the weight of the partial solution is greater than the best solution found
    if (_altitudeFloor(G, edges, currentWeight, attr) < _altitudeCeil) {

        //Check if any node has many parents
        bool anyNodeHasManyParents = _checkIfAnyNodeHasManyParents(edges);

        //Pruning if the size of edges is greater than number of nodes of the graph or
        //any node has many parents.
        if (edges.size() <= G->numberOfNodes() - 1 && !anyNodeHasManyParents) {

            //If edges condition is true, then we have a new possible solution
            if (edges.size() == G->numberOfNodes() - 1) {

                //Create the mst
                Graph<TNode> *mst = new DiGraph<TNode>();

                //Fill the mst
                for (Edge<TNode> *obj : edges) {
                    mst->addEdge(obj->getNode_S()->id(), obj->getNode_V()->id());
                    mst->edge(obj->getNode_S()->id(), obj->getNode_V()->id())->add(attr, obj->get<double>(attr));
                }

                //Check whether mst is a tree really
                bool ok = Properties::isTree(mst);
                delete mst;

                //Return edges whether mst is a tree
                if (ok) {
                    _altitudeCeil = currentWeight;
                    return edges;
                }

                //If the bound condition is false, then continue to explore possibles solutions
                //and continue expanding the current partial solution
            } else {

                //For each edge that not is contained in vector of edges, branch a new partial solution
                for (Edge<TNode> *obj : G->edges()) {
                    if (!Functions::contains(edges, obj)) {

                        //Recursive backtracking call
                        vector<Edge<TNode> *> news = _backtrackingMST(G, attr, obj, edges);

                        //Check if the new solution is better than the best current solution
                        bool weightClause = _weightOfEdges(news, attr) < _weightOfEdges(best, attr);

                        //Upgrade the best solution
                        if (!news.empty() && (best.empty() || weightClause)) {
                            best = news;
                        }
                    }
                }
            }
        }
    }

    //Return solution
    return best;
}

/**
* Get weight of edges
*/
template<typename TNode>
const double BacktrackingMST::_weightOfEdges(vector<Edge<TNode> *> edges, string attr) {

    //Weight starts as zero
    double weight = 0.0;

    //Increment the weight attribute with the weights of the edges
    for (Edge<TNode> *obj : edges) {
        weight += obj->get<double>(attr);
    }
    return weight;
}

/**
 * Check if any node has many parents or not
 */
template<typename TNode>
const bool BacktrackingMST::_checkIfAnyNodeHasManyParents(vector<Edge<TNode> *> edges) {

    //Found starts as false
    bool found = false;

    //Creates a set to hold the nodes that has been added to any edge of the tree
    set<Node<TNode> *> added;

    //Iterates the edges and fill added vector
    for (Edge<TNode> *obj : edges) {
        if (added.find(obj->getNode_V()) == added.end())
            added.insert(obj->getNode_V());
        else {
            found = true;
            break;
        }
    }

    //Returns true whether node has been added to any edge of the tree, otherwise returns false
    return found;
}

/**
 * Reverse value of attribute
 */
template<typename TNode> void BacktrackingMST::_reverseValues(Graph<TNode> * G, string attr) {

    //Complement the values
    for (Edge<TNode> *edge : G->edges()) {
        edge->set(attr, - edge->get<double>(attr));
    }
}

#endif //SV_NETWORK_BACKTRACKINGMST_H
