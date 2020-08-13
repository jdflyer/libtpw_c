#ifndef LIB_TP_MINIMAP
#define LIB_TP_MINIMAP

#include <stdint.h>

namespace Minimap {
    struct Warps {
        uint8_t ordon_spring_warp;                  // 804063BD -> 80492B25 // bit 4 gives the warp
        uint8_t _p12[0x3D];                         // 804063BE -> 80492B26
        uint8_t nfaron_woods_warp;                  // 804063FB -> 80492B63 // bit 2 gives the warp
        uint8_t _p13[0x07];                         // 804063FC -> 80492B64
        uint8_t sfaron_woods_warp;                  // 80406403 -> 80492B6B // bit 7 gives the warp
        uint8_t _p14[0x14];                         // 80406404 -> 80492B6C
        uint8_t kak_village_warp;                   // 80406418 -> 80492B80 // bit 7 gives the warp
        uint8_t death_mountain_warp;                // 80406419 -> 80492B81 // bit 5 gives the warp
        uint8_t _p15[0x1F];                         // 8040641A -> 80492B82
        uint8_t uzr_warp;                           // 80406439 -> 80492BA1 // bit 5 gives the warp
        uint8_t lake_hylia_warp;                    // 8040643A -> 80492BA2 // bit 2 gives the warp
        uint8_t zoras_domain_warp;                  // 8040643B -> 80492BA3 // bit 2 gives the warp
        uint8_t _p16[0x3C];                         // 8040643C -> 80492BA4
        uint8_t kak_gorge_unk;                      // 80406478 -> 80492BE0
        uint8_t kak_gorge_warp;                     // 80406479 -> 80492BE1 // bit 5 gives the warp
        uint8_t _p17[0x01];                         // 8040647A -> 80492BE2
        uint8_t castle_town_warp;                   // 8040647B -> 80492BE3 // bit 3 gives the warp
        uint8_t _p18[0x0B];                         // 8040647C -> 80492BE4
        uint8_t eldin_bridge_warp;                  // 80406487 -> 80492BEF // bit 3 gives the warp
        uint8_t _p19[0x1F];                         // 80406488 -> 80492BF0
        uint8_t sacred_grove_warp;                  // 804064A7 -> 80492C0F // bit 4 gives the warp
        uint8_t _p20[0x11];                         // 804064A8 -> 80492C10
        uint8_t snowpeak_warp;                      // 804064B9 -> 80492C21 // bit 5 gives the warp
        uint8_t _p21[0x3F];                         // 804064BA -> 80492C22
        uint8_t gerudo_mesa_warp;                   // 804064F9 -> 80492C61 // bit 5 gives the warp
        uint8_t _p22[0x04];                         // 804064FA -> 80492C62
        uint8_t mirror_chamber_warp;                // 804064FE -> 80492C66 // bit 0 gives the warp
    }; // struct Warps

    static_assert(sizeof(Warps) == 0x142);

    struct Region {
        uint8_t area_unlocked;                      // 8040623D -> 804929A5 // bits - 0: n/a, 1: ordon, 2: faron, 3: eldin, 4: lanayru, 5: gerudo, 6: snowpeak, 7: n/a   
    }; // struct Region

    static_assert(sizeof(Region) == 0x01);
};

#endif // LIB_TP_MINIMAP