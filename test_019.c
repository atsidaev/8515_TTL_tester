void test_019(void)
    {
        char n=0;
        sym[1]=9;
        sym[2]=1;
        sym[3]=12;
        res=0;
        sym[0]=12;
        Direct_L=195;
        Direct_H=135;
        Port_L=62;
        Port_H=125;
        Port_L=60;
        Port_H=121; 
        delay_ms(1);       
        if ((Pin_L==0) && (Pin_H==1)) res=1;
            else res=0;            
        Port_L=61;
        Port_L=60;
        Port_H=123;
        Port_H=121;
        delay_ms(1);
        if ((Pin_L==4) && (Pin_H==9) && (res==1)) res=1;
            else res=0;
        for (n=0;n<14;n++) {    
            Port_L=61;
            Port_L=60;
            Port_H=123;
            Port_H=121;}
        delay_ms(1);
        if ((Pin_L==60) && (Pin_H==121) && (res==1)) res=1;
            else res=0;       
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;            
    }