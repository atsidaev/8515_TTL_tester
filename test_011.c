void test_011(void)
    {
        sym[1]=1;
        sym[2]=1;
        sym[3]=12;
        res=0;
        sym[0]=12;
        Direct_L=171;
        Direct_H=87;
        Port_L=84;
        Port_H=169; 
        delay_ms(1);       
        if ((Pin_L==0) && (Pin_H==1)) res=1;
            else res=0;            
        Port_L=118;
        Port_H=185;
        delay_ms(1);
        if ((Pin_L==102) && (Pin_H==49) && (res==1)) res=1;
            else res=0;
        Port_L=126;
        Port_H=253;
        delay_ms(1); 
        if ((Pin_L==126) && (Pin_H==253) && (res==1)) res=1;
            else res=0;      
        if (res==1) sym[0]=10;
            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}
            
            //else sym[0]=11;
        Port_L=0;
        Port_H=0;            
    }