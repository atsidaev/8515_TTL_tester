void test_7475(void)
    {   
        sym[1]=5;
        sym[2]=7;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=126;
        Direct_H=24;
        Port_L=145;
        Port_H=231;
        Port_L=153;
        Port_H=239;
        Port_L=145;
        Port_H=231;
        delay_ms(1);
        if ((Pin_L==145) && (Pin_H==36)) res=1;
            else res=0;
        Port_L=247;
        Port_H=231;
        Port_L=255;
        Port_H=239;
        Port_L=247;
        Port_H=231;
        if ((Pin_L==118) && (Pin_H==195) && (res==1)) res=1;
            else res=0;   
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }