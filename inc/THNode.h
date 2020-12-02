#ifndef THNODE_H_
#define THNODE_H_

//node
typedef struct tag_th_node
{
    int idx;
    int value;
    struct tag_th_node* pl;
    struct tag_th_node* pr;
    struct tag_th_node& operator=(const struct tag_th_node& node);
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
    E_NODE_COLOR color
    struct tag_th_node* pl;
    struct tag_th_node* pr;
} THTREE_RB_NODE;


//node key
#define NODE_KEY_T int
bool operator==(const THREE_NODE& left, const THREE_NODE& right);
bool operator>(const THREE_NODE& left, const THREE_NODE& right);
bool operator<(const THREE_NODE& left, const THREE_NODE& right);
bool operator>(const NODE_KEY_T& key, const THREE_NODE& right);
bool operator<(const NODE_KEY_T& key, const THREE_NODE& right);


#endif //THNODE_H_