#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define Pl 43

int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int HGC;
int j_year,j_mon,c_year=0,c_mon=0;

struct date today;

int get_video_mode(){
    union REGS r;

 r.h.ah = 15;
 int86(0x10,&r,&r);
 return(r.h.al);
}

void color(int col,int ba,int color,int back){
     if(HGC==7)textattr(col|ba<<4);
     else textattr(color|back<<4);
}
void cal_date(int j){
    if(j_mon == 1 && j==1) color(15,0,12,5);
    if(j_mon == 1 && j==2) color(15,0,12,5);
    if(j_mon == 3 && j==1) color(15,0,12,5);
    if(j_mon == 4 && j==5) color(15,0,12,5);
    if(j_mon == 5 && j==5) color(15,0,12,5);
    if(j_mon == 6 && j==6) color(15,0,12,5);
    if(j_mon == 7 && j==17) color(15,0,12,5);
    if(j_mon == 8 && j==15) color(15,0,12,5);
    if(j_mon == 10 && j==3) color(15,0,12,5);
    if(j_mon == 12 && j==25) color(15,0,12,5);
}

void cal(int y_k,int m_k){
    int count = 1,i,last,year,clr;
    long tot_nalsu;
    div_t aa,bb,cc;

   getdate(&today);
   if(m_k==0)c_mon=today.da_mon;
   if(j_year!=3000)if(y_k==1)c_year++;
   if(j_year!=1000)if(y_k==2)c_year--;
   if(j_year==3000&&c_mon==12){}
    else if(m_k==1)c_mon++;
   if(j_year==1&&c_mon==1){}
    else if(m_k==2)c_mon--;

   j_mon=c_mon;
   if(j_mon==13){
     c_year++;
     j_mon=1;
     c_mon=1;
   }

   if(j_mon==0){
     c_year--;
     j_mon=12;
     c_mon=12;
    }
    j_year=today.da_year+c_year;

    color(7,0,14,5);
    gotoxy(1,1);

    cprintf("  %4d Year %2d Mon ",j_year,j_mon);

    color(7,0,10,5);
    if(((j_year%4==0)&&(j_year%100 !=0))||(j_year%400==00))days[2]=29;else days[2]=28;

    year=j_year-1;
    aa=div(year,4);
    bb=div(year,100);
    cc=div(year,400);
    tot_nalsu=year*(long)365+aa.quot-bb.quot+cc.quot;

   for(i=1;i<j_mon;i++)
    tot_nalsu=tot_nalsu+days[i];
    tot_nalsu=tot_nalsu+1;
    last=tot_nalsu%7;
    color(7,0,15,5);

   for(clr=7;clr<=8;clr++){
     gotoxy(1,clr);
     cputs("                     ");
   }
   gotoxy(1,3);

  for(i=1;i<=last;i++)cprintf("   ");/*1·©›‹¡*/

  for(i=1;i<=days[j_mon];i++){
     if(((i+last)%7)==1) color(15,0,12,5);
     cal_date(i);
     if(((i+last)%7)==0)color(9,0,11,5);
     if(i==today.da_day){
         color(15,0,15,5);cprintf(" ");/*µ¡“i‰Á ´á¹A ›‹¡*/
        if(i<10){
         color(0,7,15,6);cprintf("%2d",i);
        }else{
         color(0,7,15,6);cprintf("%2d",i);
        }
     }else cprintf("%3d",i);
     if(((i+last)%7)==0){
         count++;
         gotoxy(1,2+count);
    }
    color(7,0,15,5);
   }
  }
char *SV;
CRD_MAIN(int Windows){
    char ch=0;

    SV=malloc(4000);
    gettext(1,1,80,25,SV);
    HGC=get_video_mode();
    color(15,0,10,5);
    window(11,11,32,18);
    gotoxy(1,2);
    if(Windows==0){
     cprintf(" SU MO TU WE TH FR SA");
    }else{
     cprintf(" ÀÏ ¿ù È­ ¼ö ¸ñ ±Ý Åä");
    }
    cal(0,0);
    while(ch!=ESC){
        ch=getch();
        if(ch==0){
             switch(ch=getch()){
                 case RIGHT : cal(4,1);
                              break;
                 case LEFT : cal(4,2);
                             break;
                 case UP : cal(1,4);
                           break;
                 case DOWN : cal(2,4);
                             break;

                 case Pl : cal(12,4);
                             break;
             }
        }
    }
    textattr(7);
    clrscr();
    window(1,1,80,25);
    gettext(1,1,80,25,SV);
    return(0);
}
