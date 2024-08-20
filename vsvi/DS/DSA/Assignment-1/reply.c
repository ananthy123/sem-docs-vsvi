#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "reply.h"
#include "comment.h"

typedef struct Reply Reply;

Reply* createReply (char* username, char* content) {
    Reply* newReply  = (Reply*) malloc (sizeof(Reply));
    assert(newReply!= NULL);
    strcpy(newReply->Username, username);
    strcpy(newReply->Content, content);
    newReply->next = NULL;
    newReply->prev = NULL;
    //newReply->size = 0;
    return newReply;
}

