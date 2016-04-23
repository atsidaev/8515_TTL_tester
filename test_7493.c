#define P_nCLK1 BIT_L0
#define P_RST1 BIT_L1
#define P_RST2 BIT_L2
#define P_NC1 BIT_L3
#define P_VCC BIT_L4
#define P_NC2 BIT_L5
#define P_NC3 BIT_L6
#define P_Q2 BIT_H6
#define P_Q1 BIT_H5
#define P_GND BIT_H4
#define P_Q3 BIT_H3
#define P_Q0 BIT_H2
#define P_NC4 BIT_H1
#define P_nCLK0 BIT_H0


/* nCLK1 RST1 RST2 NC VCC NC NC Q2 Q1 GND Q3 Q0 NC nCLK0 */
/* 4-bit asynchronous binary counter with /2 and /8 sections and reset.  */
void test_7493(void)
    {   
        Direct_L=(P_nCLK1 | P_RST1 | P_RST2 | P_NC1 | P_VCC | P_NC2 | P_NC3 | BIT_L7);
        Direct_H=(BIT_H7 | P_GND | P_NC4 | P_nCLK0);
        Port_H=0;        
        Port_L=(P_RST1 | P_RST2 | P_VCC);
        Port_L=(P_VCC);
        delay_ms(1);
        res &= (Pin_H==0);

        Port_H=(P_nCLK0);
        Port_H=0;
        delay_ms(1);       
        res &= ((Pin_H==(P_Q0)));

        Port_L=(P_nCLK1 | P_VCC);
        Port_L=(P_VCC);
        delay_ms(1);       
        res &= ((Pin_H==(P_Q1 | P_Q0)));

        Port_L=(P_nCLK1 | P_VCC);
        Port_L=(P_VCC);
        delay_ms(1);
        res &= ((Pin_H==(P_Q2 | P_Q0)));

        Port_L=(P_nCLK1 | P_VCC);
        Port_L=(P_VCC);
        Port_L=(P_nCLK1 | P_VCC);
        Port_L=(P_VCC);
        delay_ms(1);    
        res &= ((Pin_H==(P_Q3 | P_Q0)));

        Port_L=(P_RST1 | P_RST2 | P_VCC);
        Port_L=(P_VCC);
        delay_ms(1);
        res &= ((Pin_H==0));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_nCLK1
#undef P_RST1
#undef P_RST2
#undef P_NC1
#undef P_VCC
#undef P_NC2
#undef P_NC3
#undef P_Q2
#undef P_Q1
#undef P_GND
#undef P_Q3
#undef P_Q0
#undef P_NC4
#undef P_nCLK0
