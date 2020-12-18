#ifndef THREDBLACK_H_
#define THREDBLACK_H_
#include "THNode.h"
#include "THTree.h"

template<typename T> class THRBTree
    : public THBStree<T>
{
private:
    typedef enum tag_rb_path_black
    {
        RB_FACTER_ZERO = 0,
        RB_FACTOR_MINUS_ONE
    }E_RB_BLACK_NODE_FACTOR;

    typedef struct tag_rb_balance_node
    {
        T* node;
        T* parent;
        E_RB_BLACK_NODE_FACTOR path_of_black;
    }RB_BALANCE_NODE;

public:
    THRBTree()
        :THBStree<T>()
    {

    }
    ~THRBTree()
    {

    }
private: 
    virtual THUINT Support_self_balance()
    {
        return TH_SUP_SELF_BALANCE;
    }
    void Insert_balance(T* next_node)
    {
        T* parent = THTree<T>::Get_parent_node(next_node, this->m_root);
        if(parent == NULL)
        {
            this->m_root->color = NODE_BLACK;
        }
        else if (parent->color == NODE_BLACK)
        {

        }
        else //parent is RED
        {
            T* uncle   = THTree<T>::Get_uncle_node(next_node, this->m_root);
            T* gparent = THTree<T>::Get_parent_node(parent, this->m_root);
            if(uncle && uncle->color == NODE_RED)
            {
                uncle->color = parent->color = NODE_BLACK;
                gparent->color = NODE_RED;
                Insert_balance(gparent);
            }
            else // uncle is BLACK 
            {
                if(parent == gparent->pl)
                {
                    if(parent->pr == next_node)
                        this->Rotation_left(parent);
                    this->Rotation_right(gparent);
                }
                else
                {
                    if(parent->pl == next_node)
                        this->Rotation_right(parent);
                    this->Rotation_left(gparent);
                }
                next_node->color = NODE_BLACK;
                gparent->color = NODE_RED;
            }
        }
        return;
    }
    void Remove_balance(T* next_node)
    {
        
    }

protected:
    virtual int  Vmalloc_node(T& node, T*& root)
    {
        int ret = THBStree<T>::Vmalloc_node(node,root);
        if(ret == TH_OK) Insert_balance(root);
        return TH_OK;
    }
    virtual T* Vfree_node(T*& root)
    {   
        RB_BALANCE_NODE node;
        T* pNode = THTree<T>::Get_most_right_node(root->pl);
        if(pNode == NULL)
            pNode = THTree<T>::Get_most_left_node(root->pr);
        if(pNode == NULL)
        {
            pNode = root;
            root = NULL;
        }
        else if(pNode == root->pl)
        {
            pNode->pr = root->pr;
            Replace_node(root, pNode);
        }
        else if(pNode == root->pr)
        {
            pNode->pl = root->pl;
            Replace_node(root, pNode);
        }
        else
        {
            T* parent_of_noode = THTree<T>::Get_parent_node(pNode, this->m_root);
            if(pNode == parent_of_noode->pr)
            {
                parent_of_noode->pr = pNode->pl;
            }
            else
            {
                parent_of_noode->pl = pNode->pr;
            }
            Replace_node(root, pNode);
        }
        delete pNode;
        return TH_OK;
    }
    void Replace_node(T* p_dst, T*& p_src)
    {
        //TO-DO;
        return
    }
};
#endif