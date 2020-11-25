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
    return Get_tree_height(node->pr) - Get_tree_height(node->pl);
}

THREE_NODE *THAVLTree::Rotation_left(THREE_NODE *node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *right_child = node->pr;

    node->pr = right_child->pl;
    right_child->pl = node;

    if (parent)
    {
        (parent->pl == node) ? parent->pl = right_child : parent->pr = right_child;
    }
    else
    {
        m_root = right_child;
    }
    return parent;
}
THREE_NODE *THAVLTree::Rotation_right_left(THREE_NODE *node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *right_child = node->pr;
    THREE_NODE *right_child_left = right_child->pl;

    right_child->pl = right_child_left->pr;
    right_child_left->pr = right_child;
    node->pr = right_child_left->pl;
    right_child_left->pl = node;

    if (parent)
    {
        parent->pl == node ? parent->pl = right_child_left : parent->pr = right_child_left;
    }
    else
    {
        m_root = right_child_left;
    }
    return parent;
}

THREE_NODE*  THAVLTree::Rotation_right(THREE_NODE* node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *left_child = node->pl;

    node->pl = left_child->pr;
    left_child->pr = node;
    if (parent)
    {
        (parent->pl == parent) ? parent->pl = left_child : parent->pr = left_child;
    }
    else
    {
        m_root = left_child;
    }
    return parent;
}

THREE_NODE*  THAVLTree::Rotation_left_right(THREE_NODE* node)
{
    THREE_NODE *parent      = Get_node_parent(node, m_root);
    THREE_NODE *left_child = node->pl;
    THREE_NODE *left_child_right = left_child->pr;

    left_child->pr = left_child_right->pl;
    left_child_right->pl = left_child;

    node->pl = left_child_right->pr;
    left_child_right->pr = node;

    if (parent)
    {
        (parent->pl == node) ? parent->pl = left_child_right : parent->pr = left_child_right;
    }
    else
    {
        m_root = left_child_right;
    }
    return parent;
}

void THAVLTree::Balance(THREE_NODE *node)
{
    if (node == NULL) 
        return;
    int node_factor = Get_AVL_Balance_factor(node);
    std::cout << "node factor = " << node_factor << std::endl; 
    if (node_factor == 2)
    {
        if( Get_AVL_Balance_factor(node->pr) > 0 )
        {
            node = Rotation_left(node);
        }
        else
        {
            node = Rotation_left_right(node);
        }
        
    }
    else if (node_factor == -2)
    {
        if (node_factor > 0)
        {
            node = Rotation_right(node);
        }
        else
        {
            node = Rotation_right_left(node);
        }
    }
    else if (node_factor == 0)
    {
        return;
    }
    else
    {
        node = Get_node_parent(node, m_root);
    }
    Balance(node);
    return;
}

int THAVLTree::Do_insert(THREE_NODE &node, THREE_NODE *&root)
{
    int ret = TH_OK;
    if(root == NULL)
    {
        root = NEW THREE_NODE;
        if(root == NULL)
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
    else if(node > *root)
    {
        ret = Do_insert(node, root->pr);
    }
    else if(node < *root)
    {
        ret = Do_insert(node, root->pl);
    }
    else
    {
        *root = node;
    }
    return TH_OK;
    return ret;
}

int THAVLTree::Do_remove(THREE_NODE &node, THREE_NODE *&root)
{
    int ret = TH_OK;
    if (root == NULL)
    {
        ret == TH_FAIL;
    }
    else if (*root > node)
    {
        ret = Do_remove(node, root->pr);
    }
    else if (*root < node)
    {
        ret = Do_remove(node, root->pl);
    }
    else
    {
        THREE_NODE *balance_node_start = NULL;
        THREE_NODE *root_ref = root;
        if (root->pl == NULL && root->pr == NULL)
        {
            balance_node_start = Get_node_parent(root, m_root);
            root = NULL;
        }
        else
        {
            if (root->pl == NULL)
            {
                balance_node_start = Get_node_parent(root, m_root);
                root = root->pr;
            }
            else
            {
                THREE_NODE *most_right_of_root_left = Get_most_right_node(root->pl);
                if (most_right_of_root_left == root->pl)
                {
                    most_right_of_root_left->pr = root->pr;
                    root = most_right_of_root_left;
                    balance_node_start = root;
                }
                else
                {
                    THREE_NODE* parent_most_right_of_root_left = Get_node_parent(most_right_of_root_left, root);
                    parent_most_right_of_root_left->pr = most_right_of_root_left->pl;
                    root = most_right_of_root_left;
                    root->pl = root_ref->pl;
                    root->pr = root_ref->pr;
                    balance_node_start = parent_most_right_of_root_left;
                }
            }
        
        }
        delete root_ref;
        std::cout << "balance_node_start = " << balance_node_start << std::endl;
        Balance(balance_node_start);
    }
    return ret;
}
