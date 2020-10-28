#ifndef THNODE_H_
#define THNODE_H_

#include <string>
typedef struct tag_th_node
{
    int idx;
    int value;
    struct tag_th_node* pl;
    struct tag_th_node* pr;
} THREE_NODE;

bool operator==(THREE_NODE& left, THREE_NODE& right);
bool operator>(THREE_NODE& left, THREE_NODE& right);
bool operator<(THREE_NODE& left, THREE_NODE& right);
//bool operator==(THREE_NODE& left, THREE_NODE& right);





#endif //THNODE_H_