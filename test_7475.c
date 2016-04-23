#define P_n1Q1 BIT_L0
#define P_1D1 BIT_L1
#define P_1D2 BIT_L2
#define P_2LE BIT_L3
#define P_VCC BIT_L4
#define P_2D1 BIT_L5
#define P_2D2 BIT_L6
#define P_n2Q2 BIT_L7
#define P_2Q2 BIT_H7
#define P_2Q1 BIT_H6
#define P_n2Q1 BIT_H5
#define P_GND BIT_H4
#define P_1LE BIT_H3
#define P_n1Q2 BIT_H2
#define P_1Q2 BIT_H1
#define P_1Q1 BIT_H0


/* n1Q1 1D1 1D2 2LE VCC 2D1 2D2 n2Q2 2Q2 2Q1 n2Q1 GND 1LE n1Q2 1Q2 1Q1 */
/* Dual 2-bit transparent latches with complementary outputs. */
void test_7475(void)
    {   
        sym[1]=5;
        sym[2]=7;
        sym[3]=13;
        Direct_L=(P_1D1 | P_1D2 | P_2LE | P_VCC | P_2D1 | P_2D2);
        Direct_H=(P_GND | P_1LE);
        Port_L=(P_n1Q1 | P_VCC | P_n2Q2);
        Port_H=(P_2Q2 | P_2Q1 | P_n2Q1 | P_n1Q2 | P_1Q2 | P_1Q1);
        Port_L=(P_n1Q1 | P_2LE | P_VCC | P_n2Q2);
        Port_H=(P_2Q2 | P_2Q1 | P_n2Q1 | P_1LE | P_n1Q2 | P_1Q2 | P_1Q1);
        Port_L=(P_n1Q1 | P_VCC | P_n2Q2);
        Port_H=(P_2Q2 | P_2Q1 | P_n2Q1 | P_n1Q2 | P_1Q2 | P_1Q1);
        delay_ms(1);
        res &= ((Pin_L==(P_n1Q1 | P_VCC | P_n2Q2)) && (Pin_H==(P_n2Q1 | P_n1Q2)));

        Port_L=(P_n1Q1 | P_1D1 | P_1D2 | P_VCC | P_2D1 | P_2D2 | P_n2Q2);
        Port_H=(P_2Q2 | P_2Q1 | P_n2Q1 | P_n1Q2 | P_1Q2 | P_1Q1);
        Port_L=(P_n1Q1 | P_1D1 | P_1D2 | P_2LE | P_VCC | P_2D1 | P_2D2 | P_n2Q2);
        Port_H=(P_2Q2 | P_2Q1 | P_n2Q1 | P_1LE | P_n1Q2 | P_1Q2 | P_1Q1);
        Port_L=(P_n1Q1 | P_1D1 | P_1D2 | P_VCC | P_2D1 | P_2D2 | P_n2Q2);
        Port_H=(P_2Q2 | P_2Q1 | P_n2Q1 | P_n1Q2 | P_1Q2 | P_1Q1);
        res &= ((Pin_L==(P_1D1 | P_1D2 | P_VCC | P_2D1 | P_2D2)) && (Pin_H==(P_2Q2 | P_2Q1 | P_1Q2 | P_1Q1)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_n1Q1
#undef P_1D1
#undef P_1D2
#undef P_2LE
#undef P_VCC
#undef P_2D1
#undef P_2D2
#undef P_n2Q2
#undef P_2Q2
#undef P_2Q1
#undef P_n2Q1
#undef P_GND
#undef P_1LE
#undef P_n1Q2
#undef P_1Q2
#undef P_1Q1
