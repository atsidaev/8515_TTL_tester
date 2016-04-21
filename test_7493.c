/* nCLK1 RST1 RST2 NC VCC NC NC Q2 Q1 GND Q3 Q0 NC nCLK0 */
/* 4-bit asynchronous binary counter with /2 and /8 sections and reset.  */
void test_7493(void)
    {   
        sym[1]=3;
        sym[2]=9;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H4 | BIT_H1 | BIT_H0);
        Port_H=0;        
        Port_L=(BIT_L1 | BIT_L2 | BIT_L4);
        Port_L=(BIT_L4);
        delay_ms(1);
        if (Pin_H==0) res=1;
            else res=0;
        Port_H=(BIT_H0);
        Port_H=0;
        delay_ms(1);       
        if ((Pin_H==(BIT_H2)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L4);
        Port_L=(BIT_L4);
        delay_ms(1);       
        if ((Pin_H==(BIT_H5 | BIT_H2)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L4);
        Port_L=(BIT_L4);
        delay_ms(1);
        if ((Pin_H==(BIT_H6 | BIT_H2)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L0 | BIT_L4);
        Port_L=(BIT_L4);
        Port_L=(BIT_L0 | BIT_L4);
        Port_L=(BIT_L4);
        delay_ms(1);    
        if ((Pin_H==(BIT_H3 | BIT_H2)) && (res==1)) res=1;
            else res=0;
        Port_L=(BIT_L1 | BIT_L2 | BIT_L4);
        Port_L=(BIT_L4);
        delay_ms(1);
        if ((Pin_H==0) && (res==1)) res=1;
            else res=0;               
        if (res==1) sym[0]=10;
            else sym[0]=11;  
        Port_L=0;
        Port_H=0;                                        
    }
