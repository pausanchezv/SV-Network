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
     * Example 1
     *
     * To simplify the example we read the directed graph directly from a file with an initialized
     * attribute for all edges, that is the weight of it.
     *
     * The graph of example has a diamond shape.
     */
    string file = "files" + slash + "graph_diamond.dat";
    Graph<int> *G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

    //Graph description
    cout << endl << "The graph:";
    cout << endl << "Graph shape: " << G;
    cout << endl << "Nodes: " << G->nodes();
    cout << endl << "Edges: " << G->edges();
    cout << endl << "Neighbors of node 3: " << G->neighbors(3);
    cout << endl << "Number of nodes: " << G->numberOfNodes();
    cout << endl << "Number of edges: " << G->numberOfEdges();
    cout << endl;

    //Remove a node from the graph
    //Note that the edges that are connected to the node are also deleted
    cout << endl << "Remove node 3 from the graph:";
    G->removeNode(3);
    cout << endl << "Nodes: " << G->nodes();
    cout << endl << "Edges: " << G->edges();
    cout << endl;

    //Add the node 3 to the graph again
    //Note that whether we want the graph as the initial graph, we must insert the edges again
    cout << endl << "Add node 3 to the graph:";
    G->addNode(3);
    cout << endl << "Nodes: " << G->nodes();
    cout << endl << "Edges: " << G->edges();
    cout << endl;

    //Insert again the edges that connects with node 3
    cout << endl << "Add edges from node 3:";
    G->addEdge(1, 3);
    G->addEdge(2, 3);
    G->addEdge(4, 3);
    G->addEdge(5, 3);
    G->addEdge(6, 3);
    cout << endl << "Nodes: " << G->nodes();
    cout << endl << "Edges: " << G->edges();
    cout << endl;

    //Add an attribute to all the nodes of the graph
    cout << endl << "Add an attribute to all nodes";
    G->addNodeAttributes("sugar", 0);

    for (Node<int> *node : G->nodes()) {
        cout << endl << node;
    }
    cout << endl;

    //Add an attribute to all the nodes of the graph
    cout << endl << "Rename attribute sugar to coffee";
    G->renameNodeAttributes("sugar", "coffee");

    for (Node<int> *node : G->nodes()) {
        cout << endl << node;
    }
    cout << endl;

    //Reset or change value of attribute to all nodes in the graph
    cout << endl << "Reset attribute";
    G->setNodeAttributes("coffee", 100);

    for (Node<int> *node : G->nodes()) {
        cout << endl << node;
    }
    cout << endl;

    //Reset or change value of attribute to all nodes in the graph
    cout << endl << "Remove attribute coffee";
    G->removeNodeAttributes("coffee");

    for (Node<int> *node : G->nodes()) {
        cout << endl << node;
    }
    cout << endl;

    cout << endl << "Has node 3: " << G->hasNode(3);
    cout << endl << "Has edge (3, 6): " << G->hasEdge(3, 6);
    cout << endl << "Is directed: " << G->isDirected();
    cout << endl;

    cout << endl << "Graph transpose: ";
    cout << endl << "Edges before transposition: " << G->edges();
    G->transpose();
    cout << endl << "Edges after transposition: " << G->edges();
    cout << endl << "There are changes because de graph is directed";
    cout << endl;

    //Remember to remove the pointers
    delete G;

    return 0;
}



