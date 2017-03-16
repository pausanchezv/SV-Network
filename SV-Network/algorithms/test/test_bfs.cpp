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

    /**
     * Example 1 (Undirected Graph)
     *
     * To simplify the example we read the graph directly from a file.
     *
     * The graph of example has a diamond shape.
     */
    string file = "files" + slash + "graph_diamond.dat";
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    cout << "\nTest Undirected Graph\n";

    //Breadth first search traversal
    cout << endl << "Breadth First Search Traversal";
    NodeArray<Node<int> *> bfsTraversal = SV::breadthFirstSearchTraversal(G, 1);
    cout << endl << bfsTraversal;
    cout << endl;

    //Breadth first search traversal
    cout << endl << "Breadth First Search Path";
    NodeArray<Node<int> *> bfsPath = SV::breadthFirstSearchPath(G, 1, 7);
    cout << endl << bfsPath;
    cout << endl;

    //Now try to add more nodes into the graph and retry the bfs traversal.
    //Add the nodes so that there is an unconnected graph.

    G->addEdge(8, 9);
    G->addEdge(8, 9);
    G->addEdge(9, 10);

    //Breadth first search traversal
    cout << endl << "Breadth First Search Traversal";
    bfsTraversal = SV::breadthFirstSearchTraversal(G, 1);
    cout << endl << bfsTraversal;
    cout << endl;

    //Breadth first search traversal
    cout << endl << "Breadth First Search Path";
    bfsPath = SV::breadthFirstSearchPath(G, 1, 7);
    cout << endl << bfsPath;
    cout << endl;

    /**
     * Example 1 (Directed Graph)
     *
     * To simplify the example we read the graph directly from a file.
     *
     * The graph of example has a diamond shape.
     */
    cout << endl << "\nTest Directed Graph\n";

    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    //Breadth first search traversal
    cout << endl << "Breadth First Search Traversal";
    bfsTraversal = SV::breadthFirstSearchTraversal(G, 1);
    cout << endl << bfsTraversal;
    cout << endl;

    //Breadth first search traversal
    cout << endl << "Breadth First Search Path";
    bfsPath = SV::breadthFirstSearchPath(G, 1, 7);
    cout << endl << bfsPath;
    cout << endl;

    //Now try to add more nodes into the graph and retry the bfs traversal.
    //Add the nodes so that there is an unconnected graph.

    G->addEdge(8, 9);
    G->addEdge(8, 9);
    G->addEdge(9, 10);

    //Breadth first search traversal
    cout << endl << "Breadth First Search Traversal";
    bfsTraversal = SV::breadthFirstSearchTraversal(G, 1);
    cout << endl << bfsTraversal;
    cout << endl;

    //Breadth first search traversal
    cout << endl << "Breadth First Search Path";
    bfsPath = SV::breadthFirstSearchPath(G, 1, 7);
    cout << endl << bfsPath;
    cout << endl;


    delete G;

    return 0;
}
