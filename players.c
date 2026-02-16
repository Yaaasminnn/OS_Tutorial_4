/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2026, <6>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
  for (int i = 0; i < num_players; i++)
  {
    if (strcmp(name, players[i].name) == 0) // Comparing the current
                                            // player name with each existing
                                            // player name with strcmp
      return true; // true if their name already exists
  }
  return false; // false if the player's name does not exist
}

// Go through the list of players and update the score for the
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{
  for (int i = 0; i < num_players; i++)
  {
    if (strcmp(name, players[i].name) == 0) {
        players[i].score += score; // if the player's name exists
        // their score will be updated
        break; // break is used so that the loop stops after the first
        // match and update
    }
  }
}
