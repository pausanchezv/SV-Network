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


#include "../../SV-Network.h"

int main() {

    string file = "files" + slash + "graph_diamond.dat";

    /**
     * Read the graphs from file
     */
    Graph<string> *graph = ReadGraphFromFile::readGraphFromFile<string>(file, "weight");
    Graph<string> *diGraph = ReadGraphFromFile::readDirectedGraphFromFile<string>(file, "weight");

    /**
     * 1. Check if the graph id directed or undirected
     */
    cout << endl << "Is directed graph: " << SV::isDirected(graph);
    cout << endl << "Is directed diGraph: " << SV::isDirected(diGraph);
    cout << endl << "Is undirected graph: " << SV::isUndirected(graph);
    cout << endl << "Is undirected diGraph: " << SV::isUndirected(diGraph) << endl;

    /**
     * 2. Check whether the graph is connected or not
     */
    cout << endl << "Is connected graph: " << SV::isConnected(graph);
    cout << endl << "Is connected diGraph: " << SV::isConnected(diGraph) << endl;

    /**
     * 3. Articulation points
     */
    cout << endl << "Articulations Graph: " << SV::articulationPoints(graph);
    cout << endl << "Articulations DiGraph: " << SV::articulationPoints(diGraph) << endl;

    /**
     * 3. Bridges
     */
    cout << endl << "Articulations Graph: " << SV::bridges(graph);
    cout << endl << "Articulations DiGraph: " << SV::bridges(diGraph) << endl;

    /**
     * 4. Adjacency Matrix
     */
    cout << endl << "AdjMatrix Graph:\n" << SV::adjacencyMatrix(graph) << endl;
    cout << endl << "AdjMatrix DiGraph:\n" << SV::adjacencyMatrix(diGraph) << endl;

    /**
     * 5. Bridges
     */
    cout << endl << "Isolated nodes of Graph: " << SV::isolatedNodes(graph);
    cout << endl << "Isolated Nodes of DiGraph: " << SV::isolatedNodes(diGraph) << endl;

    /**
     * 6. Check whether the graph contains a cycle or not
     */
    cout << endl << "Graph contains a cycle: " << SV::hasCycle(graph);
    cout << endl << "DiGraph contains a cycle: " << SV::hasCycle(diGraph) << endl;

    /**
     * 7. Check whether the graph is a tree or not
     */
    cout << endl << "Graph is a tree: " << SV::isTree(graph);
    cout << endl << "DiGraph is a tree: " << SV::isTree(diGraph) << endl;

    /**
     * 8.Node eccentricity
     */
    cout << endl << "Eccentricity of node 5 in the Graph: " << SV::eccentricity(graph, "5");
    cout << endl << "Eccentricity of node 5 in the DiGraph: " << SV::eccentricity(diGraph, "5") << endl;

    //graph->addEdge("4", "80");
    /**
     * 9. Diameter of the graph
     */
    cout << endl << "Diameter of Graph: " << SV::diameter(graph);
    //cout << endl << "Diameter of Digraph: " << SV::diameter(diGraph) << endl;

    /**
     * 10. Radius of the graph
     */
    cout << endl << "Radius of Graph: " << SV::radius(graph);
    //cout << endl << "Radius of Digraph: " << SV::radius(diGraph) << endl;

    /**
     * 11. Center of the graph
     */
    cout << endl << "Center of Graph: " << SV::center(graph);
    //cout << endl << "Center of Digraph: " << SV::center(diGraph) << endl;

    /**
     * 12. Periphery of the graph
     */
    cout << endl << "Periphery of Graph: " << SV::periphery(graph) << endl;
    //cout << endl << "Periphery of Digraph: " << SV::periphery(diGraph) << endl;

    /**
     * 13. Check if the graph is eulerian or not
     */
    cout << endl << "Is eulerian graph: " << SV::isEulerian(graph);
    cout << endl << "Is eulerian diGraph: " << SV::isEulerian(diGraph) << endl;

    /**
     * 14. Check if the graph cantains an eulerian path or not
     */
    cout << endl << "The graph contains an eulerian path: " << SV::hasEulerianPath(graph);
    cout << endl << "The graph contains an eulerian path: " << SV::hasEulerianPath(diGraph) << endl;

    /**
     * 15. Graph density
     */
    cout << endl << "Graph density: " << SV::density(graph);
    cout << endl << "DiGraph density: " << SV::density(diGraph) << endl;

    /**
     * 16. Check whether a node is isolated or not
     */
    cout << endl << "Is isolated node 4 in graph: " << SV::isIsolated(graph, "4");
    cout << endl << "Is isolated node 4 in diGraph: " << SV::isIsolated(diGraph, "4") << endl;

    /**
     * 17. Obtain an graph transposed from the current graph
     */
    cout << endl << "Edges of the DiGraph: " << diGraph->edges();
    Graph<string> *transposedDiGraph = SV::transposed(diGraph);
    cout << endl << "Edges of the DiGraph transposed: " << transposedDiGraph->edges() << endl;

    delete transposedDiGraph;

    /**
     * 18. Transpose the current graph
     */
    cout << endl << "Edges of the DiGraph: " << diGraph->edges();
    SV::transpose(diGraph);
    cout << endl << "Edges of the DiGraph transposed: " << diGraph->edges() << endl;

    delete graph;
    delete diGraph;

    return 0;
}
