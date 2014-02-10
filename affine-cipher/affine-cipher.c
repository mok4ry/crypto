#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/cipher.h"
#include "../lib/ioutils.h"
#include "../lib/cryptomath.h"

void print_all_likely(char *in) {
    int coefficients[] = {1,3,5,7,9,11,15,17,19,21,23,25};
    int i, j;

    for (i = 0; i < sizeof(coefficients)/sizeof(int); i++) {
        for (j = 1; j < 26; j++) {
            char *affine_alphabet = get_affine_alphabet(coefficients[i], j);
            char *ciphertext = encrypt_with_alphabet(in, affine_alphabet);
            if (plaintext_likelihood(ciphertext) > 3) {
                printf("a: %d, n: %d - %s", coefficients[i], j, ciphertext);
            }
        }
    }
}

int main(int argc, char *argv[]) {
	int c, a = 3, shift_number = 5;  // default to (3x + 5)
    int brute_force_break = 0;

	while ((c = getopt(argc, argv, "ba:n:")) != -1)
		switch (c) {
            case 'b':  // attempt to break input with affine cipher
                brute_force_break = 1;
                break;
			case 'a':  // specify coefficient
				a = atoi(optarg);
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
        print_all_likely(slurp_stdin());
    } else if (are_coprime(a, 26)) {
		char *affine_alphabet = get_affine_alphabet(a, shift_number);
		printf("%s", encrypt_with_alphabet(slurp_stdin(), affine_alphabet));
	} else {
		printf("Invalid 'a': %d. Choice for 'a' must be coprime with 26.\n", a);
	}

	return 0;
}
