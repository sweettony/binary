#ifndef THTREE_H_
#define THTREE_H_
#include "THNode.h"
#include "stddef.h"

class THTree
{
public:
    THTree();
    virtual ~THTree();
public:
    template<typename T> static T* Get_uncle_node(T* node,  T* root)
    {
        T* uncle = NULL;
        T* parent = THTree::Get_parent_node<T>(node, root);
        if(parent != NULL)
            uncle = (parent->pl == node ? parent->pr : parent->pl);
        return uncle;
    }
    template<typename T> static T* Get_parent_node(T* node,  T* root)
    {
        T* parent = NULL;
        if(node == root || node == NULL || (node < root->pr && node > root->pl))
        {

        }
        else if (node == root->pr || node == root->pl)
        {
            parent = root;
        }
        else
        {
            parent = Get_parent_node<T>(node, root->pr > node ? root->pl : root->pr);
        }
        return parent;
    }
};
#endif //THTREE_H_