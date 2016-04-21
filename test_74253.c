/* /1EN S1 1A3 1A2 1A1 1A0 1Y GND 2Y 2A0 2A1 2A2 2A3 S0 /2EN VCC */
/* 74253 8-to-2 line 3-state noninverting data selector/multiplexer. */

void test_74253(void)
    {   
        sym[1]=3;
        sym[2]=5;
        sym[3]=2;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L7);
        Direct_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0);
        Port_L=(BIT_L3 | BIT_L5);
        Port_H=(BIT_H5 | BIT_H3 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L3 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H5 | BIT_H3 | BIT_H0))) res=1;
            else res=0;
        Port_L=(BIT_L3 | BIT_L5);
        Port_H=(BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L3 | BIT_L5)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
            else res=0;             
        Port_L=(BIT_L1 | BIT_L3 | BIT_L5);
        Port_H=(BIT_H5 | BIT_H3 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L3 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H5 | BIT_H3 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L1 | BIT_L3 | BIT_L5);
        Port_H=(BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L3 | BIT_L5)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L2 | BIT_L4);
        Port_H=(BIT_H6 | BIT_H4 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L2 | BIT_L4)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H4 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L2 | BIT_L4);
        Port_H=(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
            else res=0; 
        Port_L=(BIT_L1 | BIT_L2 | BIT_L4);
        Port_H=(BIT_H6 | BIT_H4 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L2 | BIT_L4)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H4 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L1 | BIT_L2 | BIT_L4);
        Port_H=(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
            else res=0;             
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }
