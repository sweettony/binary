#ifndef THNODE_H_
#define THNODE_H_

//node
typedef struct tag_th_node
{
    int idx;
    int value;
    struct tag_th_node* pl;
    struct tag_th_node* pr;
    const struct tag_th_node& operator=(const struct tag_th_node& node);
} THREE_NODE;

typedef enum tag_enum_rb_node_color
{
    NODE_RED,
    NODE_BLACK
}E_NODE_COLOR;


typedef struct tag_th_rb_node
{
    int idx;
    int value;
    E_NODE_COLOR color;
    struct tag_th_rb_node* pl;
    struct tag_th_rb_node* pr;
    const struct tag_th_rb_node& operator=(const struct tag_th_rb_node& node);
} THTREE_RB_NODE;


//node key
#define NODE_KEY_T int
bool operator==(const THREE_NODE& left, const THREE_NODE& right);
bool operator>(const THREE_NODE& left, const THREE_NODE& right);
bool operator<(const THREE_NODE& left, const THREE_NODE& right);
bool operator>(const NODE_KEY_T& key, const THREE_NODE& right);
bool operator<(const NODE_KEY_T& key, const THREE_NODE& right);

// red-black tree
bool operator==(const THTREE_RB_NODE& left, const THTREE_RB_NODE& right);
bool operator>(const THTREE_RB_NODE& left,  const THTREE_RB_NODE& right);
bool operator<(const THTREE_RB_NODE& left,  const THTREE_RB_NODE& right);
bool operator>(const NODE_KEY_T& key, const THTREE_RB_NODE& node);
bool operator<(const NODE_KEY_T& key, const THTREE_RB_NODE& node);
bool operator>(const THTREE_RB_NODE& node, const NODE_KEY_T& key);
bool operator<(const THTREE_RB_NODE& node, const NODE_KEY_T& key);

#endif //THNODE_H_