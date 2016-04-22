#define P_1A BIT_L0
#define P_1B BIT_L1
#define P_1Y BIT_L2
#define P_2A BIT_L3
#define P_2B BIT_L4
#define P_2Y BIT_L5
#define P_GND BIT_L6
#define P_3Y BIT_H6
#define P_3A BIT_H5
#define P_3B BIT_H4
#define P_4Y BIT_H3
#define P_4A BIT_H2
#define P_4B BIT_H1
#define P_VCC BIT_H0


/* 1A 1B 1Y 2A 2B 2Y GND 3Y 3A 3B 4Y 4A 4B VCC */
void test_7402(void)
    {   
        sym[1]=2;
        sym[2]=0;
        sym[3]=13;
        res=1;
        sym[0]=12;
        Direct_L=(P_1B | P_1Y | P_2B | P_2Y | P_GND | BIT_L7);
        Direct_H=(BIT_H7 | P_3Y | P_3A | P_4Y | P_4A | P_VCC);
        Port_L=0;
        Port_H=(P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1A | P_2A)) && (Pin_H==(P_3B | P_4B | P_VCC)));

        Port_L=(P_1Y | P_2Y);
        Port_H=(P_3Y | P_4Y | P_VCC);
        res &= ((Pin_L==(P_1Y | P_2Y)) && (Pin_H==(P_3Y | P_4Y | P_VCC)));

        Port_L=(P_1B | P_2B);
        Port_H=(P_3A | P_4A | P_VCC);
        res &= ((Pin_L==(P_1B | P_2B)) && (Pin_H==(P_3A | P_4A | P_VCC)));

        Port_L=(P_1B | P_1Y | P_2B | P_2Y);
        Port_H=(P_3Y | P_3A | P_4Y | P_4A | P_VCC);
        res &= ((Pin_L==(P_1B | P_1Y | P_2B | P_2Y)) && (Pin_H==(P_3Y | P_3A | P_4Y | P_4A | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_1A
#undef P_1B
#undef P_1Y
#undef P_2A
#undef P_2B
#undef P_2Y
#undef P_GND
#undef P_3Y
#undef P_3A
#undef P_3B
#undef P_4Y
#undef P_4A
#undef P_4B
#undef P_VCC
