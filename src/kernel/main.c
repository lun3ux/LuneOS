#include <stdint.h>
#include "stdio.h"
#include "memory.h"

extern uint8_t __bss_start;
extern uint8_t __end;

void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));

    clrscr();

    printf("Hello world from kernel!!!\n");
        // // browse files in root
    // FAT_File  fd = FAT_Open(&disk, "/");
    // FAT_DirectoryEntry entry;
    // int i = 0;
    // while (FAT_ReadEntry(&disk, fd, &entry) && i++ < 5)
    // {
    //     printf("  ");
    //     for (int i = 0; i < 11; i++)
    //         putc(entry.Name[i]);
    //     printf("\r\n");
    // }
    // FAT_Close(fd);

    // // read test.txt
    // char buffer[256];
    // uint32_t read;
    // fd = FAT_Open(&disk, "test.txt");
    // while ((read = FAT_Read(&disk, fd, sizeof(buffer), buffer)))
    // {
    //     for (uint32_t i = 0; i < read; i++)
    //     {
    //         if (buffer[i] == '\n') {
    //         putc('\r');
    //     }
    //         putc(buffer[i]);
    //     }
    // }
    // FAT_Close(fd);

    printf("\r");
    printf("   ,,                                                                          ");
    printf("  `7MM                                                                           ");
    printf("   MM                                                                           ");
    printf("   MM `7MM  `7MM  `7MMpMMMb.  .gP\"Ya       ,pW\"Wq.  ,pP\"Ybd                        ");
    printf("MM   MM    MM    MM    MM ,M'   Yb     6W'   `Wb 8I   `\"                        ");
    printf("MM   MM    MM    MM    MM 8M\"\"\"\"\"\"     8M     M8 `YMMMa.                       ");
    printf(" MM   MM    MM    MM    MM YM.    ,     YA.   ,A9 L.   I8                      ");
    printf(".JMML. `Mbod\"YML..JMML  JMML.`Mbmmd'      `Ybmd9'  M9mmmP'                      ");
    printf("                                                                                 ");
    printf("ALPHA 1.0.0                                               ");
    printf("\r");

end:
    for (;;);
}
