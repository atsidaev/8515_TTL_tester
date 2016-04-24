void test_7492(void)
    {   
        sym[1]=2;
        sym[2]=9;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=147;
        Port_H=0;        
        Port_L=112;        
        Port_L=16;
        if (Pin_H==0) res=1;
            else res=0;
               
        if (res==1) sym[0]=10;
            else sym[0]=11;  
        Port_L=0;
        Port_H=0;                                        
    }