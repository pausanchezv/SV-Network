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
     * EXAMPLE 1
     *
     * The PriorityQueue is prepared to work with two types of objects: nodes and edges.
     * It is necessary to initialize an attribute that will serve to maintain the priority of the elements.
     *
     * The priority queue uses a heap to sort its elements.
     */

    //Create a graph where the type of nodes is, e.g., string.
    Graph<string> *G = new Graph<string>();

    //Create the identifiers of nodes
    string cities[] = {"Barcelona", "London", "New York", "Paris", "Boston"};

    //Add nodes to the graph
    for (string city : cities) {
        G->addNode(city);
    }

    //Add the attribute of nodes that indicates the priority
    G->node("Barcelona")->add("priority", 10.5);
    G->node("London")->add("priority", 1.1);
    G->node("New York")->add("priority", 20);
    G->node("Paris")->add("priority", 16);
    G->node("Boston")->add("priority", -2);


    //Creates the priority queue with the attribute that indicate the priority of element in the queue
    PriorityQueue<Node<string> *> *queue = new PriorityQueue<Node<string> *>("priority");

    //Push the nodes to the queue
    queue->push(G->node("Barcelona"));
    queue->push(G->node("London"));
    queue->push(G->node("New York"));
    queue->push(G->node("Paris"));
    queue->push(G->node("Boston"));

    //Pop the items from the queue
    cout << "Popped nodes:" << endl;
    cout << endl << queue->pop();
    cout << endl << queue->pop();
    cout << endl << queue->pop();
    cout << endl << queue->pop();
    cout << endl << queue->pop();

    cout << endl;

    //Remember to remove the pointers
    delete queue;
    delete G;

    return 0;
}


