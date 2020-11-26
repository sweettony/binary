#include <cstdio>
#include <iostream>
#include <string>
#include "THMemory.h"
#include "THBSTree.h"
#include "THAVLTree.h"

int main()
{
    THAVLTree tree;
    for(int i = 0; i < 65536; i++)
    {
        THREE_NODE node = {i, i, NULL, NULL};
        tree.Insert(node);
    }
    std::cout << "tree height = " << tree.Get_height() << std::endl;
    //THTREENS::TH_HEAPDUMP();
    // for(int i = 0; i < 65536; i++)
    // {
    //     THREE_NODE node = {i, i, NULL, NULL};
    //     tree.Remove(node); 
    // }
    tree.Release();
    THTREENS::TH_HEAPDUMP();
    return 0;
}

