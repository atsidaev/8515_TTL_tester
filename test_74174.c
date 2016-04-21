/* /RST Q0 D0 D1 Q1 D2 Q2 GND CLK Q3 D3 Q4 D4 D5 Q6 VCC */
/* 74174 6-bit D flip-flop with reset. */
void test_74174(void)
    {   
        sym[1]=4;
        sym[2]=7;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L5 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0);
        Port_H=(BIT_H0);
        Port_L=0;
        delay_ms(1);
        Port_L=(BIT_L0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0)) && (Pin_H==(BIT_H0))) res=1;
            else res=0;        
        Port_L=(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L5);
        Port_H=(BIT_H7 | BIT_H0);
        Port_H=(BIT_H0);
        Port_L=(BIT_L0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H0)) && (res==1)) res=1;
            else res=0;                   
        Port_H=(BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0);
        Port_H=(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0);
        Port_H=(BIT_H5 | BIT_H3 | BIT_H2 | BIT_H0);
        Port_H=(BIT_H0);
        if ((Pin_L==(BIT_L0)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L=0;
        delay_ms(1);
        Port_L=(BIT_L0);
        delay_ms(1);
        if ((Pin_L==(BIT_L0)) && (Pin_H==(BIT_H0)) && (res==1)) res=1;
            else res=0;                
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }
