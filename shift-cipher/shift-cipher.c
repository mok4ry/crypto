#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/cipher.h"
#include "../lib/ioutils.h"

int main(int argc, char *argv[]) {
    int c, shift_number = 3; // default to Caeser cipher

    while ((c = getopt(argc, argv, "n:")) != -1)
        switch (c) {
            case 'n':  // specify shift number
                shift_number = atoi(optarg);
                break;
            case '?':
                printf("Error with flag: %c (invalid or argument missing)\n",
                    optopt);
                return -1;
        }

    char *shifted_alphabet = get_shifted_alphabet(shift_number);
    printf("%s", encrypt_with_alphabet(slurp_stdin(), shifted_alphabet));

    return 0;
}
