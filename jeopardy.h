/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2026, 6
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "players.h"

//#define MAX_LEN 256
typedef char tokens_t [MAX_LEN][MAX_LEN];

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern char* tokenize(char *input);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */