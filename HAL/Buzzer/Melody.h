#ifndef __MELORY_H__
#define __MELORY_H__


/*
 * macros for reading a byte from program memory
 * hese macros provide an abstraction for reading a byte
 * from program memory, and the implementation details are handled
 * through the use of inline assembly (lpm instruction)
 */
#define pgm_read_byte(address_short)    pgm_read_byte_near(address_short)
#define pgm_read_byte_near(address_short) __LPM((uint16)(address_short))
#define __LPM(addr)         __LPM_enhanced__(addr)
#define __LPM_enhanced__(addr)  \
(__extension__({                \
    uint16 __addr16 = (uint16)(addr); \
    uint8 __result;           \
    __asm__                     \
    (                           \
        "lpm %0, Z" "\n\t"      \
        : "=r" (__result)       \
        : "z" (__addr16)        \
    );                          \
    __result;                   \
}))


#endif //__MELORY_H__
