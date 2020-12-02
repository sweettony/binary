#include "THRedblack.h"
#include "THStatVal.h"
#include "THMemory.h"


THTREE_RB_NODE* THRBTree::Get_parent_node(THTREE_RB_NODE* node, THTREE_RB_NODE* root)
{
    THTREE_RB_NODE* parent = NULL;
    if(node == root || node == NULL || (node < root->pr && node > root->pl))
    {

    }
    else if (node == root->pr || node == root->pl)
    {
        parent = root;
    }
    else
    {
        Get_parent_node(node, root->pr > node ? root->pl : root->pr);
    }
    return parent;
}

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
int THRBTree::Find(THTREE_RB_NODE* node)
{
    return VFind(node, m_root);
}
int THRBTree::Remove(THTREE_RB_NODE* node)
{
    return VRemove(node, m_root);
}
int THRBTree::Rotate_left(THTREE_RB_NODE* rotate)
{

}
int THRBTree::Rotate_right(THTREE_RB_NODE* rotate)
{
    
}
int THRBTree::VBalance(THTREE_RB_NODE* node)
{
    THTREE_RB_NODE* parent = THRBTree::Get_parent_node(node, m_root);
    if(parent == NULL)
    {
        m_root->color = E_NODE_COLOR::NODE_BLACK;
    }
    else if (parent->color == E_NODE_COLOR::NODE_BLACK)
    {

    }
    else
    {
        THTREE_RB_NODE* uncle = THRBTree::Get_uncle_node(node, m_root);
        if(uncle->color == E_NODE_COLOR::NODE_RED)
        {
            uncle->color == parent->color = E_NODE_COLOR::NODE_BLACK;
            THTREE_RB_NODE* gparent = THRBTree::Get_parent_node(parent, m_root);
            gparent->color = E_NODE_COLOR::NODE_RED;
            VBalance(gparent);
        }
        else
        {
            //first
            
        }
    }

}
int THRBTree::VInsert(THTREE_RB_NODE* node, THTREE_RB_NODE*& root)
{
    int ret = TH_OK;
    if(root == NULL)
    {
        root = NEW THTREE_RB_NODE;
        if(root == NULL)
        {
            ret = TH_FAIL;
        }
        else
        {
            *root = *node;
            (*root).pl = (*root).pr = NULL;
            VBalance(root);
        }
    }
    else if(node > *root)
    {
        ret = VInsert(node, root->pr);
    }
    else if(node < *root)
    {
        ret = VInsert(node, root->pl);
    }
    else
    {
        *root = node;
    }
    return ret;
}

int THRBTree::VFind(THTREE_RB_NODE* node, THTREE_RB_NODE* root)
{
    return TH_OK;
}
int THRBTree::VRemove(THTREE_RB_NODE* node, THTREE_RB_NODE* root)
{
    return TH_OK;
}
