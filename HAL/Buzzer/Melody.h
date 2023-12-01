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



//PinkPanther
extern const unsigned char    Melody001[54];

//AxelF
extern const unsigned char    Melody002[48];

//Dallas
extern const unsigned char    Melody003[70];

//Szimszonék :)
extern const unsigned char    Melody004[48];

//Agadoo
extern const unsigned char    Melody005[54];

//Adams
extern const unsigned char    Melody006[56];

//PacMan
extern const unsigned char    Melody007[106];

//FunkyTown
extern const unsigned char    Melody008[52];

//Indiana
extern const unsigned char    Melody009[112];

//Looney
extern const unsigned char    Melody010[54];

//Monty Pyton
extern const unsigned char    Melody011[118];

//Popey
extern const unsigned char    Melody012[72];

//Popcorn
extern const unsigned char    Melody013[64];

//Star trek
extern const unsigned char    Melody014[18];

//Piccolo
extern const unsigned char    Melody015[68];

//A team (Szuper csapat)
extern const unsigned char    Melody016[42];

//Bond
extern const unsigned char    Melody017[76];

//Knight Rider
extern const unsigned char    Melody018[62];

//Smurfs (Hupikék törpikék)
extern const unsigned char    Melody019[64];

//Benny Hill
extern const unsigned char    Melody020[96];

#endif //__MELORY_H__
