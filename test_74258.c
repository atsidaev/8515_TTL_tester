void test_74258(void)
    {   
        sym[1]=8;
        sym[2]=5;
        sym[3]=2;
        res=0;
        sym[0]=12;
        Direct_L=183;
        Direct_H=111;
        Port_L=72;
        Port_H=145;
        delay_ms(1);
        if ((Pin_L==72) && (Pin_H==145)) res=1;
            else res=0;
        Port_L=90;
        Port_H=181;
        delay_ms(1);
        if ((Pin_L==18) && (Pin_H==37) && (res==1)) res=1;
            else res=0;             
        Port_L=91;
        delay_ms(1);
        if ((Pin_L==91) && (Pin_H==181) && (res==1)) res=1;
            else res=0;    
        Port_L=109;
        Port_H=217;
        delay_ms(1);
        if ((Pin_L==37) && (Pin_H==73) && (res==1)) res=1;
            else res=0;
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }