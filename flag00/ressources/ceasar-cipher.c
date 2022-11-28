#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int ac, char **av) {
	if (ac == 3) {
		char ch, text[4096];
		int key = atoi(av[2]);
		if (key == 0) {
			puts("Enter number in second argument");
			return 1;
		}

		// visiting character by character
		for (int i = 0; av[1][i] != '\0'; ++i) {

			ch = av[1][i];
			// check for valid character
			if (isalnum(ch)) {

			// lower case characters
			if (islower(ch)) {
				ch = (ch - 'a' + key) % 26 + 'a';
			}
			// uppercase characters
			if (isupper(ch)) {
				ch = (ch - 'A' + key) % 26 + 'A';
			}

			// numbers
			if (isdigit(ch)) {
				ch = (ch - '0' + key) % 10 + '0';
			}
			}
			// invalid character
			else {
				printf("Invalid Message");
			}
			// adding encoded answer 
			text[i] = ch;

		}

		printf("Encrypted message: %s", text);

		return 0;
	}
	return 1;
}