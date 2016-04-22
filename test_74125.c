#define P_n1OE BIT_L0
#define P_1A BIT_L1
#define P_1Y BIT_L2
#define P_n2OE BIT_L3
#define P_2A BIT_L4
#define P_2Y BIT_L5
#define P_GND BIT_L6
#define P_3Y BIT_H6
#define P_3A BIT_H5
#define P_n3OE BIT_H4
#define P_4Y BIT_H3
#define P_4A BIT_H2
#define P_n4OE BIT_H1
#define P_VCC BIT_H0


/* n1OE 1A 1Y n2OE 2A 2Y GND 3Y 3A n3OE 4Y 4A n4OE VCC */
/* Quad 3-state noninverting buffer with active low enables.  */
void test_74125(void)
    {   
        sym[1]=5;
        sym[2]=2;
        sym[3]=1;
        res=1;
        sym[0]=12;
        Direct_L=(P_n1OE | P_1A | P_n2OE | P_2A | P_GND | BIT_L7);
        Direct_H=(BIT_H7 | P_3A | P_n3OE | P_4A | P_n4OE | P_VCC);
        Port_L=(P_1Y | P_2Y);
        Port_H=(P_3Y | P_4Y | P_VCC);
        delay_ms(1);
        res &= ((Pin_L==0) && (Pin_H==(P_VCC)));

        Port_L=(P_1A | P_1Y | P_2A | P_2Y);
        Port_H=(P_3Y | P_3A | P_4Y | P_4A | P_VCC);
        res &= ((Pin_L==(P_1A | P_1Y | P_2A | P_2Y)) && (Pin_H==(P_3Y | P_3A | P_4Y | P_4A | P_VCC)));

        Port_L=(P_n1OE | P_1Y | P_n2OE | P_2Y);
        Port_H=(P_3Y | P_n3OE | P_4Y | P_n4OE | P_VCC);
        res &= ((Pin_L==(P_n1OE | P_1Y | P_n2OE | P_2Y)) && (Pin_H==(P_3Y | P_n3OE | P_4Y | P_n4OE | P_VCC)));

        Port_L=(P_n1OE | P_1A | P_1Y | P_n2OE | P_2A | P_2Y);
        Port_H=(P_3Y | P_3A | P_n3OE | P_4Y | P_4A | P_n4OE | P_VCC);
        res &= ((Pin_L==(P_n1OE | P_1A | P_1Y | P_n2OE | P_2A | P_2Y)) && (Pin_H==(P_3Y | P_3A | P_n3OE | P_4Y | P_4A | P_n4OE | P_VCC)));

        Port_L=0;
        Port_H=0;                                        
    }


#undef P_n1OE
#undef P_1A
#undef P_1Y
#undef P_n2OE
#undef P_2A
#undef P_2Y
#undef P_GND
#undef P_3Y
#undef P_3A
#undef P_n3OE
#undef P_4Y
#undef P_4A
#undef P_n4OE
#undef P_VCC
