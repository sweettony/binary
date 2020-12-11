#ifndef THTREE_H_
#define THTREE_H_
#include "THNode.h"
#include "stddef.h"

template<typename T>class THTree
{
protected:
    THTree()
    {
        m_root = NULL;
    }
    virtual ~THTree()
    {

    }
public:
    static T* Get_uncle_node(T* node,  T* root)
    {
        T* uncle = NULL;
        T* parent = THTree::Get_parent_node(node, root);
        if(parent != NULL)
            uncle = (parent->pl == node ? parent->pr : parent->pl);
        return uncle;
    }
    static T* Get_parent_node(T* node,  T* root)
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
            parent = Get_parent_node(node, root->pr > node ? root->pl : root->pr);
        }
        return parent;
    }
    static T* Get_most_right_node(T* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->pr != NULL)
        {
            return Get_most_right_node(root->pr);
        }
        else
        {
            
        }
        return root;
    }
    static T* Get_most_left_node(T* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->pl != NULL)
        {
            return Get_most_left_node(root->pl);
        }
        else
        {
            
        }
        return root;
    }
    unsigned int Get_tree_height(T* root)
    {
        if(root == NULL) return 0;
        int r_h = Get_tree_height(root->pr);
        int l_h = Get_tree_height(root->pl);
        return (r_h > l_h ? ++r_h : ++l_h);
    }

protected:
    T* m_root;
};
#endif //THTREE_H_