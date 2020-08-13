#ifndef LIB_TP_PLAYER
#define LIB_TP_PLAYER

#include <stdint.h>

namespace Player {
    struct Player {
        uint8_t player_stage[0x08];                 // 80406218 -> 80492980
        uint8_t player_spawn_id;                    // 80406220 -> 80492988
        uint8_t player_room_id;                     // 80406221 -> 80492989
        uint8_t _p3[0x10];                          // 80406222 -> 8049298A
        uint8_t player_previous_stage[0x08];        // 80406232 -> 8049299A
    }; // struct Player

    static_assert(sizeof(Player) == 0x22);

    struct Filename {
        uint8_t player_file_name[0x10];             // 80406374 -> 80492ADC
    }; // struct Filename

    static_assert(sizeof(Filename) == 0x10);
}; // namespace Player

#endif // LIB_TP_PLAYER