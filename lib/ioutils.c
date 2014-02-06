#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ioutils.h"

char *slurp_stdin() {
	char *memo = malloc(1), *input = malloc(1);
	size_t len = 0;
	ssize_t read;
	int new_len;

	if (input == NULL || memo == NULL) {
		perror("Failed to allocate content");
		exit(1);
	}
	input[0] = '\0';
	memo[0] = '\0';

	while((read = getline(&input, &len, stdin) != -1)) {
		new_len = strlen(memo) + strlen(input);
		memo = realloc(memo, new_len + 1);
		strcat(memo, input);

		free(input);
	}
	
	return memo;
}