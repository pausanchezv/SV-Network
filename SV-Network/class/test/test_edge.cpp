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

    //When you use SV-Network, you never need to create edge instances,
    //edges are created by the program automatically when you insert a edge
    //in the graph with the action addEdge(Node, Node).

    /**
     * Example 1
     *
     * Edge containing integer nodes
     */

    //Creation of nodes
    Node<int> *n1 = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);

    //Example of edge type int. The nodes 1 and 2 are created automatically by the program
    Edge<int> *edgeInt = new Edge<int>(n1, n2);

    cout << endl << "Edge integer example:\nThe edge starts without attributes";
    cout << endl << edgeInt;

    //Add attributes to the edge
    edgeInt->add("weight", 13)->add("total_distance", 34.9)->add("name", "Edge name");
    cout << endl << edgeInt;

    //Example to get attribute
    cout << endl << "\nThe name is: ";

    //Remember that when attribute is a string and it contains spaces, is necessary to use
    //the gets() method instead of get<type>(), otherwise we will retrieve only the first word
    //of the string.
    cout << edgeInt->gets("name");

    cout << endl;


    /**
     * Example 2
     *
     * Edge containing char nodes
     */

    //Creation of nodes
    Node<char> *c1 = new Node<char>('X');
    Node<char> *c2 = new Node<char>('Y');

    //Example of edge type char.The nodes X and Y are created automatically by the program.
    Edge<char> *edgeChar = new Edge<char>(c1, c2);

    cout << endl << "Edge char example:\nThe edge starts without attributes";
    cout << endl << edgeChar;

    //Add attributes to the node.
    edgeChar->add("title", "Kingdom Rush")
            ->add("OS", "Android & iOS")
            ->add("year", 2013);
    cout << endl << edgeChar;

    //Example to get attribute string with spaces
    cout << endl << "\nThe title is: ";
    cout << edgeChar->gets("title");

    cout << "\nThe year is: ";
    cout << edgeChar->get<int>("year");

    cout << endl;

    cout << endl << "Node S: " << edgeChar->getNode_S();
    cout << endl << "Node V: " << edgeChar->getNode_V();
    cout << endl << "Contains: " << edgeChar->contains(edgeChar->getNode_S());
    cout << endl << "Attributes: " << edgeChar->attrs();
    cout << endl << "Has 'perk' attribute: " << edgeChar->has("perk");
    cout << endl << "Edge before swap (Node S): " << edgeChar->getNode_S();
    edgeChar->swap();
    cout << endl << "Edge after swap (Node S): " << edgeChar->getNode_S();

    cout << endl << "\nClear all attributes of edge:";
    edgeChar->clear();
    cout << endl << "Attributes: " << edgeChar->attrs();

    cout << endl;

    //Remember to remove the pointers
    delete edgeInt;
    delete edgeChar;

    return 0;
}



