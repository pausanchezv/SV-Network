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

#ifndef SV_NETWORK_READGRAPHFROMFILE_H
#define SV_NETWORK_READGRAPHFROMFILE_H

#include <fstream>
#include <iterator>

using namespace std;

/**
 * Class ReadGraphFromFile
 *
 * There are 4 ways to read a graph from file:
 *
 * 1. Read an undirected graph
 * 2. Read an undirected weighted graph
 * 3. Read a directed graph
 * 4. Read a directed weighted graph
 *
 * Depending on whether the graph is weighted or not, it's necessary to call the method with a different
 * number of arguments.
 */
class ReadGraphFromFile {

    /**
     * General method to read a graph from file
     */
    template <typename TNode> static Graph<TNode> *_constructGraph(Graph<TNode> *G, string key, unsigned int num, string file);


public:

    /**
     * Read an undirected graph from file
     */
    template <typename TNode> static Graph<TNode> *readGraphFromFile(string file);

    /**
     * Read a weighted graph from file
     */
    template <typename TNode> static Graph<TNode> *readGraphFromFile(string file, string key);

    /**
     * Read a directed graph from file
     */
    template <typename TNode> static Graph<TNode> *readDirectedGraphFromFile(string file);

    /**
     * Read a directed weighted graph from file
     */
    template <typename TNode> static Graph<TNode> *readDirectedGraphFromFile(string file, string key);
};

/**
 * General method to read a graph from file
 */
template<typename TNode>
Graph<TNode> *ReadGraphFromFile::_constructGraph(Graph<TNode> *G, string key, unsigned int num, const string file) {

    //Exit whether file doesn't exists
    if (!Functions::exists(file)) {
        delete G;
        throw IOFileError(file);
    }

    //Create stream obj
    ifstream input(file);

    //Create a string to hold the current line
    string line;

    while (getline(input, line)) {

        //Split string to get the value of attribute
        istringstream iss(line);
        vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};

        //Split string to get nodes to insert in the graph
        istringstream newline(line);
        vector<TNode> tTokens{istream_iterator<TNode>{newline}, istream_iterator<TNode>{}};

        //Do nothing for the empty lines
        if (tokens.size() < 1)
            continue;

        //Check whether the format of file is correctly
        if (tokens.size() != num) {
            throw IOError(num, tokens.size());
        }

        //Insert the objects to the graph
        if (num == 2)
            G->addEdge(tTokens[0], tTokens[1]);
        else
            G->addEdge(tTokens[0], tTokens[1])->add(key, stod(tokens[2]));
    }

    input.close();

    return G;
}

/**
 * Read an undirected graph from file
 */
template<typename TNode>
Graph<TNode> *ReadGraphFromFile::readGraphFromFile(string file) {
    Graph<TNode> *G = new Graph<TNode>();
    return _constructGraph(G, "", 2, file);
}

/**
 * Read a weighted graph from file
 */
template<typename TNode>
Graph<TNode> *ReadGraphFromFile::readGraphFromFile(string file, string key) {
    Graph<TNode> *G = new Graph<TNode>();
    return _constructGraph(G, key, 3, file);
}

/**
 * Read a directed graph from file
 */
template<typename TNode>
Graph<TNode> *ReadGraphFromFile::readDirectedGraphFromFile(string file) {
    Graph<TNode> *G = new DiGraph<TNode>();
    return _constructGraph(G, "", 2, file);
}

/**
 * Read a directed weighted graph from file
 */
template<typename TNode>
Graph<TNode> *ReadGraphFromFile::readDirectedGraphFromFile(string file, string key) {
    Graph<TNode> *G = new DiGraph<TNode>();
    return _constructGraph(G, key, 3, file);
}

#endif //SV_NETWORK_READGRAPHFROMFILE_H
