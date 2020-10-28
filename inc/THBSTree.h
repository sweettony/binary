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
    //<to insert node>
    //return TH_OK on sucess others on fail
    virtual int Insert(THREE_NODE& node);

private:
    //<to insert node, where>
    int Insert(THREE_NODE& node, THREE_NODE*& root);

    void Release(THREE_NODE* root);
private:
    THREE_NODE* m_root;
};

#endif //BSTREE_H_