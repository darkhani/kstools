
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dir.h>
#include<string.h>
#include <ctype.h>

#define offset(x,y)  (x*2)+(y*160)
#define RIGHT     0x4d
#define LEFT      0x4b
#define ESC       0x1b
#define ENTER     0x0d
#define DEL       0x53
#define END       0x4f
#define BACKSPACE 0x08
#define CANCEL    0
#define OK        1

#define MAXKEY 7
static KEY[MAXKEY] = { 0x31, 0xf4, 0x09, 0x0f, 0xec,0x01,0x99 }; /* ���� ���i�� ���*/
static unsigned int count = 0;

char far *v_seg;

struct date d1;
struct time t1;

FILE *fp;

int code(char *input, char *output);
int input_string(int x,int y,char *string,int length,int color);
void SDIR();
void BOX();
void FASTKEY();
void cline(int x,int y,int max,int attr);

int Date(int x,int y,int Ha);

/****���� �Է� �ޱ� �Լ��ε�  gets ���� �� ����~~~*/
FILE *fp;
int code(char *input, char *output)  /* �qѡ���� Ё���i Ё���e �q�� */
{
        FILE *fp1, *fp2;  /* �a�� �a�a�� ͡���� ���� */
        char ch;

        if (( fp1 = fopen(input,"rb"))== NULL) {    /* �� �a���i ������ ���� */
                printf("cannot open input file\n"); /* �wȁ�� �e�a. */
                return;                            /* �i���A ��́�e �w�� */
        }                                           /*  �a���a���i �{���a */

        if (( fp2 = fopen(output,"wb"))== NULL) {  /* �b �a���i �a���� ���� */
                printf("%s",output);     /*  �wȁ�� �e�a */
                printf("cannot open output file\n");     /*  �wȁ�� �e�a */
                return;
        }
        do {
                ch = getc(fp1);                   /* �a�a�� ���a�i ����i���a */
                ch ^=  KEY[ count % MAXKEY ];     /* ǡ�t�� XOR �e�e�i �e�a */
                if( feof(fp1) ) break;      /* �a���� �{���e �i��i �a�a�a�q */
                putc( ch,fp2 );
                count++;
        } while(!ferror(fp1) && !ferror(fp2)); /* ���� Ж�e�a ? */
        close(fp1); close(fp2);   /* �a���i �h�e�a */
}
CFG_OPEN(){
  fp=fopen("C:\\KT.CFG","r");
  if(fp==NULL){
      fclose(fp);
      return 0;
  }else{
      fclose(fp);
      return 1;
  }
}

Is_Reg(){
  int YesNo;
  YesNo=CFG_OPEN();
  if(YesNo==0){
      fclose(fp);
      return 0;
  }else{
      fclose(fp);
      return 1;
  }
}

int input_string(int x,int y,char *string,int length,int color)
{
char temp_string1[80+1],temp_string2[80+1], /* �A�� 80���a�i ��w�a�A �q */
					    /* 1�i ���a�e ���A�e �颅�a�� ͡�q�a�� ������ */
     temp[81],
     ch[2];                                 /* �e�� ���b�e ���a�i ��w */
 int cursor_position=0,i=0;

 ch[1]='\0';           /* �b ���a�i �e���i�i ������ �q */
 temp_string1[0]='\0';
 temp_string2[0]='\0';
 gotoxy(x,y);
 cprintf("%s",string); /* main()�q���A�� ��i�e string�i �b */
 gotoxy(x,y);
 strcpy(temp_string2,string);
 while(1){
       if(kbhit()){              /* ǡ���a�i ���e �w�� */
          textattr(color);
          if((ch[0]=getch())==0) /* 2byte�a���� ǡ�� �w�� */
              ch[0]=getch();     /* �w�� 1byte�i �a�� ���� �i�� */
          switch(ch[0]){
                 case ESC:
                      return CANCEL;
		 case ENTER:     /* string��  �t�i �����A ���b�e ���a�i�� �a�� */
                      strcpy(string,temp_string1);
                      strcat(string,temp_string2);
                      textattr(7);
                      return OK;
                 case RIGHT:
                      /* ��� ��á�a ���a�i�� �{�� �a�� �w�� */
                      if(cursor_position<(strlen(temp_string1)+strlen(temp_string2))){
                         /* ���i ���e���a�� ���� */
                         cursor_position++;
                         gotoxy(x+cursor_position,y);
                         /* temp_string1�t �e�w */
                         temp_string1[cursor_position-1]=temp_string2[0];
                         temp_string1[cursor_position]='\0';
                         /* temp_string2�t �e�w */
                         for(i=0;temp_string2[i]!='\0';i++)
                             temp_string2[i]=temp_string2[i+1];
                      }
                      break;
                 case BACKSPACE: /* case LEFT�� case DEL�i �����A ��З�q */
		 case LEFT:      /* BACKSPACEǡ�a LEFTǡ�i ���e �w�� */
                      /* ��� ��á�a ���a�i�� ��q�� �a�� �w�� */
                      if(cursor_position>0){
                         /* ���i �E���a�� ���� */
                         cursor_position--;
                         gotoxy(x+cursor_position,y);
                         /* temp_string1�t �e�w */
                         temp[0]=temp_string1[cursor_position];
                         temp[1]='\0';
                         temp_string1[cursor_position]='\0';
                         /* temp_string2�t �e�w */
                         strcat(temp,temp_string2);
                         strcpy(temp_string2,temp);
                      }
                      else
                         break;
                      if(ch[0]==LEFT)
                         break; /* BACKSPACEǡ�i ���e �w���A�e case DEL�� ��З�a�A �q */
                 /*case END:*/

                 case DEL:
                      /* temp_string2�� �� �弁 ���a(��� ��á�� ���a)�i ���� */
                      for(i=0;temp_string2[i]!='\0';i++)
                          temp_string2[i]=temp_string2[i+1];
                      /* temp_string2�i �b */
                      cprintf("%s ",temp_string2);
                      /* ��� ��á�i temp_string2�� ��q�a�� ���� */
                      gotoxy(x+cursor_position,y);
                      break;
		 default:        /* ���a�i �s���a�a �b */
                      /* ���a�i�� �����a length���a �b�e �w�� */
                      if((strlen(temp_string1)+strlen(temp_string2))<length){
                         cprintf("%s",ch); /* �e�� ��� ��á�A ���b�e ���a�i �b */
                         strcat(temp_string1,ch);
                         cprintf("%s",temp_string2);
                         cursor_position++;
                         gotoxy(x+cursor_position,y);
                      }
          }
       }
 }
}
void SDIR(){/*�ɼǿ��� /d�ϸ� ȣ��*/
 int i=0,search,files=0;
 struct fcb fcb;
 long int Size=0;
 struct ffblk f;
 clrscr();
 gotoxy(1,1);
 search=findfirst("*.*",&f,FA_LABEL);
 if(search!=-1){
  parsfnm(f.ff_name,&fcb,0);
  printf("K.S. File Speed Printer \n\r Volume in Drive %c is Label %s\n",getdisk()+'A',fcb.fcb_name);
 }else{
  printf("K.S. File Speed Printer \n\r Volume in Drive %c is No Label\n",getdisk()+'A');
 }
 search=0;
 search=findfirst("*.*",&f,FA_ARCH|FA_DIREC);
 while(!search){
     if(f.ff_attrib & FA_DIREC){   /* ���巡 �q���e ���� ��w �a�� ������ */
       textattr(12);
       cprintf("[%-13s]",f.ff_name);   /* �a���w */
       files=files-1;
       goto DAG;
      }
       cprintf("%13s  ",f.ff_name);   /* �a���w */
       DAG:
       cprintf("%10ld  ",f.ff_fsize); /* �a�� �a�� */
       if(f.ff_attrib & FA_DIREC){   /* ���巡 �q���e ���� ��w �a�� ������ */
         textattr(12);
          cprintf("D");
         textattr(7);
         }else{
          cprintf(".");
          }
       if(f.ff_attrib & FA_RDONLY){   /* ���巡 �q���e ���� ��w �a�� ������ */
          textattr(14);
          cprintf("R");
          textattr(7);
       }else{
          cprintf(".");
       }
       if(f.ff_attrib & FA_HIDDEN){   /* ���巡 �q���e Hidden �a�� ������ */
          textattr(13);
          cprintf("H");
          textattr(7);
       }else{
          cprintf(".");
       }
       if(f.ff_attrib & FA_SYSTEM){   /* ���巡 �q���e System �a�� ������ */
          textattr(4);
          cprintf("S");
          textattr(7);
       }else{
          cprintf(".");
       }
       if(f.ff_attrib & FA_ARCH){     /* ���巡 �q���e Archive �a�� ������ */
          textattr(10);
          cprintf("A");
          textattr(7);
       }else{
          cprintf(".");
       }
       cprintf("  %4d-%02d-%02d  ",(f.ff_fdate>>9)+1980,     /* �e */
                                  (f.ff_fdate>>5) & 0x000f, /* �� */
                                   f.ff_fdate & 0x001f);    /* �� */
       cprintf("  %02d:%02d",f.ff_ftime>>11,                 /* �� */
                            (f.ff_ftime>>5) & 0x003f);      /* �� */
       cprintf("\n\r");
       i++;       /* �a�� �����i �b�e ҁ �e З�i �a�� */
       if(i==22){ /* 24���� �a�� �����i �b�e �w�� �A�����i �b�a�� ǡ���b�i ���a�� */
         textattr(7);
          cprintf("Press any key when ready...");
         textattr(7);
          getch();
          printf("\n");
          i=0;
       }
       files+=1;
       Size=Size+f.ff_fsize;
       search=findnext(&f);
 }
   printf("%9d file(s) %10ld bytes\n",files,Size);
}

long GetTotalDiskSpace(int drive) {
    unsigned long availspace;
    union REGS disk;
    disk.h.ah = 0x36;
    disk.h.dl = drive;
    int86(0x21, &disk, &disk);
    if(disk.x.ax == 0xFFFF)
        return 0;
    else {
        availspace = (long)disk.x.dx * (long)disk.x.ax * (long)disk.x.cx;
        return availspace;
    }
}
vmode(){
  union REGS r;
  r.h.ah=15;
  return int86(16,&r,&r) & 0xff;
}
set_seg(){
  int vm;
  vm=vmode();
  if ((vm!=2) && (vm!=3) && vm!=7){ /* 80Į�� �ؽ�Ʈ��尡 �ƴѰ�� */
     puts("NOT 80 column text mode");
     exit(1);
  }
  /* v_seg �� ���� ���� */
  v_seg=(vm==7) ? (char far *) 0xb0000000 : (char far *) 0xb8000000;
  return;
}
void cline(int x,int y,int max,int attr){/*����� ��� �Լ�*/
   char far *sv;      /* ���� ������ x,y��ǥ�� �ش��ϴ� ���� ���� */
   int i;
   set_seg();

   x--; y--;
   sv=v_seg+offset(x,y);
   for(i=x; i<=x+max-1; i++){
         *sv++;       /* ���ڰ� ����� �޸𸮸� �ǳʶڴ� */
         *sv++=attr;  /* �Ӽ��� �����ϰ� ������ ������Ŵ */
   }
}
Buffer(){/*Ű���� ���ۿ� ST.BAT�� �ֱ�*/
     asm MOV AH,05;
     asm MOV CX,254bh;   /*K*/;
     asm INT 16H;

     asm MOV AH,05;
     asm MOV CX,1454h;   /*T*/
     asm INT 16H;

     asm MOV AH,05;
     asm MOV CX,342eh; /*.*/
     asm INT 16H;

     asm MOV AH,05;
     asm MOV CX,3042h; /*B*/
     asm INT 16H;

     asm MOV AH,05;
     asm MOV CX,1e41h; /*A*/
     asm INT 16H;

     asm MOV AH,05;
     asm MOV CX,1454h; /*T*/
     asm INT 16H;

     asm MOV AH,05;
     asm MOV CX,280Dh;/*ENTER*/
     asm INT 16H;

     asm MOV AH,4CH;
     asm INT 21H;
}
/***************** ���콺 ���� �Լ� **************/
ismouse(){
 union REGS mouse;
 mouse.x.ax=0;
 int86(0x33,&mouse,&mouse);
 if(mouse.x.ax==0xFFFF)
  return 1;
 else
  return 0;
}
mousebt(){
 union REGS mouse;
 mouse.x.ax=0;
 int86(0x33,&mouse,&mouse);
 return mouse.x.bx;
}
mouseon(){
 Cu(0);
 asm mov ax,1;
 asm int 33h;
 return 0;
}
mouseoff(){
  Cu(1);
  asm mov ax,2;
  asm int 33h;
  return 0;
}
mouseinput(){
  asm mov ax,3;
  asm int 33h;
  return;
}
mousex(){
  union REGS mouse;
  int x;
  mouse.x.ax=3;
  int86(0x33,&mouse,&mouse);
  x=mouse.x.cx/8;
  return x;
}
mousey(){
  union REGS mouse;
  int y;
  mouse.x.ax=3;
  int86(0x33,&mouse,&mouse);
  y=mouse.x.dx/8;
  return y;
}

/***************** ȭ�� ���� �Լ� **************/

