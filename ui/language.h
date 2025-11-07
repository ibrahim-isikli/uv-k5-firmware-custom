#ifndef UI_LANGUAGE_H
#define UI_LANGUAGE_H

#include <stdint.h>
#include <stdbool.h>

// ============================================================
// Dil tipleri
// ============================================================

typedef enum {
    LANG_EN = 0,   // İngilizce
    LANG_TR = 1    // Türkçe
} lang_t;

// ============================================================
// Global aktif dil
// ============================================================

extern lang_t gActiveLang;

// ============================================================
// Yardımcı makrolar
// ============================================================

// Şu anki dilin Türkçe olup olmadığını kontrol eder
#define IS_TR()   (gActiveLang == LANG_TR)

// ============================================================
// Fonksiyon prototipleri
// ============================================================

// EEPROM'dan dili okur ve uygular
void UI_Language_InitFromEEPROM(void);

// Yeni dil uygular (0 = EN, 1 = TR)
void UI_Language_Apply(uint8_t lang);

// Menü yazılarını aktif dile göre bağlar
void UI_Menu_BindLanguage(void);

#endif // UI_LANGUAGE_H
