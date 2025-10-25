#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdint.h>

typedef struct 
{
    const char *step;
    const char *txp;
    const char *r_dcs;
    const char *lang;
} LanguagePack_t;

extern const LanguagePack_t LANG_EN;
extern const LanguagePack_t LANG_TR;

extern const LanguagePack_t *ActiveLang;

void UI_SetLanguage(uint8_t lang);

#endif
