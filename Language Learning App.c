#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char word[50];
    char translation[50];
} Vocabulary;

Vocabulary vocabulary[] = {
    {"cat", "gato"},
    {"dog", "perro"},
    {"house", "casa"},
    {"car", "coche"},
    {"apple", "manzana"}
};

#define NUM_WORDS (sizeof(vocabulary) / sizeof(Vocabulary))

void vocabulary_quiz() {
    int score = 0;
    int total_questions = 5;

    printf("Welcome to the Vocabulary Quiz!\n");
    printf("Translate the following words into Spanish:\n");
    printf("--------------------\n");

    for (int i = 0; i < NUM_WORDS; i++) {
        int j = rand() % NUM_WORDS;
        Vocabulary temp = vocabulary[i];
        vocabulary[i] = vocabulary[j];
        vocabulary[j] = temp;
    }

    for (int i = 0; i < total_questions; i++) {
        Vocabulary word = vocabulary[i];

        printf("What is the Spanish translation for '%s'?\n", word.word);

        char user_translation[50];
        scanf("%s", user_translation);

        for (int j = 0; user_translation[j]; j++) {
            user_translation[j] = tolower(user_translation[j]);
        }

        if (strcmp(user_translation, word.translation) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is '%s'.\n", word.translation);
        }

        printf("--------------------\n");
    }

    printf("Quiz complete!\n");
    printf("Your score: %d/%d\n", score, total_questions);
}

int main() {
    
    srand(time(NULL));

    vocabulary_quiz();

    return 0;
}
