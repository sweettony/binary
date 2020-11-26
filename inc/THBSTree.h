#ifndef THBSTREE_H_
#define THBSTREE_H_

#include "THNode.h"
#include "THTree.h"
#include <stddef.h>
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
    int  Get_height();
    int  Insert(THREE_NODE& node);
    int  Remove(THREE_NODE& node);
    const THREE_NODE* Find(const NODE_KEY_T& key);
    const THREE_NODE* Find(const NODE_KEY_T& key) const;
    void Release();

protected:
    //<to insert node, where>
    virtual int Do_insert(THREE_NODE& node, THREE_NODE*& root);
    virtual int Do_remove(THREE_NODE& node, THREE_NODE*& root);
    THREE_NODE* Find(const NODE_KEY_T& key, THREE_NODE* root) const;
    void Release(THREE_NODE* root);

protected:
    THREE_NODE* m_root;
};

inline int THBStree::Insert(THREE_NODE& node)
{
    return Do_insert(node, m_root);
} 
inline void THBStree::Release()
{
    Release(m_root);
    m_root = NULL;
    return;
}
inline const THREE_NODE* THBStree::Find(const NODE_KEY_T& key) const
{
    return Find(key, m_root);
}

inline const THREE_NODE* THBStree::Find(const NODE_KEY_T& key)
{
    return Find(key, m_root);
}
inline int THBStree::Remove(THREE_NODE& node)
{
    return Do_remove(node, m_root);
}
inline int THBStree::Get_height()
{
    return Get_tree_height(m_root);
}
#endif //BSTREE_H_