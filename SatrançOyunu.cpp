#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define true 1
#define false 0


char table1[8][8]= {
                        {'W','W','W','W','W','W','W','W'},
                        {'W','W','W','W','W','W','W','W'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'B','B','B','B','B','B','B','B'},
                        {'B','B','B','B','B','B','B','B'},
                           
                      };

char table[8][8]= {
                        {'R','N','D','Q','K','D','N','R'},
                        {'P','P','P','P','P','P','P','P'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'P','P','P','P','P','P','P','P'},
                        {'R','N','D','Q','K','D','N','R'},
                           
                      };
                      
void gotoxy3(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void draw_table(int j){
    printf("Chess Board:(t=%d)\n",j);
    printf("\n");
	
	int m=8;
    for(int satir = 0;satir<8;satir++){
        for(int i = 0;i<8;i++){
            char tas = table[satir][i];
            if(i == 0 ){
               
                printf("%d   %c  ",m,tas);
                m-=1;
            }else if(i == 7){
                printf(" %c  ",tas);
            }else{
                printf(" %c  ",tas);
            }
        }
        
        printf("\n");

        
        printf("\n");
 
    }
    printf("    A   B   C   D   E   F   G   H   \n");
    

}


int clearscreen()

{
    system("cls");
    return 0;
}


void update_pieces()
{
    int i,j;
        
	for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            gotoxy3((6+(4*j)),(3+(2*i)));
            
            if (table[i][j] == '0')
                printf("%c", ' ');
            
            else
            
            printf("%c", table1[i][j]);
                
        }
    
    }   
    
    gotoxy3(1,28);
}


bool W_check_your_own_pieces(char destination)

{
        if    (destination !='p'&& destination !='n'&&  destination !='d'&&  destination !='r'&& destination !='k' && destination != 'q') return true;

    return false;
}


bool B_check_your_own_pieces(char destination)

{
    if    (destination !='P'&& destination !='N' && destination !='D'&& destination !='R'&& destination !='K' && destination != 'Q') return true;

    return false;
    
}


int check_table(char* command, int j)

{

char X1,Y1,X2,Y2, test, destination;
    
    

    X1 = (command [0]-97);
    Y1 = (56-command [1]);
    X2 = (command [2]-97);
    Y2 = (56-command [3]);

    test = table[Y1][X1];             
    destination = table[Y2][X2];
    
    bool space= true;
    int i;

if (j %2 ==0)

{

        switch(test)
        {
        
        case 'P':
                if ( W_check_your_own_pieces(destination) &&  ( (X2-X1 == 0 && Y2-Y1==1)  |  (Y1==1 && Y2-Y1==2 && X2-X1 == 0) ) && destination == '0')
                    {
                            
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='P';
                    update_pieces();
                    }
                else if (W_check_your_own_pieces(destination) && !B_check_your_own_pieces(destination) && ((X2-X1== -1| X2-X1==1 )&& Y2-Y1==1 ))   
                
                    {
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='P';
                    update_pieces();                       
                    }
                    
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break ;
        
        case 'N':
                if (W_check_your_own_pieces(destination)&& (Y2>-1 && Y2<8)&&(X2>-1&& X2<8) && ( ((X2-X1==1)&&(Y2-Y1==2))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==-2))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==2))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==-2))|
                                                                                                ((X2-X1==2)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==2)&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==-2)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==-2)&&(Y2-Y1==-1))
                                                                                                ))
                    {
                        
                        
                    table [Y1][X1] ='0'; 
                    table [Y2][X2] ='N';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
        
        case 'D':
                if (W_check_your_own_pieces(destination))
                    {
                    table [Y1][X1] ='0'; 
                    table [Y2][X2] ='D';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
    
        case 'R':
            
            if (W_check_your_own_pieces(table[Y2][X2]))
{
                        
                if (X2-X1==0)
                    { if (Y2-Y1>0)
                        {     for (i=Y1+1;i<Y2;i++)
                                { if(table[i][X2] !='0'| !W_check_your_own_pieces(table[i][X2]))  space= false;    }                         
                                
                            if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                        
                                        break;
                                        }
                            else {
                                        table [Y1][X1] ='0'; 
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                        }
                                
                        if (Y2-Y1<0)
                        {
                            for (i=Y2+1;i<Y1;i++)
                            
                            {
                                     if(table[i][X2] !='0'| !W_check_your_own_pieces(table[i][X2]))  space= false;
                            }                         
                                        if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                        
                                        break;
                                        }
                            
                                else{
                                
                                
                                        table [Y1][X1] ='0';
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                                    
                        }
                        
                    }
                    
            if (Y2-Y1==0)   
                {
                    { if (X2-X1>0)
                        {     for (i=X1+1;i<X2;i++)
                                { if(table[Y2][i] !='0'| !W_check_your_own_pieces(table[Y2][i]))  space= false;    }                         
                                
                            if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                       
                                        break;
                                        }
                            else {
                                        table [Y1][X1] ='0'; 
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                        }
                                
                        if (X2-X1<0)
                        {
                            for (i=X2+1;i<X1;i++)
                            
                            {
                                     if(table[Y2][i] !='0'| !W_check_your_own_pieces(table[Y2][i]))  space= false;
                            }                         
                                        if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                        
                                        break;
                                        }
                            
                                else{
                                
                                
                                        table [Y1][X1] ='0';
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                                    
                        }
                        
                        
            }
            
            }
                            
}

else
{
        printf("%s", "Invalid command!");
        j=j-1;
        
}
        break;
        
        case 'K':
                if (W_check_your_own_pieces(destination)&& (Y2>-1 && Y2<8)&&(X2>-1&& X2<8) && ( ((X2-X1==0)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==0&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==0))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==0))
                                                                                                
                                                                                                )))
                    {
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='K';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
        
        case 'Q':
                if (W_check_your_own_pieces(destination))
                    {
                    table [Y1][X1] ='0'; 
                    table [Y2][X2] ='Q';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
    
        default :
        printf("%s", "Invalid command!");
        j=j-1;
        
        break;
        
        
        
    }
        

}

