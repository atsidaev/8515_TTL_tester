#define P_S0 BIT_L0
#define P_S1 BIT_L1
#define P_S2 BIT_L2
#define P_nEN3 BIT_L3
#define P_nEN2 BIT_L4
#define P_EN1 BIT_L5
#define P_nY7 BIT_L6
#define P_GND BIT_L7
#define P_nY6 BIT_H7
#define P_nY5 BIT_H6
#define P_nY4 BIT_H5
#define P_nY3 BIT_H4
#define P_nY2 BIT_H3
#define P_nY1 BIT_H2
#define P_nY0 BIT_H1
#define P_VCC BIT_H0


/* S0 S1 S2 nEN3 nEN2 EN1 nY7 GND nY6 nY5 nY4 nY3 nY2 nY1 nY0 VCC */
/* 1-of-8 inverting decoder/demultiplexer.  */
void test_74138(void)
    {   
        Direct_L=(P_S0 | P_S1 | P_S2 | P_nEN3 | P_nEN2 | P_EN1 | P_GND);
        Direct_H=(P_VCC);
        Port_L=(P_EN1);
        Port_H=(P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_EN1 | P_nY7)) && (Pin_H==(P_nY6 | P_nY5 | P_nY4 | P_nY3 | P_nY2 | P_nY1 | P_VCC)));

        Port_L=(P_S0 | P_EN1);
        Port_H=(P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S0 | P_EN1 | P_nY7)) && (Pin_H==(P_nY6 | P_nY5 | P_nY4 | P_nY3 | P_nY2 | P_nY0 | P_VCC)));

        Port_L=(P_S1 | P_EN1);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_EN1 | P_nY7)) && (Pin_H==(P_nY6 | P_nY5 | P_nY4 | P_nY3 | P_nY1 | P_nY0 | P_VCC)));

        Port_L=(P_S0 | P_S1 | P_EN1);
        delay_ms(1);
        res &= ((Pin_L==(P_S0 | P_S1 | P_EN1 | P_nY7)) && (Pin_H==(P_nY6 | P_nY5 | P_nY4 | P_nY2 | P_nY1 | P_nY0 | P_VCC)));

        Port_L=(P_S2 | P_EN1);
        delay_ms(1);
        res &= ((Pin_L==(P_S2 | P_EN1 | P_nY7)) && (Pin_H==(P_nY6 | P_nY5 | P_nY3 | P_nY2 | P_nY1 | P_nY0 | P_VCC)));

        Port_L=(P_S0 | P_S2 | P_EN1);
        delay_ms(1);
        res &= ((Pin_L==(P_S0 | P_S2 | P_EN1 | P_nY7)) && (Pin_H==(P_nY6 | P_nY4 | P_nY3 | P_nY2 | P_nY1 | P_nY0 | P_VCC)));

        Port_L=(P_S1 | P_S2 | P_EN1);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_S2 | P_EN1 | P_nY7)) && (Pin_H==(P_nY5 | P_nY4 | P_nY3 | P_nY2 | P_nY1 | P_nY0 | P_VCC)));

        Port_L=(P_S0 | P_S1 | P_S2 | P_EN1);
        delay_ms(1);
        res &= ((Pin_L==(P_S0 | P_S1 | P_S2 | P_EN1)) && (Pin_H==(P_nY6 | P_nY5 | P_nY4 | P_nY3 | P_nY2 | P_nY1 | P_nY0 | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_S0
#undef P_S1
#undef P_S2
#undef P_nEN3
#undef P_nEN2
#undef P_EN1
#undef P_nY7
#undef P_GND
#undef P_nY6
#undef P_nY5
#undef P_nY4
#undef P_nY3
#undef P_nY2
#undef P_nY1
#undef P_nY0
#undef P_VCC
