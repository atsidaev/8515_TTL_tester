/* 1EN1 n1EN2 S1 n1Y3 n1Y2 n1Y1 n1Y0 GND n2Y0 n2Y1 n2Y2 n2Y3 S0 n2EN2 n2EN1 VCC */
/* 2-of-8 inverting decoder/demultiplexer with separate enables. */
void test_74155(void)
    {   
        sym[1]=5;
        sym[2]=5;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L7);
        Direct_H=(BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0);
        Port_L=(BIT_L1);
        Port_H=(BIT_H2 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H2 | BIT_H0))) res=1;
        Port_L = 0;
        Port_H = (BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L = 0;
        Port_H = (BIT_H3 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L = (BIT_L2);
        Port_H = (BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H4 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L = (BIT_L2);
        Port_H = (BIT_H3 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H3 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L = (BIT_L0);
        Port_H = (BIT_H1 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L3 | BIT_L4 | BIT_L5)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_H = (BIT_H3 | BIT_H1 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L3 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L = (BIT_L0 | BIT_L2);
        Port_H = (BIT_H1 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_H = (BIT_H3 | BIT_H1 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L4 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;      
    }