Open_Screen(){/*ȭ�� ����*/
  int a, b, cursor_x, cursor_y;
  cursor_x=wherex ();
  cursor_y=wherey ();
  for (a=40, b=41 ; a>0 ; a=a-1, b=b+1){
    window(a,1,a,25);
    clrscr();    Cu(0);
    window(b,1,b,25);
    clrscr();
    Cu(0);
    delay (10);
  }
  gotoxy (cursor_x, cursor_y);
  normvideo();
  cprintf("     ");
  window(1,1,80,25);
  return 0;
}
Cprintfxy(int x,int y,char *NAE,int color){/*�������*/
  gotoxy(x,y);
  textattr(color);
  cputs(NAE);
}
/**���� ��ƾ***/
Game(){
 fp=fopen("BBALL.EXE","r");
 if(fp==NULL){
   printf("\aBBALL.EXE not found!");
   getch();
   fclose(fp);
   return 0;
 }
 system("BBALL.EXE");
 return 0;
}
/*�������*/
HOK(int mode,int x,int y,int Hi){
 textattr(122);
if(Hi==1){
    gotoxy(x,y);
    cprintf("H");
    return;
  }else{
  gotoxy(x,y);
  cprintf(" ");
 }
}
/**************** �ð��� ��¥ ���� �Լ�*****************/
Time(int x,int y,int Ha){
    char *DDA="_M";
    textattr(63);
    gettime(&t1);
    gotoxy(x,y);
    if(t1.ti_hour<12){
      DDA[0]='A';
    }
    if(t1.ti_hour>12){
    DDA[0]='P';
    t1.ti_hour-=12;
    }
    if(t1.ti_hour==12){
    DDA[0]='P';
    }
    if(t1.ti_hour<10){
          cprintf("%s 0%1d:%2d:%2d",DDA,t1.ti_hour,t1.ti_min,t1.ti_sec);
          textattr(7);
          return;
    }
    cprintf("%s %2d:%2d:%2d",DDA,t1.ti_hour,t1.ti_min,t1.ti_sec);
    textattr(7);
  return;
}
int Date(int x,int y,int Ha){
    union REGS r;
    char *WEK;
    int wk;
    r.h.ah=0x2a;
    int86(0x21,&r,&r);
    wk=r.h.al;
    textattr(63);
    getdate(&d1);
    gotoxy(x,y);
    wk=r.h.al;
    if(wk==0){
      strcpy(WEK,"Sun");
     if(Ha==1){
      strcpy(WEK," ��");
     }
    }
    if(wk==1){
    strcpy(WEK,"Mon");
     if(Ha==1){
      strcpy(WEK," ��");
     }
    }
    if(wk==2){
    strcpy(WEK,"Tue");
     if(Ha==1){
      strcpy(WEK," ȭ");
     }
    }
    if(wk==3){
    strcpy(WEK,"Wed");
     if(Ha==1){
      strcpy(WEK," ��");
     }
    }
    if(wk==4){
    strcpy(WEK,"Thu");
     if(Ha==1){
      strcpy(WEK," ��");
     }
    }
    if(wk==5){
    strcpy(WEK,"Fri");
     if(Ha==1){
      strcpy(WEK," ��");
     }
    }
    if(wk==6){
    strcpy(WEK,"Sat");
     if(Ha==1){
      strcpy(WEK," ��");
     }
    }
    cprintf("%4d/%2d/%2d",d1.da_year,d1.da_mon,d1.da_day);
    textattr(48);
     cprintf("�");
    textattr(63);
      cprintf("%s",WEK);
    textattr(48);
     cprintf("�");
    textattr(7);
    WEK="\0";
    return;
}
void BOX(int mode,int x,int y,int x1,int y1,int color,int help){
   int b,a;
   char JU[5][10]={{'�','�','�','�','�','�'},
                   {'','','','','',''}};

  gotoxy(x,y);
  textattr(color);
  cprintf("%c",JU[mode][0]);/*�*/
  for(b=x+1;b<=x1-1;b++){/*=====*/
    gotoxy(b,y);
    cprintf("%c",JU[mode][1]);
  }
  gotoxy(x1-1,y);
  cprintf("%c",JU[mode][2]);/*�*/
  for(b=y+1;b<=y1-1;b++){/*�*/
    gotoxy(x,b);
    if(help==0){
    cprintf("%c                                 ",JU[mode][3]);
    }
    if(help==1){
    cprintf("%c                              ",JU[mode][3]);
    }
    if(help==2){
     cprintf("%c                                                                    ",JU[mode][3]);
    }
    gotoxy(x1-1,b);
    cprintf("%c",JU[mode][3]);
  }
  gotoxy(x,y1);
  cprintf("%c",JU[mode][4]);/*�*/
  for(b=x+1;b<=x1-1;b++){/*=====*/
    gotoxy(b,y1);
    cprintf("%c",JU[mode][1]);
  }
  gotoxy(x1-1,y1);
  cprintf("%c",JU[mode][5]);/*�*/
}
void FASTKEY(){
 asm mov ax,4040h;
 asm int 16h;
}
