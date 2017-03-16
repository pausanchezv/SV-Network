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

    /*
     * EXAMPLE 1
     *
     * Stack using an object
     */
    Stack<int> stackInt;

    //Fill the stack with numbers 1-5
    for (int i = 1; i <= 5; i++) {
        stackInt.push(i);
    }

    cout << endl << "Stack integer";
    cout << endl << "Popped int: " << stackInt.pop();
    cout << endl << "Popped int: " << stackInt.pop();
    cout << endl << "Popped int: " << stackInt.pop();
    cout << endl << "Popped int: " << stackInt.pop();
    cout << endl << "Popped int: " << stackInt.pop();

    cout << endl;

    /**
     * EXAMPLE 2
     *
     * Stack using an pointer
     */
    Stack<char> *stackChar = new Stack<char>();

    char chars[5] = {'A', 'B', 'C', 'D', 'E'};

    //Fill the stack with characters
    for (int i = 0; i < 5; i++) {
        stackChar->push(chars[i]);
    }

    cout << endl << "Stack char";
    cout << endl << "Popped char: " << stackChar->pop();
    cout << endl << "Popped char: " << stackChar->pop();
    cout << endl << "Popped char: " << stackChar->pop();
    cout << endl << "Popped char: " << stackChar->pop();
    cout << endl << "Popped char: " << stackChar->pop();

    //Remember to remove the pointer
    delete stackChar;

    cout << endl;

    /**
     * EXAMPLE 3
     *
     * Using stack with nodes. The same example is valid for edges or another type of object
     */

    //Create a graph
    Graph<int> *G = new Graph<int>();

    //Insert 5 nodes into the graph
    for (int i = 1; i <= 5; i++) {
        G->addNode(i);
    }

    //Create a stack that holds the pointers of nodes
    //Note that is possible to initialize stack with a vector items,
    //(G->nodes() returns a vector that contains the nodes of the graph).
    //Also is possible to initialize the stack with a single item
    Stack<Node<int> *> *stackNode = new Stack<Node<int> *>(G->nodes());

    cout << endl << "Queue nodes";
    cout << endl << "Popped node: " << stackNode->pop();
    cout << endl << "Popped node: " << stackNode->pop();
    cout << endl << "Popped node: " << stackNode->pop();
    cout << endl << "Popped node: " << stackNode->pop();
    cout << endl << "Popped node: " << stackNode->pop();

    cout << endl;

    //Remember to remove the pointers
    delete G;
    delete stackNode;

    return 0;
}

