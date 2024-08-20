#ifndef post_h
#define post_h

#include "comment.h"

typedef struct Post {
    char Username[101];
    char Caption[101];
    struct Comment *head_comment;
    struct Comment *tail_comment;
    struct Post *next;
    struct Post *prev;
} Post;

Post *createPost(char *username, char *caption) ;

#endif