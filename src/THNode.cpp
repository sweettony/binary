#include "THNode.h"
#include <cstring>

template<class T> bool node_eq(T op_l, T op_r)
{
    return (op_l == op_r);
}
template<class T> bool node_gt(T op_l, T op_r)
{
    return (op_l > op_r);
}
template<class T> bool node_lt(T op_l, T op_r)
{
    return (op_l < op_r);
}
 
//THTREE_NODE
bool operator==(const THREE_NODE& left, const THREE_NODE& right)
{
    return (left.idx == right.idx);
}
bool operator>(const THREE_NODE& left, const THREE_NODE& right)
{
    return (left.idx > right.idx);
}
bool operator<(const THREE_NODE& left, const THREE_NODE& right)
{
    return (right > left);
}
bool operator>(const NODE_KEY_T& key, const THREE_NODE& node)
{
    return (key > node.idx);
}
bool operator<(const NODE_KEY_T& key, const THREE_NODE& node)
{
    return (node.idx > key);
}
bool operator>(const THREE_NODE& node, const NODE_KEY_T& key)
{
    return (key < node);
}
bool operator<(const THREE_NODE& node, const NODE_KEY_T& key)
{
    return (key > node);
}
const THREE_NODE& THREE_NODE::operator=(const THREE_NODE& node)
{
    memcpy(this, &node, sizeof(THREE_NODE));
    return *this;
}

//THTREE_RB_NODE
const THTREE_RB_NODE& THTREE_RB_NODE::operator=(const THTREE_RB_NODE& node)
{
    memcpy(this, &node, sizeof(THTREE_RB_NODE));
    return *this;
}
bool operator==(const THTREE_RB_NODE& left, const THTREE_RB_NODE& right)
{
    return (left.idx == right.idx);
}
bool operator>(const THTREE_RB_NODE& left, const THTREE_RB_NODE& right)
{
    return (left.idx > right.idx);
}
bool operator<(const THTREE_RB_NODE& left, const THTREE_RB_NODE& right)
{
    return (right > left);
}
bool operator>(const NODE_KEY_T& key, const THTREE_RB_NODE& node)
{
    return (key > node.idx);
}
bool operator<(const NODE_KEY_T& key, const THTREE_RB_NODE& node)
{
    return (node.idx > key);
}
bool operator>(const THTREE_RB_NODE& node, const NODE_KEY_T& key)
{
    return (key < node);
}
bool operator<(const THTREE_RB_NODE& node, const NODE_KEY_T& key)
{
    return (key > node);
}

