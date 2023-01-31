#include <stdio.h>
#include <dos.h>

/*
  Simple DOS utility to dump the conventional memory of a PC
  Memory model "large" required
*/

char buffer[0x4000];

int main(void) {
	char *dest;
	unsigned long seg;
	int i;
	FILE *file;

	file = fopen("dump.bin", "wb");

	for (seg = 0xc000; seg < 0x10000; seg += 0x400) {
		dest = MK_FP(seg, 0);

		for (i = 0; i < 0x4000; i++) {
			buffer[i] = dest[i];
			fwrite(buffer, 1, 0x4000, file);
		}

	fclose(file);
	return 0;
}
