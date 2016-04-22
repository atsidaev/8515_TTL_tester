#define P_nRST BIT_L0
#define P_Q1 BIT_L1
#define P_nQ1 BIT_L2
#define P_D1 BIT_L3
#define P_D2 BIT_L4
#define P_nQ2 BIT_L5
#define P_Q2 BIT_L6
#define P_GND BIT_L7
#define P_CLK BIT_H7
#define P_Q3 BIT_H6
#define P_nQ3 BIT_H5
#define P_D3 BIT_H4
#define P_D4 BIT_H3
#define P_nQ4 BIT_H2
#define P_Q4 BIT_H1
#define P_VCC BIT_H0


/* /RST Q1 /Q1 D1 D2 /Q2 Q2 GND CLK Q3 /Q3 D3 D4 /Q4 Q4 VCC */
/* 74175 4-bit D flip-flop with complementary outputs and reset. */

void test_74175(void)
    {
        sym[1]=5;
        sym[2]=7;
        sym[3]=1;
        res=1;
        sym[0]=12;
        Direct_L=(P_nRST | P_D1 | P_D2 | P_GND);
        Direct_H=(P_CLK | P_D3 | P_D4 | P_VCC);    
        Port_H=(P_VCC);
        Port_L=0;
        delay_ms(1);
        Port_L=(P_nRST);
        delay_ms(1);
        res &= ( ( Pin_L == (P_nRST | P_nQ1 | P_nQ2)) && ( Pin_H  == (P_nQ3 | P_nQ4 | P_VCC)) );
        Port_L = (P_nRST | P_D1);
        Port_H = (P_D4 | P_VCC);
        Port_H = (P_CLK | P_D4 | P_VCC);
        Port_H = (P_VCC);
        delay_ms(1);        
        res &= ((Pin_L == (P_nRST | P_Q1 | P_D1 | P_nQ2)) && (Pin_H == (P_nQ3 | P_Q4 | P_VCC)) && res == 1);

        Port_L = (P_nRST | P_D2);
        Port_H = (P_D3 | P_VCC);
        Port_H = (P_CLK | P_D3 | P_VCC);    
        Port_H = (P_VCC);
        delay_ms(1);        
        res &= ((Pin_L == (P_nRST | P_nQ1 | P_D2 | P_Q2)) && (Pin_H == (P_Q3 | P_nQ4 | P_VCC)) && res == 1);

        Port_L = (P_nRST);
        Port_H = (P_VCC);
        Port_H = (P_CLK | P_VCC);    
        Port_H = (P_VCC);
        delay_ms(1);
        res &= ((Pin_L == (P_nRST | P_nQ1 | P_nQ2)) && (Pin_H == (P_nQ3 | P_nQ4 | P_VCC)) && res == 1);

        Port_L = (P_nRST | P_D1 | P_D2);
        Port_H = (P_D3 | P_D4 | P_VCC);
        Port_H = (P_CLK | P_D3 | P_D4 | P_VCC);    
        Port_H = (P_D3 | P_D4 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L == (P_nRST | P_Q1 | P_D1 | P_D2 | P_Q2)) && (Pin_H == (P_Q3 | P_D3 | P_D4 | P_Q4 | P_VCC)) && res == 1);

        Port_L = 0;
        Port_H = 0;
    }


#undef P_nRST
#undef P_Q1
#undef P_nQ1
#undef P_D1
#undef P_D2
#undef P_nQ2
#undef P_Q2
#undef P_GND
#undef P_CLK
#undef P_Q3
#undef P_nQ3
#undef P_D3
#undef P_D4
#undef P_nQ4
#undef P_Q4
#undef P_VCC
