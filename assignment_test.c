#include <assert.h>
#include <string.h>
#include "assignment.h"

int main() {
    // Define the expected words in the file.
    char* expected_words[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    
    // Call the student's function.
    Node* list = readWords("words.txt");

    // Iterate through the linked list, checking each word.
    for (int i = 0; i < 10; i++) {
        assert(list != NULL);  // There should be a node here.
        assert(strcmp(list->word, expected_words[i]) == 0);  // The word should match the expected word.
        list = list->next;  // Go to the next node.
    }

    assert(list == NULL);  // There should be no more nodes.

    printf("All tests passed!\n");

    return 0;
}
