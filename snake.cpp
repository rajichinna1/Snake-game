#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
bool finish;
const int height=40,width=40;
int a,b,targeta,targetb,score=0;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void set()
{
    finish=false;
    dir=STOP;
    a=width/2;
    b=height/2;
    targeta=rand() % width;
    targetb=rand() % height;


}
void draw()
{
    system("cls");
    int i,j;
    for(i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(j==0 || j==width-1)
            {
            	cout<<"#";
            	
			}
            if(i==b && j==a)
            {
                cout<<"O";
            }
            else if(i==targetb && j==targeta)
            {
                cout<<"I";
            }
			else
			{
				cout<<" ";
			}
            
           
        }
        cout<<endl;
    }
    for(i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;

}
void in()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            
                dir = LEFT;
                break;
            
            case 'd':
            
                dir=RIGHT;
                break;
            
            case 's':
            
                dir=UP;
                break;
            
            case 'w':
            
                dir=DOWN;
                break;
            
            case 'x':
            
                finish=true;
                break;
            
                 
        }
    }

}
void logic()
{
    switch(dir)
    {
        case LEFT:
        {
            a--;
            break;
        }
        case RIGHT:
        {
            a++;
            break;
        }
        case DOWN:
        {
            b--;
            break;
        }
        case UP:
        {
            b++;
            break;
        }
        default:
        {
            break;
        }
    }
    if(a>width || a<0 || b>height || b<0)
    {
        finish=true;
    }

}
int main()
{
    set();
    while(!finish)
    {
        draw();
        in();
        logic();

    }

}

