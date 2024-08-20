# Assumptions
The user has to input the command, and in the next line the username, and content, and then in the next line the number (for reply).
I have only used one extra function, `void printComments(Comment* head_comment)` which prints the comments upon using view_comments.

# Social Media Platform

This project implements a simple social media platform in C, allowing users to create posts, add comments, and reply to comments. The platform is represented using the following data types:

## Data Types

### Post
- **Username**: Username of the user posting (Always a single string).
- **Caption**: Caption to the post by the user.
- **Comments**: List of comments on the post, by different users.

### Comment
- **Username**: Username of the user commenting.
- **Content**: Content of the comment.
- **Replies**: List of replies to the comment by different users.

### Platform
The social media platform ADT must store the following information:
- **Posts**: Lists of posts stored in some order of the time they were posted.
- **lastViewedPost**: The last viewed post on the terminal. If this does not hold for any post, it is the most recently added post till now.

### Reply 
Replies to the comments on a post must store the following information:
- **Username**: Username of the user replying.
- **Content**: Content of the reply.

## Functions

### Post

#### `createPost`
```c
Post* createPost(char* username, char* caption);
```
Creates a post using the given parameters, returning a pointer to it.

### Comment

#### `createComment`
```c
Comment* createComment(char* username, char* content);
```
Creates a comment using the given parameters, returning a pointer to it.

### Reply (Bonus)

#### `createReply`
```c
Reply* createReply(char* username, char* content);
```
Creates a reply using the given parameters, returning a pointer to it.

### Platform

#### `createPlatform`
```c
Platform* createPlatform(void);
```
Create an instance of the platform data type. Only one such instance should be made throughout the code.

#### `addPost`
```c
bool addPost(char* username, char* caption);
```
Create a post of the given parameters and adds it to the existing list of posts, returning whether the process is successful or not.

#### `deletePost`
```c
bool deletePost(int n);
```
Deletes the nth recent post, returning whether the deletion is successful or not. It also clears the comments and replies to the post.

#### `viewPost`
```c
Post* viewPost(int n);
```
Returns the nth recent post, if existing. If it does not exist, a NULL pointer must be returned.

#### `currPost`
```c
Post* currPost(void);
```
Returns the lastViewedPost. If no post has been viewed, a NULL pointer must be returned.

#### `nextPost`
```c
Post* nextPost(void);
```
Returns the post posted just before the lastViewedPost. If the lastViewedPost is the first post added, then return it. In case of any error, a NULL pointer must be returned.

#### `previousPost`
```c
Post* previousPost(void);
```
Returns the post posted just after the lastViewedPost. If the lastViewedPost is the most recent post added, then return it. In case of any error, a NULL pointer must be returned.

#### `addComment`
```c
bool addComment(char* username, char* content);
```
Adds a comment to the lastViewedPost, returning whether the addition is successful or not.

#### `deleteComment`
```c
bool deleteComment(int n);
```
Deletes the nth recent comment to the lastViewedPost, returning whether the deletion is successful or not. It also clears the replies to the comment.

#### `viewComments`
```c
Comment* viewComments(void);
```
Returns a list of all comments to the lastViewedPost. The order of the comments in the list is in order of the time of commenting, the latest being at last.

#### `addReply` 
```c
bool addReply(char* username, char* content, int n);
```
Adds a reply to the nth recent comment of the lastViewedPost, returning whether the addition is successful or not.

#### `deleteReply` 
```c
bool deleteReply(int n, int m);
```
Deletes the mth recent reply to the nth recent comment of the lastViewedPost, returning whether the deletion is successful or not.