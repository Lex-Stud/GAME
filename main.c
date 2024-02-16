#include "functii.h"

int main(int argc, char *argv[])
{   
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"programare", "dezvoltare", "algoritm", "structura", "compilator"};
    char secret_word[MAX_WORD_LENGTH];
    int secret_word_length;
    int money = 20;
    char guessed_letters[MAX_WORD_LENGTH];
    char continue_game;

    // Mesaj de bun venit
    printf("Bun venit la Spanzuratoarea!\n");
    printf("Ai %d lei.\n", money);
    printf("Cumpara o litera pentru 5 lei -- 1. Skip cuvant 10 lei -- 2\n");

    do {
        // Alege un cuvânt la începutul fiecărei iterații
        select_word(words, secret_word);
        secret_word_length = strlen(secret_word);
        initialize_guessed_letters(guessed_letters, secret_word_length);
        play_game(secret_word, guessed_letters, secret_word_length, &money, words);

        // Întrebă utilizatorul dacă dorește să continue jocul
        printf("Doresti sa continui jocul? (y/n): ");
        scanf(" %c", &continue_game);
    } while (continue_game == 'y' || continue_game == 'Y');

    return 0;
}
