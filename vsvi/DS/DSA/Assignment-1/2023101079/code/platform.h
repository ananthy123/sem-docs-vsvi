#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdbool.h>
#include "post.h"

    typedef struct Platform {
    struct Post *head_post;
    struct Post *tail_post;
    struct Post *lastViewedPost; // the tail of the linked list
} Platform;

//Platform* platform;

Platform* createPlatform();
bool addPost(char* username, char* caption);
bool deletePost(int n);
Post* viewPost(int n);
void printPostList();
Post* currPost();
Post* nextPost();
Post* previousPost();

bool addComment(char* username, char* content);
bool deleteComment(int n);

Comment* viewComments();
void printComments(Comment* head_comment);

bool addReply(char* username, char* content, int n);
bool deleteReply(int n, int m);


#endif