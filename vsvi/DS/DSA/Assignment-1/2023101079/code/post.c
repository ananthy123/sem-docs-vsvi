#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "post.h"
#include "reply.h"
#include "comment.h"
#include "platform.h"

//typedef struct Post Post;

Post *createPost(char *username, char *caption) {
    Post *newPost = (Post *)malloc(sizeof(Post));
    assert(newPost != NULL);

    strcpy(newPost->Username, username);
    strcpy(newPost->Caption, caption);
    newPost->head_comment = NULL;
    newPost->next = NULL;
    newPost->prev = NULL;
    newPost->tail_comment = NULL;
    //newPost->size = 0;
    return newPost;
}