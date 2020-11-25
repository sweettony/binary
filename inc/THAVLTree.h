#ifndef THAVLTREE_H_
#define THAVLTREE_H_
#include "THBSTree.h"
class THAVLTree
    : public THBStree
{

public:
    THAVLTree();
    virtual ~THAVLTree();

protected:
    virtual int Do_insert(THREE_NODE& node, THREE_NODE*& root);
    virtual int Do_remove(THREE_NODE& node, THREE_NODE*& root);

private:
    int Get_AVL_Balance_factor(THREE_NODE* node);
    void Balance(THREE_NODE* node);
    THREE_NODE*  Rotation_left(THREE_NODE* node);
    THREE_NODE*  Rotation_right_left(THREE_NODE* node);
    THREE_NODE*  Rotation_right(THREE_NODE* node);
    THREE_NODE*  Rotation_left_right(THREE_NODE* node);
};
#endif //THAVLTREE_H_