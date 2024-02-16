#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 5
#define MAX_WORD_LENGTH 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 5
#define MAX_WORD_LENGTH 20

void initialize_guessed_letters(char guessed_letters[], int length);
int check_guess(char secret_word[], char guessed_letters[], char guess, int length);
int check_win(char guessed_letters[], int length);
void display_word(char guessed_letters[], int length);
void select_word(char words[MAX_WORDS][MAX_WORD_LENGTH], char secret_word[]);
void reveal_letter(char secret_word[], char guessed_letters[], int length);
void play_game(char secret_word[], char guessed_letters[], int secret_word_length, int *money, char words[MAX_WORDS][MAX_WORD_LENGTH]);