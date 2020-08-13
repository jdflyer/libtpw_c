#ifndef LIB_TP_ITEMS
#define LIB_TP_ITEMS

#include <stdint.h>
#include "addrs.h"

namespace Items {
    namespace Bottle {
        struct BottleProperty {
            uint8_t _p0[0x04];                   // 8038E90C -> 803e4aa8
            float _p1;                           // 8038E910 -> 803e4aac
            float _p2;                           // 8038E914 -> 803e4ab0
            float _p3;                           // 8038E918 -> 803e4ab4
            float _p4;                           // 8038E91C -> 803e4ab8
            uint8_t _p5[0x04];                   // 8038E920 -> 803e4abc
            float _p6;                           // 8038E924 -> 803e4ac0
            float _p7;                           // 8038E928 -> 803e4ac4
            float _p8;                           // 8038E92C -> 803e4ac8
            float _p9;                           // 8038E930 -> 803e4acc
            uint16_t wait_after_cork_pull;       // 8038E934 -> 803e4ad0
            uint8_t _p10[0x02];                  // 8038E936 -> 803e4ad2
            float cork_pull_anim_speed;          // 8038E938 -> 803e4ad4
            float wait_before_cork_pull_anim;    // 8038E93C -> 803e4ad8
            float grabbing_cork_anim_speed;      // 8038E940 -> 803e4adc
            float _p11;                          // 8038E944 -> 803e4ae0
            uint16_t wait_after_bottle_dump;     // 8038E948 -> 803e4ae4
            uint8_t _p12[0x02];                  // 8038E94A -> 803e4ae6
            float bottle_dump_anim_speed;        // 8038E94C -> 803e4ae8
            float wait_before_dump_anim_1;       // 8038E950 -> 803e4aec
            float wait_before_dump_anim_2;       // 8038E954 -> 803e4af0
            float _p13;                          // 8038E958 -> 803e4af4
            uint16_t wait_after_bottle_scoop_1;  // 8038E95C -> 803e4af8
            uint8_t _p14[0x02];                  // 8038E95E -> 803e4afa
            float bottle_scoop_anim_speed_1;     // 8038E960 -> 803e4afc
            float link_lean_down_anim_speed;     // 8038E964 -> 803e4b00
            float bottle_scoop_anim_speed_2;     // 8038E968 -> 803e4b04
            float wait_after_bottle_scoop_2;     // 8038E96C -> 803e4b08
            uint16_t wait_after_bottle_swing_1;  // 8038E970 -> 803e4b0c
            uint8_t _p15[0x02];                  // 8038E972 -> 803e4b0e
            float bottle_swing_anim_speed_1;     // 8038E974 -> 803e4b10
            float link_swing_anim_speed;         // 8038E978 -> 803e4b14
            float bottle_swing_anim_speed_2;     // 8038E97C -> 803e4b18
            float wait_after_bottle_swing_2;     // 8038E980 -> 803e4b1c
            uint16_t wait_before_show_text;      // 8038E984 -> 803e4b20
            uint8_t _p16[0x02];                  // 8038E986 -> 803e4b22
            float corking_anim_speed_1;          // 8038E988 -> 803e4b24
            float corking_anim_speed_2;          // 8038E98C -> 803e4b28
            float corking_anim_speed_3;          // 8038E990 -> 803e4b2c
            float _p17;                          // 8038E994 -> 803e4b30
            uint8_t _p27[0x04];                  // 8038E998 -> 803e4b34
            float _p18;                          // 8038E99C -> 803e4b38
            float _p19;                          // 8038E9A0 -> 803e4b3c
            float _p20;                          // 8038E9A4 -> 803e4b40
            float _p21;                          // 8038E9A8 -> 803e4b44
            uint8_t _p22[0x04];                  // 8038E9AC -> 803e4b48
            float _p23;                          // 8038E9B0 -> 803e4b4c
            float _p24;                          // 8038E9B4 -> 803e4b50
            float _p25;                          // 8038E9B8 -> 803e4b54
            float _p26;                          // 8038E9BC -> 803e4b58
        };                                       // struct BottleProperty
        static_assert(sizeof(BottleProperty) == 0xB4);
    };  // namespace Bottle
    namespace Bow {
        struct BowProperty {
            uint8_t _p0[0x04];
            float bow_release_anim_speed;
            uint8_t _p1[0x04];
            
        };  // struct BowProperty
        //static_assert(sizeof(BowProperty) == 0x70);
    };  // namespace Bow
    namespace GaleBoomerang {
        struct GaleBoomerangProperty {
            uint8_t _p0[0x04];                          // 8038E6C8 -> 803e4864
            float link_throw_anim_speed_1;              // 8038E6CC -> 803e4868
            float link_throw_anim_speed_2;              // 8038E6D0 -> 803e486c
            float link_throw_anim_speed_3;              // 8038E6D4 -> 803e4870
            float link_walking_throw_anim_speed;        // 8038E6D8 -> 803e4874
            uint8_t _p1[0x04];                          // 8038E6DC -> 803e4878
            float link_catch_anim_speed_1;              // 8038E6E0 -> 803e487c
            float link_catch_and_hold_anim_speed;       // 8038E6E4 -> 803e4880
            float link_catch_anim_speed_2;              // 8038E6E8 -> 803e4884
            float link_walking_catch_anim_speed;        // 8038E6EC -> 803e4888
            uint8_t _p2[0x04];                          // 8038E6F0 -> 803e488c
            float boomerang_idle_sway_anim_speed;       // 8038E6F4 -> 803e4890
            float boomerang_idle_ready_anim_speed;      // 8038E6F8 -> 803e4894
            float _p3;                                  // 8038E6FC -> 803e4898
            float boomerang_speed;                      // 8038E700 -> 803e489c
            float boomerang_throw_distance;             // 8038E704 -> 803e48a0
            float _p4;                                  // 8038E708 -> 803e48a4
            float _p5;                                  // 8038E70C -> 803e48a8
            float boomerang_item_grabbed_return_speed;  // 8038E710 -> 803e48ac
        };                                              // struct GaleBoomerangProperty
        static_assert(sizeof(GaleBoomerangProperty) == 0x4C);
    };  // namespace GaleBoomerang
    namespace Spinner {
        struct SpinnerProperty {
            uint8_t _p0[0x18];            // 8038EA30 -> 803e4bcc
            uint16_t turning;             // 8038EA48 -> 803e4be4
            uint8_t _p1[0x06];            // 8038EA4A -> 803e4be6
            float vertical_speed_1;       // 8038EA50 -> 803e4bec // checked when y pos decreases at all
            float vertical_speed_2;       // 8038EA50 -> 803e4bf0 // not sure what conditions are needed for this
            uint8_t _p2[0x04];            // 8038EA58 -> 803e4bf4
            float horizontal_speed;       // 8038EA5C -> 803e4bf8
            uint8_t _p3[0x04];            // 8038EA60 -> 803e4bfc
            float deceleration_factor_1;  // 8038EA64 -> 803e4c00
            float deceleration_factor_2;  // 8038EA68 -> 803e4c04
            uint8_t _p4[0x04];            // 8038EA6C -> 803e4c08
        };                                // struct Spinner
        static_assert(sizeof(SpinnerProperty) == 0x40);
    };  // namespace Spinner
    namespace Clawshot {
        struct ClawshotProperty {
            uint8_t _p0[0x04];                       // 8038E9C0 -> 803e4b5c
            uint16_t arm_animation1;                 // 8038E9C4 -> 803e4b60 affects first person anim while firing
            uint8_t _p1[0x02];                       // 8038E9C6 -> 803e4b62
            uint16_t arm_animation2;                 // 8038E9C8 -> 803e4b64 affects first person anim while firing
            uint8_t _p20[0x22];                      // 8038E9CA -> 803e4b66
            uint16_t wall_hang_anim_speed;           // 8038E9EC -> 803e4b88
            uint8_t _p3[0x02];                       // 8038E9EE -> 803e4b8a
            uint16_t wall_hang_anim;                 // 8038E9F0 -> 803e4b8c has something to do with wall anim but not speed specifically
            uint8_t _p4[0x06];                       // 8038EAF2 -> 803e4b8e
            uint16_t second_clawshot_wait_frames;    // 8038EAF8 -> 803e4b94 how long before you can use clawshot 2 when hanging from wall (ceiling is different)
            uint8_t _p5[0x06];                       // 8038EAFA -> 803e4b96
            uint16_t third_person_ready_anim_angle;  // 8038EA00 -> 803e4b9c data type is wrong probably
            uint16_t third_person_ready_anim_speed;  // 8038EA02 -> 803e4b9e data type is wrong probably
            float first_person_ready_anim_frames;    // 8038EA04 -> 803e4ba0
            float extension_rate;                    // 8038EA08 -> 803e4ba4
            float speed;                             // 8038EA0C -> 803e4ba8
            float retraction_rate;                   // 8038EA10 -> 803e4bac
            float pull_rate;                         // 8038EA14 -> 803e4bb0
            uint8_t _p6[0x1C];                       // 8038EA18 -> 803e4bb4
        };                                           // struct ClawshotProperty
        static_assert(sizeof(ClawshotProperty) == 0x74);

