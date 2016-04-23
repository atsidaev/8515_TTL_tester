#define P_D BIT_L0
#define P_P0 BIT_L1
#define P_P1 BIT_L2
#define P_P2 BIT_L3
#define P_P3 BIT_L4
#define P_CLK1 BIT_L5
#define P_CLK2 BIT_L6
#define P_GND BIT_L7
#define P_nRST BIT_H7
#define P_P4 BIT_H6
#define P_P5 BIT_H5
#define P_P6 BIT_H4
#define P_Q7 BIT_H3
#define P_P7 BIT_H2
#define P_SH_LD BIT_H1
#define P_VCC BIT_H0


/* D P0 P1 P2 P3 CLK1 CLK2 GND /RST P4 P5 P6 Q7 P7 SH_LD VCC */
/* 74166 8-bit parallel-in serial-out shift register with asynchronous reset */
void test_74166(void)
    {   
        Direct_L=(P_D | P_P0 | P_P1 | P_P2 | P_P3 | P_CLK1 | P_CLK2 | P_GND);
        Direct_H=(P_nRST | P_P4 | P_P5 | P_P6 | P_P7 | P_SH_LD | P_VCC);
        Port_L=0;
        Port_H=(P_VCC);
        Port_H=(P_nRST | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==0) && (Pin_H==(P_nRST | P_VCC)));

        Port_L=(P_P0 | P_P1 | P_P2 | P_P3);
        Port_H=(P_nRST | P_P4 | P_P6 | P_VCC);
        Port_L=(P_P0 | P_P1 | P_P2 | P_P3 | P_CLK2);
        Port_L=(P_P0 | P_P1 | P_P2 | P_P3);
        Port_H=(P_nRST | P_SH_LD | P_VCC);        
        Port_L=0;
        delay_ms(1);
        res &= ((Pin_L==0) && (Pin_H==(P_nRST | P_SH_LD | P_VCC)));

        Port_L=(P_CLK2);
        Port_L=0;
        delay_ms(1);
        res &= ((Pin_H==(P_nRST | P_Q7 | P_SH_LD | P_VCC)));

        Port_L=(P_CLK2);
        Port_L=0;
        res &= ((Pin_H==(P_nRST | P_SH_LD | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_D
#undef P_P0
#undef P_P1
#undef P_P2
#undef P_P3
#undef P_CLK1
#undef P_CLK2
#undef P_GND
#undef P_nRST
#undef P_P4
#undef P_P5
#undef P_P6
#undef P_Q7
#undef P_P7
#undef P_SH_LD
#undef P_VCC
