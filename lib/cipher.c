#include <stdlib.h>
#include <string.h>
#include "cipher.h"

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";
const int ALPHABET_STRING_LENGTH = 27;

char *get_shifted_alphabet(int shift_number) {
	int index = 0, corresponding_index;
	char *shifted_alphabet = get_empty_alphabet();

	while (index < 26) {
		corresponding_index = (index + shift_number) % 26;
		shifted_alphabet[index] = ALPHABET[corresponding_index];
		index++;
	}

	return shifted_alphabet;
}

char *get_empty_alphabet() {
	char *empty_alphabet = malloc(ALPHABET_STRING_LENGTH);
	empty_alphabet[ALPHABET_STRING_LENGTH - 1] = '\0';
	return empty_alphabet;
}

char *encrypt_with_alphabet(char *plaintext, char *alphabet) {
	int i, plaintext_length = strlen(plaintext);
	char *encrypted = malloc(plaintext_length + 1);
	encrypted[plaintext_length] = '\0';
	for (i = 0; i < plaintext_length; i++) {
		encrypted[i] = alphabet[getCharAlphabetIndex(plaintext[i])];
	}
	return encrypted;
}

int getCharAlphabetIndex (char c) {
	return c - 'a';
}