        struct ClawshotBG {
            uint8_t _p0[0x2C];   // 801087B0 -> 800fcdbc
            uint32_t is_target;  // 801087E0 -> 800fcde8
            uint8_t _p1[0x44];   // 801087E4 -> 800fcdec
        };                       // struct ClawshotBG // pretty sure this actually needs to be a function pointer
        static_assert(sizeof(ClawshotBG) == 0x74);
    };  // namespace Clawshot

    namespace IronBoots {
        struct IronBootsProperty {
            uint8_t _p0[0x04];             // 8038E7F4 -> 803e4990
            uint16_t switch_speed;         // 8038E7F8 -> 803e4994
            uint8_t _p1[0x02];             // 8038E7FA -> 803e4996
            uint8_t switch_speed2;         // 8038E7FC -> 803e4998 this single byte seem to affect switching speed as well?
            uint8_t _p2[0x07];             // 8038E7FD -> 803e4999
            uint16_t wait_after_switch;    // 8038E804 -> 803e49a0
            uint8_t _p3[0x02];             // 8038E806 -> 803e49a2
            uint8_t weight1;               // 8038E808 -> 803e49a4 can't figure out this one :(
            uint8_t weight2;               // 8038E809 -> 803e49a5
            uint8_t _p4[0x02];             // 8038E80A -> 803e49a6
            float speed;                   // 8038E80C -> 803e49a8 affects speed but doesn't appear to be float? // this also affects speed while sinking in sand. shared i'm guess
            uint16_t stepping_anim_speed;  // 8038E810 -> 803e49ac
            uint8_t _p5[0x02];             // 8038E812 -> 803e49ae
            uint16_t ess_anim_speed;       // 8038E814 -> 803e49b0
            uint8_t _p6[0x12];             // 8038E816 -> 803e49b2
            uint8_t magnet_strength;       // 8038E828 -> 803e49c4
            uint8_t _p7[0x17];             // 8038E829 -> 803e49b5
        };                                 // struct IronBootsProperty
        static_assert(sizeof(IronBootsProperty) == 0x4C);
    };  // namespace IronBoots

    namespace BallAndChain {
        struct BallAndChainProperty {
            uint8_t _p0[0x04];                  // 8038EA70 -> 803e4c0c
            float return_anim_speed_1;          // 8038EA74 -> 803e4c10 // how fast link returns to idle anim after catching b&c
            float return_anim_speed_2;          // 8038EA78 -> 803e4c14 // affects arm animation specifically?
            float return_anim_speed_3;          // 8038EA7C -> 803e4c18
            float _p1;                          // 8038EA80 -> 803e4c1c // appears to be float but idk what it is
            uint8_t _p2[0x04];                  // 8038EA84 -> 803e4c20
            float _p3;                          // 8038EA88 -> 803e4c24 // appears to be float but idk what it is
            float swinging_ready_anim_speed;    // 8038EA8C -> 803e4c28
            float link_arm_anim_speed;          // 8038EA90 -> 803e4c2c
            float rotation_speed;               // 8038EA94 -> 803e4c30
            float link_body_sway_anim_speed;    // 8038EA98 -> 803e4c34
            float link_throw_anim_speed_1;      // 8038EA9C -> 803e4c38
            float link_throw_anim_speed_2;      // 8038EAA0 -> 803e4c3c
            float unk_throw_speed;              // 8038EAA4 -> 803e4c40 // not quite sure what this controls
            float link_extend_arm_anim_speed;   // 8038EAA8 -> 803e4c44
            float link_raise_arm_anim_speed_1;  // 8038EAAC -> 803e4c48
            float link_raise_arm_anim_speed_2;  // 8038EAB0 -> 803e4c4c
            float chain_anim_speed;             // 8038EAB4 -> 803e4c50
            float chain_position_throw;         // 8038EAB8 -> 803e4c54 // affects chain position while throwing
            float chain_position_return;        // 8038EABC -> 803e4c58 // affects chain position when its returning
            float ball_return_v_speed_1;        // 8038EAC0 -> 803e4c5c
            float link_throw_anim_speed_3;      // 8038EAC4 -> 803e4c60
            float link_throw_anim_speed_4;      // 8038EAC8 -> 803e4c64
            float chain_falling_anim_speed;     // 8038EACC -> 803e4c68
            float ball_v_speed_after_throw_1;   // 8038EAD0 -> 803e4c6c
            float ball_v_speed_during_throw;    // 8038EAD4 -> 803e4c70
            float ball_v_speed_after_throw_2;   // 8038EAD8 -> 803e4c74 // very similar to the first one
            float _p4;                          // 8038EADC -> 803e4c78 // appears to be float but idk what it is
            float ball_h_speed_during_throw;    // 8038EAE0 -> 803e4c7c
            float ball_throw_height;            // 8038EAE4 -> 803e4c80
            float _p5;                          // 8038EAE8 -> 803e4c84 // appears to be float but idk what it is
            float _p6;                          // 8038EAEC -> 803e4c88 // appears to be float but idk what it is
            float link_running_speed;           // 8038EAF0 -> 803e4c8c // takes priority over next two
            float link_walking_speed;           // 8038EAF4 -> 803e4c90
            float link_ess_walking_speed;       // 8038EAF8 -> 803e4c94

        };  // struct BallAndChainProperty
        static_assert(sizeof(BallAndChainProperty) == 0x8C);

    };  // namespace BallAndChain
};      // namespace Items

#define tp_clawshot (*(Items::Clawshot::ClawshotProperty *)tp_clawshot_addr)
#define tp_clawshot_bg (*(Items::Clawshot::ClawshotBG *)tp_clawshot_checkbg_addr)
#define tp_ironboots (*(Items::IronBoots::IronBootsProperty *)tp_ironboots_addr)
#define tp_spinner (*(Items::Spinner::SpinnerProperty *)tp_spinner_addr)
#define tp_bottle (*(Items::Bottle::BottleProperty *)tp_bottle_addr)
#define tp_ball_and_chain (*(Items::BallAndChain::BallAndChainProperty *)tp_ball_and_chain_addr)

#endif  // LIB_TP_ITEMS