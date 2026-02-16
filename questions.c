/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2026, 6
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    int index = 0;

    // ================= Programming Category =================
    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "This language is used to write operating systems.");
    strcpy(questions[index].answer, "c");
    questions[index].value = 100;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "This keyword is used to define a constant in C.");
    strcpy(questions[index].answer, "const");
    questions[index].value = 200;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "This loop runs at least once.");
    strcpy(questions[index].answer, "do");
    questions[index].value = 300;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "This function prints output to the console.");
    strcpy(questions[index].answer, "printf");
    questions[index].value = 400;
    questions[index].answered = false;
    index++;

    // ================= Algorithms Category =================
    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "This sorting algorithm has average time complexity O(n log n).");
    strcpy(questions[index].answer, "mergesort");
    questions[index].value = 100;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "This data structure follows FIFO.");
    strcpy(questions[index].answer, "queue");
    questions[index].value = 200;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "Binary search works only on this type of array.");
    strcpy(questions[index].answer, "sorted");
    questions[index].value = 300;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "This traversal visits left, root, right.");
    strcpy(questions[index].answer, "inorder");
    questions[index].value = 400;
    questions[index].answered = false;
    index++;

    // ================= Databases Catgeory =================
    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "SQL stands for Structured Query ____.");
    strcpy(questions[index].answer, "language");
    questions[index].value = 100;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "This SQL command retrieves data.");
    strcpy(questions[index].answer, "select");
    questions[index].value = 200;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "This key uniquely identifies a row.");
    strcpy(questions[index].answer, "primary");
    questions[index].value = 300;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "This SQL command removes a table.");
    strcpy(questions[index].answer, "drop");
    questions[index].value = 400;
    questions[index].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("\nAvailable Questions:\n");

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("Category: %s | $%d\n",
                   questions[i].category,
                   questions[i].value);
        }
    }
}

// Displays the question for the category and dollar value
bool display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value &&
            !questions[i].answered) {

            printf("\nQuestion: %s\n", questions[i].question);
            return true;
        }
    }

    printf("Question not found.\n");
    return false;
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for (int i = 0; i < NUM_QUESTIONS; i++) {

        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value) {

            questions[i].answered = true;

            if (strcmp(questions[i].answer, answer) == 0) {
                return true;
            } else {
                printf("Correct answer: %s\n", questions[i].answer);
                return false;
            }
        }
    }

    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value) {

            return questions[i].answered;
        }
    }

    return true; // if not found treat as invalid
}
