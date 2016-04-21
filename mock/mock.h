char sym[4], seg, res=0;

extern unsigned char Port_H;
extern unsigned char Direct_H;
extern unsigned char Pin_H;
extern unsigned char Port_L;
extern unsigned char Direct_L;
extern unsigned char Pin_L;

extern unsigned char DDRE;
extern unsigned char PINE;
extern unsigned char PORTE;

#define BIT_L0 1
#define BIT_L1 2
#define BIT_L2 4
#define BIT_L3 8
#define BIT_L4 16
#define BIT_L5 32
#define BIT_L6 64
#define BIT_L7 128

#define BIT_H0 1
#define BIT_H1 2
#define BIT_H2 4
#define BIT_H3 8
#define BIT_H4 16
#define BIT_H5 32
#define BIT_H6 64
#define BIT_H7 128
