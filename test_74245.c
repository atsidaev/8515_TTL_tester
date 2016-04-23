#define P_DIR BIT_L0
#define P_A1 BIT_L1
#define P_A2 BIT_L2
#define P_A3 BIT_L3
#define P_A4 BIT_L4
#define P_A5 BIT_L5
#define P_A6 BIT_L6
#define P_A7 BIT_L7
#define P_A8 BIT_L8
#define P_GND BIT_L9
#define P_B8 BIT_H9
#define P_B7 BIT_H8
#define P_B6 BIT_H7
#define P_B5 BIT_H6
#define P_B4 BIT_H5
#define P_B3 BIT_H4
#define P_B2 BIT_H3
#define P_B1 BIT_H2
#define P_nEN BIT_H1
#define P_VCC BIT_H0


/* DIR A1 A2 A3 A4 A5 A6 A7 A8 GND B8 B7 B6 B5 B4 B3 B2 B1 /EN VCC */
/* 74245 8-bit 3-state noninverting bus transceiver. */
void test_74245(void)
    {
        sym[1]=5;
        sym[2]=4;
        sym[3]=2;
        Direct_L=(P_DIR | P_A1 | P_A2 | P_A3 | P_A4 | P_A5 | P_A6 | P_A7);
        Direct_H=(P_nEN | P_VCC);
        DDRE=1;
        Port_L=(P_DIR | P_A1 | P_A3 | P_A5 | P_A7);
        Port_H=(P_VCC);
        PORTE=0;
        res &= ((Pin_L==(P_DIR | P_A1 | P_A3 | P_A5 | P_A7)) && (Pin_H==(P_B5 | P_B3 | P_B1 | P_VCC)) && (PINE==4));

        Port_L=(P_DIR | P_A2 | P_A4 | P_A6);
        Port_H=(P_VCC);
        PORTE=1;
        res &= ((Pin_L==(P_DIR | P_A2 | P_A4 | P_A6)) && (Pin_H==(P_B6 | P_B4 | P_B2 | P_VCC)) && (PINE==3));

        Direct_L=(P_DIR);
        Direct_H=(P_B6 | P_B5 | P_B4 | P_B3 | P_B2 | P_B1 | P_nEN | P_VCC);
        DDRE=6;
        Port_L=0;
        Port_H=(P_B5 | P_B3 | P_B1 | P_VCC);
        PORTE=4;
        delay_ms(1);
        res &= ((Pin_L==(P_A1 | P_A3 | P_A5 | P_A7)) && (Pin_H==(P_B5 | P_B3 | P_B1 | P_VCC)) && (PINE==4));

        Port_L=0;
        Port_H=(P_B6 | P_B4 | P_B2 | P_VCC);
        PORTE=2;
        delay_ms(1);
        res &= ((Pin_L==(P_A2 | P_A4 | P_A6)) && (Pin_H==(P_B6 | P_B4 | P_B2 | P_VCC)) && (PINE==3));

        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }


#undef P_DIR
#undef P_A1
#undef P_A2
#undef P_A3
#undef P_A4
#undef P_A5
#undef P_A6
#undef P_A7
#undef P_A8
#undef P_GND
#undef P_B8
#undef P_B7
#undef P_B6
#undef P_B5
#undef P_B4
#undef P_B3
#undef P_B2
#undef P_B1
#undef P_nEN
#undef P_VCC
