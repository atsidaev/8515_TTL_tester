void test_7420(void)
    {   
        sym[1]=0;
        sym[2]=2;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=223;
        Direct_H=191;
        Port_L=32;
        Port_H=65;
        delay_ms(1);
        if ((Pin_L==32) && (Pin_H==65)) res=1;
            else res=0;
        Port_L=33;
        Port_H=67;
        if ((Pin_L==33) && (Pin_H==67) && (res==1)) res=1;
            else res=0; 
        Port_L=35;
        Port_H=71;
        if ((Pin_L==35) && (Pin_H==71) && (res==1)) res=1;
            else res=0;
        Port_L=43;
        Port_H=87;
        if ((Pin_L==43) && (Pin_H==87) && (res==1)) res=1;
            else res=0;  
        Port_L=59;
        Port_H=119;
        if ((Pin_L==27) && (Pin_H==55) && (res==1)) res=1;
            else res=0;          
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }