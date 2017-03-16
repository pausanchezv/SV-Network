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
     * Example 1 (Undirected Graph)
     *
     * To simplify the example we read the graph directly from a file.
     *
     * The graph of example has a diamond shape.
     */
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    NodeArray<Node<int> *> path = SV::uniformCostSearchPath(G, 1, 7, "weight");

    cout << "\nTest Undirected Graph\n";
    cout << path;

    cout << endl;

    /**
     * Example 2 (Directed Graph)
     *
     * To simplify the example we read the graph directly from a file.
     *
     * The graph of example has a diamond shape.
     */
    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    path = SV::uniformCostSearchPath(G, 4, 2, "weight");

    cout << "\nTest Directed Graph\n";
    cout << path;

    cout << endl;

    delete G;

    return 0;
}

