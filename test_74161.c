/* /RST CLK P0 P1 P2 P3 ENP GND /LOAD ENT Q3 Q2 Q1 Q0 RCO VCC */
/* 74161 4-bit synchronous binary counter with load, asynchronous reset, and ripple */
void test_74161(void)
    {   
        char i=0;
        sym[1]=1;
        sym[2]=6;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6 | BIT_L7);
        Direct_H=(BIT_H7 | BIT_H6 | BIT_H0);
        Port_H=(BIT_H7 | BIT_H0);
        Port_L=0;   //Clear
        delay_ms(1);
        Port_L=(BIT_L1);   //CLK
        delay_ms(1);                
        if ((Pin_L==(BIT_L1)) && (Pin_H==(BIT_H7 | BIT_H0))) res=1;
            else res=0;

        Port_L=(BIT_L0);   //CLK   
        delay_ms(1);
        Port_L = (BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4); //D=0,A=B=C=1, CLK = 0        
        Port_H=(BIT_H0);   //Load
        delay_ms(1);
        Port_L = (BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4); //D=0,A=B=C=1, CLK = 1
        delay_ms(1);
        Port_H=(BIT_H7 | BIT_H6 | BIT_H0);  //ENT=1
        Port_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);   //ENP=1
        delay_ms(1);        
        Port_L=(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);  //CLK
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        Port_L = (BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H0)) && (res==1)) res=1;        
            else res=0;
        Port_L = (BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);    //CLK
        delay_ms(1);
        Port_L = (BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);    //CLK
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
           else res=0;
           
        Port_L = (BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4);    //CLK
        delay_ms(1);
        Port_L = (BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4);    //CLK
        delay_ms(1);
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H2 | BIT_H0)) && (res==1)) res=1;
            else res=0;
        for (i= 0;i<6;i++) {
            Port_L = (BIT_L0 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);    //CLK
            delay_ms(1);
            Port_L = (BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6);    //CLK
            delay_ms(1);
        }
        if ((Pin_L==(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0)) && (res==1)) res=1;
            else res=0;      
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                     
    }
