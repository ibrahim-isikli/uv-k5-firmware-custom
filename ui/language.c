#include "language.h"

const LanguagePack_t LANG_EN = {
    .step     = "Step",
    .txpwr    = "TxPwr",
    .rxmode   = "RxMode",
    .language = "Language",
};

const LanguagePack_t LANG_TR = {
    .step     = "Adim",
    .txpwr    = "Guc",
    .rxmode   = "Alici",
    .language = "Dil",
};

const LanguagePack_t *ActiveLang = &LANG_EN;

void UI_SetLanguage(uint8_t lang)
{
    ActiveLang = (lang == 1) ? &LANG_TR : &LANG_EN;
}
