#ifndef COMMENT_H
#define COMMENT_H

#include "reply.h"

typedef struct Comment {
    char Username[101];
    char Content[101];
    struct Reply *head_reply;
    struct Reply *tail_reply;
    struct Comment *next;
    struct Comment *prev;
} Comment;


Comment* createComment (char* username, char* content);

#endif
