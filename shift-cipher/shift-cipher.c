#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/cipher.h"
#include "../lib/ioutils.h"

void print_most_likely(char *in, int threshold) {
    int i;
    for (i = 1; i < 26; i++) {
        char *shifted_alphabet = get_shifted_alphabet(i);
        char *ciphertext = encrypt_with_alphabet(in, shifted_alphabet);
        if (plaintext_likelihood(ciphertext) > threshold) {
            // real shift is 26 - i because we're going from ciphertext to
            // plaintext, so working backward
            printf("shift: %d - %s", 26 - i, ciphertext); 
        }
    }
}

int main(int argc, char *argv[]) {
    int c, shift_number = 3; // default to Caeser cipher
    int brute_force_break = 0, threshold = 2;

    while ((c = getopt(argc, argv, "bt:n:")) != -1)
        switch (c) {
            case 'b':
                brute_force_break = 1;
                break;
            case 't':
                threshold = atoi(optarg);
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
        print_most_likely(slurp_stdin(), threshold);
    } else {
        char *shifted_alphabet = get_shifted_alphabet(shift_number);
        printf("%s", encrypt_with_alphabet(slurp_stdin(), shifted_alphabet));
    }

    return 0;
}
