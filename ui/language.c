#include "language.h"

const LanguagePack_t LANG_EN = 
{
    .step     = "Step",
    .language = "Lang",
    .txpwr    = "TxPwr",
    .rxmode   = "RxDCS",
};

const LanguagePack_t LANG_TR = 
{
    .step     = "Adim",
    .language = "Dil",
    .txpwr    = "Guc",
    .rxmode   = "Alici",
};

const LanguagePack_t *ActiveLang = &LANG_EN;

void UI_SetLanguage(uint8_t lang)
{
    ActiveLang = (lang == 1) ? &LANG_TR : &LANG_EN;
   // UI_UpdateMenuText();
}

