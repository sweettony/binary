#include "THNode.h"

bool operator==(THREE_NODE& left, THREE_NODE& right)
{
    return (left.idx == right.idx);
}

bool operator>(THREE_NODE& left, THREE_NODE& right)
{
    return (left.idx > right.idx);
}

bool operator<(THREE_NODE& left, THREE_NODE& right)
{
    return (left.idx < right.idx);
}