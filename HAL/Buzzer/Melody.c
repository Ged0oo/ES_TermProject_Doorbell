/*
 * Melody.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Mohamed Nagy
 */

#include "Melody.h"


//PinkPanther
const unsigned char    Melody001[54] = {40,8,164,8,165,2,160,8,167,8,168,2,160,8,164,8,165,16,160,8,167,8,168,16,160,8,193,8,172,16,160,8,164,8,165,16,160,8,172,2,171,2,160,16,170,16,168,16,165,16,163,2,165,0};

//AxelF
const unsigned char    Melody002[48] = {40,4,167,136,170,8,167,16,167,8,172,8,167,8,165,4,167,136,194,8,167,16,167,8,195,8,194,8,170,8,167,8,194,8,199,16,167,8,165,16,165,8,162,8,169,132,167,0};

//Dallas
const unsigned char    Melody003[70] = {31,8,165,132,170,8,165,132,197,8,170,4,194,8,172,8,194,4,170,4,165,4,170,4,199,4,197,8,194,8,195,130,197,8,160,8,165,4,170,4,199,4,197,8,194,8,195,4,197,8,172,8,194,4,170,4,165,4,170,8,194,8,195,132,172,8,170,2,170,0};

//Szimszonék :)
const unsigned char    Melody004[48] = {40,132,193,4,197,4,199,8,202,132,200,4,197,4,193,8,170,8,167,8,167,8,167,2,168,8,160,8,160,8,167,8,167,8,167,8,168,132,171,8,193,8,193,8,193,4,193,0};

//Agadoo
const unsigned char    Melody005[54] = {31,8,172,8,169,4,165,8,165,8,165,4,165,8,165,8,165,8,165,8,165,8,164,8,165,4,167,8,170,8,167,4,164,8,164,8,164,4,164,8,164,8,164,8,164,8,164,8,162,8,164,8,165,0};

//Adams
const unsigned char    Melody006[56] = {40,8,161,4,166,8,170,4,166,8,161,4,140,2,168,8,166,4,165,8,168,4,165,8,133,4,138,2,166,8,161,4,166,8,170,4,166,8,161,4,140,2,168,8,166,4,165,8,161,4,163,8,165,1,166,0};

//PacMan
const unsigned char    Melody007[106] = {28,32,140,32,128,32,172,32,128,32,167,32,128,32,164,32,128,32,172,32,167,16,128,16,164,16,128,32,161,32,128,32,193,32,128,32,168,32,128,32,165,32,128,32,193,32,168,16,128,16,165,16,128,32,140,32,128,32,172,32,128,32,167,32,128,32,164,32,128,32,172,32,167,16,128,16,164,16,128,32,164,32,165,32,166,32,128,32,166,32,167,32,168,32,128,32,168,32,169,32,170,32,128,160,172,0};

//FunkyTown
const unsigned char    Melody008[52] = {31,8,193,8,193,8,171,8,193,8,128,8,168,8,128,8,168,8,193,8,198,8,197,8,193,2,128,8,193,8,193,8,171,8,193,8,128,8,168,8,128,8,168,8,193,8,198,8,197,8,193,0};

//Indiana
const unsigned char    Melody009[112] = {62,4,165,8,160,8,166,8,168,8,160,1,193,136,160,4,163,8,160,8,165,1,166,132,160,4,168,8,160,8,170,8,172,8,160,1,198,4,160,4,170,8,160,8,172,2,193,2,195,2,197,4,165,8,160,8,166,8,168,8,160,1,193,4,160,4,195,8,160,8,197,129,198,4,168,8,160,8,168,132,197,8,160,4,195,8,160,8,168,132,197,8,160,4,195,8,160,8,168,132,198,8,160,4,197,8,160,8,195,2,193,0};

//Looney
const unsigned char    Melody010[54] = {35,4,193,8,198,8,197,8,195,8,193,132,170,8,193,8,198,8,197,8,195,8,196,132,197,8,197,8,197,8,193,8,195,8,193,8,197,8,193,8,195,8,170,8,193,8,168,8,171,8,170,8,166,0};

//Monty Pyton
const unsigned char    Melody011[118] = {50,4,198,8,197,4,195,8,194,4,193,8,172,4,171,8,170,8,168,8,170,8,171,4,170,8,168,2,193,8,160,8,193,8,170,8,160,8,170,8,170,8,169,8,170,8,198,8,160,8,193,8,193,8,160,8,170,8,171,8,160,8,171,8,171,8,160,8,193,2,195,8,160,8,171,8,168,8,160,8,168,8,168,8,167,8,168,8,197,8,160,8,195,8,195,8,160,8,171,8,170,8,160,8,170,8,170,8,160,8,171,2,193,8,160,0};

//Popey
const unsigned char    Melody012[72] = {40,8,170,8,193,8,193,8,193,4,171,8,170,4,193,2,192,8,193,8,195,8,171,8,195,4,198,8,195,2,193,8,192,8,193,8,195,8,171,8,195,8,198,8,197,8,195,8,193,8,195,8,193,8,170,8,166,8,170,8,193,8,195,8,193,4,171,8,168,2,166,0};

//Popcorn
const unsigned char    Melody013[64] = {40,8,193,8,171,8,193,8,168,8,164,8,168,4,161,8,193,8,171,8,193,8,168,8,164,8,168,4,161,8,193,8,195,8,196,16,193,8,196,16,193,8,196,8,195,16,171,8,195,16,171,8,195,8,193,8,171,8,168,8,171,4,193,0};

//Star trek
const unsigned char    Melody014[18] = {16,136,166,16,171,132,196,8,195,144,171,144,168,144,193,4,198,0};

//Piccolo
const unsigned char    Melody015[68] = {80,4,195,4,200,4,168,4,200,8,195,8,197,8,195,8,172,4,168,4,163,8,168,8,170,8,172,8,193,4,195,4,200,1,195,4,195,4,200,4,168,4,200,8,195,8,197,8,172,4,168,4,163,8,166,8,168,8,170,8,172,4,193,4,198,1,193,0};

//A team (Szuper csapat)
const unsigned char    Melody016[42] = {40,4,196,8,171,2,196,16,160,8,169,4,171,132,164,8,160,16,168,16,171,8,196,8,171,8,198,2,196,16,160,136,194,16,193,16,171,136,169,2,171,0};

//Bond
const unsigned char    Melody017[76] = {80,4,161,8,163,8,163,4,163,2,163,4,161,4,161,4,161,4,161,8,164,8,164,4,164,2,164,4,163,4,163,4,163,4,161,8,163,8,163,4,163,2,163,4,161,4,161,4,161,4,161,8,164,8,164,4,164,2,164,4,163,4,162,4,161,4,193,129,172,4,168,4,166,129,168,0};

//Knight Rider
const unsigned char    Melody018[62] = {15,16,165,32,166,32,165,8,172,16,197,32,198,32,197,8,172,16,165,32,166,32,165,16,172,16,197,4,195,8,160,4,160,16,165,32,166,32,165,8,172,16,197,32,198,32,197,8,172,16,165,32,166,32,165,16,172,16,197,4,198,0};

//Smurfs (Hupikék törpikék)
const unsigned char    Melody019[64] = {25,4,193,4,198,16,193,8,195,8,171,4,168,32,160,4,193,16,170,8,166,8,170,4,168,16,160,32,168,32,169,32,170,32,171,32,172,4,193,32,160,4,198,16,193,8,195,8,171,4,168,32,160,4,193,16,170,8,171,8,165,4,166,0};

//Benny Hill
const unsigned char    Melody020[96] = {31,136,195,16,197,8,200,8,200,16,197,16,195,16,170,16,172,16,195,16,172,8,197,16,195,16,172,16,170,16,172,8,170,16,170,16,171,16,172,16,195,16,197,16,195,4,200,8,192,16,195,16,197,16,195,8,200,8,200,16,197,16,195,16,170,16,172,16,195,16,172,8,197,16,195,16,172,16,170,16,172,8,195,16,195,16,195,16,199,16,202,8,198,4,195,0};

