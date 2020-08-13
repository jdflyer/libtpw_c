#ifndef LIB_TP_ACTOR
#define LIB_TP_ACTOR

#include <stdint.h>
#include "addrs.h"

namespace Actor {
    struct Property {
        uint8_t _p0[0x04];  // 80450610 -> 8053a9c8
        bool freeze;        // 80450614 -> 8053a9cc
        uint8_t _p1[0x03];  // 80450615 -> 8053a9cd
    };
    static_assert(sizeof(Property) == 0x8);

    struct StopStatus {
        uint8_t _p0[0x02];  // 80450CBC -> 8053a90c
        bool hide_actors;   // 80450CBE -> 8053a90e
        uint8_t _p1[0x01];  // 80450CBF -> 8053a90f
    };
    static_assert(sizeof(StopStatus) == 0x4);
};  // namespace Actor

#define tp_actor (*(Actor::Property *)tp_actor_addr)
#define tp_stopstatus (*(Actor::StopStatus *)tp_actor_stopstatus_addr)


#endif  // LIB_TP_ACTOR