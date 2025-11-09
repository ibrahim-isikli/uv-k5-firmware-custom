#ifndef UI_LANGUAGE_H
#define UI_LANGUAGE_H

#include <stdint.h>
#include <stdbool.h>



typedef enum 
{
    LANG_EN = 0,   
    LANG_TR = 1    
} lang_t;


extern lang_t gActiveLang;


#define IS_TR()   (gActiveLang == LANG_TR)

/**
 * @brief Initialize the active language from EEPROM.
 *
 * Reads the persisted language setting (e.g., gEeprom.LANG_LEVEL).
 * Falls back to LANG_EN on invalid/unsupported values.
 */
void UI_Language_InitFromEEPROM(void);

/**
 * @brief Apply a new active language at runtime.
 *
 * Updates the global `gActiveLang` variable and rebinds all
 * user-interface strings accordingly.
 */
void UI_Language_Apply(uint8_t lang);

/**
 * @brief Re-binds menu titles to the currently active language.
 *
 * Mutates static menu label storage in-place (e.g., MenuList[i].name) to match gActiveLang.
 * Call on boot, and any time the language is changed at runtime.
 */
void UI_Menu_BindLanguage(void);

/**
 * @brief Get a localized string for a given menu index.
 *
 * @param index Zero-based index into the menu table.
 * @return const char* NUL-terminated, read-only string owned by the UI layer.
 *         Returns an English fallback if the index is out of range or translation is missing.
 */
const char *UI_Language_GetMenuText(uint8_t index);

#endif // UI_LANGUAGE_H
