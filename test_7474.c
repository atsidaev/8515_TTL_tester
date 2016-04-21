void test_7474(void)
    {   
        sym[1]=4;
        sym[2]=7;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=207;
        Direct_H=159;
        Port_L=8;
        Port_H=17;
        Port_L=9;
        Port_H=19;
        delay_ms(1);
        if ((Pin_L==41) && (Pin_H==83)) res=1;
            else res=0;
        Port_L=11;
        Port_H=23;
        Port_L=15;
        Port_H=31;
        Port_L=9;
        Port_H=19;
        if ((Pin_L==25) && (Pin_H==51) && (res==1)) res=1;
            else res=0;
        Port_L=13;
        Port_H=27;
        Port_L=9;
        Port_H=19;
        if ((Pin_L==41) && (Pin_H==83) && (res==1)) res=1;
            else res=0;    
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }