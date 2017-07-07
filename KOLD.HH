#include"system.h"

#define RIGHT  0x01
#define LEFT   0x02
#define CTRL   0x04
#define ALT    0x08

#define INS    0x5200
#define ESC    0x011b
#define RET    0x1c0d
#define TAB    0x0f09
#define UP     0x4800
#define LT     0x4b00
#define RT     0x4d00
#define	DN     0x5000
#define DeL    0x5300
#define cRET   0x1c0a

#define F1     0x3b00
#define F2     0x3c00
#define F3     0x3d00
#define F4     0x3e00
#define F5     0x3f00
#define F6     0x4000
#define F7     0x4100
#define F8     0x4200
#define F9     0x4300
#define F10    0x4400

#define cA     0x1e01
#define cB     0x3002
#define cC     0x2e03
#define cD     0x2004
#define cE     0x1205
#define cF     0x2106
#define cG     0x2207
#define cH     0x2308
#define cI     0x1709
#define cJ     0x240a
#define cK     0x250b
#define cL     0x260c
#define cM     0x320d
#define cN     0x310e
#define cO     0x180f
#define cP     0x1910
#define cQ     0x1011
#define cR     0x1312
#define cS     0x1f13
#define cT     0x1414
#define cU     0x1615
#define cV     0x2f16
#define cW     0x1117
#define cX     0x2d18
#define cY     0x1519
#define cZ     0x2c1a

#define aA     0x1e00
#define aB     0x3000
#define aC     0x2e00
#define aD     0x2000
#define aE     0x1200
#define aF     0x2100
#define aG     0x2200
#define aH     0x2300
#define aI     0x1700
#define aJ     0x2400
#define aK     0x2500
#define aL     0x2600
#define aM     0x3200
#define aN     0x3100
#define aO     0x1800
#define aP     0x1900
#define aQ     0x1000
#define aR     0x1300
#define aS     0x1f00
#define aT     0x1400
#define aU     0x1600
#define aV     0x2f00
#define aW     0x1100
#define aX     0x2d00
#define aY     0x1500
#define aZ     0x2c00

#define _A      0x1e41
#define _B      0x3042
#define _C1     0x2e43
#define _D      0x2044
#define _E      0x1245
#define _F      0x2146
#define _G      0x2247
#define _H      0x2348
#define _I      0x1749
#define _J      0x244a
#define _K      0x244b
#define _L      0x264c
#define _M      0x324d
#define _N      0x314e
#define _O      0x184f
#define _P      0x1950
#define _Q      0x1051
#define _R      0x1352
#define _S      0x1f53
#define _T      0x1454
#define _U      0x1655
#define _V      0x2f56
#define _W      0x1157
#define _X      0x2d58
#define _Y      0x1559
#define _Z      0x2c5a

#define _a      0x1e61
#define _b      0x3062
#define _c1     0x2e63
#define _d      0x2064
#define _e      0x1265
#define _f      0x2166
#define _g      0x2267
#define _h      0x2368
#define _i      0x1769
#define _j      0x246a
#define _k      0x246b
#define _l      0x266c
#define _m      0x326d
#define _n      0x316e
#define _o      0x186f
#define _p      0x1970
#define _q      0x1071
#define _r      0x1372
#define _s      0x1f73
#define _t      0x1474
#define _u      0x1675
#define _v      0x2f76
#define _w      0x1177
#define _x      0x2d78
#define _y      0x1579
#define _z      0x2c7a

#define Dote     0x343e
#define dote     0x342e
#define FA_LIST  FA_ARCH|FA_SYSTEM|FA_RDONLY|FA_HIDDEN|FA_DIREC

void CTRL_T();
void STBAT(char filena[200]);
void STWBAT(char filena[200]);
void ROOTINE();
void FINFO(int Windows,int x,int y);
int FINFO2(int Windows,int x,int y);
void Re_Install();

char NA[]="Kwangsung Tools 99 Ver 1.00                                                  ";char NAH[]=" ±¤ ¼º Åø Áî  Ver 1.00                                                     ";
char Ver[]="Kwangsung Tools Ver1.00 [100]";
char VerH[]=" ±¤ ¼º Åø Áî  Ver 1.00 [100]";
char Ju[]="";
char JuP[]="³";
char savepath[MAXPATH],newpath[MAXPATH],OldA[MAXPATH],*PN="PATH",*PN2="°æ·Î";
char *SAT,*STDOS_SCR,*SCR,FM[12];

FILE *fp;

int Ff,i,HFDD,wy;
int chde=2,Ram,Ran;
char *FILENAM="*.*",FN[14],*SAT10,*SAT9;
unsigned char savedisk,newdisk;
  long drive_free;
  unsigned long drive_total;
