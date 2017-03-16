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
     * Example 1 (All paths from start to all nodes in Undirected Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    vector<NodeArray<Node<int> *>> paths = SV::allShortestPathsFromStartToAll(G, 1);

    cout << "\nTest Undirected Graph: All shortest paths from start to all\n";

    for (NodeArray<Node<int> *> path : paths)
        cout << endl << path;

    cout << endl;

    /**
     * Example 2 (All paths from start to all nodes in Directed Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    paths = SV::allShortestPathsFromStartToAll(G, 1);

    cout << "\nTest Directed Graph: All shortest paths from start to all\n";

    for (NodeArray<Node<int> *> path : paths)
        cout << endl << path;

    cout << endl;

    /**
     * Example 3 (All paths from start to goal in Directed Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    paths = SV::allPathsFromStartToGoal(G, 1, 7);

    cout << "\nTest Directed Graph: All paths from start to goal\n";

    for (NodeArray<Node<int> *> path : paths)
        cout << endl << path;

    cout << endl;

    /**
     * Example 4 (All paths from start to goal in Directed Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    paths = SV::allPathsFromStartToGoal(G, 1, 7);

    cout << "\nTest Directed Graph: All paths from start to goal\n";

    for (NodeArray<Node<int> *> path : paths)
        cout << endl << path;

    cout << endl;

    delete G;
    return 0;
}
