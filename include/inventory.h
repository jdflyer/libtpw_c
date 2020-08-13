#ifndef LIB_TP_INVENTORY
#define LIB_TP_INVENTORY

#include <stdint.h>
#include "flag.h"

#define GALE_BOOMERANG_ID_INDEX 0
#define LANTERN_ID_INDEX 1
#define SPINNER_ID_INDEX 2
#define IRON_BOOTS_ID_INDEX 3
#define HEROS_BOW_ID_INDEX 4
#define HAWKEYE_ID_INDEX 5
#define BALL_AND_CHAIN_ID_INDEX 6
#define DOMINION_ROD_ID_INDEX 8
#define CLAWSHOT_ID_INDEX 9
#define DOUBLE_CLAWSHOT_ID_INDEX 10
#define BOTTLE_1_ID_INDEX 11
#define BOTTLE_2_ID_INDEX 12
#define BOTTLE_3_ID_INDEX 13
#define BOTTLE_4_ID_INDEX 14
#define BOMB_BAG_1_ID_INDEX 15
#define BOMB_BAG_2_ID_INDEX 16
#define BOMB_BAG_3_ID_INDEX 17
#define OOCCOO_ID_INDEX 18
#define LETTER_ID_INDEX 19
#define FISHING_ROD_ID_INDEX 20
#define ILIA_QUEST_ID_INDEX 21
#define SKY_BOOK_ID_INDEX 22
#define SLINGSHOT_ID_INDEX 23

namespace Inventory {
    struct ItemValues {
        union {
            uint8_t value[24];  // 8040625C -> 804929C4
            struct {
                uint8_t gale_boomerang_id;              // 8040625C -> 804929C4
                uint8_t lantern_id;                     // 8040625D -> 804929C5
                uint8_t spinner_id;                     // 8040625E -> 804929C6
                uint8_t iron_boots_id;                  // 8040625F -> 804929C7
                uint8_t hero_s_bow_id;                  // 80406260 -> 804929C8
                uint8_t hawkeye_id;                     // 80406261 -> 804929C9
                uint8_t ball_and_chain_id;              // 80406262 -> 804929CA
                uint8_t _unk_0;                         // 80406263 -> 804929CB
                uint8_t dominion_rod_id;                // 80406264 -> 804929CC
                uint8_t clawshot_id;                    // 80406265 -> 804929CD
                uint8_t double_clawshot_id;             // 80406266 -> 804929CE
                uint8_t bottle_1_id;                    // 80406267 -> 804929CF
                uint8_t bottle_2_id;                    // 80406268 -> 804929D0
                uint8_t bottle_3_id;                    // 80406269 -> 804929D1
                uint8_t bottle_4_id;                    // 8040626A -> 804929D2
                uint8_t bomb_bag_1_id;                  // 8040626B -> 804929D3
                uint8_t bomb_bag_2_id;                  // 8040626C -> 804929D4
                uint8_t bomb_bag_3_id;                  // 8040626D -> 804929D5
                uint8_t ooccoo_id;                      // 8040626E -> 804929D6
                uint8_t auru_s_memo_ashei_s_sketch_id;  // 8040626F -> 804929D7
                uint8_t fishing_rod_earring_id;         // 80406270 -> 804929D8
                uint8_t horse_call_id;                  // 80406271 -> 804929D9
                uint8_t ancient_sky_book_id;            // 80406272 -> 804929DA
                uint8_t slingshot_id;                   // 80406273 -> 804929DB
            };
        };
    };
    static_assert(sizeof(ItemValues) == 0x18);

    struct ItemWheel {
        uint8_t slot[24];  // 80406274 -> 804929DC
    };
    static_assert(sizeof(ItemWheel) == 0x18);

