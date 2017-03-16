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

/**
 * Add the x and y coordinates to the node
 */
static void addCoordinates(Graph<int> *, Node<int> *);


/**
 * Main Function
 */
int main() {

    string file = "files" + slash + "graph_labyrinth.dat";

    /**
     * Example 1 (Undirected Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    Graph<int> *G = ReadGraphFromFile::readGraphFromFile<int>(file, "weight");

    //First add the x and y coordinates to the nodes. To do this, we use the attributes of the node.
    for (Node<int> *node : G->nodes())
        addCoordinates(G, node);

    //Call to aStar method
    NodeArray<Node<int> *> path = SV::aStarSearch(G, 11, 14, "weight", Heuristic::euclideanDistance);

    cout << "\nTest Undirected Graph\n";
    cout << path;

    cout << endl;

    /**
     * Example 2 (Directed Graph)
     *
     * To simplify the example we read the graph directly from a file.
     * The graph of example has a diamond shape.
     */
    G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    //First add the x and y coordinates to the nodes. To do this, we use the attributes of the node.
    for (Node<int> *node : G->nodes())
        addCoordinates(G, node);

    //Call to aStar method
    path = SV::aStarSearch(G, 11, 14, "weight", Heuristic::manhattanDistance);

    cout << "\nTest Directed Graph\n";
    cout << path;

    cout << endl;

    delete G;

    return 0;
}

/**
 * Add the x and y coordinates to the node
 */
static void addCoordinates(Graph<int> *G, Node<int> *node) {

    G->node(11)->add("x", 1)->add("y", 1);
    G->node(21)->add("x", 1)->add("y", 2);
    G->node(31)->add("x", 1)->add("y", 3);
    G->node(41)->add("x", 1)->add("y", 4);
    G->node(51)->add("x", 1)->add("y", 5);

    G->node(12)->add("x", 2)->add("y", 1);
    G->node(22)->add("x", 2)->add("y", 2);
    G->node(32)->add("x", 2)->add("y", 3);
    G->node(42)->add("x", 2)->add("y", 4);
    G->node(52)->add("x", 2)->add("y", 5);

    G->node(13)->add("x", 3)->add("y", 1);
    G->node(23)->add("x", 3)->add("y", 2);
    G->node(33)->add("x", 3)->add("y", 3);
    G->node(43)->add("x", 3)->add("y", 4);
    G->node(53)->add("x", 3)->add("y", 5);

    G->node(14)->add("x", 4)->add("y", 1);
    G->node(24)->add("x", 4)->add("y", 2);
    G->node(34)->add("x", 4)->add("y", 3);
    G->node(44)->add("x", 4)->add("y", 4);
    G->node(54)->add("x", 4)->add("y", 5);
}

