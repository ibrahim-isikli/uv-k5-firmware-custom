#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdint.h>

typedef struct 
{
    const char *step;
    const char *txp;
    const char *r_dcs;
    const char *lang;
    const char *r_ctcs;
    const char *t_dcs;
    const char *t_ctcs;
    const char *sft_d;
    const char *offset;
    const char *w_n;
    const char *scr;
    const char *bcl;
    const char *compand;
    const char *am;
    const char *s_add1;
    const char *s_add2;
    const char *mem_ch;
    const char *del_ch;
    const char *mem_name;
    const char *s_list;
    const char *s_list1;
    const char *s_list2;
    const char *sc_rev;
    #ifdef ENABLE_NOAA
    const char *noaa_s;
    #endif
    const char *f1shrt;
    const char *f1long;
    const char *f2shrt;
    const char *f2long;
    const char *mlong;
    const char *autolk;
    const char *tot;
    const char *save;
    const char *mic;
    #ifdef ENABLE_AUDIO_BAR
	const char *mic_bar;
    #endif
    const char *mdf;
    const char *ponmsg;
    const char *bat_txt;
    const char *abr;
    const char *abr_min;
    const char *abr_max;
    const char *abr_on_tx_rx;
    const char *beep;
    #ifdef ENABLE_VOICE
    const char *voice;
    #endif
    const char *roger;
    const char *ste;
    const char *rp_ste;
    const char *call1;
    #ifdef ENABLE_ALARM
    const char *al_mod;
    #endif
    #ifdef ENABLE_DTMF_CALLING
    const char *ani_id;
    #endif
    const char *upcode;
    const char *dwcode;
    const char *ptt_id;
    const char *d_st;
    #ifdef ENABLE_DTMF_CALLING
    const char *d_rsp;
    const char *d_hold;
    #endif
    const char *d_pre;
    #ifdef ENABLE_DTMF_CALLING
    const char *d_dcd;
    const char *d_list;
    #endif
    const char *d_live_dec;
    #ifdef ENABLE_AM_FIX
    const char *am_fix;
    #endif
    #ifdef ENABLE_VOX
    const char *vox;
    #endif
    const char *vol;
    const char *tdr;
    const char *sql;
    const char *f_lock;
    const char *m_200_tx;
    const char *m_350_tx;
    const char *m_500_tx;
    const char *screen;
    #ifdef ENABLE_F_CAL_MENU
    const char *f_calib;
    #endif
    const char *batcal;
    const char *battyp;
    const char *reset;
} LanguagePack_t;

extern const LanguagePack_t LANG_EN;
extern const LanguagePack_t LANG_TR;

extern const LanguagePack_t *ActiveLang;

void UI_SetLanguage(uint8_t lang);

#endif
