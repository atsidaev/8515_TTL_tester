void test_7430(void)
    {   
        sym[1]=0;
        sym[2]=3;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=191;
        Port_L=0;
        Port_H=115;
        delay_ms(1);
        if ((Pin_L==0) && (Pin_H==115)) res=1;
            else res=0;
        Port_L=21;
        Port_H=119;
        if ((Pin_L==21) && (Pin_H==119) && (res==1)) res=1;
            else res=0; 
        Port_L=42;
        Port_H=123;
        if ((Pin_L==42) && (Pin_H==123) && (res==1)) res=1;
            else res=0;
        Port_L=63;
        Port_H=127;
        if ((Pin_L==63) && (Pin_H==63) && (res==1)) res=1;
            else res=0;       
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }