#define P_nRST BIT_L0
#define P_Q0 BIT_L1
#define P_D0 BIT_L2
#define P_D1 BIT_L3
#define P_Q1 BIT_L4
#define P_D2 BIT_L5
#define P_Q2 BIT_L6
#define P_GND BIT_L7
#define P_CLK BIT_H7
#define P_Q3 BIT_H6
#define P_D3 BIT_H5
#define P_Q4 BIT_H4
#define P_D4 BIT_H3
#define P_D5 BIT_H2
#define P_Q6 BIT_H1
#define P_VCC BIT_H0


/* /RST Q0 D0 D1 Q1 D2 Q2 GND CLK Q3 D3 Q4 D4 D5 Q6 VCC */
/* 74174 6-bit D flip-flop with reset. */
void test_74174(void)
    {   
        sym[1]=4;
        sym[2]=7;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(P_nRST | P_D0 | P_D1 | P_D2 | P_GND);
        Direct_H=(P_CLK | P_D3 | P_D4 | P_D5 | P_VCC);
        Port_H=(P_VCC);
        Port_L=0;
        delay_ms(1);
        Port_L=(P_nRST);
        delay_ms(1);
        if ((Pin_L==(P_nRST)) && (Pin_H==(P_VCC))) res=1;
            else res=0;        
        Port_L=(P_nRST | P_D0 | P_D1 | P_D2);
        Port_H=(P_CLK | P_VCC);
        Port_H=(P_VCC);
        Port_L=(P_nRST);
        delay_ms(1);
        if ((Pin_L==(P_nRST | P_Q0 | P_Q1 | P_Q2)) && (Pin_H==(P_VCC)) && (res==1)) res=1;
            else res=0;                   
        Port_H=(P_D3 | P_D4 | P_D5 | P_VCC);
        Port_H=(P_CLK | P_D3 | P_D4 | P_D5 | P_VCC);
        Port_H=(P_D3 | P_D4 | P_D5 | P_VCC);
        Port_H=(P_VCC);
        if ((Pin_L==(P_nRST)) && (Pin_H==(P_Q3 | P_Q4 | P_Q6 | P_VCC)) && (res==1)) res=1;
            else res=0;
        Port_L=0;
        delay_ms(1);
        Port_L=(P_nRST);
        delay_ms(1);
        if ((Pin_L==(P_nRST)) && (Pin_H==(P_VCC)) && (res==1)) res=1;
            else res=0;                
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }


#undef P_nRST
#undef P_Q0
#undef P_D0
#undef P_D1
#undef P_Q1
#undef P_D2
#undef P_Q2
#undef P_GND
#undef P_CLK
#undef P_Q3
#undef P_D3
#undef P_Q4
#undef P_D4
#undef P_D5
#undef P_Q6
#undef P_VCC
