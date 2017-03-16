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

#ifndef SV_NETWORK_PROPERTIES_H
#define SV_NETWORK_PROPERTIES_H

#include "Traversal.h"
#include "../arrays/AdjMatrix.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"

using namespace std;

/**
 * Class Properties
 *
 * This class includes algorithms based on the properties of the graph, nodes and edges.
 */
class Properties {


    /**
     * Returns the number of graph's connected components where the graph is undirected
     */
    template <typename TNode> static const vector<NodeArray<Node<TNode> *>> _SSCUndirected(Graph<TNode> *);

    /**
     * Adds the single nodes of the graph at SSC
     */
    template <typename TNode> static const vector<NodeArray<Node<TNode> *>> _addSinglesToSCC(Graph<TNode> *G, Graph<TNode> *gCopy, vector<NodeArray<Node<TNode> *>> *);

    /**
     * Returns the number of graph's connected components where the graph is directed
     */
    template <typename TNode> static const vector<NodeArray<Node<TNode> *>> _SSCDirected(Graph<TNode> *);


public:

    /**
     * Check whether the graph is directed
     */
    template <typename TNode> static const bool isDirectedGraph(Graph<TNode> *);

    /**
     * Check whether the graph is undirected
     */
    template <typename TNode> static const bool isUndirectedGraph(Graph<TNode> *);

    /**
     * Check whether the graph is connected or not
     */
    template <typename TNode> static const bool isConnected(Graph<TNode> *);

    /**
     * Returns graph's articulation points
     *
     * A point of articulation in a graph is a node that if it is removed, the number of
     * connected components of the graph increases.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> articulationPoints(Graph<TNode> *);

    /**
     * Returns the number of graph's connected components
     * A connected component in a graph is a subgraph that is fully connected.
     */
    template <typename TNode> static const vector<NodeArray<Node<TNode> *>> stronglyConnectedComponents(Graph<TNode> *);

    /**
     * Returns graph's bridges
     *
     * A point of articulation in a graph is a node that if it is removed, the number of
     * connected components of the graph increases.
     */
    template <typename TNode> static const EdgeArray<Edge<TNode> *> bridges(Graph<TNode> *);


    /**
     * Returns the adjacency matrix of the graph
     */
    template <typename TNode> static const AdjMatrix adjacencyMatrix(Graph<TNode> *);

    /**
     * Make a copy of the graph
     */
    template <typename TNode> static Graph<TNode> *makeGraphCopy(Graph<TNode> *);

    /**
     * Returns the isolated nodes of the graph
     */
    template <typename TNode> static NodeArray<Node<TNode> *> isolatedNodes(Graph<TNode> *G);

    /**
     * Check whether the graph contains a cycle or not
     */
    template <typename TNode> static bool hasCycle(Graph<TNode> *);

    /**
     * Check whether the graph is a tree or not
     */
    template <typename TNode> static bool isTree(Graph<TNode> *);

    /**
     * Returns the eccentricity of node
     *
     * The eccentricity of a node is the shortest path to the farthest node of the graph
     */
    template <typename TNode> static const unsigned long int eccentricity(Graph<TNode> *, Node<TNode>*);

    /**
     * Returns the graph's diameter
     *
     * The radius of the graph is the maximun of the graph's eccentricities
     */
    template <typename TNode> static const unsigned long int diameter(Graph<TNode> *);

    /**
     * Returns the graph's radius
     *
     * The radius of the graph is the minimum of the graph's eccentricities
     */
    template <typename TNode> static const unsigned long int radius(Graph<TNode> *);

    /**
     * Returns the nodes that belong to the center of the graph
     *
     * A node belongs to the center of the graph if its eccentricity is equal to the radius of graph
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> center(Graph<TNode> *);

    /**
     * Returns the nodes that belong to the periphery of the graph
     *
     * A node belongs to the periphery of the graph if its eccentricity is equal to the diameter of graph
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> periphery(Graph<TNode> *);

    /**
     * Returns whether the graph is eulerian or not
     *
     * A graph is eulerian if all the nodes of it have even degree
     */
    template <typename TNode> static const bool isEulerian(Graph<TNode> *);

    /**
     * Check whether the graph contains a eulerian path or not
     *
     * A graph contains an eulerian path if number of odd degree nodes is 0 or 2
     */
    template <typename TNode> static const bool hasEulerianPath(Graph<TNode> *);

    /**
     * Graph density
     *
     * Calculate the number of edges divided by the number of pairs
     */
    template <typename TNode> static const double density(Graph<TNode> *);

    /**
     * Obtain transposed graph
     */
    template <typename TNode> static Graph<TNode> *transposed(Graph<TNode> *);

    /**
     * Check whether a node is isolated or not
     */
    template <typename TNode> static const bool isIsolated(Graph<TNode> *, Node<TNode> *);

};

/**
 * Check whether the graph is directed
 */
template<typename TNode>
const bool Properties::isDirectedGraph(Graph<TNode> *G) {
    return G->isDirected();
}

/**
 * Check whether the graph is undirected
 */
template<typename TNode>
const bool Properties::isUndirectedGraph(Graph<TNode> *G) {
    return !isDirectedGraph(G);
}

/**
 * Check whether the graph is connected or not
 */
template<typename TNode>
const bool Properties::isConnected(Graph<TNode> * G) {

    if (G->numberOfNodes() > 0) {

        //In non-directed graphs a graph is connected if the number of nodes in the graph is equal
        //to the number of nodes of the DFS traversal.
        if (isUndirectedGraph(G)) {
            return G->numberOfNodes() == DepthFirstSearch::depthFirstSearch(G, G->nodes().front()->id()).size();
        }

        //Otherwise, in directed graphs a graph is connected if only have one Strongly Connected Component
        else if (isDirectedGraph(G)) {
            return _SSCDirected(G).size() == 1;
        }
    }
    return false;
}

/**
 * Returns graph's articulation points
 *
 * A point of articulation in a graph is a node that if it is removed, the number of
 * connected components of the graph increases.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> Properties::articulationPoints(Graph<TNode> * G) {

    //Array that hold the articulation nodes
    NodeArray<Node<TNode> *> articulations;

    //Num of sub-graphs from graph
    unsigned long numSubGraphs = stronglyConnectedComponents(G).size();

    //Iterate all graph's nodes and make a copy of the graph for each iteration
    for (Node<TNode> * node : G->nodes()) {
        Graph<TNode> * gCopy = makeGraphCopy(G);

        //Remove the current node from the graph copy
        gCopy->removeNode(node->id());

        //Check whether the connected components have increased and add the articulation node
        if (numSubGraphs < stronglyConnectedComponents(gCopy).size()) {
            articulations.push_back(node);
        }

        //Free memory from the graph copy
        delete gCopy;
    }
    return articulations;
}

/**
 * Returns the number of graph's connected components
 * A connected component in a graph is a subgraph that is fully connected.
 */
template<typename TNode>
const vector<NodeArray<Node<TNode> *>> Properties::stronglyConnectedComponents(Graph<TNode> *G) {
    return isUndirectedGraph(G) ? _SSCUndirected(G) : _SSCDirected(G);
}

/**
 * Returns graph's bridges
 *
 * A bridge in a graph is an edge that if it is removed, the number of
 * connected components of the graph increases.
 */
template<typename TNode>
const EdgeArray<Edge<TNode> *> Properties::bridges(Graph<TNode> *G) {

    //Array that hold the bridge-edges
    EdgeArray<Edge<TNode> *> bridges;

    //Num of sub-graphs from graph
    unsigned long numSubGraphs = stronglyConnectedComponents(G).size();

    //Make a copy of the graph
    Graph<TNode> * gCopy = makeGraphCopy(G);

    for (Edge<TNode> * edge : G->edges()) {

        //Remove the current edge from the graph copy
        gCopy->removeEdge(edge->getNode_S()->id(), edge->getNode_V()->id());

        //Check whether the connected components have increased and add the bridge-edge
        if (numSubGraphs < stronglyConnectedComponents(gCopy).size()) {
            bridges.push_back(edge);
        }

        //Add the edge again to the graph
        gCopy->addEdge(edge->getNode_S()->id(), edge->getNode_V()->id());
    }

    //Free memory from the graph copy
    delete gCopy;
    return bridges;
}

/**
 * Returns the adjacency matrix of the graph
 */
template<typename TNode>
const AdjMatrix Properties::adjacencyMatrix(Graph<TNode> *G) {

    //Create an obj and get vector with the nodes of the graph
    AdjMatrix adjMatrix;
    vector<Node<TNode> *> nodes = G->nodes();

    //Iterate the number of nodes twice and fill the boolean matrix
    for (unsigned int row = 0; row < G->numberOfNodes(); row++) {
        vector<bool> valuesRow;

        for (unsigned int col = 0; col < G->numberOfNodes(); col++) {
            valuesRow.push_back(G->hasEdge(nodes[row]->id(), nodes[col]->id()));
        }
        adjMatrix.push_back(valuesRow);
    }
    return adjMatrix;
}

/**
 * Make a copy of the graph
 */
template<typename TNode>
Graph<TNode> *Properties::makeGraphCopy(Graph<TNode> *G) {

    //Create a new graph pointer
    Graph<TNode> * gCopy;
    if (isDirectedGraph(G))
        gCopy = new DiGraph<TNode>();
    else
        gCopy = new Graph<TNode>();

    //Add nodes to the new graph
    for (Node<TNode> * obj : G->nodes()) {
        gCopy->addNode(obj->id());

        //Copy node's attributes
        for (pair<string, string> attr : obj->attrs()) {
            gCopy->node(obj->id())->add(attr.first, attr.second);
        }
    }

    //Add edges to the new graph
    for (Edge<TNode> * obj : G->edges()) {
        gCopy->addEdge(obj->getNode_S()->id(), obj->getNode_V()->id());

        //Copy edge's attributes
        for (pair<string, string> attr : obj->attrs()) {
            gCopy->edge(obj->getNode_S()->id(), obj->getNode_V()->id())->add(attr.first, attr.second);
        }
    }

    return gCopy;
}

/**
 * Returns the number of graph's connected components where the graph is undirected
 */
template<typename TNode>
const vector<NodeArray<Node<TNode> *>> Properties::_SSCUndirected(Graph<TNode> *G) {

    //Array that hold all possible distinct traversals
    vector<NodeArray<Node<TNode> *>> allDFS;

    //Unvisited nodes
    //vector<Node<TNode>*> unvisited = Functions::makeArrayCopy(G->nodes());

    //The priority is the node's degree
    for (Node<TNode> *node : G->nodes()) {
        node->add("sv_priority", node->degree());
    }

    //Create a heap with the nodes of the graph
    Heap<Node<TNode> *> *heap = new Heap<Node<TNode> *>("sv_priority");
    heap->heapify(G->nodes());

    while (heap->size() > 0) {

        //Get the current unvisited node
        Node<TNode> *node = heap->heapPop();

        //Check if the node has been added to any traversal
        bool found = false;
        for(vector<Node<TNode> *> traversal : allDFS) {
            if (Functions::contains(traversal, node)) {
                found = true;
            }
        }

        //Add possible new traversal
        if (!found) {
            allDFS.push_back(DepthFirstSearch::depthFirstSearch(G, node->id()));
        }
    }

    delete heap;
    G->removeNodeAttributes("sv_priority");

    return allDFS;
}


/**
 * Returns the strongly connected components from a directed graph
 */
template<typename TNode>
const vector<NodeArray<Node<TNode> *>> Properties::_SSCDirected(Graph<TNode> *G) {

    //Create a copy of graph
    Graph<TNode> *gCopy = makeGraphCopy(G);

    //Create an vector SSC to return at the end of the function
    vector<NodeArray<Node<TNode> *>> SCC;

    //Add single nodes to Strongly Connected Components
    _addSinglesToSCC(G, gCopy, &SCC);

    //Initialize node's attribute 'visited'
    gCopy->addNodeAttributes("sv_visited_CCS", false);

    //Remove auto-edges
    for (Node<TNode> *node : gCopy->nodes()) {
        gCopy->removeEdge(node->id(), node->id());
    }

    //Vector that holds the different components
    vector<NodeArray<Node<TNode> *>> components;

    //The components are extracted from undirected components that using dfs traversal
    //Note that is necessary get the components from de graph and also from graph transposed
    for (NodeArray<Node<TNode>*> cmp : _SSCUndirected(gCopy)) {
        components.push_back(cmp);
    }
    gCopy->transpose();

    for (NodeArray<Node<TNode>*> cmp : _SSCUndirected(gCopy)) {
        components.push_back(cmp);
    }
    gCopy->transpose();

    /*sort(components.begin(), components.end(), [] (NodeArray<Node<TNode>*> a, NodeArray<Node<TNode>*> b) {
        return b.size() > a.size();
    });*/

    while (!components.empty()) {

        //Find the minimum undirected component of the graph
        double size = std::numeric_limits<double>::max();
        NodeArray<Node<TNode>*> min;

        for (NodeArray<Node<TNode>*> cmp : components) {
            if (cmp.size() < size) {
                size = cmp.size();
                min = cmp;
            }
        }

        //Create a new empty component
        NodeArray<Node<TNode> *> cmp;

        //Fill the new component with the nodes that have not been visited
        for (Node<TNode> *node : min) {
            if (!node->get<bool>("sv_visited_CCS")) {
                cmp.push_back(G->node(node->id()));
            }
            node->set("sv_visited_CCS", true);
        }

        //Remove min from components
        Functions::removeItem(&components, min);

        //Add the new component to the SSC to return
        if (!cmp.empty())
            SCC.push_back(cmp);
    }

    //Remove attribute, free memory and return SSC
    gCopy->removeNodeAttributes("sv_visited_CCS");
    delete gCopy;
    return SCC;
}

/**
 * Adds the single nodes to SCC
 */
template<typename TNode>
const vector<NodeArray<Node<TNode> *>> Properties::_addSinglesToSCC(Graph<TNode> *G, Graph<TNode> *gCopy, vector<NodeArray<Node<TNode> *>> *SCC) {

    do {

        //Vector that holds isolated nodes
        NodeArray<Node<TNode> *> single;

        //Traverse the graph to find single nodes
        //A node is considered as a single node if the node is isolated in the graph or transposed graph
        for (Node<TNode> *node : gCopy->nodes()) {
            if (!node->inDegree() || !node->outDegree()) {
                single.push_back(G->node(node->id()));
            }
        }

        //Stop when single nodes can't be found
        if (!single.size()) {
            break;
        }

        //Push the single nodes to SCC and remove node from the graph
        for (Node<TNode> *node : single) {
            NodeArray<Node<TNode> *> cmp;
            cmp.push_back(G->node(node->id()));
            SCC->push_back(cmp);
            gCopy->removeNode(node->id());
        }

    } while(true);

    return *SCC;
}

/**
 * Returns the isolated nodes of the graph
 */
template<typename TNode>
NodeArray<Node<TNode> *> Properties::isolatedNodes(Graph<TNode> *G) {

    NodeArray<Node<TNode> *> isolated;

    for (Node<TNode> *node : G->nodes()) {
        if (node->isIsolated())
            isolated.push_back(node);
    }
    return isolated;
}

/**
 * Check whether a graph has cycle or not
 */
template<typename TNode>
bool Properties::hasCycle(Graph<TNode> *G)  {

    //The SCC tells us whether a graph contains a cycle or not
    for (NodeArray<Node<TNode> *> array : stronglyConnectedComponents(G)) {

        //In the case of undirected graphs, run the specific DFS to detect a cycle
        if (isUndirectedGraph(G)) {
            if (DepthFirstSearch::hasCycleDFS(G, array.front()))
                return true;
        }
        //Otherwise, the graph contains a cycle if any SSC has a size greater than 1
        else {
            if (array.size() > 1)
                return true;
        }
    }
    return false;
}

/**
 * Check whether a graph is a tree or not
 */
template<typename TNode>
bool Properties::isTree(Graph<TNode> *G) {

    if (isUndirectedGraph(G)) {

        //When the graph is undirected, to check whether it's a tree is very simple: only
        //is necessary check the edge-clause and checks if the graph is connected or contains a cycle.
        bool edgeClause = G->numberOfEdges() == G->numberOfNodes() - 1;
        return (edgeClause && !hasCycle(G)) || (edgeClause && isConnected(G));
    }

    else {

        //Find the start node. A node is useful as a start whether only has out-edges. Otherwise
        //the node can't be used as a start node.
        Node<TNode> *start = nullptr;
        for (Node<TNode> *node : G->nodes()) {
            if (node->outDegree() && !node->inDegree()) {
                start = node;
            }
        }

        //If start has not been found, then the graph is not a tree
        if(!start) {
            return false;
        }

        //Get start id
        TNode id = start->id();

        //Check whether a simple dfs can visit all the nodes or not
        bool dfsTest = DepthFirstSearch::depthFirstSearch(G, start->id()).size() == G->numberOfNodes();

        //delete gCopy;
        return BreadthFirstSearch::isTreeBFS(G, id) && !hasCycle(G) && dfsTest;
    }
}

/**
 * Returns the eccentricity of node
 */
template<typename TNode>
const unsigned long int Properties::eccentricity(Graph<TNode> *G, Node<TNode> *node) {

    //Eccentricity is infinity in unconnected graphs because the farthest node is inaccessible
    if (!isConnected(G))
        return numeric_limits<unsigned long int >::max();

    //Max distance starts as -infinity
    unsigned long int maxDistance = numeric_limits<unsigned long int>::min();

    //The weight of the edges is 1 to imitate the BFS
    G->addEdgeAttributes("sv_eccentricity_weight", 1);

    //Call dijkstra (BFS)
    vector<NodeArray<Node<TNode> *>> paths = Dijkstra::dijkstraAllPaths(G, node->id(), "sv_eccentricity_weight");

    //Remove attribute of edges
    G->removeEdgeAttributes("sv_eccentricity_weight");

    //Find the maximum of the shortest paths
    for (NodeArray<Node<TNode> *> path: paths) {
        if (path.size() > maxDistance)
            maxDistance = path.size();
    }

    //Return eccentricity
    return maxDistance - 1;
}

