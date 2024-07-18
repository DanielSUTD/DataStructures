#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
#define WORD_MAX 500

typedef struct {
    char structure[MAX][WORD_MAX];
    int top;
} Stack;

void initStack(Stack *stackS) {
    stackS->top = -1;
}

bool isFull(Stack *stackS) {
    return stackS->top == MAX - 1;
}

bool isEmpty(Stack *stackS) {
    return stackS->top == -1;
}

void stackPush(Stack *stackS, const char *word) {
    if (isFull(stackS)) {
        printf("The stack is full\n");
    } else {
        stackS->top += 1;
        strcpy(stackS->structure[stackS->top], word);
        printf("Completed!\n");
    }
}

void stackPop(Stack *stackS) {
    if (isEmpty(stackS)) {
        printf("The stack is empty\n");
    } else {
        stackS->top -= 1;
    }
}

void showStack(Stack *stackS) {
    printf("STACK:\n");
    for (int i = stackS->top; i >= 0; i--) {
        printf("%s\n", stackS->structure[i]);
    }
}

void stackSize(Stack *stackS) {
    printf("Size of the stack: %d\n", stackS->top + 1);
}

void topElement(Stack *stackS) {
    if (!isEmpty(stackS)) {
        printf("Top: %s\n", stackS->structure[stackS->top]);
    } else {
        printf("The stack is empty\n");
    }
}

int main(void) {
    Stack stackS;
    char word[WORD_MAX];
    char option = 'C';
    int x;

    initStack(&stackS);

    while (option == 'C') {
        printf("Type a word: ");
        fgets(word, WORD_MAX, stdin);
        word[strcspn(word, "\n")] = 0;

        stackPush(&stackS, word);

        printf("\n1 - Remove word from stack");
        printf("\n2 - Don't remove\n");
        scanf("%d", &x);
        getchar();

        if (x == 1) {
            stackPop(&stackS);
        }

        stackSize(&stackS);
        topElement(&stackS);

        printf("\nExit = E");
        printf("\nContinue = C\n");
        scanf(" %c", &option);
        getchar();
    }

    showStack(&stackS);

    return 0;
}
