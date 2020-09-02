#ifndef LIB_TP_TP
#define LIB_TP_TP

#include <stdint.h>
#include <cstddef>
#include "flag.h"
#include "addrs.h"
#include "dungeon.h"
#include "epona.h"
#include "inventory.h"
#include "link.h"
#include "minimap.h"
#include "ooccoo.h"
#include "player.h"
#include "utils.h"
#include "warping.h"
template <size_t S> class Sizer { };

namespace TP {
    struct Momentum {
        uint8_t _p0[0x4F8];
        Vec3 link_momentum;
    };
    static_assert(sizeof(Momentum) == 0x504);

    struct LinkCollision {             // offsets
        uint8_t _p0[0x570];            // 0x0000
        uint16_t invincibility_timer;  // 0x0570
        uint8_t _p1[0x1432];           // 0x056D
        uint8_t door_collision;        // 0x199F // lock to 0x40 for door storage collisions, lock to 0xF0 for sidehop hovering
        uint8_t chest_collision;       // 0x19A0 // Set to 0xE4 or 0xF4 for chest storage collisions, set to 0x40 to disable collision
    };
    static_assert(sizeof(LinkCollision) == 0x19A6);

    struct LinkDebug {                     // offsets
        Vec3 position;                     // 0x0000
        uint8_t _p0[0xA];                  // 0x000C
        uint16_t facing;                   // 0x0016
        uint8_t _p1[0x44];                 // 0x0018
        float speed;                       // 0x005C
        uint8_t _p2[0x44];                 // 0x0060
        uint8_t current_boots;             // 0x00A0 -> 0x00A4
        uint8_t _p11;                      // 0x00A1 -> 0x00A5
        uint8_t status;                    // 0x00A2 -> 0x00A6
        uint8_t _p3[0x14EF];               // 0x00A3 -> 0x00A7
        bool over_void;                    // 0x1592 -> 0x1596
        uint8_t _p4[0x574];                // 0x1593 -> 0x1597
        uint8_t unk_attack_1;              // 0x1B07 -> 0x1B0B
        uint8_t _p15[0x03];                // 0x1B08 -> 0x1B0C
        uint8_t unk_attack_2;              // 0x1B0B -> 0x1B0F
        float link_animation_speed;        //           0x1B10
        uint8_t _p14[0xA4];                // 0x1B0C -> 0x1B14
        bool show_aim_pointer;             //           0x1BB8
        bool appears_clawshottable;        //           0x1BB9 // only the visual effect when using clawshot
        uint8_t _p14_2;                    //           0x1BBA
        bool appears_targetable;           //           0x1BBB // only the visual effect when using Gale
        uint8_t _p13[0x7A8];               // 0x1BE1 -> 0x1BBC
        uint32_t held_item_animation;      // 0x235F -> 0x2364 // 0xF9 for big rock
        uint32_t held_item_collision_ptr;  // 0x2360 -> 0x2368 // may be more than collision
        uint8_t _p12[0x374];               // 0x2362 -> 0x236C
        float sand_height_lost;            // 0x26D8 -> 0x26E0
        uint8_t _p5[0x412];                // 0x26DC -> 0x26E4
        uint8_t air_timer;                 // 0x2AEE -> 0x2AF6
        uint8_t _p6[0x1D];                 // 0x2AEF -> 0x2AF7
        uint16_t current_item;             // 0x2B0D -> 0x2B14
        uint8_t _p10[0x0A];                // 0x2B0E -> 0x2B16
        uint16_t current_action_id;        // 0x2B18 -> 0x2B20
        uint8_t _p7[0x28];                 // 0x2B1A -> 0x2B22
        uint16_t action_value_2;           // 0x2B42 -> 0x2B4A
        uint8_t _p8[0xB6];                 // 0x2B44 -> 0x2B4C
        uint16_t idle_timer;               //           0x2C02
        uint8_t _p8_1[0xCC];               //           0x2C04
        uint32_t action_value_1;           // 0x2CC8 -> 0x2CD0
        uint8_t _p8_2[0x4];                //           0x2CD4
        uint32_t equipped_item_usable;     //           0x2CD8 // bit 2 sets if buttons are globaly enabled
        uint8_t _p9[0x25C];                // 0x2CCC -> 0x2CDC
        float last_ground_y_pos_fall;      // 0x2EF4 -> 0x2F38
        float last_ground_y_pos_void;      // 0x2EF8 -> 0x2F3C
    };
    static_assert(sizeof(LinkDebug) == 0x2F40);

