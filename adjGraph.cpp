#pragma once
#include "adjGraph.h"

adjGraph::adjGraph():adjList(nullptr),size(0),nodeCount(0)
{
    size = INIT_SIZE;
    for(auto i = 0; i < size; i++)
        adjList[i] = nullptr;
}

adjGraph::adjGraph(const adjGraph & aGraph):adjList(nullptr),size(0),nodeCount(0) {
    *this = aGraph;
}


adjGraph& adjGraph::operator=(const adjGraph &aGraph)
{
    if(this == &aGraph)
    {
        return *this;
    }

    if(adjList)
        destroy();
}


void adjGraph::destroy()
{
    for(auto i = 0; i < size; i++)
        destroyList(adjList[i]);
    if(adjList) delete []adjList;
    adjList = nullptr;

}
void adjGraph::destroyList(node *&head) {
    if(!head)
        return;
    destroyList(head->next);
    delete head;

}