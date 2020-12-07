#include "THRedblack.h"
#include "THStatVal.h"
#include "THMemory.h"


// THTREE_RB_NODE* THRBTree::Get_parent_node(THTREE_RB_NODE* node, THTREE_RB_NODE* root)
// {
//     THTREE_RB_NODE* parent = NULL;
//     if(node == root || node == NULL || (node < root->pr && node > root->pl))
//     {

//     }
//     else if (node == root->pr || node == root->pl)
//     {
//         parent = root;
//     }
//     else
//     {
//         parent = Get_parent_node(node, root->pr > node ? root->pl : root->pr);
//     }
//     return parent;
// }

// THTREE_RB_NODE* THRBTree::Get_uncle_node(THTREE_RB_NODE* node,  THTREE_RB_NODE* root)
// {
//     THREE_NODE* uncle = NULL;
//     THREE_NODE* parent = THRBTree::Get_parent_node(node, root);
//     if(parent != NULL)
//         uncle = (parent->pl == node ? parent->pr : parent->pl);
//     return uncle;
// }
THRBTree::THRBTree()
{
    m_root = NULL;    
}

THRBTree::~THRBTree()
{

}
int THRBTree::Insert(THTREE_RB_NODE* node)
{
    return VInsert(node, m_root);
}
THTREE_RB_NODE* THRBTree::Find(const NODE_KEY_T& key)
{
    return VFind(key, m_root);
}
int THRBTree::Remove(THTREE_RB_NODE* node)
{
    return VRemove(node, m_root);
}
int THRBTree::Rotate_left(THTREE_RB_NODE* rotate)
{
    THTREE_RB_NODE* parent    = THTree::Get_parent_node<THTREE_RB_NODE>(rotate, m_root);
    THTREE_RB_NODE* rotate_pr = rotate->pr;
    rotate->pr    = rotate_pr->pl;
    rotate_pr->pl = rotate;
    if(parent != NULL)
        parent->pl == rotate ? (parent->pl = rotate_pr) : (parent->pr = rotate_pr);
    return TH_OK;
}
int THRBTree::Rotate_right(THTREE_RB_NODE* rotate)
{
    THTREE_RB_NODE* parent    = THTree::Get_parent_node<THTREE_RB_NODE>(rotate, m_root);
    THTREE_RB_NODE* rotate_pl = rotate->pl;
    rotate->pl    = rotate_pl->pr;
    rotate_pl->pr = rotate;
    if(parent != NULL)
        parent->pl == rotate ? (parent->pl = rotate_pl) : (parent->pr = rotate_pl);
    return TH_OK;
}
int THRBTree::VBalance(THTREE_RB_NODE* node)
{
    THTREE_RB_NODE* parent = THTree::Get_parent_node<THTREE_RB_NODE>(node, m_root);
    if(parent == NULL)
    {
        m_root->color = NODE_BLACK;
    }
    else if (parent->color == NODE_BLACK)
    {

    }
    else
    {
        THTREE_RB_NODE* uncle = THTree::Get_uncle_node<THTREE_RB_NODE>(node, m_root);
        THTREE_RB_NODE* gparent = THTree::Get_parent_node<THTREE_RB_NODE>(parent, m_root);
        if(uncle->color == NODE_RED)
        {
            uncle->color = parent->color = NODE_BLACK;
            gparent->color = NODE_RED;
            VBalance(gparent);
        }
        else
        {
            if(parent == gparent->pl)
            {
                if(parent->pr == node)
                    Rotate_left(parent);
                Rotate_right(gparent);
            }
            else
            {
                if(parent->pl == node)
                    Rotate_right(parent);
                Rotate_left(gparent);
            }
        }
    }

}
int THRBTree::VInsert(THTREE_RB_NODE* node, THTREE_RB_NODE*& root)
{
    if(root == NULL)
    {
        root = NEW THTREE_RB_NODE;
        if(root == NULL)
            return TH_FAIL;
        *root       = *node;
        root->pl    = root->pr = NULL;
        root->color = NODE_RED;
        VBalance(root);
    }
    else if(*node > *root)
    {
        return VInsert(node, root->pr);
    }
    else if(*node < *root)
    {
        return VInsert(node, root->pl);
    }
    else
    {
        E_NODE_COLOR color = root->color;
        *root = *node;
        root->color = color;
    }
    return TH_OK;
}

THTREE_RB_NODE* THRBTree::VFind(const NODE_KEY_T& key, THTREE_RB_NODE* root)
{
    if(root == NULL)
    {

    }
    else if(key > *root)
    {
        return VFind(key, root->pr);
    }
    else if(key < *root)
    {
        return VFind(key, root->pl);
    }
    else
    {
        
    }
    return root;
}
int THRBTree::VRemove(THTREE_RB_NODE* node, THTREE_RB_NODE* root)
{
    if(root == NULL)
    {
        return TH_FAIL;
    }
    else if(*node > *root)
    {
        return VRemove(node, root->pr);
    }
    else if(*node < *root)
    {
        return VRemove(node, root->pl);
    }
    else
    {
        if(*node == *root)
        {
            delete m_root;
            m_root = NULL;
        }
        if(root->color == NODE_RED) // has two leaf node
        {
            THTREE_RB_NODE Get_parent_node<THTREE_RB_NODE>(root, m_root);
        }
    }
    return TH_OK;
}
