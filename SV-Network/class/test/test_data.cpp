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
     * To simplify the example we read the graph directly from a file with an initialized
     * attribute for all edges, that is the weight of it.
     *
     * The graph of example has a square shape.
     */
    string file = "files" + slash + "graph_square.dat";
    Graph<string> *G = ReadGraphFromFile::readDirectedGraphFromFile<string>(file, "weight");

    cout << endl << "The attributes of the nodes starts empty but the attributes of the edges starts with weight attribute that was read from file.";
    cout << endl << "Nodes: " << G->nodes();
    cout << endl << "Edges: " << G->edges();

    cout << endl;

    cout << endl << "Now add an score attribute to the node \"NE\":";
    G->node("NE")->add("score", 1000);
    cout << endl << "Nodes: " << G->nodes();

    cout << endl;

    cout << endl << "Now add a spam attribute to all nodes:";
    G->addNodeAttributes("spam", "eggs");
    cout << endl << "Nodes: " << G->nodes();

    cout << endl;

    cout << endl << "Now remove the spam attribute from node \"NE\":";
    G->node("NE")->removeAttr("spam");
    cout << endl << "Nodes: " << G->nodes();

    cout << endl;

    cout << endl << "Now rename the weight attribute to all edges:";
    G->renameEdgeAttributes("weight", "distance");
    cout << endl << "Edges: " << G->edges();

    cout << endl;

    cout << endl << "Now change the distance attribute value to edge (\"SW\", \"NW\"):";
    G->edge("SW", "NW")->set("distance", 0.5);
    cout << endl << "Edges: " << G->edges();

    cout << endl;

    cout << endl << "Now clear all attributes from edge (\"SW\", \"NW\"):";
    G->edge("SW", "NW")->clear();
    cout << endl << "Edges: " << G->edges();

    cout << endl;

    cout << endl << "Now get any attribute of nodes or edges";
    cout << endl << "NE score: " << G->node("NE")->get<int>("score");
    cout << endl << "(SE, SW) distance: " << G->edge("SE", "SW")->get<double>("distance");
    cout << endl << "NW spam: " << G->node("NW")->get<string>("spam");

    cout << endl;

    cout << endl << "Now add a string attribute that it value contains spaces (\"SW\", \"NW\"):";
    G->edge("SW", "NW")->add("name", "Attribute value type string with spaces");
    cout << endl << "Get attribute using 'gets': " << G->edge("SW", "NW")->gets("name");
    cout << endl << "Get attribute using 'get<type>': " << G->edge("SW", "NW")->get<string>("name");

    cout << endl;

    //Remember to remove pointers
    delete G;

    return 0;
}