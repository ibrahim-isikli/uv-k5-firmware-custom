#include "ui/language.h"
#include "settings.h"   // gEeprom

lang_t gActiveLang = LANG_EN;

void UI_Language_Apply(uint8_t lang)
{
    gActiveLang = (lang == LANG_TR) ? LANG_TR : LANG_EN;
}

void UI_Language_InitFromEEPROM(void)
{
    UI_Language_Apply(gEeprom.LANG_LEVEL);   // varsa mevcut alanı kullan
}
