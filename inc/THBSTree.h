#ifndef THBSTREE_H_
#define THBSTREE_H_

#include "THNode.h"
#include "THTree.h"

class THBStree
    : public THTree
{
public:
    THBStree();
    ~THBStree();
public:
    virtual int Insert(TREE_NODE& node);
public:
    TREE_NODE* m_root;
};

#endif //BSTREE_H_