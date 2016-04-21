void test_74374(void)
    {
        sym[1]=4;
        sym[2]=7;
        sym[3]=3;
        res=0;
        sym[0]=12;
        Direct_L=205;
        Direct_H=205;
        DDRE=2;
        Port_L=68;
        Port_H=69;
        PORTE=2;
        PORTE=0;
        Port_L=0;
        Port_H=1;
        if ((Pin_L==34) && (Pin_H==35)) res=1;
            else res=0;
        Port_L=136;
        Port_H=137;
        PORTE=2;
        PORTE=0;
        Port_L=0;
        Port_H=1;
        if ((Pin_L==16) && (Pin_H==17) && (PINE==5) && (res==1)) res=1;
            else res=0;    
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }