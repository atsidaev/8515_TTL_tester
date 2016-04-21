/* /1OE 1A1 2Y4 1A2 2Y3 1A3 2Y2 1A4 2Y1 GND 2A1 1Y4 2A2 1Y3 2A3 1Y2 2A4 1Y1 /2OE VCC */
/* 74244 Dual 4-bit 3-state noninverting buffer/line driver. */ 
void test_74244(void)
    {
        sym[1]=4;
        sym[2]=4;
        sym[3]=2;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H1 | BIT_H0);
        DDRE=2;
        Port_L=(BIT_L1 | BIT_L5);
        Port_H=(BIT_H7 | BIT_H3 | BIT_H0);
        PORTE=0;
        if ((Pin_L==(BIT_L1 | BIT_L2 | BIT_L5 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H3 | BIT_H2 | BIT_H0)) && (PINE==0)) res=1;
            else res=0;
        Port_L=(BIT_L3 | BIT_L7);
        Port_H=(BIT_H5 | BIT_H0);
        PORTE=2;
        if ((Pin_L==(BIT_L3 | BIT_L4 | BIT_L7)) && (Pin_H==(BIT_H5 | BIT_H4 | BIT_H0)) && (PINE==7) && (res==1)) res=1;
            else res=0;    
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }
