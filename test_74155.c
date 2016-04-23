#define P_1EN1 BIT_L0
#define P_n1EN2 BIT_L1
#define P_S1 BIT_L2
#define P_n1Y3 BIT_L3
#define P_n1Y2 BIT_L4
#define P_n1Y1 BIT_L5
#define P_n1Y0 BIT_L6
#define P_GND BIT_L7
#define P_n2Y0 BIT_H7
#define P_n2Y1 BIT_H6
#define P_n2Y2 BIT_H5
#define P_n2Y3 BIT_H4
#define P_S0 BIT_H3
#define P_n2EN2 BIT_H2
#define P_n2EN1 BIT_H1
#define P_VCC BIT_H0


/* 1EN1 n1EN2 S1 n1Y3 n1Y2 n1Y1 n1Y0 GND n2Y0 n2Y1 n2Y2 n2Y3 S0 n2EN2 n2EN1 VCC */
/* 2-of-8 inverting decoder/demultiplexer with separate enables. */
void test_74155(void)
    {   
        sym[1]=5;
        sym[2]=5;
        sym[3]=1;
        Direct_L=(P_1EN1 | P_n1EN2 | P_S1 | P_GND);
        Direct_H=(P_S0 | P_n2EN2 | P_n2EN1 | P_VCC);
        Port_L=(P_n1EN2);
        Port_H=(P_n2EN2 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_n1EN2 | P_n1Y3 | P_n1Y2 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y2 | P_n2Y3 | P_n2EN2 | P_VCC)));
        Port_L = 0;
        Port_H = (P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_n1Y3 | P_n1Y2 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y1 | P_n2Y2 | P_n2Y3 | P_VCC)));

        Port_L = 0;
        Port_H = (P_S0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_n1Y3 | P_n1Y2 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y2 | P_n2Y3 | P_S0 | P_VCC)));

        Port_L = (P_S1);
        Port_H = (P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_n1Y3 | P_n1Y2 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y3 | P_VCC)));

        Port_L = (P_S1);
        Port_H = (P_S0 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_S1 | P_n1Y3 | P_n1Y2 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y2 | P_S0 | P_VCC)));

        Port_L = (P_1EN1);
        Port_H = (P_n2EN1 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1EN1 | P_n1Y3 | P_n1Y2 | P_n1Y1)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y2 | P_n2Y3 | P_n2EN1 | P_VCC)));

        Port_H = (P_S0 | P_n2EN1 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1EN1 | P_n1Y3 | P_n1Y2 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y2 | P_n2Y3 | P_S0 | P_n2EN1 | P_VCC)));

        Port_L = (P_1EN1 | P_S1);
        Port_H = (P_n2EN1 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1EN1 | P_S1 | P_n1Y3 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y2 | P_n2Y3 | P_n2EN1 | P_VCC)));

        Port_H = (P_S0 | P_n2EN1 | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==(P_1EN1 | P_S1 | P_n1Y2 | P_n1Y1 | P_n1Y0)) && (Pin_H==(P_n2Y0 | P_n2Y1 | P_n2Y2 | P_n2Y3 | P_S0 | P_n2EN1 | P_VCC)));

        Port_L=0;
        Port_H=0;      
    }


#undef P_1EN1
#undef P_n1EN2
#undef P_S1
#undef P_n1Y3
#undef P_n1Y2
#undef P_n1Y1
#undef P_n1Y0
#undef P_GND
#undef P_n2Y0
#undef P_n2Y1
#undef P_n2Y2
#undef P_n2Y3
#undef P_S0
#undef P_n2EN2
#undef P_n2EN1
#undef P_VCC
