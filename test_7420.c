/* 1A 1B NC 1C 1D n1Y GND n2Y 2A 2B NC 2C 2D VCC */
void test_7420(void)
    {   
        sym[1]=0;
        sym[2]=2;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0);
        Port_L=(BIT_L5);
        Port_H=(BIT_H6 | BIT_H0);
        delay_ms(1);
        if ((Pin_L==(BIT_L5)) && (Pin_H==(BIT_H6 | BIT_H0))) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H1 | BIT_H0);
        if ((Pin_L==(BIT_L0 | BIT_L5)) && (Pin_H==(BIT_H6 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0; 
        Port_L=(BIT_L0 | BIT_L1 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H2 | BIT_H1 | BIT_H0);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L5)) && (Pin_H==(BIT_H6 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H1 | BIT_H0);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L5)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;  
        Port_L=(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L4 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H2 | BIT_H1 | BIT_H0);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L3 | BIT_L4)) && (Pin_H==(BIT_H5 | BIT_H4 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;          
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }
