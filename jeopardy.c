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
#include <stdbool.h>
//#include "questions.h"
//#include "players.h"
#include "jeopardy.h"
#include <time.h>
#include <ctype.h>

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4


// Put global environment variables here

// utility functions
void swap(player* players, int i, int j) {
    player temp = players[i];
    players[i] = players[j];
    players[j] = temp;
}

void bubble_sort(player *players, int num_players) {
    for (int i=0; i < num_players; i++) {
        for (int j = 0; j< num_players - i - 1; j++) {
            if (players[j].score < players[j+1].score)
                swap(players, j, j+1);
        }
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
char* tokenize(char *input) {
    // uncapitalize it
    // tokenize
    char tokens[MAX_LEN][MAX_LEN];
    toLowerCase(input); // fix case
    //printf("%s\n", input);
    char* token;
    char* delim = " ";
    //char *tkn;
    int i=1;
    char* tkn = strtok(input, delim);
    //printf("token[%d]: %s\n", 0, tkn);
    //strcpy(tokens[0], token);
    while (tkn != NULL) {
        tkn = strtok(NULL, delim);
        if (tkn == NULL && i<2) {
            printf("Answer in 'what is X / who is Y' \n");
            return NULL;
        }
        else if (tkn == NULL) {
            break;
        }
        //printf("token[%d]: %s\n", i, tkn);
        strcpy(tokens[i], tkn);
        i++;
        //if (i==3) break;
    }
    //printf("answer: %s\n", tkn);
    token = tokens[i-1];
    //strcpy(token, tkn);
    //*token = token;
    return token;
}

void display_winner(player *players, int num_players) {
    bubble_sort(players, num_players);
    printf("Congratulations to player '%s' for winning!\n", players[0].name);
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    bubble_sort(players, num_players);
    for (int i=0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}


int main(void)
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names and initialize them
    for (int i=0; i < NUM_PLAYERS; i++) {
        char pname[BUFFER_LEN];
        printf("Please enter player %d's name\n", i);
        scanf("%s", pname);
        if (!player_exists(players, NUM_PLAYERS, pname)) {
            // Use strncpy to copy pname into players[i].name and initialize score to 0
            strncpy(players[i].name, pname, MAX_LEN - 1);
            // Ensure null termination
            players[i].name[MAX_LEN - 1] = '\0'; 
            players[i].score = 0;
        }
        else {
            i--;
            printf("Error! name already exists '%s'\n", pname);
            continue;
        }
    }
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
        // Call functions from the questions and players source files
        display_categories();

        // choose the player
        player current_player = players[rand() % (NUM_PLAYERS - 0 + 1) + 0];
        printf("Current player: %s\n", current_player.name);

        // ask the player for their category and value
        char cat[BUFFER_LEN];
        int *val = malloc(sizeof(int));
        printf("Choose which category\n");
        scanf("%s", cat);
        printf("Choose which value\n");
        scanf("%d", val);

        if (!display_question(cat, *val))
            continue;

        // ask for answer. what is X / who is why
        char ans[BUFFER_LEN];
        tokens_t tokens;
        printf("What is your answer (Phrased as 'What is X' / 'Who is Y')\n");
        //scanf(" %99[^\\n]", ans);

        fgets(ans, BUFFER_LEN, stdin);
        fgets(ans, BUFFER_LEN, stdin);
        ans[strcspn(ans, "\n")] = '\0';
        //printf("%s\n", ans);

        // tokenize
        char *token = tokenize(ans);
        if (token == NULL) {
            continue;
        }
        printf("answer: %s\n", token);
        // feed token[2] to valid answer
        if (valid_answer(cat, *val, token)) {
            // if correct, update score
            update_score(players, NUM_PLAYERS, current_player.name, *val);
        }

        // Execute the game until all questions are answered
        bool all_answered = true;
        for (int i=0; i < NUM_QUESTIONS; i++) {
            if (!questions[i].answered) {
                all_answered = false;
                break;
            }
        }
        show_results(players, NUM_PLAYERS);
        if (all_answered) { // Display the final results and exit
            display_winner(players, NUM_PLAYERS);
            break;
        }
        // free malloced memory
        free(val);
        printf("Press Enter to continue\n");
    }
    return EXIT_SUCCESS;
}
