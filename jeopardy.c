/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2026, <GROUP NUMBER>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// utility functions
void swap(player* players, int i, int j) {
    player temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(player *players, int num_players) {
    for (int i=0; i < num_players; i++) {
        for (int j = 0; j< num_players - i - 1; j++) {
            if (players[j].score > players[j+1].score)
                swap(players, j, j+1);
        }
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens) {
    // uncapitalize it
    // tokenize

    toLowerCase(input); // fix case
    char* token;
    char* delim = " ";
    //char tokens[3];
    int i=1;
    token = strtok(input, delim);
    printf("token[%d]: %s\n", 0, token);
    strcpy(tokens[0], token);
    while (token != NULL) {
        token = strtok(NULL, delim);
        strcpy(tokens[i], token);
        printf("token[%d]: %s\n", i, token);
        i++;
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    bubble_sort(players, num_players);
    for (int i=0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names and initialize them
    for (int i=0; i < NUM_PLAYERS; i++) {
        char* pname;
        printf("Please enter player %d's name\n", i);
        scanf("%c", pname);
        if (!player_exists(players, NUM_PLAYERS, pname))
            players[i] = {
                    pname,
                    0
            };
        else {
            i--;
            printf("Error! name already exists '%s'\n", pname);
            continue;
        }
    }
    
    // initialize each of the players in the array


    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        display_categories();
        // choose the player
        // ask the player for their category and value
        display_question();
        // ask for answer. what is X / who is why
        // tokenize
        // feed token[2] to valid answer
        // if correct, update score

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
