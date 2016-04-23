void test_019(void)
    {
        char n=0;
        sym[1]=9;
        sym[2]=1;
        sym[3]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L6 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H2 | BIT_H1 | BIT_H0);
        Port_L=(BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H0);
        Port_L=(BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H0); 
        delay_ms(1);       
        res &= ((Pin_L==0) && (Pin_H==(BIT_H0)));

        Port_L=(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5);
        Port_L=(BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5);
        Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H1 | BIT_H0);
        Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H0);
        delay_ms(1);
        res &= ((Pin_L==(BIT_L2)) && (Pin_H==(BIT_H3 | BIT_H0)));

        for (n=0;n<14;n++) {    
            Port_L=(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5);
            Port_L=(BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5);
            Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H1 | BIT_H0);
            Port_H=(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H0);}
        delay_ms(1);
        res &= ((Pin_L==(BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5)) && (Pin_H==(BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H0)));

        Port_L=0;
        Port_H=0;            
    }