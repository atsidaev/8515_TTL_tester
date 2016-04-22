#define P_n1OE BIT_L0
#define P_1A1 BIT_L1
#define P_2Y4 BIT_L2
#define P_1A2 BIT_L3
#define P_2Y3 BIT_L4
#define P_1A3 BIT_L5
#define P_2Y2 BIT_L6
#define P_1A4 BIT_L7
#define P_2Y1 BIT_L8
#define P_GND BIT_L9
#define P_2A1 BIT_H9
#define P_1Y4 BIT_H8
#define P_2A2 BIT_H7
#define P_1Y3 BIT_H6
#define P_2A3 BIT_H5
#define P_1Y2 BIT_H4
#define P_2A4 BIT_H3
#define P_1Y1 BIT_H2
#define P_n2OE BIT_H1
#define P_VCC BIT_H0


/* /1OE 1A1 2Y4 1A2 2Y3 1A3 2Y2 1A4 2Y1 GND 2A1 1Y4 2A2 1Y3 2A3 1Y2 2A4 1Y1 /2OE VCC */
/* 74244 Dual 4-bit 3-state noninverting buffer/line driver. */ 
void test_74244(void)
    {
        sym[1]=4;
        sym[2]=4;
        sym[3]=2;
        res=1;
        sym[0]=12;
        Direct_L=(P_n1OE | P_1A1 | P_1A2 | P_1A3 | P_1A4);
        Direct_H=(P_2A2 | P_2A3 | P_2A4 | P_n2OE | P_VCC);
        DDRE=2;
        Port_L=(P_1A1 | P_1A3);
        Port_H=(P_2A2 | P_2A4 | P_VCC);
        PORTE=0;
        res &= ((Pin_L==(P_1A1 | P_2Y4 | P_1A3 | P_2Y2)) && (Pin_H==(P_2A2 | P_1Y3 | P_2A4 | P_1Y1 | P_VCC)) && (PINE==0));

        Port_L=(P_1A2 | P_1A4);
        Port_H=(P_2A3 | P_VCC);
        PORTE=2;
        res &= ((Pin_L==(P_1A2 | P_2Y3 | P_1A4)) && (Pin_H==(P_2A3 | P_1Y2 | P_VCC)) && (PINE==7));

        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }


#undef P_n1OE
#undef P_1A1
#undef P_2Y4
#undef P_1A2
#undef P_2Y3
#undef P_1A3
#undef P_2Y2
#undef P_1A4
#undef P_2Y1
#undef P_GND
#undef P_2A1
#undef P_1Y4
#undef P_2A2
#undef P_1Y3
#undef P_2A3
#undef P_1Y2
#undef P_2A4
#undef P_1Y1
#undef P_n2OE
#undef P_VCC
