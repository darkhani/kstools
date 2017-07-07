#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<dir.h>
#include<bios.h>
#include<string.h>
#include<stdarg.h>

#define ESC 0x11b
#define UP     0x4800
#define LEFT     0x4b00
#define RIGHT     0x4d00
#define DOWN     0x5000
#define ENTER    0x1c0d
#define aX     0x2d00
#define FALSE  0x00
#define TRUE  0x01
#define OPEN  0x00
#define CLOSE  0x01

char far *VIDEO;

struct{
     unsigned char deep;
     unsigned char file[12];
     unsigned char dir[MAXPATH];
    }t[150];
char mem_dir[MAXPATH];
char buffer[MAXPATH];
char tree_count=1;
char deep_count=1;
int go,tree_y=0;
struct ffblk ffblk;

int get_video_mode(){
    int set_video;
    union REGS r;

    r.h.ah = 0x0f;
    int86(0x10,&r,&r);

    set_video=r.h.al;

    VIDEO=(char far*)0xA0000000;
}

void cursor(int onoff){
   union REGS r;
   r.h.ah=0x01;
   switch(onoff){
      case 0 : r.h.ch=0x0c;          /* CURSOR ON */
               r.h.cl=0x0d;
               int86(0x10,&r,&r);
               break;
      case 1 : r.h.ch=0x20;         /* CURSOR OFF */
               r.h.cl=0x0c;
               int86(0x10,&r,&r);
               break;
      default : r.h.ch=0x0c;         /* DEFAULT CURSOR */
                r.h.cl=onoff;
                int86(0x10,&r,&r);
                break;
   }
   int86(0x10,&r,&r);
}

void xy_cb_char(int x,int y,int color,int back,char ch){
     char far *video_seg;
     video_seg=VIDEO+(x-1)*2+(y-1)*160;
     *video_seg++=ch;
     *video_seg=(color|back<<4);
}

void xy_cls(int x1,int y1,int x2,int y2,int color,int back){
     char far *video_seg;
     int i,j;

    for(i=y1;i<=y2;i++)
    for(j=x1;j<=x2;j++){
     video_seg=VIDEO+(j-1)*2+(i-1)*160;
     *video_seg++=' ';
     *video_seg++=(color|back<<4);
  }
}

void box(int x1,int y1,int x2,int y2,int color,int back){
  int i;
  static char a[]={201,205,187,186,200,188};
  xy_cls(x1+1,y1+1,x2-1,y2-1,color,back);
  xy_cb_char(x1,y1,color,back,a[0]);
  for(i=x1+1;i<x2-1;i++){
   xy_cb_char(i,y1,color,back,a[3]);
   xy_cb_char(x2,i,color,back,a[3]);
  }
   xy_cb_char(x1,y2,color,back,a[4]);
   for(i=x1+1;i<x2-1;i++)
    xy_cb_char(i,y2,color,back,a[1]);
   xy_cb_char(x2,y2,color,back,a[5]);
}

void xy_cb_puts(int x,int y,int color,int back,char *string){
     char far *video_seg;

     video_seg=VIDEO+(x-1)*2+(y-1)*160;
   while(*string){
     *video_seg++=*string++;
     *video_seg=(color|back<<4);
   }
}

void xy_cb_printf(int x,int y,int color,int back,char *format,...){
   char far *video_seg;
   va_list argptr;
   char string[90];
   register i=0;

   va_start(argptr,format);
   vsprintf(string,format,argptr);
   video_seg = VIDEO + (x-1)*2+(y-1)*160;
   while(string[i]){
     *video_seg++=string[i++];
     *video_seg++=(color|back<<4);
    }
    va_end(argptr);
}

char *shin_dir(char *path){
  strcpy(path,"X:\\");
  path[0]='A'+getdisk();
  getcwd(path,100);
  return(path);
}

void text_attrib(int x1,int x2,int y,int color,int back){
     int i;
     char far *video_seg;
     for(i=x1-1;i<=x2-1;i++){
         video_seg=VIDEO+((i*2)+((y-1)*160)+1);
         *video_seg=(color|back<<4);
        }
}

void text_puts(int x,int y,int color,int back,char *string,int length){
     xy_cb_puts(x,y,color,back,string);
     text_attrib(x,x+length-1,y,4,7);
}

void getdir(struct ffblk blk){
   go=findfirst("*.*",&blk,FA_DIREC);
   while(!go){
     if((blk.ff_name[0]!='.')&&(blk.ff_attrib==FA_DIREC)){
        t[tree_count].deep=deep_count;
        sprintf(t[tree_count].file,"%s",blk.ff_name);
        shin_dir(buffer);
        if(t[tree_count].deep==1)
        sprintf(t[tree_count].dir,"%s%s",buffer,blk.ff_name);
        else
        sprintf(t[tree_count].dir,"%s\\%s",buffer,blk.ff_name);
        tree_count++;
        chdir(blk.ff_name);
        deep_count++;
        getdir(blk);
    }
     go=findnext(&blk);
    }
    deep_count--;
    chdir("..");
}

int checkdeep(unsigned int pnt,unsigned int ddeep){
    int i;
    for(i=pnt;i<tree_count;i++)
     if(t[i].deep<ddeep)return FALSE;
    else if(t[i].deep==ddeep)return TRUE;
    return FALSE;
}

void dos_tree(int start,int count){
     int y=2,chick;
     while(start!=count){
         chick=1;
         if(start!=0){
             while(chick<t[start].deep){
                if(checkdeep(start,chick)){
                    xy_cb_puts(chick*4,y,10,1,"³");
                }
             chick++;
            }
         if(checkdeep(start+1,t[start].deep))
           xy_cb_puts((t[start].deep)*4,y,10,1,"Ã");
         else  xy_cb_puts((t[start].deep)*4,y,10,1,"À");
        }
           xy_cb_printf((t[start].deep)*4+4,y,11,1,"%s",t[start].file);
           xy_cb_printf(43,y,15,1,"SUB-DIR=%-27s",t[start].dir);
           start++;
           y++;
        }
}

void menu_init(){
   box(1,1,40,24,11,1);
   box(41,1,80,24,11,1);
   xy_cls(1,25,80,25,0,7);
   xy_cb_printf(18,1,11,1,"Tree",getdisk()+'A');
   xy_cb_printf(52,1,11,1,"Sub-Directory",getdisk()+'A');
   text_puts(2,25,0,7,"UP-Tree Sub",2);
   text_puts(18,25,0,7,"ENTER(DOWN)-Tree Add",11);
   text_puts(62,25,0,7,"ESC,ALT+X - Quit",11);

   box(6,4,35,6,14,4);
   xy_cb_puts(8,5,15,4,"Sub-Directory Reading....");
}

void quit(){
   textattr(7);
   clrscr();
   xy_cb_puts(1,1,7,0,"Bye!");
   cursor(OPEN);
   gotoxy(1,2);
   exit(1);
}

main(int argc,char *argv[]){
     char imsi[3];
     int drive,mem_disk;
     int ch=0;
     cursor(CLOSE);
     shin_dir(mem_dir);
     mem_disk=getdisk();

     get_video_mode();
     strcpy(imsi,argv[1]);
     drive=toupper(imsi[0]);
     setdisk(drive-'A');
     menu_init();
     chdir("\\");

     sprintf(t[0].file,"%c:\\",getdisk()+'A');
     sprintf(t[0].dir,"%c:\\",getdisk()+'A');
     t[0].deep=0;
     getdir(ffblk);
     xy_cls(6,4,35,6,14,1);

     gotoxy(1,2);
     if(tree_count<22)
       dos_tree(0,tree_count);
      else dos_tree(0,22);

     setdisk(mem_disk);
     chdir(mem_dir);
     while(ch!=ESC||ch!=aX){
         ch=bioskey(0);
         switch(ch){
            case ENTER:
            case DOWN :
              if(tree_y+22<tree_count){
                 xy_cls(4,2,39,23,11,1);
                 tree_y++;
                 dos_tree(tree_y+0,tree_y+22);
                }
              break;
            case UP :
             if(tree_y>0){
                 xy_cls(4,2,39,23,11,1);
                 tree_y--;
                 dos_tree(tree_y+0,tree_y+22);
                }
            break;
          }/*switch close*/
    }
    quit();
}
