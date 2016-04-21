/* /RST Q1 /Q1 D1 D2 /Q2 Q2 GND CLK Q3 /Q3 D3 D4 /Q4 Q4 VCC */
/* 74175 4-bit D flip-flop with complementary outputs and reset. */

void test_74175(void)
    {
        sym[1]=5;
        sym[2]=7;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L3 | BIT_L4 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H4 | BIT_H3 | BIT_H0);    
        Port_H=(BIT_H0);
        Port_L=0;
        delay_ms(1);
        Port_L=(BIT_L0);
        delay_ms(1);
        if ( ( Pin_L == (BIT_L0 | BIT_L2 | BIT_L5)) && ( Pin_H  == (BIT_H5 | BIT_H2 | BIT_H0)) ) res = 1;
        Port_L = (BIT_L0 | BIT_L3);
        Port_H = (BIT_H3 | BIT_H0);
        Port_H = (BIT_H7 | BIT_H3 | BIT_H0);
        Port_H = (BIT_H0);
        delay_ms(1);        
        if ((Pin_L == (BIT_L0 | BIT_L1 | BIT_L3 | BIT_L5)) && (Pin_H == (BIT_H5 | BIT_H1 | BIT_H0)) && res == 1)  res = 1;
            else res = 0;
        Port_L = (BIT_L0 | BIT_L4);
        Port_H = (BIT_H4 | BIT_H0);
        Port_H = (BIT_H7 | BIT_H4 | BIT_H0);    
        Port_H = (BIT_H0);
        delay_ms(1);        
        if ((Pin_L == (BIT_L0 | BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H == (BIT_H6 | BIT_H2 | BIT_H0)) && res == 1)  res = 1;
            else res = 0;                    
        Port_L = (BIT_L0);
        Port_H = (BIT_H0);
        Port_H = (BIT_H7 | BIT_H0);    
        Port_H = (BIT_H0);
        delay_ms(1);
        if ((Pin_L == (BIT_L0 | BIT_L2 | BIT_L5)) && (Pin_H == (BIT_H5 | BIT_H2 | BIT_H0)) && res == 1)  res = 1;
            else res = 0;             
        Port_L = (BIT_L0 | BIT_L3 | BIT_L4);
        Port_H = (BIT_H4 | BIT_H3 | BIT_H0);
        Port_H = (BIT_H7 | BIT_H4 | BIT_H3 | BIT_H0);    
        Port_H = (BIT_H4 | BIT_H3 | BIT_H0);
        delay_ms(1);
        if ((Pin_L == (BIT_L0 | BIT_L1 | BIT_L3 | BIT_L4 | BIT_L6)) && (Pin_H == (BIT_H6 | BIT_H4 | BIT_H3 | BIT_H1 | BIT_H0)) && res == 1)  res = 1;
            else res = 0;
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L = 0;
        Port_H = 0;
    }