    struct GlobalCounters {
        uint32_t game_counter;      // 80430CD8 -> 804BECB8
        uint32_t game_counter2;     // 80430CDC -> 804BECBC
        uint32_t non_menu_counter;  // 80430CE0 -> 804BECC0
    };
    static_assert(sizeof(GlobalCounters) == 0xC);

    struct EponaDebug {
        uint8_t _p0[0x4CF];  // 0x0000
        Vec3 position;       // 0x04D0
    };
    static_assert(sizeof(EponaDebug) == 0x04DC);

    struct LinkTunic {
        uint8_t _p0[0x32A0];          // 0x0000
        uint16_t tunic_top_red;       // 0x32A0
        uint16_t tunic_top_green;     // 0x32A2
        uint16_t tunic_top_blue;      // 0x32A4
        uint16_t tunic_top_unk;       // 0x32A6 // might be a timer?
        uint16_t tunic_bottom_red;    // 0x32A8
        uint16_t tunic_bottom_green;  // 0x32AA
        uint16_t tunic_bottom_blue;   // 0x32AC
        uint16_t tunic_bottom_unk;    // 0x32AE // might be a timer?
    };

    struct GameInfo {
        Link::Link link;                             // 804061C0 -> 80492928 // mem card 1:1 copy starts here
        uint8_t _p0[0x10];                           // 804061E0 -> 80492948
        uint8_t midna_on_back_flag;                  // 804061F0 -> 80492958 // bit 3 puts midna on back, bit 1 gets set when first time wolf
        uint8_t _p1[0x03];                           // 804061F1 -> 80492959
        float raw_game_time;                         // 804061F4 -> 8049295C // used to determine hours/minutes in ZelAudio. range is 0.0 - 360.0, 90.0 - 285.0 is day, 285.0 - 90.0 is night.
        uint8_t _unk0[0x08];                         // 804061F8 -> 80492960
        Epona::Epona epona;                          // 80406200 -> 80492968
        Player::Player player;                       // 80406218 -> 80492980
        uint8_t _p4[0x03];                           // 8040623A -> 804929A2
        Minimap::Region region;                      // 8040623D -> 804929A5
        uint8_t _p5[0x02];                           // 8040623E -> 804929A6
        Ooccoo::Ooccoo ooccoo;                       // 80406240 -> 804929A8
        uint8_t _p49[0x04];                          // 80406258 -> 804929C0
        Inventory::Inventory inventory;              // 8040625C -> 804929C4
        uint8_t _p9[0x22];                           // 80406352 -> 80492ABA
        Player::Filename player_filename;            // 80406374 -> 80492ADC
        uint8_t _p10;                                // 80406384 -> 80492AEC
        Epona::Filename epona_filename;              // 80406385 -> 80492AED
        uint8_t _p11[0x0D];                          // 80406395 -> 80492AFD
        bool lockon_type;                            //             80492B0A // 0 : hold, 1 : switch
        uint8_t _p12[0x03];                          //             80492B0B
        uint16_t hori_pointer_calib;                 //             80492B0E // Default is 0x015E
        uint8_t vert_pointer_calib;                  //             80492B10 // Default is 0x00
        bool icon_shortcut;                          //             80492B11
        bool camera_control;                         //             80492B12 // 0 : normal, 1 : inverted
        bool pointer;                                //             80492B13
        uint8_t _p14[0x11];                          //             80492B14
        Minimap::Warps warps;                        // 804063BD -> 80492B25
        uint8_t _p23[0x174];                         // 804064FF -> 80492C67
        Dungeon::CityInTheSky::Flags flags;          // 80406673 -> 80492DDB
        uint8_t _p54[0x338];                         // 8040667D -> 80492DE5
        uint8_t epona_stolen_and_midna_charge_flag;  // 804069B5 -> 8049311D // bit 7 sets stolen, bit 0 gives midna charge
        uint8_t epona_tamed_and_map_warp_flag;       // 804069B6 -> 8049311E // bit 0 sets tamed, bit 2 sets map warp
        uint8_t _p24[0x03];                          // 804069B7 -> 8049311F
        uint8_t meteor_warp_enabled;                 // 804069BA -> 80493122 // bit 4 enables meteor warp
        uint8_t _p53;                                // 804069BB -> 80493123
        uint8_t midna_on_up_and_hide_weapon_as_wolf; // 804069BC -> 80493124 // bit 3 display link's weapons in his wolf form, and bit 4 sets midna
        uint8_t transform_flag;                      // 804069BD -> 80493125 // bit 2 sets transform
        uint8_t _p56[0x06];                          // 804069BE -> 80493126
        uint8_t goron_flag;                          // 804069C4 -> 8049312C ------
        uint8_t epona_visible_flag;                  // 804069C5 -> 8049312D // bit 7, makes her visible in ordon spring
        uint8_t _p25[0x08];                          // 804069C6 -> 8049312E
        uint8_t midna_state_flag;                    // 804069CE -> 80493136 // bit 3 makes midna healthy
        uint8_t _p26[0x06];                          // 804069CF -> 80493137
        uint8_t dominion_rod_state;                  // 804069D5 -> 8049313D // bit 7 controls dominion rod being restored
        uint8_t _p27[0x03];                          // 804069D6 -> 8049313E
        uint16_t hidden_skills_flags;                // 804069D9 -> 80493141 // bits 5 to 11 give the hidden skills
        uint8_t _p28[0x18];                          // 804069DB -> 80493143
        uint8_t have_sense_flag;                     // 804069F3 -> 8049315B // bit 3 gives sense
        uint8_t _p29[0x120];                         // 804069F4 -> 8049315C -------
        Flags::TempFlags temp_flags;                 // 80406B14 -> 8049327C
        uint8_t area_id;                             // 80406B38 -> 804932A0
        uint8_t _p65[0x03];                          // 80406B39 -> 804932A1
        Dungeon::CaveOfOrdeals::Floors floors;       // 80406B3C -> 804932A4
        uint8_t _p34[0x37];                          // 80406B40 -> 804932A8
        uint8_t boss_room_event_flags;               // 80406B77 -> 804932DF
        uint8_t _p63[0xDC];                          // 80406B78 -> 804932E0
        uint8_t _p51;                                // 80406C54 -> 804933BC // end of mem card 1:1 copy
        uint8_t _p52[0x31F];                         // 80406C55 -> 804933BD // start of game RAM
        uint8_t respawn_room_id;                     // 80406F74 -> 804936DC
        uint8_t _p35[0x04];                          // 80406F75 -> 804936DD
        uint8_t special_spawn_id;                    // 80406F79 -> 804936E1 // used by things like spawning in boat in lake hylia
        uint16_t respawn_angle;                      // 80406F7A -> 804936E2
        Vec3 respawn_position;                       // 80406F7C -> 804936E4
        uint8_t event_to_play;                       // 80406F88 -> 804936F0 // setting this to 0xFF skips most cutscenes
        uint8_t _p66[0x03];                          // 80406F89 -> 804936F1
        float spawn_speed;                           // 80406F8C -> 804936F4
        uint8_t respawn_item_id;                     // 80406F90 -> 804936F8 // the item in link's hand
        bool voided_as_wolf;                         // 80406F91 -> 804936F9
        uint8_t _p37;                                // 80406F92 -> 804936FA
        uint8_t respawn_animation;                   // 80406F93 -> 804936FB
        uint8_t _p38[0x402C];                        // 80406F94 -> 804936FC
        uint8_t current_stage[8];                    // 8040AFC0 -> 80497728
        uint8_t _p39;                                // 8040AFC8 -> 80497730
        uint8_t current_spawn_id;                    // 8040AFC9 -> 80497731
        uint8_t _p40[0x04];                          // 8040AFCA -> 80497732
        Warp warp;                                   // 8040AFCE -> 80497736
        uint8_t loading_animation;                   // 8040AFDD -> 80497745
        uint8_t _p42[0xBE];                          // 8040AFDE -> 80497746
        uint16_t cs_val;                             // 8040B09C -> 80497804
        uint8_t _p57[0xCF];                          // 8040B09E -> 80497806
        uint8_t freeze_game;                         // 8040B16D -> 804978D5 // this is cs event flag, rename later maybe
        uint8_t _p43[0x05];                          // 8040B16E -> 804978D6
        uint8_t current_event_id;                    // 8040B173 -> 804978DB
        uint8_t _p44[0x1C];                          // 8040B174 -> 804978DC
        uint32_t cs_skip_counter;                    // 8040B190 -> 804978F8
        uint8_t _p45[0x1B4];                         // 8040B194 -> 804978FC
        uint32_t lock_camera;                        // 8040B344 -> 80497AB0
        uint8_t _p46[0x23];                          // 8040B348 -> 80497AB4
        uint8_t last_room_id;                        // 8040B36B -> 80497AD7
        uint8_t _p47[0x50C];                         // 8040B36C -> 80497AD8
        Momentum *momentum_ptr;                      // 8040B878 -> 80497FE4
        uint8_t _p48[0x6FC];                         // 8040B87C -> 80497FE8
        LinkCollision *link_collision_ptr;           // 8040BF6C -> 804986E4
        uint8_t _p59[0x4];                           // 8040BF70 -> 804986E8
        LinkTunic *link_tunic_ptr;                   // 8040BF74 -> 804986EC
        EponaDebug *epona_debug_ptr;                 // 8040BF78 -> 804986F0
        uint8_t _p64[0x26];                          // 8040BF7C -> 804986F4
        uint16_t link_air_meter;                     // 8040BFA2 -> 8049871A
        uint8_t _p58[0x02];                          // 8040BFA4 -> 8049871C
        uint16_t link_air_meter_2;                   // 8040BFA6 -> 8049871E // appears to be the same as 8040BFA2 -> 8049870A
        uint8_t _p61[0x02];                          // 8040BFA8 -> 80498720
        uint16_t link_max_air_meter;                 // 8040BFAA -> 80498722
        uint8_t _p62[0xCC];                          // 8040BFAC -> 80498724
        uint8_t air_time_depleted;                   // 8040C077 -> 804987F0
        uint8_t _p100[0x17F57];                      // 8040C078 -> 804987F1
    } __attribute__((packed));
    // int a = sizeof(GameInfo);
    // 80423fd0 -> 804b0748 next struct start
    //static_assert(sizeof(GameInfo) == 0x1DE20);

    struct ZelAudio {
        uint8_t _p0[0x468];                      // 803DBF4C -> 8044a6ac
        float bg_audio;                          // 803DC3A0 -> 8044AB14
        uint8_t _p1[0x6C];                       // 803DC3A4 -> 8044AB18
        uint8_t time_hours;                      // 803DC410 -> 8044AB84
        uint8_t time_minutes;                    // 803DC411 -> 8044AB85
        uint8_t day_of_week;                     // 803DC412 -> 8044AB86
        uint8_t _p22[0x89];                      // 803DC413 -> 8044AB87
        float menu_sfx_volume;                   // 803DC49C -> 8044AC10
        float menu_sfx_reverb;                   // 803DC4A0 -> 8044AC14
        float menu_sfx_speed;                    // 803DC4A4 -> 8044AC18
        float menu_sfx_lr_stereo;                // 803DC4A8 -> 8044AC1C
        uint8_t _p4[0x5C];                       // 803DC4AC -> 8044AC20
        float link_voice_volume;                 // 803DC508 -> 8044AC7C
        float link_voice_reverb;                 // 803DC50C -> 8044AC80
        float link_voice_speed;                  // 803DC510 -> 8044AC84
        float link_voice_lr_stereo;              // 803DC514 -> 8044AC88
        uint8_t _p5[0x5C];                       // 803DC518 -> 8044AC8C
        float item_sfx_volume;                   // 803DC574 -> 8044ACE8
        float item_sfx_reverb;                   // 803DC578 -> 8044ACEC
        float item_sfx_speed;                    // 803DC57C -> 8044ACF0
        float item_sfx_lr_stereo;                // 803DC580 -> 8044ACF4
        uint8_t _p6[0x5C];                       // 803DC584 -> 8044ACF8
        float link_idle_sfx_volume;              // 803DC5E0 -> 8044AD54
        float link_idle_sfx_reverb;              // 803DC5E4 -> 8044AD58
        float link_idle_sfx_speed;               // 803DC5E8 -> 8044AD5C
        float link_idle_lr_stereo;               // 803DC5EC -> 8044AD60
        uint8_t _p7[0x5C];                       // 803DC5F0 -> 8044AD64
        float item_recoil_sfx_volume;            // 803DC64C -> 8044ADC0
        float item_recoil_sfx_reverb;            // 803DC650 -> 8044ADC4
        float item_recoil_sfx_speed;             // 803DC654 -> 8044ADC8
        float item_recoil_sfx_lr_stereo;         // 803DC658 -> 8044ADCC
        uint8_t _p8[0x5C];                       // 803DC65C -> 8044ADD0
        float npc_volume;                        // 803DC6B8 -> 8044AE2C
        float npc_reverb;                        // 803DC6BC -> 8044AE30
        float npc_speed;                         // 803DC6C0 -> 8044AE34
        float npc_lr_stereo;                     // 803DC6C4 -> 8044AE38
        uint8_t _p9[0x5C];                       // 803DC6C8 -> 8044AE3C
        float midna_sfx_volume;                  // 803DC724 -> 8044AE98
        float midna_sfx_reverb;                  // 803DC728 -> 8044AE9C
        float midna_sfx_speed;                   // 803DC72C -> 8044AEA0
        float midna_sfx_lr_stereo;               // 803DC730 -> 8044AEA4
        uint8_t _p10[0x5C];                      // 803DC734 -> 8044AEA8
        float enemy_sfx_volume;                  // 803DC790 -> 8044AF04
        float enemy_sfx_reverb;                  // 803DC794 -> 8044AF08
        float enemy_sfx_speed;                   // 803DC798 -> 8044AF0C
        float enemy_sfx_lr_stereo;               // 803DC79C -> 8044AF10
        uint8_t _p11[0x5C];                      // 803DC7A0 -> 8044AF14
        float env_sfx_volume;                    // 803DC7FC -> 8044AF70
        float env_sfx_reverb;                    // 803DC800 -> 8044AF74
        float env_sfx_speed;                     // 803DC804 -> 8044AF78
        float env_sfx_stereo;                    // 803DC808 -> 8044AF7C
        uint8_t _p12[0x5C];                      // 803DC80C -> 8044AF80
        float weather_sfx_stereo;                // 803DC868 -> 8044AFDC
        float weather_sfx_reverb;                // 803DC86C -> 8044AFE0
        float weather_sfx_speed;                 // 803DC870 -> 8044AFE4
        float weather_sfx_lr_stereo;             // 803DC874 -> 8044AFE8
        uint8_t _p13[0x5C];                      // 803DC878 -> 8044AFEC
        float unk1_volume;                       // 803DC8D4 -> 8044B048
        float unk1_reverb;                       // 803DC8D8 -> 8044B04C
        float unk1_speed;                        // 803DC8DC -> 8044B050
        float unk1_lr_stereo;                    // 803DC8E0 -> 8044B054
        uint8_t _p14[0x5C];                      // 803DC8E4 -> 8044B058
        float unk2_volume;                       // 803DC940 -> 8044B0B4
        float unk2_reverb;                       // 803DC944 -> 8044B0B8
        float unk2_speed;                        // 803DC948 -> 8044B0BC
        float unk2_lr_stereo;                    // 803DC94C -> 8044B0C0
        uint8_t _p15[0x5C];                      // 803DC950 -> 8044B0C4
        float unk3_volume;                       // 803DC9AC -> 8044B120
        float unk3_reverb;                       // 803DC9B0 -> 8044B124
        float unk3_speed;                        // 803DC9B4 -> 8044B128
        float unk3_lr_stereo;                    // 803DC9B8 -> 8044B12C
        uint8_t _p16[0x5C];                      // 803DC9BC -> 8044B130
        float unk4_volume;                       // 803DCA18 -> 8044B18C
        float unk4_reverb;                       // 803DCA1C -> 8044B190
        float unk4_speed;                        // 803DCA20 -> 8044B194
        float unk4_lr_stereo;                    // 803DCA24 -> 8044B198
        uint8_t _p17[0x5C];                      // 803DCA28 -> 8044B19C
        float unk5_volume;                       // 803DCA84 -> 8044B1F8
        float unk5_reverb;                       // 803DCA88 -> 8044B1FC
        float unk5_speed;                        // 803DCA8C -> 8044B200
        float unk5_lr_stereo;                    // 803DCA90 -> 8044B204
        uint8_t _p18[0x5C];                      // 803DCA94 -> 8044B208
        float unk6_volume;                       // 803DCAF0 -> 8044B264
        float unk6_reverb;                       // 803DCAF4 -> 8044B268
        float unk6_speed;                        // 803DCAF8 -> 8044B26C
        float unk6_lr_stereo;                    // 803DCAFC -> 8044B270
        uint8_t _p19[0x54];                      // 803DCB00 -> 8044B274
        float pause_button_volume;               // 803DCB54 -> 8044B2C8
        float pause_button_reverb;               // 803DCB58 -> 8044B2CC
        float pause_button_speed;                // 803DCB5C -> 8044B2D0
        float pause_button_lr_stereo;            // 803DCB60 -> 8044B2D4
        uint8_t _p20[0x54];                      // 803DCB64 -> 8044B2D8
        float enemy_bg_music_volume;             // 803DCBB8 -> 8044B32C
        float enemy_bg_music_reverb;             // 803DCBBC -> 8044B330
        float enemy_bg_music_speed;              // 803DCBC0 -> 8044B334
        float enemy_bg_music_lr_stereo;          // 803DCBC4 -> 8044B338
        uint8_t _p21[0x54];                      // 803DCBC8 -> 8044B33C
        float hyrule_castle_bg_music_volume;     // 803DCC1C -> 8044B390
        float hyrule_castle_bg_music_reverb;     // 803DCC20 -> 8044B394
        float hyrule_castle_bg_music_speed;      // 803DCC24 -> 8044B398
        float hyrule_castle_bg_music_lr_stereo;  // 803DCC28 -> 8044B39C
        uint8_t _p3[0x22C];                      // 803DCC2C -> 8044B3A0
        LinkDebug *link_debug_ptr;               // 803DCE54 -> 8044B5CC
        uint8_t _p2[0x480];                      // 803DCE58 -> 8044B5D0
    };

