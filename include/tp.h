#ifndef LIB_TP_TP
#define LIB_TP_TP

#include <stdint.h>
#include <cstddef>
#include "addrs.h"
#include "inventory.h"
#include "link.h"
#include "utils.h"
#include "warping.h"

namespace TP {
    struct Momentum {
        uint8_t _p0[0x4F8];
        Vec3 link_momentum;
    };

    struct GameInfo {
        Link::Link link;                 // 804061c0
        uint8_t _p0[0x7C];               // 804061e0
        Inventory::Inventory inventory;  // 8040625C
        uint8_t _p1[0x4D15];             // 804062B9
        Warp warp;                       // 8040AFCE
        uint8_t _p2[0x190];              // 8040AFDD
        uint8_t freeze_game;             // 8040B16D
        uint8_t _p3[0x70A];              // 8040B16E
        Momentum *momentum_ptr;          // 8040B878
        uint8_t _p4[0x726];              // 8040B87C
        uint16_t link_air_meter;         // 8040BFA2
    };

    struct GlobalCounters {
        uint32_t game_counter;
        uint32_t game_counter2;
        uint32_t non_menu_counter;
    };

    struct LinkDebug {
        Vec3 position;
        uint8_t _p0[0xA];
        uint16_t facing;
        uint8_t _p1[0x44];
        float speed;
    };

    struct ZelAudio {
        uint8_t _p0[0x4C4];         // 803DBF4C
        uint8_t time_hours;         // 803DC410
        uint8_t time_minutes;       // 803DC411
        uint8_t _p1[0xA42];         // 803DC412
        LinkDebug *link_debug_ptr;  // 803DCE54
    };

    struct LinkRollConstants {
        uint8_t _p0[0x48];
        float roll_factor;
    };

#define tp_globalCounters (*(TP::GlobalCounters *)(tp_globalCounters_addr))
#define tp_zelAudio (*(TP::ZelAudio *)(tp_zelAudio_addr))
#define tp_gameInfo (*(TP::GameInfo *)(tp_gameInfo_addr))
#define tp_bossFlags (*(uint8_t *)(tp_sConsole_addr + 8))
#define tp_linkRollConstants (*(TP::LinkRollConstants *)(tp_linkRollConstants_addr))

    uint32_t get_frame_count() {
        return tp_globalCounters.game_counter;
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
}  // namespace TP

#endif  //LIB_TP_TP