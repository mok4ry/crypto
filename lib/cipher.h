#ifndef CIPHER_H
#define CIPHER_H

extern const char *ALPHABET;
extern const int ALPHABET_STRING_LENGTH;

extern char *get_shifted_alphabet(int shift_number);

extern char *get_empty_alphabet();

extern char *encrypt_with_alphabet(char *plaintext, char *alphabet);

extern int getCharAlphabetIndex(char c);

#endif

