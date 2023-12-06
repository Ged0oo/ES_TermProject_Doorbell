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


extern const unsigned char    Melody001[54];
extern const unsigned char    Melody002[42];
extern const unsigned char    Melody003[76];
extern const unsigned char    Melody004[48];
extern const unsigned char    Melody005[96];
extern const unsigned char    Melody006[118];
extern const unsigned char    Melody007[70];
extern const unsigned char    Melody008[54];
extern const unsigned char    Melody009[112];
extern const unsigned char    Melody010[52];
extern const unsigned char    Melody011[56];
extern const unsigned char    Melody012[72];
extern const unsigned char    Melody013[64];
extern const unsigned char    Melody014[18];
extern const unsigned char    Melody015[68];
extern const unsigned char    Melody016[106];
extern const unsigned char    Melody017[48];
extern const unsigned char    Melody018[62];
extern const unsigned char    Melody019[64];
extern const unsigned char    Melody020[54];


#endif //__MELORY_H__
