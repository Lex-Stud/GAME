#include "functii.h"

// Inițializează array-ul cu litere ghicite cu caracterele '_', corespunzător lungimii cuvântului secret
void initialize_guessed_letters(char guessed_letters[], int length) {
    for(int i = 0; i < length; i++) {
        guessed_letters[i] = '_';
    }
}

// Verifică dacă litera ghicită se regăsește în cuvântul secret, actualizează array-ul cu litere ghicite și returnează un indicator de corectitudine
int check_guess(char secret_word[], char guessed_letters[], char guess, int length) {
    int correct_guess = 0;
    for(int i = 0; i < length; i++) {
        if(secret_word[i] == guess) {
            guessed_letters[i] = guess;
            correct_guess = 1;
        }
    }
    return correct_guess;
}

// Verifică dacă toate literele au fost ghicite, indicând astfel câștigul
int check_win(char guessed_letters[], int length) {
    int won = 1;
    for(int i = 0; i < length; i++) {
        if(guessed_letters[i] == '_') {
            won = 0;
            break;
        }
    }
    return won;
}

// Afișează cuvântul ghicit până în momentul actual
void display_word(char guessed_letters[], int length) {
    printf("Cuvantul: ");
    for(int i = 0; i < length; i++) {
        printf("%c ", guessed_letters[i]);
    }
    printf("\n");
}

// Alege un cuvânt secret aleatoriu din lista de cuvinte
void select_word(char words[MAX_WORDS][MAX_WORD_LENGTH], char secret_word[]) {
    srand(time(NULL));
    int random_index = rand() % MAX_WORDS;
    strcpy(secret_word, words[random_index]);
}

// Dezvăluie o literă din cuvântul secret
void reveal_letter(char secret_word[], char guessed_letters[], int length) {
    for(int i = 0; i < length; i++) {
        if(guessed_letters[i] == '_') {
            guessed_letters[i] = secret_word[i];
            break;
        }
    }
}

// Obține o presupunere de la utilizator și gestionează opțiunile speciale (cumpărare literă, schimbare cuvânt)
char get_guess(int *money, char secret_word[], char guessed_letters[], int secret_word_length, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    char guess;
    printf("Introdu o litera, apasa 1 pentru a plati 5 credite pentru a afisa o litera sau 2 pentru a schimba cuvantul cu 10 credite: ");
    scanf(" %c", &guess);

    if(guess == '1' && *money >= 5) {
        *money -= 5;
        return '*';
    } else if(guess == '2' && *money >= 10) {
        *money -= 10;
        select_word(words, secret_word);
        secret_word_length = strlen(secret_word);
        initialize_guessed_letters(guessed_letters, secret_word_length);
        return '0';
    }

    return guess;
}

// Gestionează desfășurarea jocului
void play_game(char secret_word[], char guessed_letters[], int secret_word_length, int *money, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int attempts;
    
    // Setează numărul de încercări în funcție de lungimea cuvântului secret
    if (secret_word_length < 5) {
        attempts = 5;
    } else if (secret_word_length < 8) {
        attempts = 7;
    } else {
        attempts = 10;
    }
    
    while(1) {
        while(attempts > 0) {
            display_word(guessed_letters, secret_word_length);
            printf("Incercari ramase: %d\n", attempts);
            printf("Credite: %d\n", *money);

            char guess = get_guess(money, secret_word, guessed_letters, secret_word_length, words);

            if(guess == '*') {
                reveal_letter(secret_word, guessed_letters, secret_word_length);
            } else if(guess == '0') {
                continue;
            } else if(!check_guess(secret_word, guessed_letters, guess, secret_word_length)) {
                attempts--;
            }

            if(check_win(guessed_letters, secret_word_length)) {
                printf("Ai castigat! Cuvantul era: %s\n", secret_word);
                *money += 10;
                return;
            }
        }

        if(attempts == 0) {
            printf("Ai pierdut! Cuvantul era: %s\n", secret_word);
            return;
        }

        // Alege un cuvânt nou dacă jocul continuă
        select_word(words, secret_word);
        secret_word_length = strlen(secret_word);
        initialize_guessed_letters(guessed_letters, secret_word_length);

        // Reinițializează numărul de încercări în funcție de lungimea cuvântului nou
        if (secret_word_length < 5) {
            attempts = 5;
        } else if (secret_word_length < 8) {
            attempts = 7;
        } else {
            attempts = 10;
        }
    }
}