    // alignment padding is being a pain
    // static_assert(sizeof(ZelAudio) == 0x13a4);

    struct LoadingInfo {
        uint32_t isLoading;  // 80450CE0 -> 8053a928
        uint8_t _p0[0x04];   // 80450CE4 -> 8053a92c
    };
    static_assert(sizeof(LoadingInfo) == 0x08);

    struct TitleScreenPtr {
        uint8_t _p0[0x59];             // 0x00
        uint8_t trigger_on_next_load;  // 0x59
    };

    struct TitleScreenInfo {
        TitleScreenPtr *title_screen_info;
    };

    struct MatrixPtr {
        uint8_t _p0[0x9C];   // 0x0000
        float camera0;       // 0x009C
        float camera1;       // 0x00A0
        float camera2;       // 0x00A4
        float camera3;       // 0x00A8
        float camera4;       // 0x00AC
        float camera5;       // 0x00B0
        uint8_t _p1[0x134];  // 0x00B4
        float camera6;       // 0x01E8
        uint8_t _p2[0x25C];  // 0x01EC
        float camera7;       // 0x0448
    };

    struct MatrixInfo {
        MatrixPtr *matrix_info;
    };

    struct RNG {
        int32_t RNG0;
        int32_t RNG1;
        int32_t RNG2;
        int32_t RNG02;
        int32_t RNG12;
        int32_t RNG22;
    };

