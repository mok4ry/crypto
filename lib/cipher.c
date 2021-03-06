#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cipher.h"

// 52 places for letters (upper and lowercase) and one for null terminator
const char *ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int ALPHABET_STRING_LENGTH = 53;

int get_char_alphabet_index (char c);
bool is_alpha (char c);
bool is_lowercase_letter(char c);
bool is_uppercase_letter(char c);
char *lowercase_string(char *str);

char *get_shifted_alphabet(int shift_number) {
	int index = 0, corresponding_index;
	char *shifted_alphabet = get_empty_alphabet();

	while (index < 26) {  // uppercase part
		corresponding_index = (index + shift_number) % 26;
		shifted_alphabet[index] = ALPHABET[corresponding_index];
		index++;
	}

	while (index < 52) {  // lowercase part
		corresponding_index = ((index + shift_number) % 26) + 26;
		shifted_alphabet[index] = ALPHABET[corresponding_index];
		index++;
	}

	return shifted_alphabet;
}

char *get_affine_alphabet(int coefficient, int shift_number) {
	int index = 0, corresponding_index;
	char *affine_alphabet = get_empty_alphabet();

	while (index < 26) {  // uppercase part
		corresponding_index = (coefficient * index + shift_number) % 26;
		affine_alphabet[index] = ALPHABET[corresponding_index];
		index++;
	}

	while (index < 52) {  // lowercase part
		corresponding_index = ((coefficient * index + shift_number) % 26) + 26;
		affine_alphabet[index] = ALPHABET[corresponding_index];
		index++;
	}

	return affine_alphabet;
}

char *get_empty_alphabet() {
	char *empty_alphabet = malloc(ALPHABET_STRING_LENGTH);
	empty_alphabet[ALPHABET_STRING_LENGTH - 1] = '\0';
	return empty_alphabet;
}

char *encrypt_with_alphabet(char *plaintext, char *alphabet) {
	int i, alphabet_index, plaintext_length = strlen(plaintext);
	char *encrypted = malloc(plaintext_length + 1);
	encrypted[plaintext_length] = '\0';
	for (i = 0; i < plaintext_length; i++) {
		alphabet_index = get_char_alphabet_index(plaintext[i]);
		encrypted[i] = is_alpha(plaintext[i]) ?
			alphabet[alphabet_index] : plaintext[i];
	}
	return encrypted;
}

int plaintext_likelihood(char *in) {
    char *common_letter_combos[8] = {"th", "the", "er", "on", "an", "ss", "ee", "tt"};
    char *low = lowercase_string(in);
    int score = 0, index;

    for (index = 0; index < 8; index++) {
        score += (strstr(low, common_letter_combos[index]) != NULL) ? 1 : 0;
    }

    return score;
}

char *lowercase_string(char *str) {
	int length = strlen(str);
	char *lowercase = malloc(sizeof(char) * (length + 1));
	lowercase[length] = '\0';
	int i;
	for (i = 0; i < length; i++) {
		lowercase[i] = tolower(str[i]);
	}
	return lowercase;
}

int get_char_alphabet_index (char c) {
	int index;

	if (is_uppercase_letter(c)) {
		index = c - 'A';
	} else if (is_lowercase_letter(c)) {
		index = c - 'A' - 6;  // six symbols between 'Z' and 'a'
	} else {
		index = c;
	}

	return index;
}

bool is_alpha (char c) {
	return is_lowercase_letter(c) || is_uppercase_letter(c);
}

bool is_lowercase_letter (char c) {
	return c >= 'a' && c <= 'z';
}

bool is_uppercase_letter (char c) {
	return c <= 'Z' && c >= 'A';
}
