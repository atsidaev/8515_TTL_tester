void test_C4520(void)
    {   
        char i=0;
        sym[1]=0;
        sym[2]=2;
        sym[3]=17;
        res=0;
        sym[0]=12;
        Direct_L=195;
        Direct_H=195;
        Port_L=64;
        Port_H=3;
        Port_L=0;
        Port_H=1;
        delay_ms(1);
        if ((Pin_L==0) && (Pin_H==1)) res=1;
            else res=0;
        Port_L=2;
        Port_H=65;
        Port_L=3;
        Port_H=193;
        Port_L=2;
        Port_H=65;
        delay_ms(1);
        if ((Pin_L==6) && (Pin_H==97) && (res==1)) res=1;
            else res=0;           
        Port_L=2;
        Port_H=65;
        Port_L=3;
        Port_H=193;
        Port_L=2;
        Port_H=65;
        delay_ms(1);
        if ((Pin_L==10) && (Pin_H==81) && (res==1)) res=1;
            else res=0;
        for (i=0;i<10;i++){    
        Port_L=2;
        Port_H=65;
        Port_L=0;
        Port_H=1; }
        delay_ms(1);
        if ((Pin_L==48) && (Pin_H==13) && (res==1)) res=1;
            else res=0;                  
        if (res==1) sym[0]=10;
            else sym[0]=11; 
        Port_L=0;
        Port_H=0;            
    }