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

#ifndef SV_NETWORK_SV_NETWORK_H
#define SV_NETWORK_SV_NETWORK_H

#include "class/DiGraph.h"
#include "IO/ReadGraphFromFile.h"

/**
 * Class SV
 *
 * This is the main class of the library. It's necessary to include this class in the project to use the
 * SV-Network algorithms.
 */
class SV {


public:

    /**
     * Breadth First Search Path
     */
    template <typename TNode> static NodeArray<Node<TNode> *> depthFirstSearchPath(Graph<TNode> *graph, TNode start, TNode goal);

    /**
     * Breadth First Search Traversal
     */
    template <typename TNode> static NodeArray<Node<TNode> *> depthFirstSearchTraversal(Graph<TNode> *graph, TNode start);

    /**
     * Breadth First Search Path
     */
    template <typename TNode> static NodeArray<Node<TNode> *> breadthFirstSearchPath(Graph<TNode> *graph, TNode start, TNode goal);

    /**
     * Breadth First Search Traversal
     */
    template <typename TNode> static NodeArray<Node<TNode> *> breadthFirstSearchTraversal(Graph<TNode> *graph, TNode start);

    /**
     * Uniform Cost Search Path
     */
    template <typename TNode> static NodeArray<Node<TNode> *> uniformCostSearchPath(Graph<TNode> *graph, TNode start, TNode goal, string);

    /**
     * Uniform Cost Search Path
     */
    template <typename TNode> static NodeArray<Node<TNode> *> aStarSearch(Graph<TNode> *graph, TNode start, TNode goal, string, double (*)(Node<TNode>*, Node<TNode>*));

    /**
     * All possible paths between two nodes
     */
    template<typename TNode> static vector<NodeArray<Node<TNode> *>> allPathsFromStartToGoal(Graph<TNode> *, TNode, TNode);

    /**
     * Returns all shortest paths between a start node and other nodes from graph (weighted graph)
     */
    template <typename TNode> static vector<NodeArray<Node<TNode> *>> dijkstra(Graph<TNode> *, TNode, string);

    /**
     * Returns all shortest paths between a start node and other nodes from graph (non weighted graph)
     */
    template <typename TNode> static vector<NodeArray<Node<TNode> *>> allShortestPathsFromStartToAll(Graph<TNode> *, TNode);

    /**
     * Check whether graph is connected or not
     */
    template <typename TNode> static const bool isConnected(Graph<TNode> *graph);

    /**
     * Returns graph's articulation points
     *
     * A point of articulation in a graph is a node that if it is removed, the number of
     * connected components of the graph increases.
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> articulationPoints(Graph<TNode> *);

    /**
     * Returns whether the graph has articulation points or not
     */
    template <typename TNode> static const bool hasArticulationPoints(Graph<TNode> *);

    /**
     * Returns the number of graph's connected components
     * A connected component in a graph is a subgraph that is fully connected.
     */
    template <typename TNode> static const vector<NodeArray<Node<TNode> *>> stronglyConnectedComponents(Graph<TNode> *);

    /**
     * Returns the number of graph's connected subgraphs
     */
    template <typename TNode> static const int numStronglyConnectedComponents(Graph<TNode> *);

    /**
     * Minimum Spanning Tree (Kruskal)
     */
    template <typename TNode> static Graph<TNode> *minimumSpanningTree(Graph<TNode> *, string);

    /**
     * Maximum Spanning Tree (Kruskal)
     */
    template <typename TNode> static Graph<TNode> *maximumSpanningTree(Graph<TNode> *, string);

    /**
     * Check whether the graph contains a cycle
     */
    template <typename TNode> static bool hasCycle(Graph<TNode> *);

    /**
     * Check whether the graph is a tree or not
     */
    template <typename TNode> static bool isTree(Graph<TNode> *);

    /**
     * Returns the graph's adjacency matrix
     */
    template <typename TNode> static const AdjMatrix adjacencyMatrix(Graph<TNode> *);

    /**
     * Returns graph's bridges
     *
     * A bridge in a graph is a edge that if it is removed, the number of
     * connected components of the graph increases.
     */
    template <typename TNode> static const EdgeArray<Edge<TNode> *> bridges(Graph<TNode> *);

    /**
     * Make a mcopy of the graph
     */
    template <typename TNode> static const Graph<TNode> *makeGraphCopy(Graph<TNode> *);

    /**
     * Returns the eccentricity of node
     *
     * The eccentricity of a node is the shortest path to the farthest node of the graph
     */
    template<typename TNode, typename T> static const unsigned long int eccentricity(Graph<TNode> *, T);

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
     * Transpose the graph
     */
    template <typename TNode> static void transpose(Graph<TNode> *);

    /**
     * Check whether a node is isolated or not
     */
    template <typename TNode, typename T> static const bool isIsolated(Graph<TNode> *, T);

    /**
     * Check whether the graph is directed
     */
    template <typename TNode> static const bool isDirected(Graph<TNode> *);

