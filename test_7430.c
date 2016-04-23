#define P_A BIT_L0
#define P_B BIT_L1
#define P_C BIT_L2
#define P_D BIT_L3
#define P_E BIT_L4
#define P_F BIT_L5
#define P_GND BIT_L6
#define P_nY BIT_H6
#define P_NC1 BIT_H5
#define P_NC2 BIT_H4
#define P_G BIT_H3
#define P_H BIT_H2
#define P_NC3 BIT_H1
#define P_VCC BIT_H0


/* A B C D E F GND nY NC NC G H NC VCC */
/* 8-input NAND gate. */

void test_7430(void)
    {   
        Direct_L=(P_A | P_B | P_C | P_D | P_E | P_F | P_GND | BIT_L7);
        Direct_H=(BIT_H7 | P_NC1 | P_NC2 | P_G | P_H | P_NC3 | P_VCC);
        Port_L=0;
        Port_H=(P_nY | P_NC1 | P_NC2 | P_NC3 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==0) && (Pin_H==(P_nY | P_NC1 | P_NC2 | P_NC3 | P_VCC)));

        Port_L=(P_A | P_C | P_E);
        Port_H=(P_nY | P_NC1 | P_NC2 | P_H | P_NC3 | P_VCC);
        res &= ((Pin_L==(P_A | P_C | P_E)) && (Pin_H==(P_nY | P_NC1 | P_NC2 | P_H | P_NC3 | P_VCC)));

        Port_L=(P_B | P_D | P_F);
        Port_H=(P_nY | P_NC1 | P_NC2 | P_G | P_NC3 | P_VCC);
        res &= ((Pin_L==(P_B | P_D | P_F)) && (Pin_H==(P_nY | P_NC1 | P_NC2 | P_G | P_NC3 | P_VCC)));

        Port_L=(P_A | P_B | P_C | P_D | P_E | P_F);
        Port_H=(P_nY | P_NC1 | P_NC2 | P_G | P_H | P_NC3 | P_VCC);
        res &= ((Pin_L==(P_A | P_B | P_C | P_D | P_E | P_F)) && (Pin_H==(P_NC1 | P_NC2 | P_G | P_H | P_NC3 | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_A
#undef P_B
#undef P_C
#undef P_D
#undef P_E
#undef P_F
#undef P_GND
#undef P_nY
#undef P_NC1
#undef P_NC2
#undef P_G
#undef P_H
#undef P_NC3
#undef P_VCC
