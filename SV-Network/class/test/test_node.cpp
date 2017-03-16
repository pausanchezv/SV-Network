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

    //When you use SV-Network, you never need to create node instances,
    //nodes are created by the program automatically when you insert a node id
    //in the graph with the action addNode(id).

    /**
     * Example 1
     *
     * Example of node type int
     */
    Node<int> *nodeInt = new Node<int>(1200);

    cout << endl << "Node integer example:\nThe node starts without attributes";
    cout << endl << nodeInt;

    //Add attributes to the node
    nodeInt->add("score", 13)->add("time", 34.9)->add("name", "Spam");
    cout << endl << nodeInt;

    //Example to get attribute
    cout << endl << "\nThe score is: ";
    cout << nodeInt->get<int>("score");

    cout << endl;

    /**
     * Example 1
     *
     * Example of node type char
     */
    Node<char> *nodeChar = new Node<char>('K');

    cout << endl << "Node char example:\nThe node starts without attributes";
    cout << endl << nodeChar;

    //Add attributes to the node
    nodeChar->add("title", "Scarface")
            ->add("director", "Brian de Palma")
            ->add("year", 1983);
    cout << endl << nodeChar;

    //Example to get attribute string with spaces
    cout << endl << "\nThe director is: ";

    //Remember that when attribute is a string and it contains spaces, is necessary to use
    //the gets() method instead of get<type>(), otherwise we will retrieve only the first word
    //of the string.
    cout << nodeChar->gets("director");

    cout << endl;

    //Id of node
    cout << endl << "ID: " << nodeChar->id();

    //Neighbors of node
    cout << endl << "Neighbors: " << nodeChar->neighbors();

    //Degree of node
    cout << endl << "Degree: " << nodeChar->degree();

    //Is isolated
    cout << endl << "Is isolated: " << nodeChar->isIsolated();


    cout << endl << "Attributes: " << nodeChar->attrs();
    cout << endl << "Has 'director' attribute: " << nodeChar->has("director");
    cout << endl << "\nClear all attributes of edge:";
    nodeChar->clear();
    cout << endl << "Attributes: " << nodeChar->attrs();

    cout << endl;

    //Remember to remove the pointers
    delete nodeInt;
    delete nodeChar;

    return 0;
}

