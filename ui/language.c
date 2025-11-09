#include "ui/language.h"
#include "settings.h"
#include <string.h>

lang_t gActiveLang = LANG_EN;   // Varsayılan dil

// EEPROM'dan aktif dili okur ve uygular
void UI_Language_InitFromEEPROM(void)
{
    if (gEeprom.LANG_LEVEL == 1)
        gActiveLang = LANG_TR;
    else
        gActiveLang = LANG_EN;
}
/*void UI_Language_InitFromEEPROM(void)
{
    gEeprom.LANG_LEVEL = 1;    // Zorla Türkçe
    gActiveLang = LANG_TR;
}*/


// Yeni dil uygular ve EEPROM’a yazar
void UI_Language_Apply(uint8_t lang)
{
    if (lang > 1) lang = 0;

    gEeprom.LANG_LEVEL = lang;
    gActiveLang = (lang == 1) ? LANG_TR : LANG_EN;

    // EEPROM güncelle
    SETTINGS_SaveSettings();
}

