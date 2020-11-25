#include <cstdio>
#include <iostream>
#include <string>
#include "THMemory.h"
#include "THBSTree.h"
#include "THAVLTree.h"

int main()
{
    THAVLTree tree;
    for(int i = 0; i < 500; i++)
    {
        THREE_NODE node = {i, i, NULL, NULL};
        tree.Insert(node);
    }
    std::cout << "tree height = " << tree.Get_height() << std::endl;
    for(int i = 0; i < 500; i++)
    {
        THREE_NODE node = {i, i, NULL, NULL};
        tree.Remove(node); 
    }
    
    tree.Release();
    return 0;
}