    struct Inventory {
        ItemValues item_values;                           // 8040625C -> 804929C4
        ItemWheel item_wheel;                             // 80406274 -> 804929DC
        uint8_t _p0[0x03];                                // 8040628C -> 804929F4
        uint8_t rupee_cs_flags;                           // 8040628F -> 804929F7
        uint8_t _p1;                                      // 80406290 -> 804929F8
        uint8_t equipment_flags_0;                        // 80406291 -> 804929F9 // bit 0 magic armor, bit 1 zora armor
        uint8_t equipment_flags_1;                        // 80406292 -> 804929FA // bit 0 ordon sword, bit 1 master sword, bit 2 ordon shield, bit 3 wooden shield, bit 4 hylian shield, bit 7 hero's clothes
        uint8_t _p2[0x03];                                // 80406293 -> 804929FB
        uint8_t light_sword_flag;                         // 80406296 -> 804929FE // bit 2 sets light sword
        uint8_t _p3[0x0E];                                // 80406297 -> 804929FF
        uint8_t snail_dragonfly_ant_dayfly_flags;         // 804062A5 -> 80492A0D
        uint8_t phasmid_pillbug_mantis_ladybug_flags;     // 804062A6 -> 80492A0E
        uint8_t beetle_butterfly_stag_grasshopper_flags;  // 804062A7 -> 80492A0F
        uint8_t _p4[0x04];                                // 804062A8 -> 80492A10
        uint8_t arrow_count;                              // 804062AC -> 80492A14
        uint8_t bomb_bag_1_amnt;                          // 804062AD -> 80492A15
        uint8_t bomb_bag_2_amnt;                          // 804062AE -> 80492A16
        uint8_t bomb_bag_3_amnt;                          // 804062AF -> 80492A17
        uint8_t _p5[0x04];                                // 804062B0 -> 80492A18
        uint8_t slingshot_count;                          // 804062B4 -> 80492A1C
        uint8_t _p6[0x03];                                // 804062B5 -> 80492A1D
        uint8_t arrow_capacity;                           // 804062B8 -> 80492A20
        uint8_t _p7[0x13];                                // 804062B9 -> 80492A21
        uint8_t poe_count;                                // 804062CC -> 80492A34
        uint8_t _p8[0x11];                                // 804062CD -> 80492A35
        uint16_t letters;                                 // 804062DE -> 80492A46
        uint8_t _p9[0x4C];                                // 804062E0 -> 80492A48
        uint16_t fishing_jrnl_hbass_no_caught;            // 8040632C -> 80492A94
        uint16_t fishing_jrnl_hloach_no_caught;           // 8040632E -> 80492A96
        uint16_t fishing_jrnl_hpike_no_caught;            // 80406330 -> 80492A98
        uint16_t fishing_jrnl_ocatfish_no_caught;         // 80406332 -> 80492A9A
        uint16_t fishing_jrnl_reekfish_no_caught;         // 80406334 -> 80492A9C
        uint16_t fishing_jrnl_greengill_no_caught;        // 80406336 -> 80492A9E
        uint8_t _p10[0x14];                               // 80406338 -> 80492AA0
        uint8_t fishing_jrnl_hbass_largest;               // 8040634C -> 80492AA4
        uint8_t fishing_jrnl_hloach_largest;              // 8040634D -> 80492AA5
        uint8_t fishing_jrnl_hpike_largest;               // 8040634E -> 80492AA6
        uint8_t fishing_jrnl_ocatfish_largest;            // 8040634F -> 80492AB7
        uint8_t fishing_jrnl_reekfish_largest;            // 80406350 -> 80492AB8
        uint8_t fishing_jrnl_greengill_largest;           // 80406351 -> 80492AB9
    };
    static_assert(sizeof(Inventory) == 0xF6);

    typedef void (*tp_execItemGet)(uint8_t item);
#define tp_execItemGet ((tp_execItemGet)tp_execItemGet_addr)

    Inventory *get_inventory();
    Flag bomb_capacity_flag();
    Flag ordon_sword_flag();
    Flag master_sword_flag();
    Flag light_sword_flag();
    Flag ordon_shield_flag();
    Flag wooden_shield_flag();
    Flag hylian_shield_flag();
    Flag heros_clothes_flag();
    Flag magic_armor_flag();
    Flag zora_armor_flag();
    Flag silver_rupee_flag();
    Flag orange_rupee_flag();
    Flag purple_rupee_flag();
    Flag red_rupee_flag();
    Flag yellow_rupee_flag();
    Flag blue_rupee_flag();
    void clear_rupee_flags();
    void set_rupee_flags();
    void get_item(uint8_t item);
}  // namespace Inventory

#endif  // LIB_TP_INVENTORY