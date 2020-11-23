#ifndef THAVLTREE_H_
#define THAVLTREE_H_
#include "THBSTree.h"
class THAVLTree
    : public THBStree
{

public:
    THAVLTree();
    ~THAVLTree();
public:
    int Get_AVL_Balance_factor(THREE_NODE* node);

private:
    void Balance(THREE_NODE* node);
    virtual int Insert(THREE_NODE& node, THREE_NODE*& root);
    virtual int Remove(THREE_NODE& node,THREE_NODE*& root);
    THREE_NODE*  rotation_left(THREE_NODE* node);
    THREE_NODE*  rotation_right_left(THREE_NODE* node);
    THREE_NODE*  rotation_right(THREE_NODE* node);
    THREE_NODE*  rotation_left_right(THREE_NODE* node);
};
#endif //THAVLTREE_H_