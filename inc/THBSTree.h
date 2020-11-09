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
    THREE_NODE* Get_most_right_node(THREE_NODE* root);
public:
    //to insert node
    //return TH_OK on sucess others on fail
    virtual int  Insert(THREE_NODE& node);
    virtual int  Remove(THREE_NODE& node);
    virtual const THREE_NODE* Find(const NODE_KEY_T& key);
    virtual const THREE_NODE* Find(const NODE_KEY_T& key) const;
    //Release resource
    virtual void Release();
private:
    //<to insert node, where>
    int Insert(THREE_NODE& node, THREE_NODE*& root);
    int Remove(THREE_NODE& node,THREE_NODE*& root);
    THREE_NODE* Find(const NODE_KEY_T& key, THREE_NODE* root) const;
    void Release(THREE_NODE* root);
private:
    THREE_NODE* m_root;
};

#endif //BSTREE_H_