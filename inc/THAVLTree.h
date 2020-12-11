#ifndef THAVLTREE_H_
#define THAVLTREE_H_
#include "THBSTree.h"
class THAVLTree
    : public THBStree
{

public:
    THAVLTree();
    virtual ~THAVLTree();
private:
    int          Get_AVL_Balance_factor(THREE_NODE* node);
    void         Balance(THREE_NODE* node);
    virtual int  Vmalloc_Node(THREE_NODE& node, THREE_NODE*& root)
    virtual int  Vfree_Node(THREE_NODE& node, THREE_NODE*& root);
    THREE_NODE*  Rotation_left(THREE_NODE* node);
    THREE_NODE*  Rotation_right_left(THREE_NODE* node);
    THREE_NODE*  Rotation_right(THREE_NODE* node);
    THREE_NODE*  Rotation_left_right(THREE_NODE* node);
};
#endif //THAVLTREE_H_