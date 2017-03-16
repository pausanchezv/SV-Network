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

#ifndef SV_NETWORK_HEURISTIC_H
#define SV_NETWORK_HEURISTIC_H

/**
 * Class Heuristic
 *
 * Class holding any possibles heuristics to solve search problems.
 */
class Heuristic {

public:

    /**
     * Manhattan distance between 2 nodes
     */
    static double manhattanDistance(Node<int> *, Node<int> *);

    /**
     * Manhattan distance between 2 nodes
     */
    static double euclideanDistance(Node<int> *, Node<int> *);
};

/**
 * Manhattan distance between 2 nodes
 */
double Heuristic::manhattanDistance(Node<int> *S, Node<int> *V)  {


    double v1 = abs(S->get<int>("x") - V->get<int>("x"));
    double v2 = abs(S->get<int>("y") - V->get<int>("y"));

    return v1 + v2;
}

/**
 * Manhattan distance between 2 nodes
 */
double Heuristic::euclideanDistance(Node<int> *S, Node<int> *V) {

    double v1 = pow((S->get<int>("x") - V->get<int>("x")), 2);
    double v2 = pow((S->get<int>("y") - V->get<int>("y")), 2);

    return pow((v1 + v2), 0.5);
}


#endif //SV_NETWORK_HEURISTIC_H