else

{        switch(test)
        {

        case 'P':
                if (B_check_your_own_pieces(destination)&&  ( (X2-X1 == 0 && Y2-Y1==-1)  |  (Y1==6 && Y2-Y1==-2&& X2-X1 == 0) ) && destination == '0' )
                    {
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='P';
                    update_pieces();
                    }
                else if (B_check_your_own_pieces(destination) && !W_check_your_own_pieces(destination) && ((X2-X1== -1|X2-X1==1)&& Y2-Y1==-1 ))   
                
                    {
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='P';
                    update_pieces();                       
                    }   
                
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
        
        case 'N':
                if (B_check_your_own_pieces(destination)&& (Y2>-1 && Y2<8)&&(X2>-1&& X2<8) && ( ((X2-X1==1)&&(Y2-Y1==2))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==-2))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==2))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==-2))|
                                                                                                ((X2-X1==2)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==2)&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==-2)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==-2)&&(Y2-Y1==-1))
                                                                                                ))               
                    {
                    table [Y1][X1] ='0'; 
                    table [Y2][X2] ='N';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
        
        case 'D':
                if (B_check_your_own_pieces(destination))
                    {
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='D';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;
        
        case 'R':
            
if (B_check_your_own_pieces(table[Y2][X2]))
{
                        
                if (X2-X1==0)
                    { if (Y2-Y1>0)
                        {     for (i=Y1+1;i<Y2;i++)
                                { if(table[i][X2] !='0'| !B_check_your_own_pieces(table[i][X2]))  space= false;    }                         
                                
                            if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                      
                                        break;
                                        }
                            else {
                                        table [Y1][X1] ='0'; 
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                        }
                                
                        if (Y2-Y1<0)
                        {
                            for (i=Y2+1;i<Y1;i++)
                            
                            {
                                     if(table[i][X2] !='0'| !B_check_your_own_pieces(table[i][X2]))  space= false;
                            }                         
                                        if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                       
                                        break;
                                        }
                            
                                else{
                                
                                
                                        table [Y1][X1] ='0';
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                                    
                        }
                        
                    }
                    
            if (Y2-Y1==0)   
                {
                    { if (X2-X1>0)
                        {     for (i=X1+1;i<X2;i++)
                                { if(table[Y2][i] !='0'| !B_check_your_own_pieces(table[Y2][i]))  space= false;    }                         
                                
                            if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                    
                                        break;
                                        }
                            else {
                                        table [Y1][X1] ='0';
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                        }
                                
                        if (X2-X1<0)
                        {
                            for (i=X2+1;i<X1;i++)
                            
                            {
                                     if(table[Y2][i] !='0'| !B_check_your_own_pieces(table[Y2][i]))  space= false;
                            }                         
                                        if (space==false)
                                        {
                                        printf("%s", "Invalid command!");
                                        j=j-1;
                                       
                                        break;
                                        }
                            
                                else{
                                
                                
                                        table [Y1][X1] ='0';
                                        table [Y2][X2] ='R';
                                        update_pieces();
                                }
                                    
                        }
                        
                        
            }
            
            }
                            
}

else
{
        printf("%s", "Invalid command!");
        j=j-1;
        
}
        break;
        
        case 'K':
                if (B_check_your_own_pieces(destination)&& (Y2>-1 && Y2<8)&&(X2>-1&& X2<8) && ( ((X2-X1==0)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==0&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==1))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==-1))|
                                                                                                ((X2-X1==1)&&(Y2-Y1==0))|
                                                                                                ((X2-X1==-1)&&(Y2-Y1==0))
                                                                                                
                                                                                                )))
                    {
                    table [Y1][X1] ='0'; 
                    table [Y2][X2] ='K';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;

        case 'Q':
                if (B_check_your_own_pieces(destination))
                    {
                    table [Y1][X1] ='0';
                    table [Y2][X2] ='Q';
                    update_pieces();
                    }
                else
                    {
                    printf("%s", "Invalid command!");
                    j=j-1;
                    
                    }
        break;

        default :
            
        printf("%s", "Invalid command!");
        j=j-1;
        
        break;
        
        }
}
}


int main(int argc, char *argv[])
{   
	
    int j;
    char command[255];
    while (1)
    {
        	gotoxy3(1,21);
        
			int p=0;
            while (j<100)
            {
                clearscreen();
                
                draw_table(p);
                if(j%2==1){
                	p+=1;
				}
				update_pieces();
                gotoxy3(1,21);
    
                
                if (j %2 ==0) 
                    printf("Player 1(W):\nSelect a piece: ");     
                else
                    printf("Player 2(B):\nSelect a piece: ");
            
                gets(command);
                
                check_table(command, j);
                
                j++;
            }
        

    }}
   

