#ifndef THREDBLACK_H_
#define THREDBLACK_H_
#include "THNode.h"
class THRBTree
    : public THTree
{
public:
    THRBTree();
    ~THRBTree();
public:
    static THTREE_RB_NODE* Get_parent_node(THTREE_RB_NODE* node, THTREE_RB_NODE* root);
public:
    int Insert(THTREE_RB_NODE* node);
    int Find(THTREE_RB_NODE* node);
    int Remove(THTREE_RB_NODE* node);
private:
    int Rotate_left(THTREE_RB_NODE* rotate);
    int Rotate_right(THTREE_RB_NODE* rotate);
    int VInsert(THTREE_RB_NODE* node, THTREE_RB_NODE*& root);
    int VFind(THTREE_RB_NODE* node, THTREE_RB_NODE* root);
    int VRemove(THTREE_RB_NODE* node, THTREE_RB_NODE* root);
    int VBalance(THTREE_RB_NODE* node);
private:
    THTREE_RB_NODE* m_root;
};

#endif