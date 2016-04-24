void test_74452(void)
    {   
        sym[1]=2;
        sym[2]=5;
        sym[3]=4;
        res=0;
        sym[0]=12;
        Direct_L=11;
        Direct_H=7;
        Port_L=244;
        Port_H=249;
        delay_ms(1);
        if ((Pin_L==244) && (Pin_H==249)) res=1;
            else res=0;
        Port_L=245;
        Port_H=251;
        if ((Pin_L==245) && (Pin_H==251) && (res==1)) res=1;
            else res=0; 
        Port_L=246;
        Port_H=253;
        if ((Pin_L==246) && (Pin_H==253) && (res==1)) res=1;
            else res=0;
        Port_L=247;
        Port_H=255;
        if ((Pin_L==243) && (Pin_H==247) && (res==1)) res=1;
            else res=0;        
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }