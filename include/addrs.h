#ifndef LIB_TP_ADDRS
#define LIB_TP_ADDRS

// System
#define tp_memalign_addr 0x80263228
#define tp_free_addr 0x80263260
#define tp_strlen_addr 0x80368bE4
#define tp_osReport_addr 0x80006ABC
#define tp_memcpy_addr 0x80003540
#define tp_getLayerNo_addr 0x8002B434
#define tp_getSave_addr 0x800350bc
#define tp_putSave_addr 0x800350f0

// Controller
#define tp_mPadButton_addr 0x80434420
#define tp_mPadStatus_addr 0x804343F0
#define tp_mPadSticks_addr 0x804343F2
#define tp_mPadTriggers_addr 0x804343F6

// TP
#define tp_globalCounters_addr 0x80430CD8
#define tp_zelAudio_addr 0x803DBF4C
#define tp_gameInfo_addr 0x804061C0
#define tp_sConsole_addr 0x80450C90
#define tp_fopScnRq_addr 0x80450CE0
#define tp_titleScreenPtr_addr 0x803A3A38
#define tp_matrixPtr_addr 0x803F1E10
#define tp_rng_addr 0x80451168

// Items
#define tp_clawshot_addr 0x8038E9C0
#define tp_clawshot_checkbg_addr 0x801087b0
#define tp_ironboots_addr 0x8038E7F4
#define tp_spinner_addr 0x8038EA30
#define tp_ball_and_chain_addr 0x8038EA70
#define tp_bottle_addr 0x8038E90C

// Actor
#define tp_actor_addr 0x80450610
#define tp_actor_stopstatus_addr 0x80450CBC

// Draw
#define tp_draw_addr 0x8042EBC8

// Link
#define tp_link_human_frontroll_addr 0x8038D7BC
#define tp_link_human_sidestep_addr 0x8038D864
#define tp_link_human_backjump_addr 0x8038D82C
#define tp_link_human_slide_addr 0x8038D8CC
#define tp_link_human_swim_addr 0x8038ED2C
#define tp_link_wolf_general_addr 0x8038EE28
#define tp_link_wolf_swim_addr 0x8038f8b4

// Inventory
#define tp_execItemGet_addr 0x80097E8C

// GX
#define GXSetBlendMode_addr 0x8035FBF0
#define GXBegin_addr 0x8035C764
#define GXSetVtxAttrFmt_addr 0x8035B5C4
#define GXLoadPosMtxImm_addr 0x8036024C
#define GXSetNumIndStages_addr 0x8035F0D4
#define GXSetTevDirect_addr 0x8035F0F8
#define GXSetAlphaCompare_addr 0x8035F624
#define GXSetZMode_addr 0x8035FC9C
#define GXSetTevOp_addr 0x8035F198
#define GXSetNumChans_addr 0x8035DB30
#define GXSetNumTevStages_addr 0x8035F890
#define GXSetNumTexGens_addr 0x8035BDFC
#define GXSetTevOrder_addr 0x8035F6F4
#define GXSetTevColorIn_addr 0x8035F224
#define GXSetTevAlphaIn_addr 0x8035F268
#define GXSetTevColorOp_addr 0x8035F2AC
#define GXSetTevAlphaOp_addr 0x8035F314
#define GXSetCullMode_addr 0x8035C984
#define GXLoadTexMtxImm_addr 0x80360320
#define GXSetChanCtrl_addr 0x8035DB6C
#define GXSetCurrentMtx_addr 0x803602EC
#define GXSetTexCoordGen2_addr 0x8035BB7C
#define GXSetLineWidth_addr 0x8035C8BC
#define GXClearVtxDesc_addr 0x8035B58C
#define GXSetVtxDesc_addr 0x8035AEB8
#define GXInitTexObj_addr 0x8035DE40
#define GXLoadTexObj_addr 0x8035E414
#define GXInvalidateTexAll_addr 0x8035E664
#define GXSetProjection_addr 0x803600D4
#define GXSetScissor_addr 0x803604D0
#define GXGetScissor_addr 0x80360548
#define wgPipe_addr 0xCC008000

#endif  // LIB_TP_ADDRS
