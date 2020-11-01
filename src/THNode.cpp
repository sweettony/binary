#include "THNode.h"
#include <cstring>
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


//node and key comparision
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

THREE_NODE& THREE_NODE::operator=(const THREE_NODE& node)
{
    memcpy(this, &node, sizeof(THREE_NODE));
    return *this;
}