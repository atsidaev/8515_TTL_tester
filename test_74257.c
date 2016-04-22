#define P_S BIT_L0
#define P_1A0 BIT_L1
#define P_1A1 BIT_L2
#define P_1Y BIT_L3
#define P_2A0 BIT_L4
#define P_2A1 BIT_L5
#define P_2Y BIT_L6
#define P_GND BIT_L7
#define P_3Y BIT_H7
#define P_3A1 BIT_H6
#define P_3A0 BIT_H5
#define P_4Y BIT_H4
#define P_4A1 BIT_H3
#define P_4A0 BIT_H2
#define P_nEN BIT_H1
#define P_VCC BIT_H0


/* S 1A0 1A1 1Y 2A0 2A1 2Y GND 3Y 3A1 3A0 4Y 4A1 4A0 /EN VCC */
/* 74257 8-to-4 line 3-state noninverting data selector/multiplexer. */

void test_74257(void)
    {   
        sym[1]=7;
        sym[2]=5;
        sym[3]=2;
        res=1;
        sym[0]=12;
        Direct_L=(P_S | P_1A0 | P_1A1 | P_2A0 | P_2A1 | P_GND);
        Direct_H=(P_3A1 | P_3A0 | P_4A1 | P_4A0 | P_nEN | P_VCC);
        Port_L=(P_1Y | P_2Y);
        Port_H=(P_3Y | P_4Y | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==0) && (Pin_H==(P_VCC)));

        Port_L=(P_1A0 | P_1Y | P_2A0 | P_2Y);
        Port_H=(P_3Y | P_3A0 | P_4Y | P_4A0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1A0 | P_1Y | P_2A0 | P_2Y)) && (Pin_H==(P_3Y | P_3A0 | P_4Y | P_4A0 | P_VCC)));

        Port_L=(P_S | P_1A0 | P_1Y | P_2A0 | P_2Y);
        delay_ms(1);
        res &= ((Pin_L==(P_S | P_1A0 | P_2A0)) && (Pin_H==(P_3A0 | P_4A0 | P_VCC)));

        Port_L=(P_S | P_1A1 | P_1Y | P_2A1 | P_2Y);
        Port_H=(P_3Y | P_3A1 | P_4Y | P_4A1 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S | P_1A1 | P_1Y | P_2A1 | P_2Y)) && (Pin_H==(P_3Y | P_3A1 | P_4Y | P_4A1 | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_S
#undef P_1A0
#undef P_1A1
#undef P_1Y
#undef P_2A0
#undef P_2A1
#undef P_2Y
#undef P_GND
#undef P_3Y
#undef P_3A1
#undef P_3A0
#undef P_4Y
#undef P_4A1
#undef P_4A0
#undef P_nEN
#undef P_VCC