/**
 * Returns the graph's diameter
 */
template<typename TNode>
const unsigned long int Properties::diameter(Graph<TNode> *G) {

    if (!isConnected(G)) throw DiameterError();

    //Diameter starts as -infinity
    unsigned long int diameter = numeric_limits<unsigned long int>::min();

    for (Node<TNode> *node : G->nodes()) {
        unsigned long int value = eccentricity(G, node);
        if (value > diameter)
            diameter = value;
    }

    return diameter;
}

/**
 * Returns the graph's radius
 */
template<typename TNode>
const unsigned long int Properties::radius(Graph<TNode> *G) {

    if (!isConnected(G)) throw RadiusError();

    //Radius starts as infinity
    unsigned long int radius = numeric_limits<unsigned long int>::max();

    for (Node<TNode> *node : G->nodes()) {
        unsigned long int value = eccentricity(G, node);
        if (value < radius)
            radius = value;
    }

    return radius;
}

/**
 * Returns the nodes that belong to the center of the graph
 *
 * A node belongs to the center of the graph if its eccentricity is equal to the radius of graph
 */
template<typename TNode>
const NodeArray<Node<TNode> *> Properties::center(Graph<TNode> *G) {

    if (!isConnected(G)) throw CenterError();

    unsigned long int radiusG = radius(G);

    NodeArray<Node<TNode> *> center;

    for (Node<TNode> *node : G->nodes()) {
        if (eccentricity(G, node) == radiusG) {
            center.push_back(node);
        }
    }

    return center;
}


/**
 * Returns the nodes that belong to the periphery of the graph
 *
 * A node belongs to the periphery of the graph if its eccentricity is equal to the diameter of graph
 */
template<typename TNode>
const NodeArray<Node<TNode> *> Properties::periphery(Graph<TNode> *G) {

    if (!isConnected(G)) throw PeripheryError();

    unsigned long int diameterG = diameter(G);

    NodeArray<Node<TNode> *> periphery;

    for (Node<TNode> *node : G->nodes()) {
        if (eccentricity(G, node) == diameterG) {
            periphery.push_back(node);
        }
    }

    return periphery;
}


/**
 * Returns whether the graph is eulerian or not
 *
 * A graph is eulerian if all the nodes of it have even degree
 */
template<typename TNode>
const bool Properties::isEulerian(Graph<TNode> *G) {

    if (!isConnected(G)) return false;

    for (Node<TNode> *node : G->nodes()) {
        if ((long int) node->degree() % 2) {
            return false;
        }
    }
    return true;
}


/**
 * Check whether the graph contains a eulerian path or not
 *
 * A graph contains an eulerian path if number of odd degree nodes is 0 or 2
 */
template<typename TNode>
const bool Properties::hasEulerianPath(Graph<TNode> *G) {

    if (!isConnected(G)) return false;

    int oddNodes = 0;

    for (Node<TNode> *node : G->nodes()) {
        if ((long int) node->degree() % 2) {
            if (++oddNodes > 2) break;
        }
    }

    return oddNodes == 0 || oddNodes == 2;
}

/**
 * Graph density
 *
 * Calculate the number of edges divided by the number of pairs
 */
template<typename TNode>
const double Properties::density(Graph<TNode> *G) {

    double value = 0;

    if (isUndirectedGraph(G)) {
        value = ((2.0 * G->numberOfEdges()) / (G->numberOfNodes() * (G->numberOfNodes() - 1)));
    } else {
        value = (G->numberOfEdges() / (G->numberOfNodes() * (G->numberOfNodes() - 1)));
    }
    return value;
}

/**
 * Obtain transposed graph
 */
template <typename TNode> Graph<TNode> *Properties::transposed(Graph<TNode> *G) {

    if(isUndirectedGraph(G))
        throw TransposeGraphError();

    Graph<TNode> *gCopy = makeGraphCopy(G);
    gCopy->transpose();
    return gCopy;
}

/**
 * Check if a node is isolated or not
 */
template<typename TNode>
const bool Properties::isIsolated(Graph<TNode> *G, Node<TNode> *node) {
    return G->node(node->id())->isIsolated();
}



#endif //SV_NETWORK_PROPERTIES_H
