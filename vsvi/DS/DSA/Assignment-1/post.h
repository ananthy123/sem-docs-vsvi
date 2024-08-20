#ifndef post_h
#define post_h

#include "comment.h"

typedef struct Post {
    char Username[100];
    char Caption[100];
    struct Comment *head_comment;
    struct Comment *tail_comment;
    struct Post *next;
    struct Post *prev;
} Post;

Post *createPost(char *username, char *caption) ;

#endif