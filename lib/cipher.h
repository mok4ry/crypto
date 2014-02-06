#ifndef CIPHER_H
#define CIPHER_H

extern const char *ALPHABET;
extern const int ALPHABET_STRING_LENGTH;

typedef enum { false, true } bool;

extern char *get_shifted_alphabet(int shift_number);

extern char *get_empty_alphabet();

extern char *encrypt_with_alphabet(char *plaintext, char *alphabet);

extern int get_char_alphabet_index(char c);

extern bool is_alpha (char c);

extern bool is_lowercase_letter (char c);

extern bool is_uppercase_letter (char c);

#endif

