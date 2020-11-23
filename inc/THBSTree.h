#ifndef THBSTREE_H_
#define THBSTREE_H_

#include "THNode.h"
#include "THTree.h"

class THBStree
    : public THTree
{
public:
    THBStree();
    virtual ~THBStree();
public:
    static THREE_NODE* Get_most_right_node(THREE_NODE* root);
    static THREE_NODE* Get_most_left_node(THREE_NODE* root);
    static THREE_NODE* Get_node_parent(THREE_NODE* node, THREE_NODE* root);
    static int Get_tree_height(THREE_NODE* root);
public:
    //to insert node
    //return TH_OK on sucess others on fail
    int  Insert(THREE_NODE& node);
    int  Remove(THREE_NODE& node);
    const THREE_NODE* Find(const NODE_KEY_T& key);
    const THREE_NODE* Find(const NODE_KEY_T& key) const;
    //Release resource
    void Release();
private:
    //<to insert node, where>
    virtual int Insert(THREE_NODE& node, THREE_NODE*& root);
    virtual int Remove(THREE_NODE& node,THREE_NODE*& root);
    THREE_NODE* Find(const NODE_KEY_T& key, THREE_NODE* root) const;
    void Release(THREE_NODE* root);
protected:
    THREE_NODE* m_root;
};

#endif //BSTREE_H_