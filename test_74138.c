/* S0 S1 S2 nEN3 nEN2 EN1 nY7 GND nY6 nY5 nY4 nY3 nY2 nY1 nY0 VCC */
/* 1-of-8 inverting decoder/demultiplexer.  */
void test_74138(void)
    {   
        sym[1]=8;
        sym[2]=3;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L7);
        Direct_H=(BIT_H0);
        Port_L=(BIT_L5);
        Port_H=(BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H0))) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L5);
        Port_H=(BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L1 | BIT_L5);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L1 | BIT_L5);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L2 | BIT_L5);
        delay_ms(1);
        if ((Pin_L==(BIT_L2 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L2 | BIT_L5);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L1 | BIT_L2 | BIT_L5);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L2 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0; 
        Port_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L5);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L5)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;                               
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }
