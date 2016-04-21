void test_7427(void)
    {   
        sym[1]=7;
        sym[2]=2;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=223;
        Direct_H=187;
        Port_L=0;
        Port_H=1;
        delay_ms(1);
        if ((Pin_L==32) && (Pin_H==69)) res=1;
            else res=0;
        Port_L=5;
        Port_H=33;
        if ((Pin_L==5) && (Pin_H==33) && (res==1)) res=1;
            else res=0; 
        Port_L=15;
        Port_H=49;                                                           
        if ((Pin_L==15) && (Pin_H==49) && (res==1)) res=1;
            else res=0;
        Port_L=31;
        Port_H=59;
        if ((Pin_L==31) && (Pin_H==59) && (res==1)) res=1;
            else res=0;        
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }