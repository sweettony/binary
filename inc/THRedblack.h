#ifndef THREDBLACK_H_
#define THREDBLACK_H_


class THRBTree
    : public THTree
{
public:
    THRBTree();
    ~THRBTree();

private:
    THTREE_RB_NODE* m_root;
};

#endif