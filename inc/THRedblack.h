#ifndef THREDBLACK_H_
#define THREDBLACK_H_
#include "THNode.h"
#include "THTree.h"

template<typename T> class THRBTree
    : public THBStree<T>
{
private:
    typedef enum tag_child_color
    {
        CHILD_TWO_BLACK,
        CHILD_ONE_RED
    }E_CHILD_COLOR;
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

protected:
    virtual int  Vmalloc_node(T& node, T*& root)
    {
        int ret = THBStree<T>::Vmalloc_node(node,root);
        if(ret == TH_OK) Insert_balance(root);
        return TH_OK;
    }
    virtual T*   Vfree_node(T*& root)
    {   
        T* pNode = THTree<T>::Get_most_right_node(root->pl);
        if(pNode == NULL)
            pNode = THTree<T>::Get_most_left_node(root->pr);
        T* parent_of_node = THTree<T>::Get_parent_node(root, this->m_root);
        E_NODE_COLOR color = NODE_RED;
        T* child_of_node = NULL;
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
            parent_of_node = THTree<T>::Get_parent_node(pNode, this->m_root);
            if(pNode == parent_of_node->pr)
            {
                parent_of_node->pr = pNode->pl;
            }
            else
            {
                parent_of_node->pl = pNode->pr;
            }
            Replace_node(root, pNode);
        }
        color = pNode->color;
        child_of_node = (pNode->pr == NULL) ? pNode->pl : NULL;
        if(NODE_RED == color)
        {

        }
        else if(child_of_node && NODE_RED == child_of_node->color) // child is red
        {
            child_of_node->color = NODE_BLACK;
        }
        else
        {
            Remove_balance(parent_of_node, child_of_node);
        }        
        delete pNode;
        return TH_OK;
    }
    void Remove_balance(T* parent, T* child)
    {
        if(parent == NULL) //the node is the root
        {
            this->m_root = child;
            if(this->m_root) this->m_root->color = NODE_BLACK;
        }
        else // the color is black and the parent is not equal NULL
        {
            T* psibling = parent->pl;
            if(psibling == child)
                psibling = parent->pr;
            T* gparent = THTree<T>::Get_parent_node(parent, this->m_root);
            if(NODE_RED == psibling->color)
            {    
                if(psibling == parent->pr)
                {
                    parent->pr = psibling->pl;
                    psibling->pl = parent;
                    parent->color = NODE_RED;
                }
                else
                {
                    parent->pl = psibling->pr;
                    psibling->pr = parent;
                    parent->color = NODE_RED;
                }
                if(gparent)
                {
                    if(gparent->pl == parent)
                        gparent->pl = psibling;
                    else
                        gparent->pr = psibling;
                }
                else
                {
                    this->m_root = psibling;
                }
            }
            else
            {
                if(NODE_RED == parent->color)
                {
                    parent->color = NODE_BLACK;
                    psibling->color = NODE_RED;
                }
                if(CHILD_TWO_BLACK == Color_of_two_childs(psibling))
                {
                    Remove_balance(gparent, Get_child_of_noleaf(parent));
                }
                else
                {
                    if(psibling->pr && NODE_RED == psibling->pr->color)
                    {
                        if(parent->pr = psibling)
                        {
                            psibling->pr->color = NODE_BLACK;
                            THTree<T>::Rotation_left(parent);
                        }
                        else
                        {
                            psibling->pl->color = NODE_BLACK;
                            THTree<T>::Rotation_left(psibling);
                            THTree<T>::Rotation_right(parent);
                        }
                        
                    }
                    else
                    {
                        if(parent->pl = psibling)
                        {
                            psibling->pl->color = NODE_BLACK;
                            THTree<T>::Rotation_right(parent);
                        }
                        else
                        {
                            psibling->pr->color = NODE_BLACK;
                            THTree<T>::Rotation_right(psibling);
                            THTree<T>::Rotation_left(parent);
                        }
                    }
                    
                }
            }
            
        }
        return;
    }
    
    E_CHILD_COLOR Color_of_two_childs(T* node)
    {
        if(node->pr && node->pr->color == NODE_RED)
            return CHILD_ONE_RED;
        else if(node->pl && node->pl->color == NODE_RED)
            return CHILD_ONE_RED;
        return CHILD_TWO_BLACK;
    }
    
    T* Get_child_of_noleaf(T* node)
    {
        T* child = NULL;
        if(node == NULL)
            ;
        else if(node->pr != NULL)
            child = node->pr;
        else
            child = node->pl;
        return child;
    }

    void Replace_node(T*& p_dst, T* p_src)
    {
        p_dst->value = p_src->value;
        p_dst->idx   = p_src->idx;
        return;
    }
};
#endif