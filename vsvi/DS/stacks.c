#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    return 0;
}