struct ffblk f;
struct fcb fcb;
int COPY(char FM[200],char FN[200]);
ABOUT(int han){
     int aq=1,YY=7,ie=255,ban,dd,YesNo,DAEGI=0;/*DAEGI=µî·ÏÀÏ °æ¿ì ±â´Ù¸²ÀÇ ¼ö*/
     char *c,d[255];
     SAT=malloc(4000);
     gettext(20,5,55,11,SAT);
     gotoxy(10,5);
     YesNo=CFG_OPEN();
     if(YesNo==0){/*µî·ÏÆÇ ¾Æ´Ñ°æ¿ì*/
        printf("\a");
        BOX(0,20,5,55,11,95,0);
        if(han==1){
           BOX(1,20,5,55,11,95,0);
        }
        gotoxy(23,6);
        printf("%s\n",Ver);
        if(han==1){
           gotoxy(23,6);
           printf("%s\n",VerH);
        }
     gotoxy(24,8);
     printf("Please KTSET.EXE Make KT.CFG\n");
     gotoxy(26,9);
     printf("Not Register  Only Use.");
     gotoxy(21,10);
     printf("(C)Copyright 1997~99 Han In-taeg\n");
     sleep(2);
     goto da;
    }/*µî·ÏÆÇ ¾Æ´Ñ°æ¿ì*/
     gotoxy(10,5);
     textattr(7);
     BOX(0,20,5,55,11,95,0);
     if(han==1){
        BOX(1,20,5,55,11,95,0);
     }
     gotoxy(23,6);
     printf("%s\n",Ver);
     gotoxy(30,7);
     printf("* Register  To *\n");
     gotoxy(23,8);
     printf("Name : ");     gotoxy(23,9);     printf("Regi : ");
     gotoxy(21,10);
     printf("(C)Copyright 1997~99 Han In-taeg\n");
     textattr(7);
     if(han==1){
      gotoxy(23,6);
      printf("%s\n",VerH);
      gotoxy(30,7);
      printf("* µî·ÏÀÚ Á¤º¸  \n");
      gotoxy(23,8);
      printf("ÀÌ¸§ : ");     gotoxy(23,9);     printf("¹øÈ£ : ");
      gotoxy(21,10);
      printf("(C)¸¸µç¶§ 1997~1999 ¸¸µçÀÌ ÇÑÀÎÅÃ\n");
      textattr(7);
     }
    fp=fopen("c:\\kt.cfg","r");
     for(aq=1;aq<3;aq++){
      YY+=1;
      c=fgets(d,ie,fp);
      gotoxy(30,YY);
      printf("%s",c);
      if(aq==2){
       /* KT99-*/
       if(c[0]!='K'&&c[1]!='T'&&c[2]!='9'&&c[3]!='9'&&c[4]!='-'){
         clrscr();
         printf("\n\7KT.CFG file is Change!!!");
         Cu(1);
         exit(0);
      }
      /*2500-2500-415*/
      if(c[5]!='2'&&c[6]!='5'&&c[7]!='0'&&c[8]!='0'&&c[9]!='-'&&c[10]!='2'&&c[11]!='5'&&c[12]!='0'&&c[13]!='0'&c[14]!='-'){
         clrscr();
     printf("\n\7KT.CFG file is Change!!!");
         exit(0);
      }
      gotoxy(40,9);
      printf("XXXX-XXX");
    }
  }
   cline(21,6,33,112);
   while(!kbhit()){
    for(DAEGI=1;DAEGI<=300;DAEGI++){
       delay(10);
     if(kbhit())break;
    }
    break;
   }
   da:
    fclose(fp);
    puttext(20,5,55,11,SAT);
    free(SAT);
    return;
}
JUL(int x,int color,int mode){
  int a;
  textattr(color);
  for(a=4;a<=23;a++){
   gotoxy(x,a);
   cprintf("%s",JuP);
   if(mode==1){
      gotoxy(x,a);
      cprintf("%s",Ju);
   }
  }
  return -1;
}
OPTION(int Han){
      char *MOK="(À»)¸¦ ½ÇÇà ÇÕ´Ï´Ù.";
      char *NA="Samdol Tools '99 Ver 1.00                                                     ";
   textattr(7);
          clrscr();
        if(Han==0){
          textattr(31);
          cprintf("%s",NA);
          textattr(7);
          cprintf("\n\rUsage :> C:\\KT>KT.EXE [/OPTION] Filename.ext                   \n\n\r");
          cprintf("\nOption] V = Version Print                                        \n\n\r");
          textattr(14);
          cprintf("  D ");
          textattr(7);
          cprintf("= Run to Speed See File                                      \n\r");
          textattr(14);
          cprintf("  S,X,G ");
          textattr(7);
          cprintf("= Run SYSTEM Infomation,Text reader(G=Hangul mode)             \n\r");
          textattr(14);
          cprintf("  W");
          textattr(7);
          cprintf(" = Run to Hangul Dosmode in Windows 95...                       \n\r");
          textattr(14);
          cprintf("  E");
          textattr(7);
          cprintf(" = Change Run to Hangul Dosmode to English                      \n\r");
          textattr(14);
          cprintf("  U,P");
          textattr(7);
          cprintf(" = Kwngsung Batch file Rebuild,File Code Changer...            \n\n\n\r");
          textattr(14);
          cprintf("  ?,H");
          textattr(7);
          cprintf(" = This screen,Korean Screen                                  \n\n\n\r");
          cprintf("\nNo option  = Kwangsung Tools Run.                               \n\r");
                  randomize();
                 dasikara:
                     gotoxy(1,24);
                     textattr(30);
                     Ram=random(4)+1;
                     if(Ram==1)cprintf("Dokdo is Korea Ground!                                                     ");
                     if(Ram==2)cprintf("The Samdolsoft is in the In-Chon                                           ");
                     if(Ram==3)cprintf("The Kwangsung TOOLS made by Han In-taeg                                    ");
                     if(Ram==4)cprintf("If you use Win95, KT.EXE/W...                                              ");
                     if(Ram==5)cprintf("This version is %s ",NA);
                     sleep(1);
                     Ran++;
                     if(Ran==7)exit(1);
                     goto dasikara;
               }

         if(Han==1){
          textattr(31);
          cprintf("%s",NAH);
          textattr(7);
          cprintf("\n»ç¿ë¹ý:> C:\\KT>KT.EXE [/¼±ÅÃ»çÇ×] ÆÄÀÏÀÌ¸§.È®ÀåÀÚ(/XH¿É¼ÇµÚ)   \n\n\r");
          cprintf("\n¼±ÅÃ»çÇ×] V = ¹öÁ¯%s                                              \n\n\r",MOK);
          textattr(14);
          cprintf("  D ");
          textattr(7);
          cprintf("= ÆÄÀÏº¸°³¸¦ ½ÇÇà ÇÕ´Ï´Ù.                              \n\r");
          textattr(14);
          cprintf("  S,X,G ");
          textattr(7);
          cprintf("= ½Ã½ºÅÛº¸°³,¹®¼­ ÀÐ°³(G¿É¼ÇÀº ÇÑ±Û¸ðµå)¸¦ ½ÇÇà ÇÕ´Ï´Ù.\n\r");
          textattr(14);
          cprintf("  W");
          textattr(7);
          cprintf(" = ÇÑ±Û À©µµ¿ì 95¿¡¼­ ÇÑ±Û¸ðµå·Î ½ÇÇà(µµ½º¿¡¼­µµ ÇÑ±ÛÄ«µå±ò°í..)\n\r");
          textattr(14);
          cprintf("  E");
          textattr(7);
          cprintf(" = ÇÑ±Û¸ðµå¿¡¼­ ¿µ¹®¸ðµå·Î ¹Ù²ÛÈÄ  ST½ÇÇà ÇÕ´Ï´Ù.               \n\r");
          textattr(14);
          cprintf("  U");
          textattr(7);
          cprintf(" = ±¤¼ºÀÇ ÀÓ½Ã ¹èÄ¡ÆÄÀÏÀ» ´Ù½Ã ¸¸µì´Ï´Ù.(±¤¼ºÅøÁî °æ·Î°¡ ¹Ù²ï°æ¿ì\n\r");
          textattr(14);
          cprintf("  P");
          textattr(7);
          cprintf(" = ±¤¼ºÀÇ ÆÄÀÏ ÄÚµå ¹Ù²Ù°³¸¦ ½ÇÇà ÇÕ´Ï´Ù.(ÆÄÀÏ ¾ÏÈ£È­! ¾ÏÈ£Ç®±â) \n\r");
          textattr(14);
          cprintf("  ?,H");
          textattr(7);
          cprintf(" = ¿µ¹®¸ðµå µµ¿ò¸», ÀÌ È­¸é                                   \n\n\n\r");
          cprintf("\n¼±ÅÃ»çÇ× ¾øÀ¸¸é = ±¤¼ºÅøÁî ½ÇÇàÇÕ´Ï´Ù.                            \n\r");
                         randomize();
                 dasikara1:
                     gotoxy(1,24);
                     textattr(30);
                     Ram=random(11)+1;
                     if(Ram==1||Ram==7)cprintf("±¤¼ºÅøÁî´Â ÇÑÀÎÅÃÀÌ ¸¸µé¾ú½À´Ï´Ù.                                             ");
                     if(Ram==2||Ram==8)cprintf("ÇØÄ¿½Ã½ºÅÛÀº ÀÎÃµÀÇ ±¤¼º°íµîÇÐ±³ÀÇ Å¬·´ÀÔ´Ï´Ù                                 ");
                     if(Ram==3||Ram==9)cprintf("À©µµ¿ì 95¸¦ »ç¿ë ÇÑ´Ù¸é KT.EXE/W¸¦ ÇØ º¸¼¼¿ä!                                 ");
                     if(Ram==4||Ram==10)cprintf("ÇÑ±¹À» ¿µ¹®À¸·Î Ç¥±âÇÏ¸é CoreaÀÔ´Ï´Ù. Àý´ë Korea°¡ ¾Æ´Õ´Ï´Ù.                 ");
                     if(Ram==5||Ram==11)cprintf("IFM´Â Àá½Ã»Ó... ¿ì¸®´Â ´Ù½Ã ÀÏ¾î ¼³¼ö ÀÖ½À´Ï´Ù! =ÀÎÅÃ»ý°¢=                   ");
                     if(Ram==6||Ram==12)cprintf("µ¶µµ´Â ÇÑ±¹¶¥ ÀÔ´Ï´Ù. ÀÏº»ÀÌ ¿ì°Üµµ.....                                     ");
                     delay(700);
                     Ran++;
                     if(Ran==7)exit(1);
                     goto dasikara1;
             }
   return 0;
}
int FileN=0,fn=0;
unsigned long SIZE;
float D;
TL(int Windows){
     HFDD=0;
     textattr(3);
     gotoxy(1,3);
     if(Windows==1){
     cprintf("");
     JUL(65,3,Windows);
     JUL(52,3,Windows);
     JUL(39,3,Windows);
     JUL(26,3,Windows);
     JUL(13,3,Windows);
     gotoxy(1,24);
     cprintf("");
     textattr(7);
     return 0;
     }
     cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
     JUL(65,3,Windows);
     JUL(52,3,Windows);
     JUL(39,3,Windows);
     JUL(26,3,Windows);
     JUL(13,3,Windows);
     gotoxy(1,24);
     cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
     textattr(7);
     return 0;
}
char filename[1000][16];
char *DDD="";
FILE_PRINTF(int Windows,int attrib){
     int done,X=1,I=4,a=0,p,S2=0,S=0,PA,at,filesu=0,VL,i=0;
      Cu(0); a=0;
      SIZE=FileN=fn=0;  chde=chde;
      DISK_PATH();
  if(newpath[3]==''){
    gotoxy(1,2);
   if(Windows==0){
       gotoxy(1,2);
       cprintf("%s %s%s",PN,newpath,FILENAM);
       goto A3;
   }
    if(Windows==1){
       gotoxy(1,2);
       cprintf("%s %s%s",PN2,newpath,FILENAM);
       goto A3;
    }
       cline(1,2,80,112);
       goto A3;
   }
    gotoxy(1,2);
    if(Windows==0){
    cprintf("%s %s\\%s",PN,newpath,FILENAM);
    }else{
    cprintf("%s %s\\%s",PN2,newpath,FILENAM);
    }
    VL=findfirst("*.*",&f,FA_LABEL);
    if(VL==-1){
     gotoxy(70,2);
     puts("Volume[]");
    }else{
     parsfnm(f.ff_name,&fcb,0);
     gotoxy(60,2);
     cprintf("Volume[%s]",fcb.fcb_name);
    }
    cline(1,2,80,112);
    A3:
    cline(1,2,80,112);
  for(i=0;i<=1000;i++){
   strcpy(filename[i],DDD);
   strcat(filename[i],DDD);
  }
 if(attrib==0){
  done=findfirst("*.*",&f,FA_SYSTEM|FA_RDONLY|FA_ARCH|FA_DIREC);
 }else{
  done=findfirst("*.*",&f,FA_SYSTEM|FA_RDONLY|FA_ARCH|FA_DIREC|FA_HIDDEN);
 }
   while(done==0){/*ÆÄÀÏ Ãâ·Â ·çÆ¾*/
    strcpy(filename[filesu],f.ff_name);
     if(a==0&&fn+FileN>=20){
        X=14; I=4; a=1;
     }
     if(a==1&&fn+FileN>=40){
        X=27; I=4; a=2;
     }
     if(a==2&&fn+FileN>=60){
        X=40; I=4; a=3;
     }
     if(a==3&&fn+FileN>=80){
        X=53; I=4; a=4;
     }
     if(a==4&&fn+FileN>=100){
        X=68;I=4;  a=5;
     }
     if(a==5){
       X=1;
       I=4;
       S=fn;S2=FileN;
       fn=FileN=0;
       a=0;
     }
     if(f.ff_attrib==FA_DIREC){
        if(f.ff_name[0]=='.'){
           if(f.ff_name[1]==''){
              goto col;
           }
           if(f.ff_name[1]=='.'&&f.ff_name[2]==''){
              textattr(12);
              gotoxy(1,4);
              cprintf("[%-8s]\n",f.ff_name);
              fn++;
              I++;
              goto col;
           }
         }
       if(f.ff_attrib==FA_RDONLY){
        textattr(12);
        gotoxy(X,I);
        cprintf("[%-8s]\n",f.ff_name);
        fn++;
        I++;
       }else{
        textattr(12);
        gotoxy(X,I);
        cprintf("[%-8s]\n",f.ff_name);
        fn++;
        I++;
        goto col;
       }
    }
    if(f.ff_attrib!=FA_DIREC){
       gotoxy(X,I++);
       FileN++;
       i++;
    }
    textattr(7);
    for(Ff=0;Ff<=8;Ff++){
     if(f.ff_name[0]=='P'&&f.ff_name[1]=='R'&&f.ff_name[2]=='O'&&f.ff_name[3]=='G'&&f.ff_name[4]=='R'&&f.ff_name[5]=='A'&&f.ff_name[6]=='~'){
        textattr(12);
        at=I;
        I-=1;
        gotoxy(X,I);
        cprintf("[%-8s]\n",f.ff_name);
        FileN=FileN--;
        fn++;
        I=at;
        goto col;
     }
     if(f.ff_name[0]=='R'&&f.ff_name[1]=='E'&&f.ff_name[2]=='C'&&f.ff_name[3]=='Y'&&f.ff_name[4]=='C'&&f.ff_name[5]=='L'&&f.ff_name[6]=='E'&&f.ff_name[7]=='D'){
        textattr(12);
        at=I;
        I-=1;
        gotoxy(X,I);
        cprintf("[%-8s]\n",f.ff_name);
        FileN=FileN--;
        fn++;
        I=at;
        goto col;
     }
       if(f.ff_name[Ff]=='.'){
      /*********** EXECUTE FILE *******/
          /* EXE File */
          if(f.ff_name[Ff+1]=='E'&&f.ff_name[Ff+2]=='X'&&f.ff_name[Ff+3]=='E'){
             FC(f.ff_name,10,X,I);
             goto col;
          }
          if(f.ff_name[Ff+1]=='C'&&f.ff_name[Ff+2]=='O'&&f.ff_name[Ff+3]=='M'){
             FC(f.ff_name,11,X,I);
             goto col;
          }
          if(f.ff_name[Ff+1]=='B'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='T'){
             FC(f.ff_name,14,X,I);
             goto col;
          }
         /*C ASM*/
          if(f.ff_name[Ff+1]=='C'&&f.ff_name[Ff+2]==''||f.ff_name[Ff+1]=='A'&&f.ff_name[Ff+2]=='S'&&f.ff_name[Ff+3]=='M'){
             FC(f.ff_name,9,X,I);
             goto col;
          }
            /* SYS File & BAK File*/
          if(f.ff_name[Ff+1]=='S'&&f.ff_name[Ff+2]=='Y'&&f.ff_name[Ff+3]=='S'||f.ff_name[Ff+1]=='B'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='K'){
             FC(f.ff_name,4,X,I);
             goto col;
          }
            /* H File */
         if(f.ff_name[Ff+1]=='H'&&f.ff_name[Ff+2]==''||f.ff_name[Ff+1]=='L'&&f.ff_name[Ff+2]=='I'&&f.ff_name[Ff+3]=='B'){
             FC(f.ff_name,1,X,I);
             goto col;
          }
	      /* OBJ File & PAS File*/
         if(f.ff_name[Ff+1]=='O'&&f.ff_name[Ff+2]=='B'&&f.ff_name[Ff+3]=='J'||f.ff_name[Ff+1]=='P'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='S'){
             FC(f.ff_name,1,X,I);
             goto col;
         }
          /* BAS File COB*/
         if(f.ff_name[Ff+1]=='B'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='S'||f.ff_name[Ff+1]=='C'&&f.ff_name[Ff+2]=='O'&&f.ff_name[Ff+3]=='B'){
             FC(f.ff_name,1,X,I);
             goto col;
         }
	      /**** Archive FILE ****/
	      /*ARJ & RAR */
          if(f.ff_name[Ff+1]=='A'&&f.ff_name[Ff+2]=='R'&&f.ff_name[Ff+3]=='J'||f.ff_name[Ff+1]=='R'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='R'){
             FC(f.ff_name,13,X,I);
             goto col;
          }
	     /* A0? & R0? & A1? & R1?*/
          if(f.ff_name[Ff+1]=='A'&&f.ff_name[Ff+2]=='0'||f.ff_name[Ff+1]=='R'&&f.ff_name[Ff+2]=='0'||f.ff_name[Ff+1]=='A'&&f.ff_name[Ff+2]=='1'||f.ff_name[Ff+1]=='R'&&f.ff_name[Ff+2]=='1'){
             FC(f.ff_name,15,X,I);
             goto col;
          }
	      /*LZH & ZIP*/
          if(f.ff_name[Ff+1]=='L'&&f.ff_name[Ff+2]=='Z'&&f.ff_name[Ff+3]=='H'||f.ff_name[Ff+1]=='Z'&&f.ff_name[Ff+2]=='I'&&f.ff_name[Ff+3]=='P'){
             FC(f.ff_name,13,X,I);
             goto col;
          }
	      /*DCF*/
          if(f.ff_name[Ff+1]=='D'&&f.ff_name[Ff+2]=='C'&&f.ff_name[Ff+3]=='F'){
             FC(f.ff_name,13,X,I);
             goto col;
          }
	    /******* Hangul & TXT file *******/
	      /*HWP & TXT*/
          if(f.ff_name[Ff+1]=='H'&&f.ff_name[Ff+2]=='W'&&f.ff_name[Ff+3]=='P'||f.ff_name[Ff+1]=='T'&&f.ff_name[Ff+2]=='X'&&f.ff_name[Ff+3]=='T'){
             FC(f.ff_name,3,X,I);
             goto col;
          }
	      /*DOC & CAP*/
          if(f.ff_name[Ff+1]=='D'&&f.ff_name[Ff+2]=='O'&&f.ff_name[Ff+3]=='C'||f.ff_name[Ff+1]=='C'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='P'){
             FC(f.ff_name,3,X,I);
             goto col;
          }
	     /* LST File & HLP File*/
         if(f.ff_name[Ff+1]=='L'&&f.ff_name[Ff+2]=='S'&&f.ff_name[Ff+3]=='T'||f.ff_name[Ff+1]=='H'&&f.ff_name[Ff+2]=='L'&&f.ff_name[Ff+3]=='P'){
             FC(f.ff_name,3,X,I);
             goto col;
	      }
	      /* GUL File */
         if(f.ff_name[Ff+1]=='G'&&f.ff_name[Ff+2]=='U'&&f.ff_name[Ff+3]=='L'){
             FC(f.ff_name,3,X,I);
             goto col;
         }
	     /******* Picture *******/
	      /*PCX & GIF*/
         if(f.ff_name[Ff+1]=='P'&&f.ff_name[Ff+2]=='C'&&f.ff_name[Ff+3]=='X'||f.ff_name[Ff+1]=='G'&&f.ff_name[Ff+2]=='I'&&f.ff_name[Ff+3]=='F'){
             FC(f.ff_name,2,X,I);
             goto col;
         }
	      /*BMP & ICO*/
         if(f.ff_name[Ff+1]=='B'&&f.ff_name[Ff+2]=='M'&&f.ff_name[Ff+3]=='P'||f.ff_name[Ff+1]=='I'&&f.ff_name[Ff+2]=='C'&&f.ff_name[Ff+3]=='O'){
             FC(f.ff_name,2,X,I);
             goto col;
         }
              /*JPG & FLI*/
         if(f.ff_name[Ff+1]=='J'&&f.ff_name[Ff+2]=='P'&&f.ff_name[Ff+3]=='G'||f.ff_name[Ff+1]=='F'&&f.ff_name[Ff+2]=='L'&&f.ff_name[Ff+3]=='I'){
             FC(f.ff_name,2,X,I);
             goto col;
         }
           /******* Music *******/
           /*WAV & IMS*/
         if(f.ff_name[Ff+1]=='W'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]=='V'||f.ff_name[Ff+1]=='I'&&f.ff_name[Ff+2]=='M'&&f.ff_name[Ff+3]=='S'){
             FC(f.ff_name,6,X,I);
             goto col;
         }
          /*BNK*/
          if(f.ff_name[Ff+1]=='B'&&f.ff_name[Ff+2]=='N'&&f.ff_name[Ff+3]=='K'){
             FC(f.ff_name,6,X,I);
             goto col;
          }
	      /*VOC & MID*/
          if(f.ff_name[Ff+1]=='V'&&f.ff_name[Ff+2]=='O'&&f.ff_name[Ff+3]=='C'||f.ff_name[Ff+1]=='M'&&f.ff_name[Ff+2]=='I'&&f.ff_name[Ff+3]=='D'){
             FC(f.ff_name,6,X,I);
             goto col;
          }
	      /*ROL & MOD*/
          if(f.ff_name[Ff+1]=='R'&&f.ff_name[Ff+2]=='O'&&f.ff_name[Ff+3]=='L'||f.ff_name[Ff+1]=='M'&&f.ff_name[Ff+2]=='O'&&f.ff_name[Ff+3]=='D'){
             FC(f.ff_name,6,X,I);
             goto col;
          }
	      /*MP3 & RA*/
          if(f.ff_name[Ff+1]=='M'&&f.ff_name[Ff+2]=='P'&&f.ff_name[Ff+3]=='3'||f.ff_name[Ff+1]=='R'&&f.ff_name[Ff+2]=='A'&&f.ff_name[Ff+3]==''){
             FC(f.ff_name,6,X,I);
             goto col;
          }
	      /*CFG*/
          if(f.ff_name[Ff+1]=='C'&&f.ff_name[Ff+2]=='F'&&f.ff_name[Ff+3]=='G'){
             FC(f.ff_name,8,X,I);
             goto col;
          }
       }
     }
    textattr(7);
    cprintf("%-14s",f.ff_name);
     col:
     textattr(7);
     SIZE=SIZE+f.ff_fsize;
     filesu+=1;
     done=findnext(&f);
   }
     strcpy(filename[filesu],"A:");
     filesu=filesu+1;
     if(GetFloppyNo()==2){
       strcpy(filename[filesu],"B:");
     }else{
       strcpy(filename[filesu],"C:");
       goto Dae;
     }
     filesu=filesu+1;
     strcpy(filename[filesu],"C:");
     Dae:
     TL(Windows);
     DRIVE_PRINTF(X,I);
     drive_total=GetTotalDiskSpace(0);
     drive_free=GetAvailDiskSpace(0);
     D=(float)(drive_total-drive_free)/drive_total*100;
     textattr(127);
     gotoxy(1,25);
     cprintf("                                                                              ");
     if(drive_total/1000000<2){
        gotoxy(1,25);
        cprintf(" %3d File(s) %3d Dir(s) %7.0lu Bytes %4.0lu Bytefree(%2.1f%%) ",FileN,fn,SIZE,drive_free,100-D);
        cprintf(" %lu(KB)",drive_total/1000);
        if(FileN==0){
           gotoxy(1,25);
           cprintf("                                                                              ");
           gotoxy(1,25);
           cprintf("    0 File(s) %3d Dir(s)    0 Bytes %4.0lu Bytefree(%2.1f%%) ",fn,drive_free,100-D);
           cprintf(" %lu(KB)",drive_total/1000);
        }
     }
     if(drive_total/1000000>2){
        gotoxy(1,25);
        cprintf(" %3d File(s) %3d Dir(s) %7.0lu Bytes %4.0lu Bytefree(%2.1f%%) ",FileN+S2,fn+S,SIZE,drive_free,100-D);
        cprintf(" %lu(MB)",drive_total/1000000);
        if(FileN==0){
           gotoxy(1,25);
           cprintf("                                                                              ");
           gotoxy(1,25);
           cprintf("    0 File(s) %3d Dir(s)  0 Bytes %4.0lu Bytefree(%2.1f%%) ",fn,drive_free,100-D);
           cprintf(" %lu(MB)",drive_total/1000000);
        }
     }
     textattr(7);
     return 0;
}
char *SCRE;
ENTER_ROOTINE(int Windows,int x,int y){
        char bs[100],fe[13];
        int a,root=0,fi,done;
        mouseoff();
        SCRE=malloc(4000);
      if(newpath[3]==NULL){/*ROOT*/
         strcpy(bs,filename[y-4]);
         root=1;
       }
       if(x==1){
            if(root==1){
               strcpy(bs,filename[y-4]);
            }else{
               if(y==4){chdir("..");return 0;}
               strcpy(bs,filename[y-3]);
            }
          done=findfirst(bs,&f,FA_DIREC);
          if(f.ff_name[0]=='R'&&f.ff_name[1]=='E'&&f.ff_name[2]=='C'&&f.ff_name[3]=='Y'&&f.ff_name[4]=='C'&&f.ff_name[5]=='L'&&f.ff_name[6]=='E'&&f.ff_name[7]=='D'){
            goto dir;
          }
          if(f.ff_name[0]=='P'&&f.ff_name[1]=='R'&&f.ff_name[2]=='O'&&f.ff_name[3]=='G'&&f.ff_name[4]=='R'&&f.ff_name[5]=='A'&&f.ff_name[6]=='~'&&f.ff_name[7]=='1'){
            goto dir;
          }
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           strcpy(bs,filename[y-3]);
           goto FILE;
          }
         }
         if(x==14){
          if(root==1){
            strcpy(bs,filename[16+y]);
          }else{
            strcpy(bs,filename[17+y]);
          }
          done=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         }
         if(x==27){
         if(root==1){
          strcpy(bs,filename[36+y]);
         }else{
          strcpy(bs,filename[37+y]);
         }
          done=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         }
         if(x==40){
         if(root==1){
          strcpy(bs,filename[56+y]);
         }else{
          strcpy(bs,filename[57+y]);
         }
          done=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         }
         if(x==53){
         if(root==1){
          strcpy(bs,filename[76+y]);
         }else{
          strcpy(bs,filename[77+y]);
         }
          done=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         dir:
         /*directory*/
             chdir(bs);
           FILE:
           if(bs[0]=='A'&&bs[1]==':'){
               if(DRIVEA(Windows)==0){
                chde=0;
               }
               mouseon();
               return 0;
           }
           if(bs[0]=='B'&&bs[1]==':'){
              if(DRIVEB(Windows)==0){
                 chde=1;
               }
               mouseon();
               return 0;
           }
           if(bs[0]=='C'&&bs[1]==':'){
               chde=2;
               mouseon();
               return 0;
           }
          if(bs[0]==''){
               mouseon();
             return 0;
          }
          for(a=0;a<13;a++){/*FILENAME*/
           if(bs[a]=='.'){/*FILE*/
             if(bs[a+1]=='E'&&bs[a+2]=='X'&&bs[a+3]=='E'||bs[a+1]=='C'&&bs[a+2]=='O'&&bs[a+3]=='M'||bs[a+1]=='B'&&bs[a+2]=='A'&&bs[a+3]=='T'){
               textattr(7); clrscr();
               if(Windows==0){
                STBAT(bs);
               }else{
                STWBAT(bs);
               }
               Buffer();
               exit(0);
             }/*EXE,COM,BAT*/
             if(bs[a+1]=='T'&&bs[a+2]=='X'&&bs[a+3]=='T'||bs[a+1]=='D'&&bs[a+2]=='O'&&bs[a+3]=='C'||bs[a+1]=='C'&&bs[a+2]=='A'&&bs[a+3]=='P'){
               clrscr();
               SWP(0,bs);
               mouseon();
               return 0;
             }/*TXT,DOC,CAP*/
             if(bs[a+1]=='B'&&bs[a+2]=='A'&&bs[a+3]=='S'||bs[a+1]=='C'&&bs[a+2]==''||bs[a+1]=='P'&&bs[a+2]=='A'&&bs[a+3]=='S'){
               clrscr();
               SWP(0,bs);
               mouseon();
               return 0;
             }/*C,PAS,BAS*/
             if(bs[a+1]=='B'&&bs[a+2]=='A'&&bs[a+3]=='K'){
               unlink(bs);
               mouseon();
               return 0;
             }/*BAK*/
             if(bs[a+1]=='W'&&bs[a+2]=='A'&&bs[a+3]=='V'){
                if(_osmajor==7){
                   strcpy(fe,"sndreg32 ");
                   strcat(fe,bs);
                   system(fe);
                }
               mouseon();
               return 0;
             }/*WAV*/
           }/*FILE*/
          }/*FILENAME*/
        }/*ENTER*/
  mouseon();
  return 0;
}
void CTRL_T(){
  char *msg;
  clrscr();
  puttext(1,1,80,25,SCRE);
  strcpy(msg,"Press any key to ");  strcat(msg,Ver);
  gotoxy(1,25);
  textattr(62);
  cputs(msg);  getch();  textattr(7);
}
int COPY(char FM[200],char FN[200]){
 int ch,q,q3,x,y;
 unsigned long ssize,tsize=0;
 FILE *source,*target;
 if((source=fopen(FM,"rb"))==NULL){ /* ¼Ò½º °³¹æ ½ÇÆÐ½Ã Ãâ·Â */
    printf("Cannot open source file");
    fclose(source);
    return -1;
 }
 if((target=fopen(FN,"wb"))==NULL){ /* Å¸°Ù °³¹æ ½ÇÆÐ½Ã Ãâ·Â */
    printf("Cannot open target file");
    fclose(source);
    return -1;
 }
 q=findfirst(FM,&f,FA_ARCH);
   ssize=f.ff_fsize;
 ch=fgetc(source);                       /* ­¡¯a Ìa·©¡¦Èá Ðe ¢…¸aŸi ·ª´áµ± */
 x=wherex();
 y=wherey();
 while(!feof(source)){                   /* Ìa·©· {·¥»¡ ˆñ¬a */
       fputc(ch,target);                 /* ·ª´áµ¥ ¢…¸aŸi Èa‰U Ìa·©µA Â‰b */
       ch=fgetc(source);                 /* ­¡¯a Ìa·©¡¦Èá Ðe ¢…¸aŸi ·ª´áµ± */
      tsize=tsize+1;
      gotoxy(x,y);
      printf("%2.1f%%",(float)tsize/ssize*100);
 }
 printf("\n%s->%s Copy Success.",FM,FN);
 fclose(source);                         /* ­¡¯a Ìa·© Í­á */
 fclose(target);                         /* Èa‰U Ìa·© Í­á */
}
FC(char FM[12],int color,int X,int I){
           textcolor(color);
           gotoxy(X,I-1);
           cputs(FM);
           return;
}
DISK_PATH(){
     setdisk(chde);     savedisk=newdisk=getdisk(); textattr(7);
     getcwd(savepath,MAXPATH);
     strcpy(newpath,savepath);
     strcpy(OldA,savepath);
     return;
}
MMOUSE_MENU(int HE){
 gotoxy(1,1);
 textattr(62);
 cprintf("F1");
 textattr(63);
 cprintf("HELP     ³");
 if(HE==1){
  gotoxy(12,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F2");
 textattr(63);
 cprintf("CALENDAR  ³");/*»ïµ¹¿¡¼­ °³¹ßÇÑ µµ½º*/
 if(HE==1){
  gotoxy(26,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F3");
 textattr(63);
 cprintf("SAMDOLSYS ³");/*³¯Â¥ °íÄ§,½Ã°£ °íÄ§,È®ÀÎ*/
 if(HE==1){
  gotoxy(39,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F4");
 textattr(63);
 cprintf("ST GAME  ³");
 if(HE==1){
  gotoxy(52,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F5");
 textattr(63);
 cprintf("EASY LINK³");
 if(HE==1){
  gotoxy(65,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F6");
 textattr(63);
 cprintf("HWP30->TXT  ");
 if(HE==1){
  gotoxy(80,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(7);
 return 0;
}
KEY(){
   int key,key3,modifiers;
   while(!bioskey(1));
   key=bioskey(0);
   switch(key){
        case F1: return 1;/*µµ¿ò¸»*/
        case F2: return 2;/*»ïµ¹µµ½º*/
        case F3: return 3;
        case F4: return 4;
        case F5: return 5;/*ÀÌÁö¸µÅ© È£Ãâ*/
        case F6: return 6;
        case F7: return 7;/*µî·ÏÀÚ Á¤º¸*/
        case F8: return 8;
        case F10: return 910;
        case ESC : return 10;/*³¡³»±â*/
        case UP : return 11;/*À§·Î*/
        case DN : return 12;/*¾Æ·¡·Î*/
        case LT : return 13;/*¿Þ*/
        case RT : return 14;/*¿À¸¥*/
        case RET : return 15;/*½ÇÇà*/
        case INS : return 20;/*½ÇÇà*/
        case cRET : return 1500;/*½ÇÇà*/
        case TAB : return 400;
        case _c1 : return 433;/*COPY ROOTINE*/
        case _C1 : return 403;/*°æ·Î ¹Ù²Þ*/
        case _D :
        case _d : return 404;/*°æ·Î&ÆÄÀÏ Áö¿ò*/
        case _M :
        case _m : return 413;/*¸¸µé±â*/
        case _N :
        case _n : return 414;
        case _Q :
        case _q : return 416;
        case aA : return 101;/*µå¶óÀÌºê ¿¡ÀÌA*/
        case aB : return 102; /*µå¶óÀÌºê ÀÌµ¿*/
        case aC : return 103;
        case aD : return 104;/*ÆÄÀÏ Áö¿ì±â*/
        case aF : return 106;/*ÆÄÀÏ Áö¿ì±â*/
        case aK : return 111;
        case aR : return 118;/*¸®³×ÀÓ¸í·É*/
        case aX : return 124;
        case aP : return 16;/*ÆÄÅ·*/
        case aZ : return 126;/*È÷µç°ú ºñÈ÷µç*/
        case cS : return 219;/*½ÇÇàµÚ È­¸é*/
        case cT : return 220;/*½ÇÇàµÚ È­¸é*/
        case cV : return 222;
        case DeL : return 1000;/*½ÇÇàµÚ È­¸é*/
        case Dote :
        case dote : return 2000;
      }
   return 0;
}
SWP(int HAN,char *FMW){
    int a=1,Y=1,i=90,ch=1,b,key;
    char D_str[200];
    char S_str[200],QU[8];
 char d[255],*c,*Ky,str[680];
 textattr(7);
 clrscr();
 textattr(7);
 fp=fopen(FMW,"r");
 if(fp==NULL){
  if(HAN==1){
   printf("\n\a %s¸¦ ¸øÃ£À½!",FMW);
   goto pa;
  }
  printf("\n\a %s not found!",FMW);
  pa:
  exit(1);
 }
   gotoxy(1,1);
   textattr(30);
   cprintf("                                                                                 ");
   gotoxy(1,1);
   cprintf("%s",Ver);
   sprintf(D_str,"File name  : %s  Page : 1",FMW);
   if(HAN==1){
    gotoxy(1,1);
    cprintf("                                                                                ");
    gotoxy(1,1);
    cprintf("%s",VerH);
    sprintf(D_str,"ÆÄÀÏ ÀÌ¸§  : %s  1  Àå",FMW);
   }
   gotoxy(1,2);
   textattr(112);
   cprintf("                                                                                 ");
   gotoxy(1,2);
   cprintf("%s",D_str);
   textattr(7);
   Y=3;
   for(ch=2;ch<24;ch++){
      sr:
      Y+=1;
      i+=0;
	c=fgets(d,i,fp);
       gotoxy(1,Y);
      if(c==NULL)goto end;
      sprintf(S_str,"%s\n",c);
      gotoxy(1,Y);
      textattr(30);
      gotoxy(1,Y-1);
      cprintf("                                                                              \r");
      textattr(30);
      cprintf(S_str);
      textattr(7);
    }
 a=1;
 while(c!=NULL){
  if(HAN==1){
   gotoxy(1,25);
   cprintf("*** Enter=´ÙÀ½Àå  , ESC = ³¡  ***");
   goto par;
   }
   gotoxy(1,25);
   cprintf("*** Enter to next , ESC = end ***");
   par:
    if(getch()==27){
     clrscr();
     fclose(fp);
     return;
    }
   clrscr();
   a=a+1;
   gotoxy(1,1);
   textattr(31);
   cprintf("                                                                                   ");
   gotoxy(1,1);
   cprintf("%s",Ver);
   sprintf(D_str,"File name  : %s  Page : %d",FMW,a);
   if(HAN==1){
    gotoxy(1,1);
    textattr(31);
    cprintf("                                                                                  ");
    gotoxy(1,1);
    cprintf("%s",VerH);
    sprintf(D_str,"ÆÄÀÏ ÀÌ¸§  : %s    %d Àå",FMW,a);
   }
   gotoxy(1,2);
   textattr(112);
   cprintf("                                                                                   ");
   gotoxy(1,2);
   cprintf("%s",D_str);
   textattr(7);
   Y=3;
   for(ch=2;ch<24;ch++){
      Y+=1;
      i+=0;
	c=fgets(d,i,fp);
      if(c==NULL)goto end;
      sprintf(S_str,"%s",c);
      gotoxy(1,Y-1);
      textattr(30);
      cprintf("                                                                               \r");
      cprintf(S_str);
      textattr(7);
 }
}
      end:
     gotoxy(1,25);
     textattr(112);
      cprintf("*** End of File : Use Language TC 2.0 *");
      if(HAN==1){
      gotoxy(1,Y+1);
      cprintf("*** ÆÄÀÏÀÇ ³¡   : »ç¿ë¾ð¾î : Turbo-C  *");
      }
     textattr(7);
     fclose(fp);
 getch();
     return;
}
SYSTEM(){/*½Ã½ºÅÛ ¾È³» ·çÆ¾*/
  long drive_free;
  unsigned long drive_total;
  int a,x,y,ke=0,KEY_C;
  int year,mon,day;
  char *SCR;
    SCR=malloc(4000);
    gettext(1,1,80,25,SCR);
    Cu(0);
    textattr(7);
    Open_Screen();/*È­¸é °¥¶óÁü*/
    Q:
    drive_total=GetTotalDiskSpace(0);
    drive_free=GetAvailDiskSpace(0);
    D=(float)(drive_total-drive_free)/drive_total*100;
   for(y=1;y<=25;y++){
      for(x=1;x<=80;x++){
        textattr(8);
        gotoxy(x,y);
        cprintf("Û");
      }
   }
    for(x=1;x<=80;x++){
        textattr(1);
        gotoxy(x,1);
        cprintf("Û");
    }
    Cprintfxy(24,1,15,9,"System Infomation Ver 1.00          ");
    for(x=10;x<=70;x++){
        textattr(7);
        gotoxy(x,3);
        cprintf("Û");
    }
    Cprintfxy(35,3,1,15,"System Summary");
  for(y=4;y<=20;y++){
    for(x=10;x<=70;x++){
        textattr(1);
        gotoxy(x,y);
        cprintf("Û");
    }
  }
    Cprintfxy(13,5,14,1,"    Computer Name : ");
    Cprintfxy(33,5,15,1,GetComputerName());
    Cprintfxy(13,6,14,1,"Built-In Rom Bios : ");
    gotoxy(33,6);
    textattr(31);
    GetROMDate(&year,&mon,&day);
    cprintf("19%2d-%2d-%2d",year,mon,day);
    Cprintfxy(13,7,14,1,"     Co-Processor : ");
    if(CO()==1){Cprintfxy(33,7,15,1,"Yes(Installed)");
    }else{
     Cprintfxy(33,7,15,1,"No(Not Found)");
    }
    Cprintfxy(13,8,14,1,"    Video-Adaptor : ");
    Cprintfxy(33,8,15,1,GetVideoAdaptor());
    Cprintfxy(49,8,15,1,GetVideoMode());
    Cprintfxy(13,9,14,1,"    Keyboard Type : ");
    Cprintfxy(33,9,15,1,GetKeyboardType());
    Cprintfxy(13,10,14,1,"    Mouse Driver  : ");
   if(ismouse()==0){
    Cprintfxy(33,10,15,1,"Not Install");
    Cprintfxy(45,10,14,1,"Mouse type : ");
    Cprintfxy(58,10,15,1,"I don't Know!");
    goto y2;
   }
   Cprintfxy(33,10,15,1,"Install");
   Cprintfxy(45,10,14,1,"Mouse type : ");
   gotoxy(58,10);
   textattr(31);
   cprintf("%s",GetMouseType());/**/
   y2:
  if(chde==0){
    Cprintfxy(13,12,14,1,"  Floppy Disk A:  : ");
  }
  if(chde==1){
    Cprintfxy(13,12,14,1,"  Floppy Disk B:  : ");
  }
  if(chde==2){
    Cprintfxy(13,12,14,1,"  Hard Disk of C  : ");
  }
   gotoxy(33,12);
   textattr(31);
   cprintf("%4.0lu Mega Bytes",GetTotalDiskSpace(0)/1000000);
   Cprintfxy(13,13,14,1,"      Floppy Disk : ");
 if(IsFloppyDrive()==0){
   Cprintfxy(33,13,15,1,"0 Found");
 }else{
   gotoxy(33,13);
   textattr(31);
   cprintf("%d Found",GetFloppyNo());
 }
   Cprintfxy(13,15,14,1,"       DOS Memory : ");
    gotoxy(33,15);
    textattr(31);
    cprintf("%d KBytes",biosmemory());
   Cprintfxy(13,16,14,1,"  Extended Memory : ");
 if(IsXMM()==0){
   Cprintfxy(33,16,15,1,"Not Installed");
 }else{
   gotoxy(33,16);
   textattr(31);
   cprintf("%d KBytes",GetXMSMemorySize());
 }
 DAS:
   /*** Up is Rootine 1! DOWN is Q-BOX*/
   if(ke==0){
   for(x=17;x<=30;x++){
    textattr(7);
    gotoxy(x,18);
    cprintf("Û");
   }
    Cprintfxy(20,18,4,7,"N");
    Cprintfxy(22,18,0,7,"e x t");

   for(x=47;x<=60;x++){
    textattr(0);
    gotoxy(x,18);
    cprintf("Û");
   }
    Cprintfxy(50,18,4,0,"Q ");
    Cprintfxy(52,18,7,0,"u i t");
   }
  if(ke==1){
   for(x=17;x<=30;x++){
    textattr(0);
    gotoxy(x,18);
    cprintf("Û");
   }
    Cprintfxy(20,18,4,0,"N");
    Cprintfxy(22,18,7,0,"e x t");

   for(x=47;x<=60;x++){
    textattr(7);
    gotoxy(x,18);
    cprintf("Û");
   }
    Cprintfxy(50,18,4,7,"Q ");
    Cprintfxy(52,18,0,7,"u i t");
   }
    KEY_C=KEY();
    if(KEY_C==13){
    ke=0;
    }
    if(KEY_C==14){
    ke=1;
    }
    if(KEY_C==414){
      for(x=17;x<=30;x++){
       textattr(7);
       gotoxy(x,18);
       cprintf("Û");
      }
      Cprintfxy(20,18,4,7,"N");
      Cprintfxy(22,18,0,7,"e x t");
      for(x=47;x<=60;x++){
        textattr(0);
        gotoxy(x,18);
        cprintf("Û");
      }
    Cprintfxy(50,18,4,0,"Q ");
    Cprintfxy(52,18,7,0,"u i t");
    delay(500);
    if(SYSTEM2()==0){
        goto z;
    }
    goto Q;
    }
    if(KEY_C==10||KEY_C==124||KEY_C==416){
   for(x=17;x<=30;x++){
    textattr(0);
    gotoxy(x,18);
    cprintf("Û");
   }
    Cprintfxy(20,18,4,0,"N");
    Cprintfxy(22,18,7,0,"e x t");

   for(x=47;x<=60;x++){
    textattr(7);
    gotoxy(x,18);
    cprintf("Û");
   }
    Cprintfxy(50,18,4,7,"Q ");
    Cprintfxy(52,18,0,7,"u i t");
     delay(500);
     goto z;
    }
    if(KEY_C==15){
     if(ke==0){
      if(SYSTEM2()==0){
        goto z;
      }
      goto Q;
     }
     if(ke==1){
       goto z;
     }
    }
  goto DAS;
   z:
    Cu(1);
    puttext(1,1,80,25,SCR);
    gotoxy(1,25);
    return 0;
}
SYSTEM2(){
   int x,y,a;
   float D;
   for(y=1;y<=25;y++){
      for(x=1;x<=80;x++){
        textattr(8);
        gotoxy(x,y);
        cprintf("Û");
      }
   }
    for(x=1;x<=80;x++){
        textattr(1);
        gotoxy(x,1);
        cprintf("Û");
    }
    Cprintfxy(24,1,15,9,"System Infomation Ver 1.00          ");
    for(x=10;x<=70;x++){
        textattr(7);
        gotoxy(x,3);
        cprintf("Û");
    }
    Cprintfxy(35,3,1,15,"System Summary");
  for(y=4;y<=20;y++){
    for(x=10;x<=70;x++){
        textattr(1);
        gotoxy(x,y);
        cprintf("Û");
    }
  }
   Cprintfxy(13,5,14,1,"     Serial Ports : ");
   gotoxy(33,5);
   textattr(31);
   cprintf("%d Found(s)",GetSerialNo());
   Cprintfxy(13,6,14,1,"   Parallel Ports : ");
   gotoxy(33,6);
   textattr(31);
   cprintf("%d Found(s)",GetParallelNo());
   Cprintfxy(13,8,14,1,"       OS Version : ");
   gotoxy(33,8);
   textattr(31);
   cprintf("DOS %d.%d",_osmajor,_osminor);
   if(_osmajor==7){
     Cprintfxy(42,8,15,1,"Windows '95 or Better[4.XX]");
   }
   drive_total=GetTotalDiskSpace(0);
   drive_free=GetAvailDiskSpace(0);
   D=(float)(drive_total-drive_free)/drive_total*100;
 if(chde==0){
   Cprintfxy(13,10,14,1,"   A drive Total : ");
 }
 if(chde==1){
   Cprintfxy(13,10,14,1,"   B drive Total : ");
 }
 if(chde==2){
   Cprintfxy(13,10,14,1,"   C drive Total : ");
 }
   gotoxy(33,10);
   textattr(31);
   cprintf("%lu",drive_total);
 if(chde==0){
   Cprintfxy(13,11,14,1,"   A drive Free  : ");
 }
 if(chde==1){
   Cprintfxy(13,11,14,1,"   B drive Free  : ");
 }
 if(chde==2){
   Cprintfxy(13,11,14,1,"   C drive Free  : ");
 }
   gotoxy(33,11);
   textattr(31);
   cprintf("%lu (%2.1f%%)",drive_free,100-D);
   gotoxy(12,14);
   textattr(30);
    cprintf("   FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
   for(a=1;a<=D/2;a++){
    gotoxy(12+a,14);
   textattr(31);
    cprintf("W");
   }
   Cprintfxy(12,15,14,1,"  W : Write ");
   Cprintfxy(12,16,14,1,"  F : Free  ");

      for(x=32;x<=44;x++){
       textattr(7);
       gotoxy(x,18);
       cprintf("Û");
      }
      Cprintfxy(34,18,4,7,"N ");
      Cprintfxy(36,18,0,7,"e x t ");
    for(x=33;x<=45;x++){
      Cprintfxy(x,19,0,0,"ß");
    }
      getch();
      for(x=32;x<=44;x++){
       textattr(1);
       gotoxy(x,18);
       cprintf("Û");
      }
      for(x=34;x<=46;x++){
       textattr(7);
       gotoxy(x,18);
       cprintf("Û");
      }
      Cprintfxy(36,18,4,7,"N ");
      Cprintfxy(38,18,0,7,"e x t ");
    for(x=33;x<=45;x++){
      Cprintfxy(x,19,1,1,"ß");
    }
      delay(500);
      return -1;
}
Help(int HAN){
         char *SAT3;
          SAT3=malloc(4000);
          gettext(1,1,80,25,SAT3);
          clrscr();
          if(HAN==1){
            fp=fopen("KTW.HLP","r");
           if(fp==NULL){
              textattr(7);
              cprintf("\aKTW.HLP not found!");
              getch();
              puttext(1,1,80,25,SAT3);
              free(SAT3);
              return 0;
           }
           goto ERTY;
          }
          fp=fopen("KT.HLP","r");
          if(fp==NULL){
             textattr(7);
             cprintf("\aKT.HLP not found!");
             getch();
             puttext(1,1,80,25,SAT3);
             free(SAT3);
             return 0;
          }
          ERTY:
          if(fgetc(fp)!=''){
             textattr(7);
             cprintf("\aFile Change... Re Install!");
             getch();
             puttext(1,1,80,25,SAT3);
             free(SAT3);
             return 0;
          }
          SWP(HAN,"KT.HLP");
         if(HAN==1){
          SWP(HAN,"KTW.HLP");
         }
          puttext(1,1,80,25,SAT3);
          free(SAT3);
          return 0;
}
PaK(){
   union REGS r;
   r.h.ah=0x19;
   r.h.dl=0x80;
   int86(0x13,&r,&r);
   return;
}
char *SAT1,*SHADOW;
Park(Windows){
          int KEY_CODE;
          ROOTINE();
          gotoxy(11,12);
          cprintf("         Parking  is  Completed!             ");
          if(Windows==1){
          gotoxy(11,12);
          cprintf("   ÇÏµå µð½ºÅ©°¡ ÆÄÅ· µÇ¾ú½À´Ï´Ù.            ");
          }
          gotoxy(11,13);
          cprintf("         Turn off the Your Computer...       ");
          if(Windows==1){
          gotoxy(11,13);
          cprintf("     ÄÄÇ»ÅÍÀÇ ÆÄ¿ö¸¦ ²ô¼Åµµ ÁÁ½À´Ï´Ù.        ");
          }
          cline(11,12,44,78);
      P:
      PaK();
      KEY_CODE=KEY();
      if(KEY_CODE==10){puttext(10,11,56,14,SAT1);free(SAT1);
                       puttext(12,15,53,16,SHADOW);free(SHADOW);return 0;}
      if(KEY_CODE!=10){
        KEY_CODE=0;
       goto P;
      }
    return 0;
}
char F[200];
CDIR(int Windows){
   ROOTINE();
   gotoxy(11,12);
   cprintf("         Directory Change Wizard            ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf("         °æ·Î ¹Ù²Ù±â ¸¶¹ý»ç                 ");
   }
   gotoxy(43,13);
   cprintf("            ");
   textattr(7);
   gotoxy(11,13);
   Cu(1);
   input_string(11,13,F,44,95);
   textattr(15);
   if( chdir(F) ) {
      cline(11,15,50,78);
      gotoxy(11,15);
      fprintf(stderr, "Failure : %s is not changed\n", F);
      if(Windows==1){
         gotoxy(11,15);
         fprintf(stderr, "¿À·ù¹ß»ý: %s·Î Á¢±Ù ¸øÇÔ.\n", F);
      }
      getch();
      puttext(10,11,56,14,SAT1);free(SAT1);
      return 0;
  }
  Cu(0);
  DISK_PATH();
  return 1;
}
Cprintfxy(int x,int y,int foreground_color,int background_color,char *string)
{
 gotoxy(x,y);                      /* Äá¬á· ¶áÃ¡Ÿi ¥e‰w */
 textcolor(foreground_color);      /* ¸å‰w¬‚ ¬é¸÷ */
 textbackground(background_color); /* ¤‰w¬‚ ¬é¸÷ */
 cprintf("%s",string);             /* ¢…¸aµi Â‰b */
 return 0;
}
EASYLINK(int Windows){
   int FN;
   ROOTINE();
   gotoxy(11,12);
   cprintf(" ST EasyLink Ver 2.0  Filename.ext          ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf(" »ïµ¹ ½¬¿î ÆÄÀÏ¿¬°á ¹öÁ¯ 2.0  ÆÄÀÏ¸í.È®ÀåÀÚ ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7); gotoxy(11,13);  Cu(1);
    input_string(11,13,F,44,95);
    for(FN=0;FN<=13;FN++){
       if(F[FN]=='.'){
          if(F[FN+1]=='T'&&F[FN+2]=='X'&&F[FN+1]=='T'||F[FN+1]=='t'&&F[FN+2]=='x'&&F[FN+1]=='t'){
             clrscr();
             SWP(Windows,F);
             goto ERT;
          }
          if(F[FN+1]=='B'&&F[FN+2]=='A'&&F[FN+1]=='K'||F[FN+1]=='b'&&F[FN+2]=='a'&&F[FN+1]=='k'){
             clrscr();
             unlink(F);
             goto ERT;
          }
          else{
            ERRA();
            cprintf(" %s is I don't know file format             ",F);
            if(Windows==1){
               cprintf(" %s ´Â ¾Ë¼ö¾ø´Â ÆÄÀÏ Çü½Ä ÀÔ´Ï´Ù.           ",F);
            }
            getch();
            goto ERT;
          }
       }
    }
    ERT:
    puttext(1,1,80,25,SAT1);
    free(SAT1);
    Cu(0);
    return 0;
}
CO(){
 if(IsCoprocessor()==0){
   return 0;
 }else{
 return 1;
 }
}
HWP_TXT(int Windows){
   int CANCEL=0;
   char FM[50];
   ROOTINE();
   gotoxy(11,12);
   cprintf("         Enter a HWP Filename               ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf("         HWP ÆÄÀÏÀÌ¸§À» ³Ö¾î ÁÖ¼¼¿ä         ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7); gotoxy(11,13);  Cu(1);
    CANCEL=input_string(11,13,F,44,95);
    if(CANCEL==0||F=='\0'){
      strcpy(F," ");
    }
    strcpy(FM,"HWP2TXT ");
    strcat(FM,F);
    strcat(FM," ");
    strcat(FM,"$_H2T_$.TXT>nul");
    system(FM);
    puttext(10,11,56,14,SAT1);
    free(SAT1);
    Cu(0);
    return 0;
}
DFILE(int Windows,int x,int y){
char bs[200];
    int root=0,CANCEL=0,done;
    if(newpath[3]==NULL){/*ROOT*/
         root=1;
    }
   ROOTINE();
   if(y!=4||x!=1&&y==4){/*Delete*/
      if(x==1){
         if(root==1){
          strcpy(bs,filename[y-4]);
         }else{
          strcpy(bs,filename[y-3]);
         }
          strcpy(F,bs);
        }
       if(x==14){
         if(root==1){
          strcpy(bs,filename[y+16]);
         }else{
          strcpy(bs,filename[y+17]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+17+19]);
         }else{
          strcpy(bs,filename[y+17+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+19]);
         }else{
          strcpy(bs,filename[y+17+20+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+20+19]);
         }else{
          strcpy(bs,filename[y+17+20+20+20]);
         }
          strcpy(F,bs);
       }
    }
    done=findfirst(bs,&f,FA_LIST);
    if(f.ff_attrib==FA_DIREC){
       DEL_DIR(Windows);
       puttext(10,11,56,14,SAT1);
       free(SAT1);
       Cu(0);
       return 0;
    }
   gotoxy(11,12);
   cprintf("         Enter a Delete Filename            ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf("         ÆÄÀÏ Áö¿ì±â ¸¶¹ý»ç                 ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7); gotoxy(11,13);  Cu(1);
    CANCEL=input_string(11,13,F,44,95);
    if(CANCEL==0||F=='\0'){
      strcpy(F," ");
    }
    unlink(F);
    puttext(10,11,56,14,SAT1);
    free(SAT1);
    Cu(0);
    return 0;
}
EXE_ROOTINE(int Windows,int x,int y){
  char bs[200];
  int root=0,CANCEL=0;
    if(newpath[3]==NULL){/*ROOT*/
         root=1;
    }
   ROOTINE();
   if(y!=4||x!=1&&y==4){/*Delete*/
      if(x==1){
         if(root==1){
          strcpy(bs,filename[y-4]);
         }else{
          strcpy(bs,filename[y-3]);
         }
          strcpy(F,bs);
        }
       if(x==14){
         if(root==1){
          strcpy(bs,filename[y+16]);
         }else{
          strcpy(bs,filename[y+17]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[36+y]);
         }else{
          strcpy(bs,filename[37+y]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[56+y]);
         }else{
          strcpy(bs,filename[57+y]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[76+y]);
         }else{
          strcpy(bs,filename[77+y]);
         }
          strcpy(F,bs);
       }
    }
   gotoxy(11,12);
   cputs("         Enter a Execute Filename           ");
   if(Windows==1){
      gotoxy(11,12);
      cputs("          ÆÄÀÏ ½ÇÇà  ¸¶¹ý»ç                 ");
   }
   gotoxy(43,13);
   cprintf("            ");
   textattr(7);
   gotoxy(11,13);
   Cu(1);
   CANCEL=input_string(11,13,F,44,95);
   if(CANCEL==0||F[0]==''){
    goto ERn;
   }
   clrscr();
   STBAT(F);
   Buffer();
   ERn:
   puttext(10,11,56,14,SAT1);
   free(SAT1);
   Cu(0);
   return 0;
}
DMAKE(int Windows){
    ROOTINE();
    gotoxy(11,12);
    cprintf("         Directory Make Wizard              ");
    if(Windows==1){
       gotoxy(11,12);
       cprintf("         °æ·Î ¸¸µé±â ¸¶¹ý»ç                 ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7);
    gotoxy(11,13);
    Cu(1);
    input_string(11,13,F,44,95);
    textattr(15);
    if( mkdir(F) ) {
        cline(11,15,50,78);
        gotoxy(11,15);
        fprintf(stderr, "Failure : %s is not make\n", F);
        if(Windows==1){
        gotoxy(11,15);
        fprintf(stderr, "¿À·ù¹ß»ý: %s¸¦ ¸¸µéÁö ¸øÇÔ.\n", F);
        }
        getch();
    }
    DISK_PATH();
    puttext(10,11,56,14,SAT1);
    free(SAT1);
    Cu(0);
    return 0;
}
DEL_DIR(int Windows){
   ROOTINE();
   gotoxy(11,12);
   cprintf("         Directory Delete Wizard            ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf("         °æ·Î Áö¿ì±â ¸¶¹ý»ç                 ");
   }
   gotoxy(43,13);
   cprintf("            ");
   textattr(7);
   gotoxy(11,13);
   Cu(1);
   input_string(11,13,F,44,95);
   textattr(15);
   if( rmdir(F) ) {
      cline(11,15,50,78);
      gotoxy(11,15);
      fprintf(stderr, "Failure : %s is not delete\n", F);
      if(Windows==1){
      gotoxy(11,15);
      fprintf(stderr, "¿À·ù¹ß»ý: %s¸¦ Áö¿ìÁö ¸øÇÔ.\n", F);
      }
    getch();
   }
    DISK_PATH();
    puttext(10,11,56,14,SAT1);
    free(SAT1);
    Cu(0);
    return 0;
}
DRIVEB(int Windows){
int ERR,KEY_CODE,ACR=0;
  Cu(0);
 ERR=biosdisk(0x16);
 if(ERR!=0){
    ERR=0;
    ERR=biosdisk(0x4,1);
    if(ERR!=128){
     return 0;
    }
    if(ERR==128){
       ROOTINE();
       gotoxy(11,12);
       /*General error*/
       cprintf("\aDrive Not Ready in B: Yes(Retry)/No(ignore)!");
       if(Windows==1){
          gotoxy(11,12);
          cprintf("\aµå¶óÀÌºê B:¿¡ ¹®ÀÌ¿­¸² Yes(´Ù ½Ã)/No(Æ÷ ±â)!");
       }
       DAUM2:
       cline(11,12,44,78);
       Me2:
       if(ACR==0){
          textattr(7);
          gotoxy(27,13);
          cprintf("   Yes   ");
          gotoxy(37,13);
          textattr(95);
          cprintf("   No             ");
       }
       if(ACR==1){
          textattr(95);
          gotoxy(27,13);
          cprintf("   Yes   ");
          gotoxy(37,13);
          textattr(7);
          cprintf("   No    ");
       }
         KEY_CODE=KEY();
         if(KEY_CODE==13){ACR=KEY_CODE=0;goto Me2;}
         if(KEY_CODE==14){ACR=1;KEY_CODE=0;goto Me2;}
         if(KEY_CODE==10){puttext(10,11,56,14,SAT1);Cu(1);return -1;}
         if(KEY_CODE==15){
            if(ACR==0){
               KEY_CODE=0;
               DISK_PATH();
               Cu(1);
               return 0;
            }else{
                puttext(10,11,56,14,SAT1);
                Cu(1);
                return -1;
            }
         }
         getch();
      }
   }
     textattr(7);
     Cu(1);
     return 0;
}
DRIVEA(int Windows){
int ERR=0,KEY_CODE,ACR=0;
   Cu(0);
   ERR=biosdisk(0x16);
   if(ERR!=0){
      ERR=0;
      ERR=biosdisk(0x4,0);
      if(ERR!=128){
        return 0;
      }
      if(ERR==128){
         ROOTINE();
         gotoxy(11,12);
          /*General error*/
          cprintf("\aDrive Not Ready in A: Yes(Retry)/No(ignore)!");
          if(Windows==1){
             gotoxy(11,12);
             cprintf("\aµå¶óÀÌºê A:¿¡ ¹®ÀÌ¿­¸² Yes(´Ù ½Ã)/No(Æ÷ ±â)!");
             ACR=0;
          }
       }
         DAUM:
         cline(11,12,44,78);
         Me:
       if(ACR==0){
          textattr(7);
          gotoxy(27,13);
          cprintf("   Yes   ");
          gotoxy(37,13);
          textattr(95);
          cprintf("   No             ");
       }
       if(ACR==1){
            textattr(95);
            gotoxy(27,13);
            cprintf("   Yes   ");
            gotoxy(37,13);
            textattr(7);
            cprintf("   No    ");
       }
       KEY_CODE=KEY();
         if(KEY_CODE==13){ACR=KEY_CODE=0;goto Me;}
         if(KEY_CODE==14){ACR=1;KEY_CODE=0;goto Me;}
         if(KEY_CODE==10){puttext(10,11,56,14,SAT1);Cu(1);return -1;}
         if(KEY_CODE==15){
            if(ACR==0){
               KEY_CODE=0;
               DISK_PATH();
               Cu(1);
               return 0;
            }else{
                puttext(10,11,56,14,SAT1);
                Cu(1);
                return -1;
              }
           }
          getch();
    }/*else´Ý°³*/
    textattr(7);
    Cu(1);
     return 0;
}
MAKE_ST_BAT(char DIR[200]){
 fp=fopen("c:\\_SCSAVE_.BAT","r");
  if(fp==NULL){
     fclose(fp);
     fp=fopen("c:\\_SCSAVE_.BAT","w");
     fprintf(fp,"@ECHO OFF\n");
     fprintf(fp,"%s\\snow.exe",DIR);
     fclose(fp);
  }
 fclose(fp);

 fp=fopen("c:\\_KTREE_.BAT","r");
  if(fp==NULL){
     fclose(fp);
     fp=fopen("c:\\_KTREE_.BAT","w");
     fprintf(fp,"@ECHO OFF\n");
     fprintf(fp,"%s\\kttr.exe",DIR);
     fclose(fp);
  }
 fclose(fp);

 fp=fopen("c:\\_KT_.BAT","r");
 if(fp==NULL){
    fclose(fp);
    fp=fopen("c:\\_KT_.BAT","w");
    fprintf(fp,"@ECHO OFF\n");
    fprintf(fp,"%s\\kt.exe/f",DIR);
    fclose(fp);
 }
 fclose(fp);
 fp=fopen("_KTW_.BAT","r");
 if(fp==NULL){
    fclose(fp);
    fp=fopen("c:\\_KTW_.BAT","w");
    fprintf(fp,"@ECHO OFF\n");
    fprintf(fp,"%s\\kt.exe/w",DIR);
    fclose(fp);
 }
 fclose(fp);
 fp=fopen("KT.BAT","r");
 if(fp!=NULL){
  unlink("kt.bat");
  fclose(fp);
 }
 fclose(fp);
 return 0;
}
void STBAT(char filena[200]){
  fp=fopen("KT.BAT","w");
  fprintf(fp,"cls>nul",filena);
  fprintf(fp,"\nCALL %s",filena);
  fprintf(fp,"\nC:\\_KT_.BAT");
  fclose(fp);
}
void STWBAT(char filena[200]){
  fp=fopen("KT.BAT","w");
  fprintf(fp,"cls>nul",filena);
  fprintf(fp,"\nCALL %s",filena);
  fprintf(fp,"\nC:\\_KTW_.BAT");
  fclose(fp);
}
int DRIVE_PRINTF(int x,int y){
 int FN;
 FN=GetFloppyNo();
 if(FN==0){
  goto CDE;
 }
 if(y>23){
    y=4;
    gotoxy(x+13,y);
    textattr(6);
    cputs("[-A-]");
    x=x+13;
    y+=1;
    wy=y;
    goto DAM;
 }
 gotoxy(x,y);
 textattr(6);
 cputs("[-A-]");
 y+=1;
 DAM:
if(FN==2){
 if(y>23){
    y=4;
   gotoxy(x+13,y);
   cputs("[-B-]");
   y+=1;x+=13;
   goto DAM2;
 }
   gotoxy(x,y);
   cputs("[-B-]");
   y+=1;
}
 DAM2:
 CDE:
 if(y>23){
   y=4;
   gotoxy(x+13,y);
   cputs("[-C-]");
   y+=1;x+=13;
   return wy;
 }
   gotoxy(x,y);
   cputs("[-C-]");
   return wy;
}
void ROOTINE(){
    SAT1=malloc(4000);
    gettext(10,11,56,14,SAT1);
    ERRA();
}
void ROOTINE2(){
    SAT1=malloc(4000);
    gettext(10,8,52,16,SAT1);
    ERRB();
}
int FINFO2(int Windows,int x,int y){
    char bs[41];
    int root=0,done;
    if(newpath[3]==NULL){/*ROOT*/
         root=1;
    }
      if(x==1){
         if(root==1){
          strcpy(bs,filename[y-4]);
         }else{
          strcpy(bs,filename[y-3]);
         }
          strcpy(F,bs);
        }
       if(x==14){
         if(root==1){
          strcpy(bs,filename[y+16]);
         }else{
          strcpy(bs,filename[y+17]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+17+19]);
         }else{
          strcpy(bs,filename[y+17+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+19]);
         }else{
          strcpy(bs,filename[y+17+20+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+20+19]);
/*2020*/ }else{
          strcpy(bs,filename[y+17+20+20+20]);
         }
          strcpy(F,bs);
       }
    done=findfirst(bs,&f,FA_LIST);

    textattr(62);

    gotoxy(67,8);
    cprintf("S");
    textattr(63);
    gotoxy(68,8);
    cprintf("ize         ");
    gotoxy(67,9);
   if(bs[1]==':'){
     gotoxy(67,9);
     cprintf("Drive %2s     ",bs);
     goto dadf;
   }
   if(bs[0]==''){
     gotoxy(67,9);
     cprintf("Free Shell   ",bs);
     goto dadf;
   }
   if(f.ff_attrib!=FA_DIREC){
     if(f.ff_fsize>99999999){           /* 99,999,999 Up = 99,999 KB UP*/
      cprintf("%8ld KB  ",f.ff_fsize/1000);
     }else{
      cprintf("%8ld Byte",f.ff_fsize);     /* 99,999,999 Low*/
     }
   }else{
    gotoxy(67,9);
    cprintf("  Directory  ");
   }
    dadf:
    textattr(62);
    gotoxy(67,10);
    cprintf("M");
    textattr(63);
    gotoxy(68,10);
    cprintf("ake day     ");
    gotoxy(67,11);
    cprintf("%4d-%02d-%02d   ",(f.ff_fdate>>9)+1980,     /* ‘e */
                                                  (f.ff_fdate>>5) & 0x000f, /* ¶© */
                                                   f.ff_fdate & 0x001f);    /* ·© */
    textattr(62);
    gotoxy(67,12);
    cprintf("T");
    textattr(63);
    gotoxy(68,12);
    cprintf("ime         ");
    gotoxy(73,12);
    cprintf("%02d:%02d ",f.ff_ftime>>11,                 /* ¯¡ */
                                     (f.ff_ftime>>5) & 0x003f);      /* ¦… */
    gotoxy(67,14);
    cprintf("Attribute ");
    gotoxy(67,15);
    textattr(7);
    cprintf(".....");
    if(f.ff_attrib & FA_ARCH){  gotoxy(67,15);textattr(7); cprintf("A");}
    if(f.ff_attrib & FA_DIREC){ gotoxy(68,15);textattr(12); cprintf("D");}
    if(f.ff_attrib & FA_SYSTEM){gotoxy(69,15);textattr(4); cprintf("S");}
    if(f.ff_attrib & FA_RDONLY){gotoxy(70,15);textattr(14); cprintf("R");}
    if(f.ff_attrib & FA_HIDDEN){gotoxy(71,15);textattr(10); cprintf("H");}
    delay(10);
    return 0;
}
void FINFO(int Windows,int x,int y){
    char bs[41];
    int root=0,done;
    if(newpath[3]==NULL){/*ROOT*/
         root=1;
    }
    ROOTINE2();
      if(x==1){
         if(root==1){
          strcpy(bs,filename[y-4]);
         }else{
          strcpy(bs,filename[y-3]);
         }
          strcpy(F,bs);
        }
       if(x==14){
         if(root==1){
          strcpy(bs,filename[y+16]);
         }else{
          strcpy(bs,filename[y+17]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+17+19]);
         }else{
          strcpy(bs,filename[y+17+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+19]);
         }else{
          strcpy(bs,filename[y+17+20+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+20+19]);
/*2020*/ }else{
          strcpy(bs,filename[y+17+20+20+20]);
         }
          strcpy(F,bs);
       }
    done=findfirst(bs,&f,FA_LIST);
    ERRB();
    textattr(95);
    gotoxy(12,9);
    cprintf("  Samdol Tools '99  File infoamtion ");
    cline(11,9,40,112);
    cline(11,10,40,95);
    cline(11,11,40,95);
    cline(11,12,40,95);
    cline(11,13,40,95);
    cline(11,14,40,95);
    cline(11,15,25,95);
    gotoxy(15,10);
    cprintf("Filename  : %-13s           ",bs);
    if(f.ff_attrib==FA_DIREC){
       gotoxy(15,10);
    cprintf("Directory Name : %-13s    ",bs);
    }
    gotoxy(15,11);
    cprintf("Make day,Time :  %4d-%02d-%02d   ",(f.ff_fdate>>9)+1980,     /* ‘e */
                                                  (f.ff_fdate>>5) & 0x000f, /* ¶© */
                                                   f.ff_fdate & 0x001f);    /* ·© */
    cprintf("%02d:%02d ",f.ff_ftime>>11,                 /* ¯¡ */
                                     (f.ff_ftime>>5) & 0x003f);      /* ¦… */
    gotoxy(15,12);
    cprintf("Attribute : ");
    if(f.ff_attrib & FA_ARCH){cprintf("Arch");}
   if(f.ff_attrib & FA_DIREC){cprintf(" Direc");}
  if(f.ff_attrib & FA_SYSTEM){cprintf(" Sys");}
  if(f.ff_attrib & FA_RDONLY){cprintf(" R.Only");}
  if(f.ff_attrib & FA_HIDDEN){cprintf(" Hide");}
    gotoxy(15,13);
    cprintf("Size : %9ld Byte(s)",f.ff_fsize);
    getch();
    free(SAT1);
}
void RENAME(int Windows,int x,int y){
    char bs[41];
    int root=0;
    if(newpath[3]==NULL){/*ROOT*/
         root=1;
    }
    ROOTINE();
    if(y!=4||x!=1&&y==4){/*AR*/
      if(x==1){
         if(root==1){
          strcpy(bs,filename[y-4]);
         }else{
          strcpy(bs,filename[y-3]);
         }
          strcpy(F,bs);
        }
       if(x==14){
         if(root==1){
          strcpy(bs,filename[y+18]);
         }else{
          strcpy(bs,filename[y+17]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+17+21-2]);
         }else{
          strcpy(bs,filename[y+17+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+21-2]);
         }else{
          strcpy(bs,filename[y+17+20+20]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+17+20+20+21-2]);
         }else{
          strcpy(bs,filename[y+17+20+20+20]);
         }
          strcpy(F,bs);
       }
    }

    gotoxy(11,12);
    cprintf("         Filename Change Wizard             ");
    if(Windows==1){
       gotoxy(11,12);
       cprintf("        ÆÄÀÏÀÌ¸§ ¹Ù²Ù±â ¸¶¹ý»ç              ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7);
    gotoxy(11,13);
    Cu(1);
    cline(11,13,15,95);
    input_string(11,13,F,44,95);
    textattr(15);
    rename(bs,F);
}
void Re_Install(){
  unlink("c:\\_kt_.bat");
  unlink("c:\\_ktree_.bat");
  unlink("c:\\_SCSAVE_.bat");
  unlink("c:\\_ktw_.bat");
}
KDIR(){
      fp=fopen("KTTR.EXE","r");
      if(fp==NULL){
        textattr(7);
        clrscr();
        system("_KTREE_.BAT");
        return 0;
      }
      system("KTTR.EXE");
      return 0;
}
