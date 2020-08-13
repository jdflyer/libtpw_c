#ifndef LIB_TP_EPONA
#define LIB_TP_EPONA

#include <stdint.h>

namespace Epona {
    struct Epona {
        float epona_x_pos;             // 80406200 -> 80492968
        float epona_y_pos;             // 80406204 -> 8049296C
        float epona_z_pos;             // 80406208 -> 80492970
        uint16_t epona_angle;          // 8040620C -> 80492974
        uint8_t epona_stage[0x08];     // 8040620E -> 80492976
        uint8_t epona_spawn_point_id;  // 80406216 -> 8049297E
        uint8_t epona_room_id;         // 80406217 -> 8049297F
    };                                 // struct Epona

    static_assert(sizeof(Epona) == 0x18);

    struct EponaProperty {
        uint8_t _p0[0x04];                        // 8038E5A4 -> 803e4740
        float link_start_trot_anim_speed;         // 8038E5A8 -> 803e4744
        uint8_t _p1[0x04];                        // 8038E5AC -> 803e4748
        float _p2;                                // 8038E5B0 -> 803e474C
        float _p3;                                // 8038E5B4 -> 803e4750
        uint8_t _p4[0x04];                        // 8038E5B8 -> 803e4754
        float _p5;                                // 8038E5BC -> 803e4758
        uint8_t _p6[0x04];                        // 8038E5C0 -> 803e475C
        float _p7;                                // 8038E5C4 -> 803e4760
        float _p8;                                // 8038E5C8 -> 803e4764
        uint8_t _p9[0x04];                        // 8038E5CC -> 803e4768
        float link_dash_anim_speed_1;             // 8038E5D0 -> 803e476C
        float link_dash_anim_speed_2;             // 8038E5D4 -> 803e4770
        float link_transition_to_dash_ride_anim;  // 8038E5D8 -> 803e4774
        float _p20;                               // 8038E5DC -> 803e4778
        uint8_t _p10[0x04];                       // 8038E5E0 -> 803e477C
        float _p11;                               // 8038E5E4 -> 803e4780
        uint8_t _p12[0x04];                       // 8038E5E8 -> 803e4784
        float _p13;                               // 8038E5EC -> 803e4788
        float _p14;                               // 8038E5F0 -> 803e478C
        uint8_t _p15[0x06];                       // 8038E5F4 -> 803e4790
        uint16_t dash_cooldown_timer;             // 8038E5FA -> 803e4796
        uint8_t _p16[0x04];                       // 8038E5FC -> 803e4798
        float _p17;                               // 8038E600 -> 803e479C
        float _p18;                               // 8038E604 -> 803e47A0
        float wait_before_gallop;                 // 8038E608 -> 803e47A4
        float _p19;                               // 8038E60C -> 803e47A8
    };                                            // struct EponaProperty

    static_assert(sizeof(EponaProperty) == 0x6C);

    struct Filename {
        uint8_t epona_file_name[0x10];  // 80406385 -> 80492AED
    };                                  // struct filename

    static_assert(sizeof(Filename) == 0x10);
};  // namespace Epona

#endif  //LIB_TP_EPONA