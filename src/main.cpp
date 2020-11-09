#include <cstdio>
#include <iostream>
#include "THMemory.h"
#include <string>
#include <THBSTree.h>

int main()
{
    THBStree tree;
    for(int i = 0; i < 500; i++)
    {
        THREE_NODE node = {i, i, NULL, NULL};
        tree.Insert(node);
    }
    for(int i = 0; i < 500; i++)
    {
        THREE_NODE node = {i, i, NULL, NULL};
        tree.Remove(node); 
    }

    //const THREE_NODE* p = tree.Find(2);
    //std::cout << p->value << std::endl;
   // THTREENS::TH_HEAPDUMP();
   //std::cout << THTREENS::g_default_heap.Total_usage() << std::endl;
  // THTREENS::g_default_heap.Dump();
    tree.Release();
    //THTREENS::TH_HEAPDUMP();
    return 0;
}