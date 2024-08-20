#ifndef REPLY_H
#define REPLY_H

typedef struct Reply {
    char Username[101];
    char Content[101];
    struct Reply *next;
    struct Reply *prev;
} Reply;

Reply* createReply (char* username, char* content);

#endif