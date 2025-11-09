#include "ui/language.h"
#include "settings.h"
#include <string.h>

lang_t gActiveLang = LANG_EN;   //  default language

static const char * const menu_texts_en[] = {
	"Step",
	"TxPwr",
	"RxDCS",
	"RxCTCS",
	"TxDCS",
	"TxCTCS",
	"TxODir",
	"TxOffs",
	"W/N",
	"Scramb",
	"BusyCL",
	"Compnd",
	"Demodu",
	"ScAdd1",
	"ScAdd2",
	"ChSave",
	"ChDele",
	"ChName",
	"SList",
	"SList1",
	"SList2",
	"ScnRev",
#ifdef ENABLE_NOAA
	"NOAA-S",
#endif
	"F1Shrt",
	"F1Long",
	"F2Shrt",
	"F2Long",
	"M Long",
	"KeyLck",
	"TxTOut",
	"BatSav",
	"Mic",
#ifdef ENABLE_AUDIO_BAR
	"MicBar",
#endif
	"ChDisp",
	"POnMsg",
	"BatTxt",
	"BackLt",
	"BLMin",
	"BLMax",
	"BltTRX",
	"Beep",
#ifdef ENABLE_VOICE
	"Voice",
#endif
#ifdef ENABLE_LANG_TR
	"Lang",
#endif
	"Roger",
	"STE",
	"RP STE",
	"1 Call",
#ifdef ENABLE_ALARM
	"AlarmT",
#endif
#ifdef ENABLE_DTMF_CALLING
	"ANI ID",
#endif
	"UPCode",
	"DWCode",
	"PTT ID",
	"D ST",
#ifdef ENABLE_DTMF_CALLING
	"D Resp",
	"D Hold",
#endif
	"D Prel",
#ifdef ENABLE_DTMF_CALLING
	"D Decd",
	"D List",
#endif
	"D Live",
#ifdef ENABLE_AM_FIX
	"AM Fix",
#endif
#ifdef ENABLE_VOX
	"VOX",
#endif
	"BatVol",
	"RxMode",
	"Sql",
	"F Lock",
	"Tx 200",
	"Tx 350",
	"Tx 500",
	"350 En",
	"ScraEn",
#ifdef ENABLE_F_CAL_MENU
	"FrCali",
#endif
	"BatCal",
	"BatTyp",
	"Reset",
	"",
};

static const char * const menu_texts_tr[] = {
	"ADIM",
	"TxGUC",
	"RxDCS",
	"RxCTCS",
	"TxDCS",
	"TxCTCS",
	"TxOFYO",
	"TxOFST",
	"D/G", 
	"KARISIM",
	"MesgULK",
	"COMPND",
	"DEMODU",
	"TarEk1",
	"TarEk2",
	"KanalK",
	"KanalS",
	"KanISMI",
	"TarLIST",
	"Liste1",
	"Liste2",
	"TarTERS",
#ifdef ENABLE_NOAA
	"NOAA-T",
#endif
	"F1KISA",
	"F1UZUN",
	"F2KISA",
	"F2UZUN",
	"M UZUN",
	"TusKILIT",
	"TxSURE",
	"PILKORU",
	"MIIKROF", 
#ifdef ENABLE_AUDIO_BAR
	"MIKBAR",
#endif
	"KnlGOST",
	"AcIlIsM",
	"PilYAZI",
	"ARKAIS",
	"ISKISA",
	"ISUZUN",
	"ISTxRx",
	"BIP",
#ifdef ENABLE_VOICE
	"SESLI",
#endif
#ifdef ENABLE_LANG_TR
	"DIL",
#endif
	"ROGER",
	"KuyrukB",
	"TekrKuyB",
	"1 ARAMA",
#ifdef ENABLE_ALARM
	"AlarmT",
#endif
#ifdef ENABLE_DTMF_CALLING
	"ANI ID",
#endif
	"YUKKOD",
	"ASAKOD",
	"PTT ID",
	"D DURUM",
#ifdef ENABLE_DTMF_CALLING
	"D YANIT",
	"D TUTMA",
#endif
	"D ONUST",
#ifdef ENABLE_DTMF_CALLING
	"D COZUC",
	"D LISTE",
#endif
	"D CANLI",
#ifdef ENABLE_AM_FIX
	"AM DUZ",
#endif
#ifdef ENABLE_VOX
	"VOX",
#endif
	"PilVOLT",
	"RxMODU",
	"Sustur",
	"F KILIT",
	"Tx 200",
	"Tx 350",
	"Tx 500",
	"350 Etk",
	"KarmEtk",
#ifdef ENABLE_F_CAL_MENU
	"FrekKal",
#endif
	"PilKal",
	"PilTIP",
	"SIFIRLA",
	"",
};

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

void UI_Language_Apply(uint8_t lang)
{
    if (lang > 1) lang = 0;

    gEeprom.LANG_LEVEL = lang;
    gActiveLang = (lang == 1) ? LANG_TR : LANG_EN;
    
    SETTINGS_SaveSettings();
}

const char *UI_Language_GetMenuText(uint8_t index)
{
    if (gActiveLang == LANG_TR)
        return menu_texts_tr[index];
    else
        return menu_texts_en[index];
}