void test_7438(void)
    {   
        sym[1]=8;
        sym[2]=3;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=219;
        Direct_H=183;
        Port_L=36;
        Port_H=73;
        delay_ms(1);
        if ((Pin_L==36) && (Pin_H==73)) res=1;
            else res=0;
        Port_L=45;
        Port_H=91;
        if ((Pin_L==45) && (Pin_H==91) && (res==1)) res=1;
            else res=0; 
        Port_L=54;
        Port_H=109;
        if ((Pin_L==54) && (Pin_H==109) && (res==1)) res=1;
            else res=0;
        Port_L=63;
        Port_H=127;
        if ((Pin_L==27) && (Pin_H==55) && (res==1)) res=1;
            else res=0;        
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }