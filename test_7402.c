void test_7402(void)
    {   
        sym[1]=2;
        sym[2]=0;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=246;
        Direct_H=237;
        Port_L=0;
        Port_H=1;
        delay_ms(1);
        if ((Pin_L==9) && (Pin_H==19)) res=1;
            else res=0;
        Port_L=36;
        Port_H=73;
        if ((Pin_L==36) && (Pin_H==73) && (res==1)) res=1;
            else res=0; 
        Port_L=18;
        Port_H=37;
        if ((Pin_L==18) && (Pin_H==37) && (res==1)) res=1;
            else res=0;
        Port_L=54;
        Port_H=109;
        if ((Pin_L==54) && (Pin_H==109) && (res==1)) res=1;
            else res=0;        
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }