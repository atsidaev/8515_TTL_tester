#define P_n1EN BIT_L0
#define P_S1 BIT_L1
#define P_1A3 BIT_L2
#define P_1A2 BIT_L3
#define P_1A1 BIT_L4
#define P_1A0 BIT_L5
#define P_1Y BIT_L6
#define P_GND BIT_L7
#define P_2Y BIT_H7
#define P_2A0 BIT_H6
#define P_2A1 BIT_H5
#define P_2A2 BIT_H4
#define P_2A3 BIT_H3
#define P_S0 BIT_H2
#define P_n2EN BIT_H1
#define P_VCC BIT_H0


/* /1EN S1 1A3 1A2 1A1 1A0 1Y GND 2Y 2A0 2A1 2A2 2A3 S0 /2EN VCC */
/* 74253 8-to-2 line 3-state noninverting data selector/multiplexer. */

void test_74253(void)
    {   
        Direct_L=(P_n1EN | P_S1 | P_1A3 | P_1A2 | P_1A1 | P_1A0 | P_GND);
        Direct_H=(P_2A0 | P_2A1 | P_2A2 | P_2A3 | P_S0 | P_n2EN | P_VCC);
        Port_L=(P_1A2 | P_1A0);
        Port_H=(P_2A1 | P_2A3 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1A2 | P_1A0 | P_1Y)) && (Pin_H==(P_2A1 | P_2A3 | P_VCC)));

        Port_L=(P_1A2 | P_1A0);
        Port_H=(P_2A1 | P_2A3 | P_S0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1A2 | P_1A0)) && (Pin_H==(P_2Y | P_2A1 | P_2A3 | P_S0 | P_VCC)));

        Port_L=(P_S1 | P_1A2 | P_1A0);
        Port_H=(P_2A1 | P_2A3 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_1A2 | P_1A0 | P_1Y)) && (Pin_H==(P_2A1 | P_2A3 | P_VCC)));

        Port_L=(P_S1 | P_1A2 | P_1A0);
        Port_H=(P_2A1 | P_2A3 | P_S0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_1A2 | P_1A0)) && (Pin_H==(P_2Y | P_2A1 | P_2A3 | P_S0 | P_VCC)));

        Port_L=(P_1A3 | P_1A1);
        Port_H=(P_2A0 | P_2A2 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1A3 | P_1A1)) && (Pin_H==(P_2Y | P_2A0 | P_2A2 | P_VCC)));

        Port_L=(P_1A3 | P_1A1);
        Port_H=(P_2A0 | P_2A2 | P_S0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1A3 | P_1A1 | P_1Y)) && (Pin_H==(P_2A0 | P_2A2 | P_S0 | P_VCC)));

        Port_L=(P_S1 | P_1A3 | P_1A1);
        Port_H=(P_2A0 | P_2A2 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_1A3 | P_1A1)) && (Pin_H==(P_2Y | P_2A0 | P_2A2 | P_VCC)));

        Port_L=(P_S1 | P_1A3 | P_1A1);
        Port_H=(P_2A0 | P_2A2 | P_S0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_1A3 | P_1A1 | P_1Y)) && (Pin_H==(P_2A0 | P_2A2 | P_S0 | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_n1EN
#undef P_S1
#undef P_1A3
#undef P_1A2
#undef P_1A1
#undef P_1A0
#undef P_1Y
#undef P_GND
#undef P_2Y
#undef P_2A0
#undef P_2A1
#undef P_2A2
#undef P_2A3
#undef P_S0
#undef P_n2EN
#undef P_VCC
