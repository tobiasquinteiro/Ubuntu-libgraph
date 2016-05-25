/* BRESENHAM'S CIRCLE ALGORTIHM */

#include <graphics.h>
#include <stdio.h>
#include <math.h>
void symmetry(int xc,int yc,int x,int y);
void main()
{
    /* request auto detection */
    int gdriver = DETECT, gmode ;
    int xc,yc,r,s,x,y;
    printf("Enter the coordinates of center of circle: ");
    scanf("%d%d",&xc,&yc);
    printf("Enter the radius of circle: ");
    scanf("%d",&r);
    /* initialize graphics mode */
    initgraph(&gdriver, &gmode, NULL);
    x = 0;
    y = r;
    symmetry(xc,yc,x,y);
    s = 3-2*r;
    while(x<=y)
    {
	if(s<0)
	{
	    x = x+1;
	    s = s+4*x+6;
	}
	else
	{
	    x = x+1;
	    y = y-1;
	    s = s+4*(x-y)+10;
	}
	symmetry(xc,yc,x,y);
    }
    outtextxy(120,20,"BRESENHAM'S CIRCLE ALGORITHM");
    outtextxy(xc-25,yc,"(xc,yc)");
    delay(7000);
    closegraph();
    restorecrtmode();
}
void symmetry(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,RED);
    putpixel(xc-x,yc+y,RED);
    putpixel(xc+x,yc-y,RED);
    putpixel(xc-x,yc-y,RED);
    putpixel(xc+y,yc+x,RED);
    putpixel(xc-y,yc+x,RED);
    putpixel(xc+y,yc-x,RED);
    putpixel(xc-y,yc-x,RED);
}
