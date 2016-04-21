/* DIR A1 A2 A3 A4 A5 A6 A7 A8 GND B8 B7 B6 B5 B4 B3 B2 B1 /EN VCC */
/* 74245 8-bit 3-state noninverting bus transceiver. */
void test_74245(void)
    {
        sym[1]=5;
        sym[2]=4;
        sym[3]=2;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6 | BIT_L7);
        Direct_H=(BIT_H1 | BIT_H0);
        DDRE=1;
        Port_L=(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7);
        Port_H=(BIT_H0);
        PORTE=0;
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0)) && (PINE==4)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L2 | BIT_L4 | BIT_L6);
        Port_H=(BIT_H0);
        PORTE=1;
        if ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H0)) && (PINE==3) && (res==1)) res=1;
            else res=0;            
        Direct_L=(BIT_L0);
        Direct_H=(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0);
        DDRE=6;
        Port_L=0;
        Port_H=(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0);
        PORTE=4;
        delay_ms(1);
        if ((Pin_L==(BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0)) && (PINE==4)) res=1;
            else res=0;
        Port_L=0;
        Port_H=(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H0);
        PORTE=2;
        delay_ms(1);
        if ((Pin_L==(BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H0)) && (PINE==3) && (res==1)) res=1;
            else res=0;    
        if (res==1) sym[0]=10;
            else sym[0]=11;   
        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }
