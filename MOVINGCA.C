#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
int i=250,j=250,r=3;
union REGS in,out;
void showmouse_text(){
		     int x,y;
		     in.x.ax=1;
		     int86(0x33,&in,&out);
		     if(out.x.bx==1){
					 x=out.x.cx;
					 y=out.x.dx;
					 printf("x=%d\ny=%d",x,y);
					 }
		    }
void show_position(){
		     int x,y;
		     in.x.ax=3;
		     int86(0x33,&in,&out);
					 x=out.x.cx;
					 y=out.x.dx;
					 gotoxy(1,1);
					 printf("Mouse");
					 gotoxy(1,2);
					 printf("x=%d\ny=%d",x,y);
		      }
int main(){
	 int  x=0,y=-1,ch,c,s,button;
	 int gdriver=DETECT,gmode;
	 initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	 outtextxy(300,4,"SUYASH PAINT BRUSH");
	 setcolor(YELLOW);
	 line(120,0,120,479);
	while(1){
			showmouse_text();
			show_position();
			circle(i,j,r);
			if(kbhit()){
				ch=getch();
				fflush(stdin);
				if(ch==56){
					  x=0;
					  y=-1;
					  gotoxy(1,4);
					  printf("x=%d\ny=%d",i,j);
					 }
				if(ch==52){
					  x=-1;
					  y=0;
					  gotoxy(1,4);
					  printf("x=%d\ny=%d",i,j);
					}
				if(ch==54){
					  x=1;
					  y=0;
					  gotoxy(1,4);
					  printf("x=%d\ny=%d",i,j);
					}
				if(ch==50){
					  x=0;
					  y=1;
					  gotoxy(1,4);
					  printf("x=%d\ny=%d",i,j);
					}
				if(ch!=27&&ch!=48&&ch!=50&&ch!=52&&ch!=54&&ch!=56){
										  x=0;
										  y=0;
										  }
				if(ch==83){
					   printf("Enter size");
					   scanf("%d",&s);
					   r=s;
					   }
				if(ch==80){
					gotoxy(1,4);
					printf("Give next \n");
					printf("x=");
					scanf("%d",&i);
					printf("y=");
					scanf("%d",&j);
					}
				if(ch==82){
					gotoxy(0,7);
					printf("Brush size");
					scanf("%d",&r);
					}
				if(ch==27){
					   exit(0);
					   }
					   i=i+x;
					   j=j+y;
			   delay(0);
			   }
			   }
	 }

