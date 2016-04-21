void test_74161(void)
    {   
        char i=0;
        sym[1]=1;
        sym[2]=6;
        sym[3]=1;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=193;
        Port_H=129;
        Port_L=0;   //Clear
        delay_ms(1);
        Port_L=2;   //CLK
        delay_ms(1);                
        if ((Pin_L==2) && (Pin_H==129)) res=1;
            else res=0;
/*            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}*/

        Port_L=1;   //CLK   
        delay_ms(1);
        Port_L = 29; //D=0,A=B=C=1, CLK = 0        
        Port_H=1;   //Load
        delay_ms(1);
        Port_L = 31; //D=0,A=B=C=1, CLK = 1
        delay_ms(1);
        Port_H=193;  //ENT=1
        Port_L=95;   //ENP=1
        delay_ms(1);        
        Port_L=93;  //CLK
        delay_ms(1);
        if ((Pin_L==93) && (Pin_H==221) && (res==1)) res=1;
            /*else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}*/
            else res=0;
        Port_L = 95;
        delay_ms(1);
        if ((Pin_L==95) && (Pin_H==225) && (res==1)) res=1;        
            /*else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}
              */

        
            else res=0;
        Port_L = 93;    //CLK
        delay_ms(1);
        Port_L = 95;    //CLK
        delay_ms(1);
        if ((Pin_L==95) && (Pin_H==229) && (res==1)) res=1;
/*            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}
  */            
        
           else res=0;
           
        Port_L = 29;    //CLK
        delay_ms(1);
        Port_L = 31;    //CLK
        delay_ms(1);
        if ((Pin_L==31) && (Pin_H==229) && (res==1)) res=1;
/*            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}
*/
            else res=0;
        for (i= 0;i<6;i++) {
            Port_L = 93;    //CLK
            delay_ms(1);
            Port_L = 95;    //CLK
            delay_ms(1);
        }
        if ((Pin_L==95) && (Pin_H==255) && (res==1)) res=1;
/*            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}*/
            else res=0;      

/*
//        for (char i= 0;i<3;i++) {
            Port_L = 29;    //CLK
            delay_ms(1);
            Port_L = 31;    //CLK
            delay_ms(1);
  //      }
        if ((Pin_L==31) && (Pin_H==233) && (res==1)) res=1;
            else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;}
//            else res=0;      
  */
                                    
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                     
    }
