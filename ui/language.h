#pragma once
#include <stdint.h>

typedef enum { LANG_EN = 0, LANG_TR = 1, LANG_COUNT } lang_t;

extern lang_t gActiveLang;

#define IS_TR()   (gActiveLang == LANG_TR)

void UI_Language_Apply(uint8_t lang);      // 0->EN, 1->TR
void UI_Language_InitFromEEPROM(void);     // gEeprom.LANG_LEVEL'den yükle
