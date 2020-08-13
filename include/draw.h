#ifndef LIB_TP_DRAW
#define LIB_TP_DRAW

#include <stdint.h>
#include "addrs.h"

namespace Draw {
    struct DrawProperty {
        uint8_t _p0[0x18];   // 8042EBC8 -> 804bb5d8
        uint16_t hud;        // 8042EBE0 -> 804bb5f0
        uint8_t _p1[0xF0E];  // 8042EBE2 -> 804bb5f2
    };
    static_assert(sizeof(DrawProperty) == 0xF28);

};  // namespace Draw

#define tp_draw (*(Draw::DrawProperty *)tp_draw_addr)

#endif  // LIB_TP_DRAW