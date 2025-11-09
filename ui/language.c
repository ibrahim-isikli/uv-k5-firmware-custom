#include "ui/language.h"
#include "settings.h"
#include <string.h>

lang_t gActiveLang = LANG_EN;   // Varsayılan dil

static const char * const menu_texts_en[] = {
    "Step",
    "TxPower",
    "Rx CTCSS",
    "Rx DCS",
    "Tx CTCSS",
    "Tx DCS",
    "Beep",
    "Voice",
    "Language",
    "Reset",
    "Roger",
    "Lock",
    "Light",
    "Scan",
    "VOX",
    "Save",
    "Back",
    "Exit",
    ""
};

static const char * const menu_texts_tr[] = {
    "ADIM",
    "GUC",
    "CTCSS R",
    "DCS R",
    "CTCSS T",
    "DCS T",
    "BIP",
    "SES",
    "DIL",
    "SIFIRLA",
    "ROGER",
    "KILIT",
    "ISIK",
    "TARA",
    "VOX",
    "KAYDET",
    "GERI",
    "CIKIS",
    ""
};

// EEPROM'dan aktif dili okur ve uygular
/*void UI_Language_InitFromEEPROM(void)
{
    if (gEeprom.LANG_LEVEL == 1)
        gActiveLang = LANG_TR;
    else
        gActiveLang = LANG_EN;
}*/
/*void UI_Language_InitFromEEPROM(void)
{
    gEeprom.LANG_LEVEL = 1;    // Zorla Türkçe
    gActiveLang = LANG_TR;
}*/
void UI_Language_InitFromEEPROM(void)
{
#ifdef ENABLE_LANG_TR
    if (gEeprom.LANG_LEVEL == 1)
        gActiveLang = LANG_TR;
    else
        gActiveLang = LANG_EN;
#else
    gActiveLang = LANG_EN;
#endif
}

// Yeni dil uygular ve EEPROM’a yazar
void UI_Language_Apply(uint8_t lang)
{
    if (lang > 1) lang = 0;

    gEeprom.LANG_LEVEL = lang;
    gActiveLang = (lang == 1) ? LANG_TR : LANG_EN;

    // EEPROM güncelle
    SETTINGS_SaveSettings();
}

const char *UI_Language_GetMenuText(uint8_t index)
{
    if (gActiveLang == LANG_TR)
        return menu_texts_tr[index];
    else
        return menu_texts_en[index];
}