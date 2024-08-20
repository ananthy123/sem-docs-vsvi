#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "post.h"
#include "reply.h"
#include "comment.h"
#include "platform.h"
typedef struct Platform Platform;

int check_for_view = 0;
Platform* createPlatform() {
    Platform* platform = (Platform*) malloc (sizeof(Platform));
    assert(platform != NULL);
    platform->head_post = NULL;
    platform->lastViewedPost = NULL;
    platform->tail_post = NULL;
    return platform;
}


bool addPost(char *username, char *caption)
{
    Post *post = createPost(username, caption);
    if (platform->head_post == NULL && platform->tail_post == NULL)
    {
        platform->head_post = post;
        platform->lastViewedPost = post;
        platform->tail_post = post;
        post->next = NULL;
        post->prev = NULL;
        return true;
    }
    else
    {
        Post *currentPost = platform->tail_post;
        while (currentPost->next != NULL)
        {
            currentPost = currentPost->next;
        }
        currentPost->next = post;
        post->prev = currentPost;
        post->next = NULL;
        platform->tail_post = post;
        if (check_for_view == 0) platform->lastViewedPost = post;
        return true;
    }
    return false;
}

bool deletePost (int n) {

    if (n <= 0 || platform->tail_post == NULL) {
        return false;  // Invalid input for n or empty list
    }
    Post* deletedPost = NULL;

    if (n == 1) { // deleting tail post (deleting from head in this case)
        deletedPost = platform->tail_post;
            if (platform->tail_post == platform->head_post) {
                platform->tail_post = NULL;
                platform->head_post = NULL;
                platform->lastViewedPost = NULL;
            }
            else {
                platform->tail_post = deletedPost->prev;
                deletedPost->prev->next = NULL;
            }
    }
    else {
        int temp = 1;
        Post* currentPost = platform->tail_post;

        
        while (temp < n - 1 && currentPost != NULL) {
            currentPost = currentPost->prev;
            temp++;
        }

        if (currentPost == NULL) {
            return false;
        }
        deletedPost = currentPost->prev;
        if (deletedPost == platform->head_post) {
            platform->head_post = currentPost;
            currentPost->prev = NULL;
            platform->head_post->prev = NULL;
        }
        else if (deletedPost->prev != NULL) {
            currentPost->prev = deletedPost->prev;
            deletedPost->prev->next = currentPost;
        }

        if (deletedPost == platform->lastViewedPost) {
            platform->lastViewedPost = platform->tail_post;
        }
    }

    Comment *currentComment = deletedPost->head_comment;

    while (currentComment != NULL) {
        Comment *tempComment = currentComment;

        Reply *currentReply = tempComment->head_reply;
        while (currentReply != NULL) {
            Reply *tempReply = currentReply;
            currentReply = currentReply->next;
            free(tempReply);
        }

        free(tempComment);
    }

    free(deletedPost);

    return true;
}


Post* viewPost(int n) {
    Post* currentPost = platform->tail_post;
    if (currentPost == NULL) return NULL;
    int temp = 1;
    while (temp < n) { //because indexing is 1 based
        currentPost = currentPost->prev;
        temp++;
    }
    if (currentPost == NULL) return NULL;

    platform->lastViewedPost = currentPost;
    check_for_view = 1;
    return currentPost;
    
}

Post* currPost () {
    if(platform->lastViewedPost == NULL || platform->head_post == NULL) {
        return NULL;
    }
    return platform->lastViewedPost; 
}

Post* nextPost () {
    if(platform->lastViewedPost == NULL) return NULL;
    if(platform->lastViewedPost == platform->head_post) return platform->head_post;

    Post* nextpost = platform->lastViewedPost->prev;
    platform->lastViewedPost = nextpost;
    return nextpost;
}

Post* previousPost () {
    if(platform->lastViewedPost == NULL) return NULL;
    if(platform->lastViewedPost == platform->tail_post) return platform->tail_post;

    Post* previouspost = platform->lastViewedPost->next;
    platform->lastViewedPost = previouspost;
    return previouspost;
}

bool addComment(char* username, char* content) {
    Comment* comment = createComment(username, content); 
    if(platform->lastViewedPost == NULL) return false;

    if(platform->lastViewedPost->head_comment == NULL) {
        platform->lastViewedPost->head_comment = comment;
        platform->lastViewedPost->tail_comment = comment;
        platform->lastViewedPost->next = NULL;
        platform->lastViewedPost->prev = NULL;
        return true;
    }
    else {
        Comment* currentComment = platform->lastViewedPost->tail_comment;
        while(currentComment->next != NULL) {
            currentComment = currentComment->next;
        }
        currentComment->next = comment;
        comment->next = NULL;
        comment->prev = currentComment;
        platform->lastViewedPost->tail_comment = comment;
        return true;
    }
    return false;
}



