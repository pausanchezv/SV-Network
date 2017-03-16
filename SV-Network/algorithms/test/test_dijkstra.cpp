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
     * The graph of example has a diamond shape.
     */
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    vector<NodeArray<Node<int> *>> paths = SV::dijkstra(G, 1, "weight");

    cout << "\nTest Undirected Graph\n";

    for (NodeArray<Node<int> *> path : paths)
        cout << endl << path;

    cout << endl;

    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    paths = SV::dijkstra(G, 1, "weight");

    cout << "\nTest Directed Graph\n";

    for (NodeArray<Node<int> *> path : paths)
        cout << endl << path;

    cout << endl;

    delete G;
    return 0;
}