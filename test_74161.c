#define P_nRST BIT_L0
#define P_CLK BIT_L1
#define P_P0 BIT_L2
#define P_P1 BIT_L3
#define P_P2 BIT_L4
#define P_P3 BIT_L5
#define P_ENP BIT_L6
#define P_GND BIT_L7
#define P_nLOAD BIT_H7
#define P_ENT BIT_H6
#define P_Q3 BIT_H5
#define P_Q2 BIT_H4
#define P_Q1 BIT_H3
#define P_Q0 BIT_H2
#define P_RCO BIT_H1
#define P_VCC BIT_H0


/* /RST CLK P0 P1 P2 P3 ENP GND /LOAD ENT Q3 Q2 Q1 Q0 RCO VCC */
/* 74161 4-bit synchronous binary counter with load, asynchronous reset, and ripple */
void test_74161(void)
    {   
        char i=0;
        sym[1]=1;
        sym[2]=6;
        sym[3]=1;
        Direct_L=(P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_P3 | P_ENP | P_GND);
        Direct_H=(P_nLOAD | P_ENT | P_VCC);
        Port_H=(P_nLOAD | P_VCC);
        Port_L=0;   //Clear
        delay_ms(1);
        Port_L=(P_CLK);   //CLK
        delay_ms(1);                
        res &= ((Pin_L==(P_CLK)) && (Pin_H==(P_nLOAD | P_VCC)));


        Port_L=(P_nRST);   //CLK   
        delay_ms(1);
        Port_L = (P_nRST | P_P0 | P_P1 | P_P2); //D=0,A=B=C=1, CLK = 0        
        Port_H=(P_VCC);   //Load
        delay_ms(1);
        Port_L = (P_nRST | P_CLK | P_P0 | P_P1 | P_P2); //D=0,A=B=C=1, CLK = 1
        delay_ms(1);
        Port_H=(P_nLOAD | P_ENT | P_VCC);  //ENT=1
        Port_L=(P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP);   //ENP=1
        delay_ms(1);        
        Port_L=(P_nRST | P_P0 | P_P1 | P_P2 | P_ENP);  //CLK
        delay_ms(1);
        res &= ((Pin_L==(P_nRST | P_P0 | P_P1 | P_P2 | P_ENP)) && (Pin_H==(P_nLOAD | P_ENT | P_Q2 | P_Q1 | P_Q0 | P_VCC)));

        Port_L = (P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP);
        delay_ms(1);
        res &= ((Pin_L==(P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP)) && (Pin_H==(P_nLOAD | P_ENT | P_Q3 | P_VCC)));

        Port_L = (P_nRST | P_P0 | P_P1 | P_P2 | P_ENP);    //CLK
        delay_ms(1);
        Port_L = (P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP);    //CLK
        delay_ms(1);
        res &= ((Pin_L==(P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP)) && (Pin_H==(P_nLOAD | P_ENT | P_Q3 | P_Q0 | P_VCC)));

           
        Port_L = (P_nRST | P_P0 | P_P1 | P_P2);    //CLK
        delay_ms(1);
        Port_L = (P_nRST | P_CLK | P_P0 | P_P1 | P_P2);    //CLK
        delay_ms(1);
        res &= ((Pin_L==(P_nRST | P_CLK | P_P0 | P_P1 | P_P2)) && (Pin_H==(P_nLOAD | P_ENT | P_Q3 | P_Q0 | P_VCC)));

        for (i= 0;i<6;i++) {
            Port_L = (P_nRST | P_P0 | P_P1 | P_P2 | P_ENP);    //CLK
            delay_ms(1);
            Port_L = (P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP);    //CLK
            delay_ms(1);
        }
        res &= ((Pin_L==(P_nRST | P_CLK | P_P0 | P_P1 | P_P2 | P_ENP)) && (Pin_H==(P_nLOAD | P_ENT | P_Q3 | P_Q2 | P_Q1 | P_Q0 | P_RCO | P_VCC)));

        Port_L=0;
        Port_H=0;                     
    }


#undef P_nRST
#undef P_CLK
#undef P_P0
#undef P_P1
#undef P_P2
#undef P_P3
#undef P_ENP
#undef P_GND
#undef P_nLOAD
#undef P_ENT
#undef P_Q3
#undef P_Q2
#undef P_Q1
#undef P_Q0
#undef P_RCO
#undef P_VCC
