#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "platform.h"
#include "post.h"
#include "reply.h"
#include "comment.h"

#define MAX_USERNAME_SIZE 101
#define MAX_CONTENT_SIZE 101


int main()
{
    bool exitStatus = true;
    char command[25];
    while (exitStatus == true)
    {
        scanf("%s", command);
        if (strcmp(command, "create_platform") == 0)
        {
            platform = createPlatform();
            scanf("%*c");
        }
        else if (strcmp(command, "add_post") == 0)
        {
            char username[MAX_USERNAME_SIZE];
            char caption[MAX_CONTENT_SIZE];
            scanf("%s", username);
            scanf(" %[^\n]", caption);
            getchar();

            if (addPost(username, caption)) {
                continue;
            } else {
                printf("Could not add post\n");
            }
        }
        else if (strcmp(command, "view_post") == 0)
        {
            int n;
            scanf("%d", &n);
            Post *post = viewPost(n);
            if (post != NULL) {
                printf("%s %s\n", post->Username, post->Caption);
            } else {
                printf("Post does not exist.\n");
            }
        }
        else if (strcmp(command, "current_post") == 0)
        {
            Post* post = currPost();
            if (post != NULL) {
                printf("%s %s\n", post->Username, post->Caption);
            } else {
                printf("Current post does not exist.\n");
            }
        }
        else if (strcmp(command, "next_post") == 0)
        {
            Post *post = nextPost();
            if (post != NULL) {
                printf("%s %s\n", post->Username, post->Caption);
            } else {
                printf("Next post does not exist.\n");
            }
        }
        else if (strcmp(command, "previous_post") == 0)
        {
            Post* post = previousPost();
            if (post != NULL) {
                printf("%s %s\n", post->Username, post->Caption);
            } else {
                printf("Previous post does not exist.\n");
            }
        }
        else if (strcmp(command, "delete_post") == 0)
        {
            int n;
            scanf("%d", &n);
            bool deleted = deletePost(n);
            if (deleted) {
                continue;
            } else {
                printf("Could not delete post\n");
                
            }
        }
        else if (strcmp(command, "add_comment") == 0)
        {
            char username[MAX_USERNAME_SIZE];
            char content[MAX_CONTENT_SIZE];
            scanf("%s", username);
            scanf(" %[^\n]", content);
            getchar();

            if (addComment(username, content)) {
                continue;
            } else {
                printf("Could not add comment\n");
                
            }
        }
        else if (strcmp(command, "delete_comment") == 0)
        {
            int n;
            scanf("%d", &n);
            bool deleted = deleteComment(n);
            if (deleted) {
                continue;
            } else {
                printf("Could not delete comment\n");
                
            }
        }
        else if (strcmp(command, "view_comments") == 0)
        {
            Comment* listComments = viewComments();
            if (listComments == NULL) {
                printf("Could not print comments\n");
            } else {
                printComments(listComments);
            }
        }
        else if (strcmp(command, "add_reply") == 0)
        {
            char username[MAX_USERNAME_SIZE];
            char reply[MAX_CONTENT_SIZE];
            scanf("%s", username);
            getchar();
            scanf(" %[^\n]", reply);
            getchar();
            int n;
            scanf("%d", &n);

            if (addReply(username, reply, n)) {
                continue;
            } else {
                printf("Could not add reply\n");
                
            }
        }
        else if (strcmp(command, "delete_reply") == 0)
        {
            int n, m;
            scanf("%d %d", &n, &m);
            bool deleted = deleteReply(n, m);
            if (deleted) {
                continue;
            } else {
                printf("Could not delete reply\n");
                
            }
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting program\n");
            exitStatus = false;
        }
    }
    return 0;
}
