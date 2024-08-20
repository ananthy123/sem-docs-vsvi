#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "reply.h"
#include "comment.h"


typedef struct Comment Comment;

Comment* createComment (char* username, char* content) {
    Comment *newComment = (Comment*) malloc (sizeof(Comment));
    assert(newComment != NULL);
    strcpy(newComment->Username, username);
    strcpy(newComment->Content, content);
    newComment->head_reply = NULL;
    newComment->next = NULL;
    newComment->prev = NULL;
    newComment->tail_reply = NULL;
    //newComment->size = 0;
    return newComment;
}