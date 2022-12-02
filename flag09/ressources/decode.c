#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av) {
	char buf[1];
	int i = 0, fd =0;
	if (ac == 2) {
		fd = open(av[1], O_RDONLY);
		while (read(fd, buf, 1)) {
			printf("%c", buf[0] - i);
			i++;
		}
		printf("\n");
	}
	return 0;
}