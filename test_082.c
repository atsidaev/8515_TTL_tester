void test_082(void)
    {
        sym[1]=2;
        sym[2]=8;
        sym[3]=12;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=1;
        DDRE=3;
        PORTE=2;
        Port_L=85;
        Port_H=1;
        delay_ms(1);       
        if ((Pin_L==85) && (Pin_H==171) && (PINE==2)) res=1;
            else res=0;            
        Port_L=170;
        delay_ms(1);
        if ((Pin_L==170) && (Pin_H==85) && (PINE==6) && (res==1)) res=1;
            else res=0;
        PORTE=0;
        Port_L=0;
        delay_ms(1);
        if ((Pin_L==0) && (Pin_H==85) && (PINE==4) && (res==1)) res=1;
            else res=0;        
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;
        PORTE=0;            
    }