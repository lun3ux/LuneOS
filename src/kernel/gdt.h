#pragma once
#include <stdint.h>

void create_descriptor(uint32_t base, uint32_t limit, uint16_t flag);
void buildGDT();