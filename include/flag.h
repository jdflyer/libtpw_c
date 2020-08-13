#ifndef LIB_TP_FLAG
#define LIB_TP_FLAG

#include <stdint.h>

class Flag {
   private:
    uint32_t addr;
    uint8_t bit;

   public:
    Flag(uint32_t addr, uint8_t bit) : addr(addr), bit(bit) {}
    void activate();
    void deactivate();
    bool is_active();
    void toggle();
};
namespace Flags {
    struct TempFlags {
        uint8_t temp_flag_bit_field_1;   // 80406B14 -> 8049327C
        uint8_t temp_flag_bit_field_2;   // 80406B15 -> 8049327D
        uint8_t temp_flag_bit_field_3;   // 80406B16 -> 8049327E
        uint8_t temp_flag_bit_field_4;   // 80406B17 -> 8049327F
        uint8_t temp_flag_bit_field_5;   // 80406B18 -> 80493280
        uint8_t temp_flag_bit_field_6;   // 80406B19 -> 80493281
        uint8_t temp_flag_bit_field_7;   // 80406B1A -> 80493282
        uint8_t temp_flag_bit_field_8;   // 80406B1B -> 80493283
        uint8_t temp_flag_bit_field_9;   // 80406B1C -> 80493284
        uint8_t temp_flag_bit_field_10;  // 80406B1D -> 80493285
        uint8_t temp_flag_bit_field_11;  // 80406B1E -> 80493286
        uint8_t temp_flag_bit_field_12;  // 80406B1F -> 80493287
        uint8_t temp_flag_bit_field_13;  // 80406B20 -> 80493288
        uint8_t temp_flag_bit_field_14;  // 80406B21 -> 80493289
        uint8_t temp_flag_bit_field_15;  // 80406B22 -> 8049328A
        uint8_t temp_flag_bit_field_16;  // 80406B23 -> 8049328B
        uint8_t temp_flag_bit_field_17;  // 80406B24 -> 8049328C
        uint8_t temp_flag_bit_field_18;  // 80406B25 -> 8049328D
        uint8_t temp_flag_bit_field_19;  // 80406B26 -> 8049328E
        uint8_t temp_flag_bit_field_20;  // 80406B27 -> 8049328F
        uint8_t temp_flag_bit_field_21;  // 80406B28 -> 80493290
        uint8_t temp_flag_bit_field_22;  // 80406B29 -> 80493291
        uint8_t temp_flag_bit_field_23;  // 80406B2A -> 80493292
        uint8_t temp_flag_bit_field_24;  // 80406B2B -> 80493293
        uint8_t temp_flag_bit_field_25;  // 80406B2C -> 80493294
        uint8_t temp_flag_bit_field_26;  // 80406B2D -> 80493295
        uint8_t temp_flag_bit_field_27;  // 80406B2E -> 80493296
        uint8_t temp_flag_bit_field_28;  // 80406B2F -> 80493297
        uint8_t temp_flag_bit_field_29;  // 80406B30 -> 80493298
        uint8_t temp_flag_bit_field_30;  // 80406B31 -> 80493299
        uint8_t temp_flag_bit_field_31;  // 80406B32 -> 8049329A
        uint8_t temp_flag_bit_field_32;  // 80406B33 -> 8049329B
        uint8_t temp_flag_bit_field_33;  // 80406B34 -> 8049329C
        uint8_t temp_flag_bit_field_34;  // 80406B35 -> 8049329D
        uint8_t temp_flag_bit_field_35;  // 80406B36 -> 8049329E
        uint8_t temp_flag_bit_field_36;  // 80406B37 -> 8049329F
    };                                   // struct TempFlags
    static_assert(sizeof(TempFlags) == 0x24);
};      // namespace Flags
#endif  // LIB_TP_FLAG