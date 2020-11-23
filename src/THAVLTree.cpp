#include <stdlib.h>
#include "THAVLTree.h"
#include "THStatVal.h"
#include "THMemory.h"

THAVLTree::THAVLTree()
{
}

THAVLTree::~THAVLTree()
{
}

inline int THAVLTree::Get_AVL_Balance_factor(THREE_NODE *node)
{
    if (node == NULL)
        return 0;
    return abs(Get_tree_height(node->pr) - Get_tree_height(node->pl));
}

THREE_NODE *THAVLTree::rotation_left(THREE_NODE *node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *grandparent = Get_node_parent(parent, m_root);
    if (parent == NULL)
        return NULL;
    
    parent->pr = node->pl;
    node->pl = parent;
    if (grandparent)
    {
        grandparent->pl == parent ? grandparent->pl = node : grandparent->pr = node;
    }
    return node;
}
THREE_NODE *THAVLTree::rotation_right_left(THREE_NODE *node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *grandparent = Get_node_parent(parent, m_root);
    if (parent == NULL)
        return NULL;
    THREE_NODE *pNode_left = node->pl;
    //error 
    //node->pl = pNode_left->pr;
    Get_most_left_node(node)->pl = pNode_left->pr;
    pNode_left->pr = node;

    //error
    //parent->pr = pNode_left->pl;
    Get_most_right_node(parent)->pr = pNode_left->pl;
    pNode_left->pl = parent;

    if (grandparent)
    {
        grandparent->pl == parent ? grandparent->pl = pNode_left : grandparent->pr = pNode_left;
    }

    return pNode_left;
}

THREE_NODE*  THAVLTree::rotation_right(THREE_NODE* node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *grandparent = Get_node_parent(parent, m_root);
    if (parent == NULL)
        return NULL;
    
    Get_most_left_node(parent)->pl = node->pr;
    node->pr = parent;
    if (grandparent)
    {
        grandparent->pl == parent ? grandparent->pl = node : grandparent->pr = node;
    }
    return node;
}

THREE_NODE*  THAVLTree::rotation_left_right(THREE_NODE* node)
{


}

void THAVLTree::Balance(THREE_NODE *node)
{
    if (node == NULL)
        return;

    THREE_NODE *parent       = Get_node_parent(node,   m_root);
    int parent_factor        = Get_AVL_Balance_factor(parent);
    int node_factor          = Get_AVL_Balance_factor(node);
    
    if (node_factor == 0 || parent_factor == NULL)
        return;

    if (parent_factor == 2)
    {
        if (node_factor > 0)
        {
            node = rotation_left(node);
        }
        else
        {
            node = rotation_right_left(node);
        }
    }
    if (parent_factor == -2)
    {
        if (node_factor > 0)
        {
            node = rotation_left(node);
        }
        else
        {
            node = rotation_right_left(node);
        }
    }
    Balance(node);
    return;
}

int THAVLTree::Insert(THREE_NODE &node, THREE_NODE *&root)
{
    int ret = TH_OK;
    if (root == NULL)
    {
        root = NEW THREE_NODE;
        if (root == NULL)
        {
            ret = TH_FAIL;
        }
        else
        {
            *root = node;
            (*root).pl = (*root).pr = NULL;
            Balance(Get_node_parent(root, m_root));
        }
    }
    else if (node > *root)
    {
        Insert(node, root->pr);
    }
    else if (node < *root)
    {
        Insert(node, root->pl);
    }
    else
    {
        *root = node;
    }
    return TH_OK;
}

int THAVLTree::Remove(THREE_NODE &node, THREE_NODE *&root)
{
    int ret = TH_FAIL;
    if (root == NULL)
    {
        ret == TH_FAIL;
    }
    else if (*root > node)
    {
        ret = Remove(node, root->pr);
    }
    else if (*root < node)
    {
        ret = Remove(node, root->pl);
    }
    else
    {
        if (root->pl == NULL && root->pr == NULL)
        {
            delete root;
            root = NULL;
        }
        else
        {
            THREE_NODE *pNode = Get_most_right_node(root->pl);
            if (pNode == NULL)
            {
                *root = *root->pr;
                delete root->pr;
            }
            else
            {
                THREE_NODE *pNode_parent = Get_node_parent(pNode, root);
                if (pNode_parent == root)
                {
                    pNode->pr = root->pr;
                    *root = *pNode;
                }
                else
                {
                    pNode_parent->pr = pNode->pl;
                    root->idx = pNode->idx;
                    root->value = pNode->value;
                }
                delete pNode;
            }
        }
    }
}
