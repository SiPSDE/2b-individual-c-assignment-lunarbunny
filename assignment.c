#include "assignment.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Node* readWords(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;
    char word[100];

    // Read words from the file, one line at a time
    while (fgets(word, sizeof(word), file) != NULL) {
        // Remove newline character, if present
        size_t len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        // Create a new node
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Error allocating memory\n");
            return NULL;
        }
        newNode->word = strdup(word);  // You'll need to free this later!
        newNode->next = NULL;

        // Add the new node to the end of the linked list
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    // Close the file
    fclose(file);

    return head->next;
}