    /**
     * Check whether the graph is undirected
     */
    template <typename TNode> static const bool isUndirected(Graph<TNode> *);

    /**
     * Returns the isolated nodes od the graph
     */
    template <typename TNode> static const NodeArray<Node<TNode> *> isolatedNodes(Graph<TNode> *);




};

/**
 * Breadth First Search Path
 */
template<typename TNode> NodeArray<Node<TNode> *>
SV::breadthFirstSearchPath(Graph<TNode> *graph, TNode start, TNode goal) {
    return BreadthFirstSearch::bfsPath(graph, start, goal);
}

/**
 * Breadth First Search Traversal
 */
template<typename TNode> NodeArray<Node<TNode> *>
SV::breadthFirstSearchTraversal(Graph<TNode> *graph, TNode start) {
    return BreadthFirstSearch::breadthFirstSearchFull(graph, start);
}

/**
 * Breadth First Search Path
 */
template<typename TNode> NodeArray<Node<TNode> *>
SV::depthFirstSearchPath(Graph<TNode> *graph, TNode start, TNode goal) {
    return DepthFirstSearch::dfsPath(graph, start, goal);
}

/**
 * Breadth First Search Traversal
 */
template<typename TNode> NodeArray<Node<TNode> *>
SV::depthFirstSearchTraversal(Graph<TNode> *graph, TNode start) {
    return DepthFirstSearch::depthFirstSearchFull(graph, start);
}

/**
 * All possible paths between two nodes
 */
template<typename TNode> vector<NodeArray<Node<TNode> *>>
SV::allPathsFromStartToGoal(Graph<TNode> *graph, TNode start, TNode goal) {
    return Paths::allPathsBFS(graph, start, goal);
}

/**
 * Uniform Cost Search Path
 */
template<typename TNode> NodeArray<Node<TNode> *>
SV::uniformCostSearchPath(Graph<TNode> *graph, TNode start, TNode goal, string attr) {
    return UniformCostSearch::ucsPath(graph, start, goal, attr);
}

/**
 * Uniform Cost Search Path
 */
template<typename TNode> NodeArray<Node<TNode> *>
SV::aStarSearch(Graph<TNode> *graph, TNode start, TNode goal, string attr, double (*heuristic)(Node<TNode> *, Node<TNode> *)) {
    return AstarSearch::astarPath(graph, start, goal, attr, heuristic);
}

/**
 * Returns all shortest paths between a start node and other nodes from graph (weighted graph)
 */
template<typename TNode>
vector<NodeArray<Node<TNode> *>> SV::dijkstra(Graph<TNode> *G, TNode start, string attr) {
    return Dijkstra::dijkstraAllPaths(G, start, attr);
}


/**
 * Returns all shortest paths between a start node and other nodes from graph (non weighted graph)
 */
template<typename TNode>
vector<NodeArray<Node<TNode> *>> SV::allShortestPathsFromStartToAll(Graph<TNode> *G, TNode start) {

    //The weight of the edges is 1 to imitate the BFS
    G->addEdgeAttributes("sv_bfs_paths_weight", 1);

    //Call dijkstra (BFS)
    vector<NodeArray<Node<TNode> *>> paths = Dijkstra::dijkstraAllPaths(G, start, "sv_bfs_paths_weight");

    //Remove attribute of edges
    G->removeEdgeAttributes("sv_bfs_paths_weight");

    return paths;
}


/**
 * Check whether graph is connected or not
 */
template<typename TNode>
const bool SV::isConnected(Graph<TNode> *G)  {
    return Properties::isConnected(G);
}

/**
 * Returns graph's articulation points
 *
 * A point of articulation in a graph is a node that if it is removed, the number of
 * connected components of the graph increases.
 */
template<typename TNode>
const NodeArray<Node<TNode> *> SV::articulationPoints(Graph<TNode> *G) {
    return Properties::articulationPoints(G);
}

/**
 * Returns whether the graph has articulation points or not
 */
template<typename TNode>
const bool SV::hasArticulationPoints(Graph<TNode> *G){
    return articulationPoints(G).size() > 0;
}

/**
 * Returns the number of graph's connected components
 * A connected component in a graph is a subgraph that is fully connected.
 */
template<typename TNode>
const vector<NodeArray<Node<TNode> *>> SV::stronglyConnectedComponents(Graph<TNode> *G){
    return Properties::stronglyConnectedComponents(G);
}

/**
 * Returns the number of graph's connected subgraphs
 */
template<typename TNode>
const int SV::numStronglyConnectedComponents(Graph<TNode> *G) {
    return (int) stronglyConnectedComponents(G).size() ;
}

/**
 * Minimum Spannig Tree (Kruskal)
 */
template<typename TNode>
Graph<TNode> *SV::minimumSpanningTree(Graph<TNode> *G, string attr) {
    if (G->isDirected()) {
        return BacktrackingMST::directedMST(G, attr, (Edge<int> *) nullptr, vector<Edge<int> *>(), false);
    }
    return Kruskal::kruskal(G, attr, false);
}

