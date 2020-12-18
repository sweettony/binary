#ifndef THAVLTREE_H_
#define THAVLTREE_H_
#include "THBSTree.h"
#define AVL_LEFT_ROTATION_FACTOR (2)
#define AVL_RIGHT_ROTATION_FACTOR (-2)
template<typename T>class THAVLTree
    : public THBStree<T>
{
public:
    THAVLTree()
        : THBStree<T>()
    {

    }
    virtual ~THAVLTree()
    {

    }
    virtual THUINT Support_self_balance()
    {
        return TH_SUP_SELF_BALANCE;
    }
private:
    THUINT Get_AVL_Balance_factor(T *node)
    {
        return (node == NULL) ? 0 : (Get_tree_height(node->pr) - Get_tree_height(node->pl));
    }
    T* AVL_rotation_left(T* node)
    {
        const int node_factor = Get_AVL_Balance_factor(node->pr);
        T* root = NULL;
        if(node_factor > 0)
        {
            root = Rotation_left(node);
        }
        else
        {
            Rotation_right(node->pr);
            root = Rotation_left(node);
        }
#ifdef THDEBUG
        if(root == NULL)
        {
            THERR("AVL BALANCE ERR");
        }
#endif
        return Get_parent_node(root, this->m_root);
    }

    T* AVL_rotation_right(T* node)
    {
        const int node_factor = Get_AVL_Balance_factor(node->pl);
        T* root = NULL;
        if(node_factor > 0)
        {
            root = Rotation_right(node);
        }
        else
        {
            Rotation_left(node->pl);
            root = Rotation_right(node);
        }
#ifdef THDEBUG
        if(root == NULL)
        {
            THERR("AVL BALANCE ERR");
        }
#endif
        return Get_parent_node(root, this->m_root);
    }

    virtual void Self_balance(T* next_node)
    {
        if (next_node == NULL) return;
        const int factor = Get_AVL_Balance_factor(next_node);
        if (factor == AVL_LEFT_ROTATION_FACTOR)
        {
            next_node = AVL_rotation_left(next_node);
        }
        else if (factor == AVL_RIGHT_ROTATION_FACTOR)
        {
            next_node = AVL_rotation_right(next_node);
        }
        else if (factor == 0)
        {
            return;
        }
        else
        {
            next_node = Get_node_parent(next_node, this->m_root);
        }
        Self_balance(next_node);
        return;
    }

    virtual int  Vmalloc_node(THREE_NODE& node, THREE_NODE*& root)
    {
        int ret = THBStree<T>::Vmalloc_node(node,root);
        if(ret == TH_OK) Self_balance(Get_parent_node(root, this->m_root));
        return TH_OK;
    }
    virtual int  Vfree_node(THREE_NODE& node, THREE_NODE*& root)
    {
        T* parent_of_deleted_node = THBStree<T>::Vfree_node(node, root);
        if(parent_of_deleted_node != NULL) Self_balance(parent_of_deleted_node);
        return TH_OK;
    }
};
#endif //THAVLTREE_H_
