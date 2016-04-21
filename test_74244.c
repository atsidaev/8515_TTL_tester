void test_74244(void)
    {
        sym[1]=4;
        sym[2]=4;
        sym[3]=2;
        res=0;
        sym[0]=12;
        Direct_L=171;
        Direct_H=171;
        DDRE=2;
        Port_L=34;
        Port_H=137;
        PORTE=0;
        if ((Pin_L==102) && (Pin_H==205) && (PINE==0)) res=1;
            else res=0;
        Port_L=136;
        Port_H=33;
        PORTE=2;
        if ((Pin_L==152) && (Pin_H==49) && (PINE==7) && (res==1)) res=1;
            else res=0;    
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }