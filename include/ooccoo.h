#ifndef LIB_TP_OOCCOO
#define LIB_TP_OOCCOO

#include <stdint.h>

namespace Ooccoo {
    struct Ooccoo {
        float ooccoo_x_pos;                         // 80406240 -> 804929A8
        float ooccoo_y_pos;                         // 80406244 -> 804929AC
        float ooccoo_z_pos;                         // 80406248 -> 804929B0
        uint16_t ooccoo_angle;                      // 8040624C -> 804929B4
        uint8_t ooccoo_stage[0x08];                 // 8040624E -> 804929B6
        uint8_t ooccoo_spawn_id;                    // 80406256 -> 804929BE // appears unused
        uint8_t ooccoo_room_id;                     // 80406257 -> 804929BF
    }; // struct Ooccoo

    static_assert(sizeof(Ooccoo) == 0x18);
}; // namespace Ooccoo

#endif //LIB_TP_EPONA