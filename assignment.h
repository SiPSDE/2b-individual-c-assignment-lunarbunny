#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

typedef struct node {
    char* word;
    struct node* next;
} Node;

Node* readWords(char* filename);

#endif
