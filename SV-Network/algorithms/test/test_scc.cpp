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
     * Example 1
     *
     * Strongly Connected Components in undirected graphs
     */
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    vector<NodeArray<Node<int> *>> SSC = SV::stronglyConnectedComponents(G);

    cout << endl << "Strongly Connected Components - Undirected graph";

    for (NodeArray<Node<int> *> component : SSC)
        cout << endl << component;

    cout << endl;

    /**
     * Example 2
     *
     * Strongly Connected components after adding a subgraph to the graph
     */
    cout << endl << "Strongly Connected components after adding a subgraph to the graph";
    G->addEdge(8, 9);
    G->addEdge(10, 8);
    G->addEdge(9, 10);


    SSC = SV::stronglyConnectedComponents(G);

    for (NodeArray<Node<int> *> component : SSC)
        cout << endl << component;

    cout << endl;

    /**
     * Example 3
     *
     * Strongly Connected Components in directed graphs
     */
    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    SSC = SV::stronglyConnectedComponents(G);

    cout << endl << "Strongly Connected Components - Directed graph";

    for (NodeArray<Node<int> *> component : SSC)
        cout << endl << component;

    cout << endl;

    /**
     * Example 4
     *
     * Strongly Connected components after adding a subgraph to the graph
     */
    cout << endl << "Strongly Connected components after adding a subgraph to the graph";
    G->addEdge(8, 9);
    G->addEdge(10, 8);
    G->addEdge(9, 10);


    SSC = SV::stronglyConnectedComponents(G);

    for (NodeArray<Node<int> *> component : SSC)
        cout << endl << component;

    cout << endl;

    delete G;

    return 0;
}