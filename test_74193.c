#define P_P1 BIT_L0
#define P_Q1 BIT_L1
#define P_Q0 BIT_L2
#define P_DOWN BIT_L3
#define P_UP BIT_L4
#define P_Q2 BIT_L5
#define P_Q3 BIT_L6
#define P_GND BIT_L7
#define P_P3 BIT_H7
#define P_P2 BIT_H6
#define P_nLOAD BIT_H5
#define P_nCARRY BIT_H4
#define P_nBORROW BIT_H3
#define P_RST BIT_H2
#define P_P0 BIT_H1
#define P_VCC BIT_H0


/* P1 Q1 Q0 DOWN UP Q2 Q3 GND P3 P2 /LOAD /CARRY /BORROW RST P0 VCC */
/* 74193 4-bit synchronous binary up/down counter with asynchronous load and reset, and separate up and down clocks. Carry and borrow outputs. */

void test_74193(void)
    {   
        sym[1]=3;
        sym[2]=9;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(P_P1 | P_DOWN | P_UP | P_GND);
        Direct_H=(P_P3 | P_P2 | P_nLOAD | P_RST | P_P0 | P_VCC);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        Port_H=(P_P3 | P_P2 | P_nLOAD | P_P0 | P_VCC);
        Port_H=(P_P3 | P_P2 | P_nLOAD | P_RST | P_P0 | P_VCC);
        Port_H=(P_P3 | P_P2 | P_nLOAD | P_P0 | P_VCC);
        delay_ms(1);
        if (Pin_L==(P_P1 | P_DOWN)) res=1;
            else res=0;
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        delay_ms(1);       
        if ((Pin_L==(P_P1 | P_Q0 | P_DOWN)) && (res==1)) res=1;
            else res=0;
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        delay_ms(1);       
        if ((Pin_L==(P_P1 | P_Q1 | P_DOWN)) && (res==1)) res=1;
            else res=0;
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        if ((Pin_L==(P_P1 | P_DOWN | P_Q2)) && (res==1)) res=1;
            else res=0;
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_UP | P_Q2 | P_Q3);
        Port_L=(P_P1 | P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);    
        if ((Pin_L==(P_P1 | P_DOWN | P_Q3)) && (res==1)) res=1;
            else res=0;
        Port_H=(P_P2 | P_nLOAD | P_VCC);
        Port_H=(P_P2 | P_VCC);
        Port_H=(P_P2 | P_nLOAD | P_VCC);
        if ((Pin_L==(P_P1 | P_Q1 | P_DOWN | P_Q2)) && (res==1)) res=1;
            else res=0;
        Port_L=(P_Q1 | P_Q0 | P_DOWN | P_Q2 | P_Q3);    
        Port_H=(P_P3 | P_nLOAD | P_P0 | P_VCC);
        Port_H=(P_P3 | P_P0 | P_VCC);
        Port_H=(P_P3 | P_nLOAD | P_P0 | P_VCC);
        if ((Pin_L==(P_Q0 | P_DOWN | P_Q3)) && (res==1)) res=1;
            else res=0;                  
        if (res==1) sym[0]=10;
            else sym[0]=11;  
        Port_L=0;
        Port_H=0;                                        
    }


#undef P_P1
#undef P_Q1
#undef P_Q0
#undef P_DOWN
#undef P_UP
#undef P_Q2
#undef P_Q3
#undef P_GND
#undef P_P3
#undef P_P2
#undef P_nLOAD
#undef P_nCARRY
#undef P_nBORROW
#undef P_RST
#undef P_P0
#undef P_VCC
