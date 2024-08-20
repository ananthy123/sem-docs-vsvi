#ifndef REPLY_H
#define REPLY_H

typedef struct Reply {
    char Username[100];
    char Content[100];
    struct Reply *next;
    struct Reply *prev;
} Reply;

Reply* createReply (char* username, char* content);

#endif