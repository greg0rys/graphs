#pragma once
#include <iostream>
using namespace std;


class adjGraph
{
public:
    adjGraph();
    adjGraph(const adjGraph &);
    adjGraph& operator=(const adjGraph &);
    ~adjGraph();

    void addVertex(const int &);
    void addEdge(const int &, const int &);
    bool contains(const int &);
private:

    struct node {
        int *data;
        node *next;
    };

node ** adjList;
const static int INIT_SIZE = 10;
int size,nodeCount;
void destroy();
void destroyList(node *&);
void addVertex(node *&, const int &);
void addEdge(node *&, int &, int &);
node * search(node *, int &);
};