/**
 * Maximum Spanning Tree (Kruskal)
 */
template<typename TNode>
Graph<TNode> *SV::maximumSpanningTree(Graph<TNode> *G, string attr) {
    if (G->isDirected()) {
        return BacktrackingMST::directedMST(G, attr, (Edge<int> *) nullptr, vector<Edge<int> *>(), true);
    }
    return Kruskal::kruskal(G, attr, true);
}

/**
 * Check whether the graph contains a cycle
 */
template<typename TNode>
bool SV::hasCycle(Graph<TNode> *G) {
    return Properties::hasCycle(G);
}

/**
 * Check whether the graph is a tree or not
 */
template<typename TNode>
bool SV::isTree(Graph<TNode> *G) {
    return Properties::isTree(G);
}

/**
 * Returns the graph's adjacency matrix
 */
template<typename TNode>
const AdjMatrix SV::adjacencyMatrix(Graph<TNode> *G) {
    return Properties::adjacencyMatrix(G);
}

/**
 * Returns the graph's bridges
 */
template<typename TNode>
const EdgeArray<Edge<TNode> *> SV::bridges(Graph<TNode> *G) {
    return Properties::bridges(G);
}

/**
 * Make a copy of the graph
 */
template<typename TNode>
const Graph<TNode> *SV::makeGraphCopy(Graph<TNode> *G) {
    return Properties::makeGraphCopy(G);
}

/**
 * Returns the eccentricity of node
 *
 * The eccentricity of a node is the shortest path to the farthest node of the graph
 */
template<typename TNode, typename T>
const unsigned long int SV::eccentricity(Graph<TNode> *G, T id) {
    return Properties::eccentricity(G, G->node(id));
}

/**
 * Returns the graph's diameter
 *
 * The radius of the graph is the maximun of the graph's eccentricities
 */
template<typename TNode>
const unsigned long int SV::diameter(Graph<TNode> *G) {
    return Properties::diameter(G);
}

/**
 * Returns the graph's radius
 *
 * The radius of the graph is the minimum of the graph's eccentricities
 */
template<typename TNode>
const unsigned long int SV::radius(Graph<TNode> *G) {
    return Properties::radius(G);
}

/**
 * Returns the nodes that belong to the center of the graph
 *
 * A node belongs to the center of the graph if its eccentricity is equal to the radius of graph
 */
template<typename TNode>
const NodeArray<Node<TNode> *> SV::center(Graph<TNode> *G) {
    return Properties::center(G);
}

/**
 * Returns the nodes that belong to the periphery of the graph
 *
 * A node belongs to the periphery of the graph if its eccentricity is equal to the diameter of graph
 */
template<typename TNode>
const NodeArray<Node<TNode> *> SV::periphery(Graph<TNode> *G) {
    return Properties::periphery(G);
}

/**
 * Returns whether the graph is eulerian or not
 *
 * A graph is eulerian if all the nodes of it have even degree
 */
template<typename TNode>
const bool SV::isEulerian(Graph<TNode> *G) {
    return Properties::isEulerian(G);
}

/**
 * Check whether the graph contains a eulerian path or not
 *
 * A graph contains an eulerian path if number of odd degree nodes is 0 or 2
 */
template<typename TNode>
const bool SV::hasEulerianPath(Graph<TNode> *G) {
    return Properties::hasEulerianPath(G);
}

/**
 * Graph density
 *
 * Calculate the number of edges divided by the number of pairs
 */
template<typename TNode>
const double SV::density(Graph<TNode> *G) {
    return Properties::density(G);
}

/**
 * Obtain transposed graph
 */
template<typename TNode>
Graph<TNode> *SV::transposed(Graph<TNode> *G) {
    return Properties::transposed(G);
}

/**
 * Check whetehr a node is isolated or not
 */
template<typename TNode, typename T>
const bool SV::isIsolated(Graph<TNode> *G, T id) {
    return Properties::isIsolated(G, G->node(id));
}

/**
 * Check whether the graph is directed
 */
template<typename TNode>
const bool SV::isDirected(Graph<TNode> *G) {
    return Properties::isDirectedGraph(G);
}

/**
 * Check whether the graph is undirected
 */
template<typename TNode>
const bool SV::isUndirected(Graph<TNode> *G) {
    return Properties::isUndirectedGraph(G);
}

/**
 * Returns the isolated nodes of the graph
 */
template<typename TNode>
const NodeArray<Node<TNode> *> SV::isolatedNodes(Graph<TNode> *G) {
    return Properties::isolatedNodes(G);
}

/**
 * Transpose the graph
 */
template<typename TNode>
void SV::transpose(Graph<TNode> *G) {
    G->transpose();
}

/**
 * Define a prototype of slash
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    static const std::string slash="\\";
#else
    static const std::string slash="/";
#endif


#endif //SV_NETWORK_SV_NETWORK_H
