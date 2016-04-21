void test_7432(void)
    {   
        sym[1]=2;
        sym[2]=3;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=219;
        Direct_H=183;
        Port_L=128;
        Port_H=1;
        delay_ms(1);
        if ((Pin_L==128) && (Pin_H==1)) res=1;
            else res=0;
        Port_L=137;
        Port_H=19;
        if ((Pin_L==173) && (Pin_H==91) && (res==1)) res=1;
            else res=0; 
        Port_L=146;
        Port_H=37;
        if ((Pin_L==182) && (Pin_H==109) && (res==1)) res=1;
            else res=0;
        Port_L=155;
        Port_H=55;
        if ((Pin_L==191) && (Pin_H==127) && (res==1)) res=1;
            else res=0;         
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }
