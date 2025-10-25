#include "language.h"

const LanguagePack_t LANG_EN = 
{
    .step       = "Step",
    .txp        = "TxPwr",
    .r_dcs      = "RxDCS",
    .lang       = "Lang",
};

const LanguagePack_t LANG_TR = 
{
    .step       = "Adim",
    .txp        = "Guc",
    .r_dcs      = "Alici",
    .lang       = "Dil",
};

const LanguagePack_t *ActiveLang = &LANG_EN;

void UI_SetLanguage(uint8_t lang)
{
    ActiveLang = (lang == 1) ? &LANG_TR : &LANG_EN;
   // UI_UpdateMenuText();
}

