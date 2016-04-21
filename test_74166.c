void test_74166(void)
    {   
        sym[1]=6;
        sym[2]=6;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=247;
        Port_L=0;
        Port_H=1;
        Port_H=129;
        delay_ms(1);
        if ((Pin_L==0) && (Pin_H==129)) res=1;
            else res=0;
        Port_L=30;
        Port_H=209;
        Port_L=94;
        Port_L=30;
        Port_H=131;        
        Port_L=0;
        delay_ms(1);
        if ((Pin_L==0) && (Pin_H==131) && (res==1)) res=1;
            else res=0; 
        Port_L=64;
        Port_L=0;
        delay_ms(1);
        if ((Pin_H==139) && (res==1)) res=1;
            else res=0;
        Port_L=64;
        Port_L=0;
        if ((Pin_H==131) && (res==1)) res=1;
            else res=0;        
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }