#ifndef LIB_TPW_ADDRS
#define LIB_TPW_ADDRS

// System
#define tp_memalign_addr 0x8024df80
#define tp_free_addr 0x803beecc
#define tp_strlen_addr 0x803bdb38
#define tp_osReport_addr 0x800090a8
#define tp_memcpy_addr 0x80004338
#define tp_getLayerNo_addr 0x8002f640
#define tp_getSave_addr 0x8003929c
#define tp_putSave_addr 0x800392cc

// Controller
#define tp_mPadButton_addr 0x804c2f38
#define tp_mPadStatus_addr 0x804c2f08

// TP
#define tp_globalCounters_addr 0x804becb8
#define tp_zelAudio_addr 0x8044a6ac
#define tp_gameInfo_addr 0x80492928
#define tp_sConsole_addr 0x8053a8e0
#define tp_fopScnRq_addr 0x8053a928
#define tp_titleScreenPtr_addr 804813e0
#define tp_matrixPtr_addr 0x803f1e10
#define tp_rng_addr 0x8053ae58

// Items
#define tp_clawshot_addr 0x803e4b5c
#define tp_clawshot_checkbg_addr 0x800fcdbc
#define tp_ironboots_addr 0x803e4990
#define tp_spinner_addr 0x803e4bcc
#define tp_ball_and_chain_addr 0x803e4c0c
#define tp_bottle_addr 0x803e4aa8

// Actor
#define tp_actor_addr 0x8053a9c8
#define tp_actor_stopstatus_addr 0x8053a90c

// Draw
#define tp_draw_addr 0x804bb5d8

// Link
#define tp_link_human_frontroll_addr 0x803e3958
#define tp_link_human_sidestep_addr 0x803e3a00
#define tp_link_human_backjump_addr 0x803e39c8
#define tp_link_human_slide_addr 0x803e3a68
#define tp_link_human_swim_addr 0x803e4ec8
#define tp_link_wolf_general_addr 0x803e4fc4
#define tp_link_wolf_swim_addr 0x803e5a50

// Inventory
#define tp_execItemGet_addr 0x80091d6c

// GX
#define GXSetBlendMode_addr 0x803602cc
#define GXBegin_addr 0x8035d1dc
#define GXSetVtxAttrFmt_addr 0x8035c064
#define GXLoadPosMtxImm_addr 0x803608b0
#define GXSetNumIndStages_addr 0x8035f83c
#define GXSetTevDirect_addr 0x8035f85c
#define GXSetAlphaCompare_addr 0x8035fd38
#define GXSetZMode_addr 0x80360374
#define GXSetTevOp_addr 0x8035f8fc
#define GXSetNumChans_addr 0x8035e4a4
#define GXSetNumTevStages_addr 0x8035ff58
#define GXSetNumTexGens_addr 0x8035c6c0
#define GXSetTevOrder_addr 0x8035fdfc
#define GXSetTevColorIn_addr 0x8035f990
#define GXSetTevAlphaIn_addr 0x8035f9d0
#define GXSetTevColorOp_addr 0x8035fa10
#define GXSetTevAlphaOp_addr 0x8035fa68
#define GXSetCullMode_addr 0x8035d4a4
#define GXLoadTexMtxImm_addr 0x80360978
#define GXSetChanCtrl_addr 0x8035e4c8
#define GXSetCurrentMtx_addr 0x80360958
#define GXSetTexCoordGen2_addr 0x8035c498
#define GXSetLineWidth_addr 0x8035d400
#define GXClearVtxDesc_addr 0x8035c030
#define GXSetVtxDesc_addr 0x8035b9e4
#define GXInitTexObj_addr 0x8035e750
#define GXLoadTexObj_addr 0x8035ec94
#define GXInvalidateTexAll_addr 0x8035ee78
#define GXSetProjection_addr 0x803607c0
#define GXSetScissor_addr 0x80360b08
#define GXGetScissor_addr 0x80360b70
#define wgPipe_addr 0xCC008000

#endif  // LIB_TPW_ADDRS