#ifndef THBSTREE_H_
#define THBSTREE_H_

#include "THTree.h"
#include "THStatVal.h"
#include <cstring>
#include "THMemory.h"
#include <stddef.h>
#include <map>
template<typename T> class THBStree
    : public THTree<T>
{
public:
    THBStree()
        : THTree<T>()
    {
        this->m_root = NULL;
    }
    virtual ~THBStree()
    {
        Release();
    }
public:
    int  Insert(T& node)
    {
        return Insert(node, this->m_root);
    }
    int  Remove(T& node)
    {
        return Remove(node, this->m_root);
    }
    const T* Find(const NODE_KEY_T& key)
    {
        return Find(key, this->m_root);
    }
    const T* Find(const NODE_KEY_T& key) const
    {
        return Find(key, this->m_root);
    }
    void Release()
    {
        return Release(this->m_root);
    }
private:
    int Remove(T& node,T*& root)
    {
        if(root == NULL)
        {
            return TH_FAIL;
        }
        else if(*root > node)
        {
            return Remove(node, root->pr);
        }
        else if(*root < node)
        {
            return Remove(node, root->pl);
        }
        else
        {
            Vfree_node(node, root);
        }
        return TH_OK;
    }
    T* Find(const NODE_KEY_T& key, T* root) const
    {
        if(key > *root)
        {
            return Find(key, root->pr);
        }
        else if(key < *root)
        {
            return Find(key, root->pl);
        }
        else
        {

        }
        return root;
    }

    int Insert(T& node, T*& root)
    {
        if(root == NULL)
        {
            return Vmalloc_node(node, root);
        }
        else if(node > *root)
        {
            return Insert(node, root->pr);
        }
        else if(node < *root)
        {
            return Insert(node, root->pl);
        }
        else
        {
            *root = node;
        }
        return TH_OK;
    }
    void Release(T* root)
    {
        if(root == NULL) return;
        Release(root->pl);
        Release(root->pr);
        delete root;
        root = NULL;
    }
protected:
    virtual int Vmalloc_node(T& node, T*& root)
    {
        root = NEW T;
        if(root == NULL)
            return TH_FAIL;
        *root = node;
        (*root).pl = (*root).pr = NULL;
        return TH_OK;
    }

    virtual T* Vfree_node(T& node, T*& root)
    {
        T* parent = THTree<T>::Get_parent_node(root, this->m_root);
        if(root->pl == NULL && root->pr == NULL)
        {
            delete root;
            root = NULL;
        }
        else
        {
            T* pNode = THTree<T>::Get_most_right_node(root->pl);
            if(pNode == NULL)
            {
                *root = *root->pr;
                delete root->pr;
            }
            else
            {
                parent = THTree<T>::Get_parent_node(pNode, root);
                if(parent == root)
                {
                    pNode->pr = root->pr;
                    *root = *pNode;
                }
                else
                {
                    parent->pr = pNode->pl;
                    root->idx = pNode->idx;
                    root->value = pNode->value;
                }
                delete pNode;
            }
        }
        return parent;
    }

};
#endif //BSTREE_H_