bool deleteComment (int n) {
    if (platform->lastViewedPost == NULL || platform->lastViewedPost->head_comment == NULL) {
        return false; 
    }

    Comment* deletedComment = NULL;    
    if(n == 1) {
        deletedComment = platform->lastViewedPost->tail_comment;
        if(platform->lastViewedPost->tail_comment == platform->lastViewedPost->head_comment) {
            platform->lastViewedPost->head_comment = NULL;
            platform->lastViewedPost->tail_comment = NULL;
        }
        else { //deleting head of LL
            platform->lastViewedPost->tail_comment = platform->lastViewedPost->tail_comment->prev;
            deletedComment->prev->next = NULL;
        }

    }
    else {
        int temp = 1;
        Comment* currentComment = platform->lastViewedPost->tail_comment;

        while (temp < n - 1 && currentComment != NULL) {
            currentComment = currentComment->prev;
            temp++;
        }

        if (currentComment == NULL) return false;

        deletedComment = currentComment->prev;
        if (deletedComment == platform->lastViewedPost->head_comment) {
            platform->lastViewedPost->head_comment = currentComment;
            currentComment->prev = NULL;
        }
        else if (deletedComment->prev != NULL) {
            currentComment->prev = deletedComment->prev;
            deletedComment->prev->next = currentComment;
        }
    }    

    Reply *currentReply = deletedComment->head_reply;
        while (currentReply != NULL) {
            Reply *tempReply = currentReply;
            currentReply = currentReply->next;
            free(tempReply);
        }
    free(deletedComment);
    return true;
}

Comment* viewComments() {
    if (platform->lastViewedPost == NULL || platform->lastViewedPost->head_comment == NULL) return NULL;
    else {
        return platform->lastViewedPost->head_comment;
    }
}

void printComments(Comment* head_comment) {
    if (head_comment == NULL) return;
    Comment* currentComment = head_comment;
    while (currentComment != NULL) {
        printf("%s %s\n", currentComment->Username, currentComment->Content);
        if (currentComment->head_reply != NULL) {
            Reply* currentReply = currentComment->head_reply;
            while (currentReply != NULL) {
                printf("    %s %s\n", currentReply->Username, currentReply->Content);
                currentReply = currentReply->next;
            }
        }
        currentComment = currentComment->next;
    }
    if (currentComment == NULL) printf("Exiting\n\n");
    return;
}


bool addReply(char* username, char* content, int n) {
    Reply* reply = createReply(username, content);
    Comment* currentComment = platform->lastViewedPost->tail_comment;
    
    int check = 1;
    while (check < n && currentComment != NULL) {
        currentComment = currentComment->prev;
        check++;
    }

    if (currentComment == NULL) return false;


    if (currentComment->head_reply == NULL) {
        reply->next = NULL;
        reply->prev = NULL;
        currentComment->head_reply = reply;
        currentComment->tail_reply = reply;
        return true;
    }
    else {
        Reply* currentReply = currentComment->head_reply;
        while (currentReply->next != NULL) {
            currentReply = currentReply->next;
        }
        currentReply->next = reply;
        reply->prev = currentReply;
        reply->next = NULL;
        currentComment->tail_reply = reply;
        return true;
    }
}

bool deleteReply (int n, int m) {
    int check = 1;
    Comment* currentComment = platform->lastViewedPost->tail_comment;
    while (check < n && currentComment != NULL) {
        currentComment = currentComment->prev;
        check++;
    }
    
    if (currentComment == NULL) return false;
    Reply* deletedReply = NULL;
    if (m == 1) {
        deletedReply = currentComment->tail_reply;
        if(currentComment->tail_reply == currentComment->head_reply) {
            currentComment->tail_reply = NULL;
            currentComment->head_reply = NULL;
        }
        else {
            deletedReply->prev->next = NULL;
        }
    }

    else {
        int reply_check = 1;
        Reply* currentReply = currentComment->tail_reply;
        while (reply_check < m - 1 && currentReply != NULL) {
            currentReply = currentReply->prev;
            reply_check++;
        }
        
        if(currentReply == NULL) return false;

        deletedReply = currentReply->prev;
        if (deletedReply->prev == NULL) {
            currentComment->head_reply = currentReply;
            currentReply->prev = NULL;
        }
        else if (deletedReply->prev != NULL) {
            currentReply->prev = deletedReply->prev;
            deletedReply->prev->next = currentReply;
        }
    }

    free(deletedReply);
    return true;
}