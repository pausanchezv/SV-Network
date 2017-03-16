
#include <memory>
#include "SV-Network.h"
#include <cmath>




int main() {

    //Graph<int> * G = new Graph<int>();

    string file = "/media/pausanchezv/DiskData/Dropbox/SV-Network_new/graph_test.dat";

    Graph<int> * G = ReadGraphFromFile::readDirectedGraphFromFile<int>(file, "weight");

   /* cout <<endl << G->edges();
    cout << endl << G->nodes();
    cout <<endl;

    G->removeNode(1);
    cout << G->node(2)->inLinks();

    cout <<endl << G->edges();
    cout << endl << G->nodes();
    cout <<endl;*/


    /*for (Edge<int> *e :G->edges()) {
        cout << e << " ";
    }*/


    Graph<int> *mst = SV::minimumSpanningTree(G, string("weight"));

    cout << endl;
    for (Edge<int> *edge : mst->edges()) {
        cout << endl << edge << "  ";
    }
    cout << endl;


    delete mst;

    delete G;

    return 0;
}
