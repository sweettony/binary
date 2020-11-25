
#include "THBSTree.h"
#include "THStatVal.h"
#include <cstring>
#include "THMemory.h"

THBStree::THBStree()
{
    m_root = NULL;
}


THBStree::~THBStree()
{
    Release();
}

THREE_NODE* THBStree::Get_most_right_node(THREE_NODE* root)
{
    THREE_NODE* pNode = NULL;
    if(root == NULL)
    {
        pNode =  NULL;
    }
    else if(root->pr == NULL)
    {
        pNode =  root;
    }
    else
    {
        pNode =  Get_most_right_node(root->pr);
    }
    return pNode;
}
THREE_NODE* THBStree::Get_most_left_node(THREE_NODE* root)
{
    THREE_NODE* pNode = NULL;
    if(root == NULL)
    {
        pNode =  NULL;
    }
    else if(root->pl == NULL)
    {
        pNode =  root;
    }
    else
    {
        pNode =  Get_most_left_node(root->pr);
    }
    return pNode;
}
int THBStree::Get_tree_height(THREE_NODE* root)
{
    if(root == NULL) return 0;
    int r_h = Get_tree_height(root->pr);
    int l_h = Get_tree_height(root->pl);
    return (r_h > l_h ? ++r_h : ++l_h);
}

THREE_NODE* THBStree::Get_node_parent(THREE_NODE* node, THREE_NODE* root)
{
    if(root == node || node == NULL)
    {
        return NULL;
    }
    else if(node == root->pl || node == root->pr)
    {
        return root;
    }
    else
    {
        if(*node > *root)
        {
            return Get_node_parent(node, root->pr);
        }
        else
        {
            return Get_node_parent(node, root->pl);
        }
    }
    return NULL;
}



int THBStree::Do_remove(THREE_NODE& node,THREE_NODE*& root)
{
    int ret = TH_FAIL;
    if(root == NULL)
    {
        ret == TH_FAIL;
    }
    else if(*root > node)
    {
        ret = Do_remove(node, root->pr);
    }
    else if(*root < node)
    {
        ret = Do_remove(node, root->pl);
    }
    else
    {
        if(root->pl == NULL && root->pr == NULL)
        {
            delete root;
            root = NULL;
        }
        else
        {
            THREE_NODE* pNode = Get_most_right_node(root->pl);
            if(pNode == NULL)
            {
                *root = *root->pr;
                delete root->pr;
            }
            else
            {
                THREE_NODE* pNode_parent = Get_node_parent(pNode, root);
                if(pNode_parent == root)
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
    return ret;
}



THREE_NODE* THBStree::Find(const NODE_KEY_T& key, THREE_NODE* root) const
{
    THREE_NODE* pRet = NULL;
    if(key > *root)
    {
        pRet = Find(key, root->pr);
    }
    else if(key < *root)
    {
        pRet = Find(key, root->pl);
    }
    else
    {
        pRet = root;
    }
    return pRet;
}

int THBStree::Do_insert(THREE_NODE& node, THREE_NODE*& root)
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
}


void THBStree::Release(THREE_NODE* root)
{
    if(root == NULL) return;
    Release(root->pl);
    Release(root->pr);
    delete root;
}