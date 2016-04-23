#define P_U_D BIT_L0
#define P_CLK BIT_L1
#define P_P0 BIT_L2
#define P_P1 BIT_L3
#define P_P2 BIT_L4
#define P_P3 BIT_L5
#define P_nENP BIT_L6
#define P_GND BIT_L7
#define P_nLOAD BIT_H7
#define P_nENT BIT_H6
#define P_Q3 BIT_H5
#define P_Q2 BIT_H4
#define P_Q1 BIT_H3
#define P_Q0 BIT_H2
#define P_nRCO BIT_H1
#define P_VCC BIT_H0


/* U_D CLK P0 P1 P2 P3 /ENP GND /LOAD /ENT Q3 Q2 Q1 Q0 /RCO VCC */
/* 74169 4-bit synchronous binary up/down counter with load and ripple carry output. */
void test_74169(void)
    {   
        sym[1]=9;
        sym[2]=6;
        sym[3]=1;
        Direct_L=(P_U_D | P_CLK | P_P0 | P_P1 | P_P2 | P_P3 | P_nENP | P_GND);
        Direct_H=(P_nLOAD | P_nENT | P_VCC);
        Port_L=(P_P0 | P_P2);
        Port_H=(P_VCC);
        Port_L=(P_CLK | P_P0 | P_P2);
        Port_L=(P_P0 | P_P2);
        Port_H=(P_nLOAD | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_P0 | P_P2)) && (Pin_H==(P_nLOAD | P_Q2 | P_Q0 | P_nRCO | P_VCC)));

        Port_L=(P_P1 | P_P3);
        Port_H=(P_VCC);
        Port_L=(P_CLK | P_P1 | P_P3);
        Port_L=(P_P1 | P_P3);
        Port_H=(P_nLOAD | P_VCC);
        res &= ((Pin_L==(P_P1 | P_P3)) && (Pin_H==(P_nLOAD | P_Q3 | P_Q1 | P_nRCO | P_VCC)));

        Port_L=(P_U_D);
        Port_L=(P_U_D | P_CLK);
        Port_L=(P_U_D);
        Port_L=(P_U_D | P_CLK);
        Port_L=(P_U_D);
        Port_L=(P_U_D | P_CLK);
        Port_L=(P_U_D);
        Port_L=(P_U_D | P_CLK);
        Port_L=(P_U_D);
        Port_L=(P_U_D | P_CLK);
        Port_L=(P_U_D);
        delay_ms(1);
        res &= ((Pin_L==(P_U_D)) && (Pin_H==(P_nLOAD | P_Q3 | P_Q2 | P_Q1 | P_Q0 | P_VCC)));

        Port_L=(P_U_D | P_CLK);
        Port_L=(P_U_D);    
        delay_ms(1);
        res &= ((Pin_L==(P_U_D)) && (Pin_H==(P_nLOAD | P_nRCO | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_U_D
#undef P_CLK
#undef P_P0
#undef P_P1
#undef P_P2
#undef P_P3
#undef P_nENP
#undef P_GND
#undef P_nLOAD
#undef P_nENT
#undef P_Q3
#undef P_Q2
#undef P_Q1
#undef P_Q0
#undef P_nRCO
#undef P_VCC
