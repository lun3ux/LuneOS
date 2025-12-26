#include <stdint.h>
#include "stdio.h"
#include "memory.h"

extern uint8_t __bss_start;
extern uint8_t __end;
void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));

    printf("Hello world from kernel!!!\n");
    printf("\r");
    printf("\n");
    printf("   ,,                                                                          ");
    printf("  `7MM                                                                           ");
    printf("   MM                                                                           ");
    printf("   MM `7MM  `7MM  `7MMpMMMb.  .gP\"Ya       ,pW\"Wq.  ,pP\"Ybd                        ");
    printf("MM   MM    MM    MM    MM ,M'   Yb     6W'   `Wb 8I   `\"                        ");
    printf("MM   MM    MM    MM    MM 8M\"\"\"\"\"\"     8M     M8 `YMMMa.                       ");
    printf(" MM   MM    MM    MM    MM YM.    ,     YA.   ,A9 L.   I8                      ");
    printf(".JMML. `Mbod\"YML..JMML  JMML.`Mbmmd'      `Ybmd9'  M9mmmP'                      ");
    printf("                                                                                 ");
    printf("ALPHA 1.1.0                                               ");
    printf("\r");
        int i = 0;
        int xpos = -1;
        for (int i = 0; i < 80; i++) {
            xpos++;
            putcolor(xpos, 1, i*8);
        }

end: {
    for (;;);
}
}
