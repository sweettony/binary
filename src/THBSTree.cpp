
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


int  THBStree::Remove(THREE_NODE& node)
{


}

inline const THREE_NODE* THBStree::Find(const NODE_KEY_T& key) const
{
    return Find(key, m_root);
}

inline const THREE_NODE* THBStree::Find(const NODE_KEY_T& key)
{
    return Find(key, m_root);
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

inline int THBStree::Insert(THREE_NODE& node)
{
    return Insert(node, m_root);
} 

int THBStree::Insert(THREE_NODE& node, THREE_NODE*& root)
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
        Insert(node, root->pr);
    }
    else if(node < *root)
    {
        Insert(node, root->pl);
    }
    else
    {
        *root = node;
    }
    return TH_OK;
}

inline void THBStree::Release()
{
   Release(m_root);
   m_root = NULL;
   return;
}
void THBStree::Release(THREE_NODE* root)
{
    if(root == NULL) return;
    Release(root->pl);
    Release(root->pr);
    delete root;
}