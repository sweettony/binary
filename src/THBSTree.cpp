
#include "THBSTree.h"
#include "THStatVal.h"
#include <cstring>

THBStree::THBStree()
{
    m_root = NULL;
}

THBStree::~THBStree()
{

}

int THBStree::Insert(THREE_NODE& node)
{
    return Insert(node, m_root);
}

int THBStree::Insert(THREE_NODE& node, THREE_NODE*& root)
{
    int ret = TH_OK;
    if(root == NULL)
    {
        root = new THREE_NODE;
        if(root == NULL)
        {
            ret = TH_FAIL;
        }
        else
        {
            memcpy(root, &node, sizeof(THREE_NODE));
        }
    }
    else if(node > *root)
    {
        Insert(node, root->pr);
    }
    else if(node < *root)
    {
        Insert(node, root->pl);
    }
    else
    {
        memcpy(root, &node, sizeof(THREE_NODE));
    }
    return TH_OK;
}






void THBStree::Release(THREE_NODE* root)
{
    if(root == NULL) return;
    Release(root->pl);
    Release(root->pr);
}