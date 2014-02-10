#ifndef CIPHER_H
#define CIPHER_H

extern const char *ALPHABET;
extern const int ALPHABET_STRING_LENGTH;

#ifndef BOOL
#define BOOL
typedef enum { false, true } bool;
#endif

extern char *get_shifted_alphabet(int shift_number);

extern char *get_affine_alphabet(int coefficient, int shift_number);

extern char *get_empty_alphabet();

extern char *encrypt_with_alphabet(char *plaintext, char *alphabet);

extern int plaintext_likelihood(char *in);

#endif