    struct HomeMenuSts {
        uint8_t is_visible; //              8053A968 // No idea if it is actually its true purpose, but it seems to work
    };

#define tp_rng (*(TP::RNG *)(tp_rng_addr))
#define tp_globalCounters (*(TP::GlobalCounters *)(tp_globalCounters_addr))
#define tp_zelAudio (*(TP::ZelAudio *)(tp_zelAudio_addr))
#define tp_gameInfo (*(TP::GameInfo *)(tp_gameInfo_addr))
#define tp_bossFlags (*(uint8_t *)(tp_sConsole_addr + 8))
#define tp_linkRollConstants (*(TP::LinkRollConstants *)(tp_linkRollConstants_addr))
#define tp_fopScnRq (*(TP::LoadingInfo *)(tp_fopScnRq_addr))
#define tp_titleScreenInfo (*(TP::TitleScreenInfo *)(tp_titleScreenPtr_addr))
#define tp_matrixInfo (*(TP::MatrixInfo *)(tp_matrixPtr_addr))
#define tp_homeMenuSts (*(TP::HomeMenuSts *)(tp_homeMenuSts_addr))

    uint32_t get_frame_count() {
        return tp_globalCounters.game_counter;
    }

    uint8_t get_boss_flags() {
        return tp_bossFlags;
    }

    void set_boss_flags() {
        tp_bossFlags = 0xFF;
    }

    void set_boss_flags(uint8_t value) {
        tp_bossFlags = value;
    }

    GameInfo *get_game_info() {
        return &tp_gameInfo;
    }

    LinkDebug *get_link_debug() {
        if (tp_zelAudio.link_debug_ptr) {
            return tp_zelAudio.link_debug_ptr;
        } else {
            return NULL;
        }
    }

    void set_respawn_angle(uint16_t angle) {
        tp_gameInfo.respawn_angle = angle;
    }

    void set_respawn_position(Vec3 position) {
        tp_gameInfo.respawn_position = position;
    }

    void set_respawn_animation(uint8_t animation_id) {
        tp_gameInfo.respawn_animation = animation_id;
    }
}  // namespace TP

#endif  // LIB_TP_TP