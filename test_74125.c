void test_74125(void)
    {   
        sym[1]=5;
        sym[2]=2;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=219;
        Direct_H=183;
        Port_L=128;
        Port_H=1;
        delay_ms(1);
        if ((Pin_L==128) && (Pin_H==1)) res=1;
            else res=0;
        Port_L=45+128;
        Port_H=91;
        if ((Pin_L==45+128) && (Pin_H==91) && (res==1)) res=1;
            else res=0;
        Port_L=9+128;
        Port_H=19;
        if ((Pin_L==45+128) && (Pin_H==91) && (res==1)) res=1;
/*            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;} 
  */
            else res=0;            
        Port_L=54+128;
        Port_H=109;
        if ((Pin_L==54+128) && (Pin_H==109) && (res==1)) res=1;
            else res=0;
        Port_L=63+128;
        Port_H=127;
        if ((Pin_L==63+128) && (Pin_H==127) && (res==1)) res=1;
            else res=0;         
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }