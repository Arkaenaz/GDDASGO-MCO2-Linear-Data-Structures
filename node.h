/****************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT
****************************************/
#ifndef NODE_H
#define NODE_H

struct Node{
    char *data;
    struct Node *pLink;
};

typedef struct Node sNode;

#endif