#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/cipher.h"
#include "../lib/ioutils.h"
#include "../lib/cryptomath.h"

int main(int argc, char *argv[]) {
	int c, a = 3, shift_number = 5;  // default to (3x + 5)

	while ((c = getopt(argc, argv, "a:n:")) != -1)
		switch (c) {
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

	printf("%s\n", are_coprime(a, 26) ? "YES" : "NO");
	if (are_coprime(a, 26)) {
		char *affine_alphabet = get_affine_alphabet(a, shift_number);
		printf("%s", encrypt_with_alphabet(slurp_stdin(), affine_alphabet));
	} else {
		printf("Invalid 'a': %d. Choice for 'a' must be coprime with 26.\n", a);
	}

	return 0;
}