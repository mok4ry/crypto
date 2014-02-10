#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/cipher.h"
#include "../lib/ioutils.h"

void print_most_likely(char *in) {
    int i;
    for (i = 1; i < 26; i++) {
        char *shifted_alphabet = get_shifted_alphabet(i);
        char *ciphertext = encrypt_with_alphabet(in, shifted_alphabet);
        if (plaintext_likelihood(ciphertext) > 2) {
            // real shift is 26 - i because we're going from ciphertext to
            // plaintext, so working backward
            printf("shift: %d - %s", 26 - i, ciphertext); 
        }
    }
}

int main(int argc, char *argv[]) {
    int c, shift_number = 3; // default to Caeser cipher
    int brute_force_break = 0;

    while ((c = getopt(argc, argv, "bn:")) != -1)
        switch (c) {
            case 'b':
                brute_force_break = 1;
                break;
            case 'n':  // specify shift number
                shift_number = atoi(optarg);
                break;
            case '?':
                printf("Error with flag: %c (invalid or argument missing)\n",
                    optopt);
                return -1;
        }

    if (brute_force_break) {
        print_most_likely(slurp_stdin());
    } else {
        char *shifted_alphabet = get_shifted_alphabet(shift_number);
        printf("%s", encrypt_with_alphabet(slurp_stdin(), shifted_alphabet));
    }

    return 0;
}
