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

    string file = "files" + slash + "graph_test.dat";

    /**
     * Example 1 (Undirected Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    /**
     * Get the minomum spanning tree and the maximum spanning tree
     */
    Graph<int> *minimumSpanningTree = SV::minimumSpanningTree(G, "weight");
    Graph<int> *maximumSpanningTree = SV::maximumSpanningTree(G, "weight");

    /**
     * Minimum Spanning Tree
     */
    cout << endl << "Minimum Spanning Tree:";
    cout << endl << minimumSpanningTree->edges() << endl;

    /**
     * Maximum Spanning Tree
     */
    cout << endl << "Maximum Spanning Tree:";
    cout << endl << maximumSpanningTree->edges() << endl;

    //Remember to remove all pointers
    delete minimumSpanningTree;
    delete maximumSpanningTree;
    delete G;
    return 0;
}