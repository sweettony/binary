#ifndef THTREE_H_
#define THTREE_H_
#include "THNode.h"
class THTree
{
public:
    THTree(){ };
    virtual ~THTree(){ };

public:
    virtual int Insert(TREE_NODE& node) = 0;
};
#endif //THTREE_H_