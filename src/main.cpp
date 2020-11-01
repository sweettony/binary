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
    const THREE_NODE* p = tree.Find(2);
    std::cout << p->value << std::endl;
   // THTREENS::TH_HEAPDUMP();
    tree.Release();
    //THTREENS::TH_HEAPDUMP();
    aa();
    return 0;
}