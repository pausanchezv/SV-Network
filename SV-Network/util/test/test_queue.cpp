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
     * Queue using an object
     */
    Queue<int> queueInt;

    //Fill queue with numbers 1-5
    for (int i = 1; i <= 5; i++) {
        queueInt.push(i);
    }

    cout << endl << "Queue integer";
    cout << endl << "Popped int: " << queueInt.pop();
    cout << endl << "Popped int: " << queueInt.pop();
    cout << endl << "Popped int: " << queueInt.pop();
    cout << endl << "Popped int: " << queueInt.pop();
    cout << endl << "Popped int: " << queueInt.pop();

    cout << endl;

    /**
     * EXAMPLE 2
     *
     * Queue using an pointer
     */
    Queue<char> *queueChar = new Queue<char>();

    char chars[5] = {'A', 'B', 'C', 'D', 'E'};

    //Fill the queue with characters
    for (int i = 0; i < 5; i++) {
        queueChar->push(chars[i]);
    }

    cout << endl << "Queue char";
    cout << endl << "Popped char: " << queueChar->pop();
    cout << endl << "Popped char: " << queueChar->pop();
    cout << endl << "Popped char: " << queueChar->pop();
    cout << endl << "Popped char: " << queueChar->pop();
    cout << endl << "Popped char: " << queueChar->pop();

    //Remember to remove the pointer
    delete queueChar;

    cout << endl;

    /**
     * EXAMPLE 3
     *
     * Using queue with nodes. The same example is valid for edges or another type of object
     */

    //Create a graph
    Graph<int> *G = new Graph<int>();

    //Insert 5 nodes into the graph
    for (int i = 1; i <= 5; i++) {
        G->addNode(i);
    }

    //Create an queue that holds the pointers of nodes
    //Note that is possible to initialize queue with a vector items,
    //(G->nodes() returns a vector that contains the nodes of the graph).
    //Also is possible to initialize the queue with a single item
    Queue<Node<int> *> *queueNode = new Queue<Node<int> *>(G->nodes());

    cout << endl << "Queue nodes";
    cout << endl << "Popped node: " << queueNode->pop();
    cout << endl << "Popped node: " << queueNode->pop();
    cout << endl << "Popped node: " << queueNode->pop();
    cout << endl << "Popped node: " << queueNode->pop();
    cout << endl << "Popped node: " << queueNode->pop();

    cout << endl;

    //Remember to remove the pointers
    delete G;
    delete queueNode;

    return 0;
}


