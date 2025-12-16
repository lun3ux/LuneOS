#include "stdint.h"
#include "stdio.h"
#include "disk.h"
#include "fat.h"

void far* g_data = (void far*)0x00500200;

void _cdecl cstart_(uint16_t bootDrive)
{
    DISK disk;
    if (!DISK_Initialize(&disk, bootDrive))
    {
        printf("Disk init error\r\n");
        goto end;
    }

    DISK_ReadSectors(&disk, 19, 1, g_data);

    if (!FAT_Initialize(&disk))
    {
        printf("FAT init error\r\n");
        goto end;
    }

    // browse files in root
    FAT_File far* fd = FAT_Open(&disk, "/");
    FAT_DirectoryEntry entry;
    int i = 0;
    while (FAT_ReadEntry(&disk, fd, &entry) && i++ < 5)
    {
        printf("  ");
        for (int i = 0; i < 11; i++)
            putc(entry.Name[i]);
        printf("\r\n");
    }
    FAT_Close(fd);

    // read test.txt
    char buffer[100];
    uint32_t read;
    fd = FAT_Open(&disk, "mydir/test.txt");
    while ((read = FAT_Read(&disk, fd, sizeof(buffer), buffer)))
    {
        for (uint32_t i = 0; i < read; i++)
        {
            if (buffer[i] == '\n')
                putc('\r');
            putc(buffer[i]);
        }
    }
    FAT_Close(fd);

    const char far* far_str = "far string";

    printf("Formatted %% %c %s %ls\r\n", 'a', "string", far_str);
    printf("Formatted %d %i %x %p %o %hd %hi %hhu %hhd\r\n", 1234, -5678, 0xdead, 0xbeef, 012345, (short)27, (short)-42, (unsigned char)20, (signed char)-10);
    printf("Formatted %ld %lx %lld %llx\r\n", -100000000l, 0xdeadbeeful, 10200300400ll, 0xdeadbeeffeebdaedull);
    printf("BOOTLADER STAGE 2 LOADED!                                                       ", far_str);
    printf("WELCOME TO:                                                                     ",far_str);
    printf("   ,,                                                                          ", far_str);
    printf("  `7MM                                                                           "), far_str;
    printf("   MM                                                                           "),  far_str;
    printf("   MM `7MM  `7MM  `7MMpMMMb.  .gP\"Ya       ,pW\"Wq.  ,pP\"Ybd                        ", far_str);
    printf("MM   MM    MM    MM    MM ,M'   Yb     6W'   `Wb 8I   `\"                        ", far_str);
    printf("MM   MM    MM    MM    MM 8M\"\"\"\"\"\"     8M     M8 `YMMMa.                       ", far_str);
    printf(" MM   MM    MM    MM    MM YM.    ,     YA.   ,A9 L.   I8                      ", far_str);
    printf(".JMML. `Mbod\"YML..JMML  JMML.`Mbmmd'      `Ybmd9'  M9mmmP'                      ", far_str);
    printf("                                                                                 ", far_str);
    printf("ALPHA 1.0.0                                               ");
    printf(" ");


end:
    for (;;);
}