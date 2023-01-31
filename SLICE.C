#include <stdio.h>

#define DUMP_LEN     0x100000 /* 00000:FFFFF - Real Mode Memory Dump   */
#define IVT_LEN      0x400    /* 00000:003FF - Interrupt Vector Table  */
#define BDA_LEN      0x100    /* 00400:004FF - BIOS Data Area          */
#define CONV0_LEN    0x7700   /* 00500:07BFF - Conventional Memory     */
#define BOOTSECT_LEN 0x200    /* 07C00:07DFF - OS Bootsector           */
#define CONV1_LEN    0x78200  /* 07E00:7FFFF - Conventional Memory     */
#define EBDA_LEN     0x20000  /* 80000:9FFFF - Extended BIOS Data Area */
#define VIDMEM_LEN   0x20000  /* A0000:BFFFF - Video Display Memory    */
#define VIDBIOS_LEN  0x8000   /* C0000:C7FFF - Video BIOS              */
#define BIOSEXP_LEN  0x28000  /* C8000:EFFFF - BIOS Expansions         */
#define BIOS_LEN     0x10000  /* F0000:FFFFF - Motherboard BIOS        */

int main() {
	unsigned char dumpb[DUMP_LEN];
	unsigned long start = 0;

	FILE *dump;
	FILE *ivt;
	FILE *bda;
	FILE *conv0;
	FILE *bootsect;
	FILE *conv1;
	FILE *ebda;
	FILE *vidmem;
	FILE *vidbios;
	FILE *biosexp;
	FILE *bios;

	dump = fopen("DUMP.BIN", "rb");
	fread(dumpb, DUMP_LEN, 1, dump);
	fclose(dump);

	ivt = fopen("IVT.BIN", "wb");
	fwrite(dumpb, 1, IVT_LEN, ivt);
	start += IVT_LEN;
	fclose(ivt);

	bda = fopen("BDA.BIN", "wb");
	fwrite(dumpb+start, 1, BDA_LEN, bda);
	start += BDA_LEN;
	fclose(bda);

	conv0 = fopen("CONV0.BIN", "wb");
	fwrite(dumpb+start, 1, CONV0_LEN, conv0);
	start += CONV0_LEN;
	fclose(conv0);

	bootsect = fopen("BOOTSECT.BIN", "wb");
	fwrite(dumpb+start, 1, BOOTSECT_LEN, bootsect);
	start += BOOTSECT_LEN;
	fclose(bootsect);

	conv1 = fopen("CONV1.BIN", "wb");
	fwrite(dumpb+start, 1, CONV1_LEN, conv1);
	start += CONV1_LEN;
	fclose(conv1);

	ebda = fopen("EBDA.BIN", "wb");
	fwrite(dumpb+start, 1, EBDA_LEN, ebda);
	start += EBDA_LEN;
	fclose(ebda);

	vidmem = fopen("VIDMEM.BIN", "wb");
	fwrite(dumpb+start, 1, VIDMEM_LEN, vidmem);
	start += VIDMEM_LEN;
	fclose(vidmem);

	vidbios = fopen("VIDBIOS.BIN", "wb");
	fwrite(dumpb+start, 1, VIDBIOS_LEN, vidbios);
	start += VIDBIOS_LEN;
	fclose(vidbios);

	biosexp = fopen("BIOSEXP.BIN", "wb");
	fwrite(dumpb+start, 1, BIOSEXP_LEN, biosexp);
	start += BIOSEXP_LEN;
	fclose(biosexp);

	bios = fopen("BIOS.BIN", "wb");
	fwrite(dumpb+start, 1, BIOS_LEN, bios);
	fclose(bios);

	return 0;
}
