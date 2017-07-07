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
#define SPACE   0x3920

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
#define _slu    0x352f

#define Dote     0x343e
#define dote     0x342e
#define FA_LIST  FA_ARCH|FA_SYSTEM|FA_RDONLY|FA_HIDDEN|FA_DIREC

void CTRL_T();
void STBAT(char filena[200]);
void STWBAT(char filena[200]);
void ROOTINE();
int FINFO2(int Windows,int x,int y);
void Re_Install();

char NA[]="Kwangsung Tools  '99 Ver 1.10                                             ";
char NAH[]=" ±§ º∫ ≈¯ ¡Ó   '99 Ver 1.10                                              ";
char Ver[]="Kwangsung Tools '99 Ver 1.10";
char VerH[]=" ±§ º∫ ≈¯ ¡Ó  '99 Ver 1.10 ";
char Ju[]="";
char JuP[]="≥";
char savepath[MAXPATH],newpath[MAXPATH],OldA[MAXPATH],*PN="PATH",*PN2="∞Ê∑Œ";
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
int COPY2(int x,int y);
int ADR;
int BDR;
int DDR;
void ABOUT(int han);
void FILE_PRINTF(int Windows,int attrib,int AD,int BD,int DD);
int ENTER_ROOTINE(int Windows,int x,int y);
unsigned char getcolorxy(int x,int y);

void ABOUT(int han){
     int aq=1,YY=7,ie=255,ban,dd,YesNo,DAEGI=0;/*DAEGI=µÓ∑œ¿œ ∞ÊøÏ ±‚¥Ÿ∏≤¿« ºˆ*/
     char *c,d[255];
     SAT=malloc(4000);
     gettext(20,5,55,11,SAT);
     gotoxy(10,5);
     YesNo=CFG_OPEN();
     if(YesNo==0){/*µÓ∑œ∆« æ∆¥—∞ÊøÏ*/
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
    }/*µÓ∑œ∆« æ∆¥—∞ÊøÏ*/
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
      printf("* µÓ∑œ¿⁄ ¡§∫∏  \n");
      gotoxy(23,8);
      printf("¿Ã∏ß : ");     gotoxy(23,9);     printf("π¯»£ : ");
      gotoxy(21,10);
      printf("(C)∏∏µÁ∂ß 1997~1999 ∏∏µÁ¿Ã «—¿Œ≈√\n");
      textattr(7);
     }
    fp=fopen("c:\\kt.cfg","r");
     for(aq=1;aq<6;aq++){
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
    if(aq==3){
     goto h;
    }
  }
   h:
   cline(21,6,33,112);
    for(DAEGI=1;DAEGI<=300;DAEGI++){
       delay(10);
       if(kbhit())goto da;
    }
   da:
    fclose(fp);
    puttext(20,5,55,11,SAT);
    kbhit();
    bioskey(0);
    free(SAT);
}
ADRIVE_IFO(){
     int aq=1,ie=255;
     char *c,d[200];
    fp=fopen("c:\\kt.cfg","r");
     for(aq=1;aq<5;aq++){
      c=fgets(d,ie,fp);
     if(aq==3){
      ADR=atoi(c);
     }
    }
    fclose(fp);
    return ADR;
}
BDRIVE_IFO(){
     int aq=1,ie=255;
     char *c,d[200];
    fp=fopen("c:\\kt.cfg","r");
     for(aq=1;aq<5;aq++){
      c=fgets(d,ie,fp);
     if(aq==4){
      BDR=atoi(c);
     }
    }
    fclose(fp);
    return BDR;
}
DDRIVE_IFO(){
     int aq=1,ie=255;
     char *c,d[200];
    fp=fopen("c:\\kt.cfg","r");
     for(aq=1;aq<6;aq++){
      c=fgets(d,ie,fp);
     if(aq==5){
      DDR=atoi(c);
     }
    }
    fclose(fp);
    return DDR;
}
JUL(int x,int color,int mode){
  int a;
  textattr(color);
  for(a=4;a<=22;a++){
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
      char *MOK="(¿ª)∏¶ Ω««‡ «’¥œ¥Ÿ.";
      char *NA="Kwang-sung Tools '99 Ver 1.50[1.50.000]                                         ";
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
          cprintf("\nªÁøÎπ˝:> C:\\KT>KT.EXE [/º±≈√ªÁ«◊] ∆ƒ¿œ¿Ã∏ß.»Æ¿Â¿⁄(/XHø…º«µ⁄)   \n\n\r");
          cprintf("\nº±≈√ªÁ«◊] V = πˆ¡Ø%s                                              \n\n\r",MOK);
          textattr(14);
          cprintf("  D ");
          textattr(7);
          cprintf("= ∆ƒ¿œ∫∏∞≥∏¶ Ω««‡ «’¥œ¥Ÿ.                              \n\r");
          textattr(14);
          cprintf("  S,X,G ");
          textattr(7);
          cprintf("= Ω√Ω∫≈€∫∏∞≥,πÆº≠ ¿–∞≥(Gø…º«¿∫ «—±€∏µÂ)∏¶ Ω««‡ «’¥œ¥Ÿ.\n\r");
          textattr(14);
          cprintf("  W");
          textattr(7);
          cprintf(" = «—±€ ¿©µµøÏ 95ø°º≠ «—±€∏µÂ∑Œ Ω««‡(µµΩ∫ø°º≠µµ «—±€ƒ´µÂ±Ú∞Ì..)\n\r");
          textattr(14);
          cprintf("  E");
          textattr(7);
          cprintf(" = «—±€∏µÂø°º≠ øµπÆ∏µÂ∑Œ πŸ≤€»ƒ  STΩ««‡ «’¥œ¥Ÿ.               \n\r");
          textattr(14);
          cprintf("  U");
          textattr(7);
          cprintf(" = ±§º∫¿« ¿”Ω√ πËƒ°∆ƒ¿œ¿ª ¥ŸΩ√ ∏∏µÏ¥œ¥Ÿ.(±§º∫≈¯¡Ó ∞Ê∑Œ∞° πŸ≤Ô∞ÊøÏ\n\r");
          textattr(14);
          cprintf("  P");
          textattr(7);
          cprintf(" = ±§º∫¿« ∆ƒ¿œ ƒ⁄µÂ πŸ≤Ÿ∞≥∏¶ Ω««‡ «’¥œ¥Ÿ.(∆ƒ¿œ æœ»£»≠! æœ»£«Æ±‚) \n\r");
          textattr(14);
          cprintf("  ?,H");
          textattr(7);
          cprintf(" = øµπÆ∏µÂ µµøÚ∏ª, ¿Ã »≠∏È                                   \n\n\n\r");
          cprintf("\nº±≈√ªÁ«◊ æ¯¿∏∏È = ±§º∫≈¯¡Ó Ω««‡«’¥œ¥Ÿ.                            \n\r");
                         randomize();
                 dasikara1:
                     gotoxy(1,24);
                     textattr(30);
                     Ram=random(11)+1;
                     if(Ram==1||Ram==7)cprintf("±§º∫≈¯¡Ó¥¬ «—¿Œ≈√¿Ã ∏∏µÈæ˙Ω¿¥œ¥Ÿ.                                             ");
                     if(Ram==2||Ram==8)cprintf("«ÿƒøΩ√Ω∫≈€¿∫ ¿Œ√µ¿« ±§º∫∞ÌµÓ«–±≥¿« ≈¨∑¥¿‘¥œ¥Ÿ                                 ");
                     if(Ram==3||Ram==9)cprintf("¿©µµøÏ 95∏¶ ªÁøÎ «—¥Ÿ∏È KT.EXE/W∏¶ «ÿ ∫∏ººø‰!                                 ");
                     if(Ram==4||Ram==10)cprintf("«—±π¿ª øµπÆ¿∏∑Œ «•±‚«œ∏È Corea¿‘¥œ¥Ÿ. ¿˝¥Î Korea∞° æ∆¥’¥œ¥Ÿ.                 ");
                     if(Ram==5||Ram==11)cprintf("IFM¥¬ ¿·Ω√ª”... øÏ∏Æ¥¬ ¥ŸΩ√ ¿œæÓ º≥ºˆ ¿÷Ω¿¥œ¥Ÿ! =¿Œ≈√ª˝∞¢=                   ");
                     if(Ram==6||Ram==12)cprintf("µ∂µµ¥¬ «—±π∂• ¿‘¥œ¥Ÿ. ¿œ∫ª¿Ã øÏ∞‹µµ.....                                     ");
                     delay(700);
                     Ran++;
                     if(Ran==7)exit(1);
                     goto dasikara1;
             }
   return 0;
}
int FileN=0,fn=0,Dulda=0;
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
     gotoxy(1,23);
     cprintf("");
     textattr(7);
     return 0;
     }
     cprintf("ÕÕÕÕÕÕÕÕÕÕÕÕ—ÕÕÕÕÕÕÕÕÕÕÕÕ—ÕÕÕÕÕÕÕÕÕÕÕÕ—ÕÕÕÕÕÕÕÕÕÕÕÕ—ÕÕÕÕÕÕÕÕÕÕÕÕ—ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕ");
     JUL(65,3,Windows);
     JUL(52,3,Windows);
     JUL(39,3,Windows);
     JUL(26,3,Windows);
     JUL(13,3,Windows);
     gotoxy(1,23);
     cprintf("ÕÕÕÕÕÕÕÕÕÕÕÕœÕÕÕÕÕÕÕÕÕÕÕÕœÕÕÕÕÕÕÕÕÕÕÕÕœÕÕÕÕÕÕÕÕÕÕÕÕœÕÕÕÕÕÕÕÕÕÕÕÕœÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕ");
     textattr(7);
     return 0;
}
char filename[1000][16];
char *DDD="";
void FILE_PRINTF(int Windows,int attrib,int AD,int BD,int DD){
     int done,X=1,I=4,a=0,p,S2=0,S=0,PA,at,filesu=0,VL,i=0,root=0;
      Cu(0); a=0;
      SIZE=FileN=fn=0;  chde=chde;
      DISK_PATH();
  if(newpath[3]==''){
    gotoxy(1,2);
    root=1;
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
   root=0;
    gotoxy(1,2);
    if(Windows==0){
    cprintf("%s %s\\%s",PN,newpath,FILENAM);
    }else{
    cprintf("%s %s\\%s",PN2,newpath,FILENAM);
    }
    A3:
    VL=findfirst("*.*",&f,FA_LABEL);
    if(VL==-1){
     gotoxy(70,2);
     puts("Volume[]");
    }else{
     parsfnm(f.ff_name,&fcb,0);
     gotoxy(60,2);
     cprintf("Volume[%-8s]",fcb.fcb_name);
    }
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
   while(done==0){/*∆ƒ¿œ √‚∑¬ ∑Á∆æ*/
    strcpy(filename[filesu],f.ff_name);
     if(a==0&&fn+FileN>=19){
        X=14; I=4; a=1;
     }
     if(a==1&&fn+FileN>=38){
        X=27; I=4; a=2;
     }
     if(a==2&&fn+FileN>=57){
        X=40; I=4; a=3;
     }
     if(a==3&&fn+FileN>=76){
        X=53; I=4; a=4;
     }
     if(a==4&&fn+FileN>=95){
        X=66;I=4;  a=5;
     }
     if(a==5&&fn+FileN>=114){
        X=79;I=4;  a=6;
     }
     if(a==6){
       X=1; I=4; a=0;
       S=fn;S2=FileN;
       fn=FileN=0;
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
     if(root==1){
        strcpy(filename[filesu],"A:");
        filesu=filesu+1;
      if(GetFloppyNo()==2){
          strcpy(filename[filesu],"B:");
          filesu=filesu+1;
          strcpy(filename[filesu],"C:");
         goto Dae2;
       }else{
         strcpy(filename[filesu],"C:");
         goto Dae2;
       }
        Dae2:
        if(DDR!=0){
           filesu=filesu+1;
           strcpy(filename[filesu],"D:");
           goto Dae5;
        }
     }else{
        strcpy(filename[filesu],"A:");
        filesu=filesu+1;
      if(GetFloppyNo()==2){
          strcpy(filename[filesu],"B:");
          filesu=filesu+1;
          strcpy(filename[filesu],"C:");
         goto Dae;
       }else{
         strcpy(filename[filesu],"C:");
         goto Dae;
       }

     Dae:
        if(DDR!=0){
           filesu=filesu+1;
           strcpy(filename[filesu],"D:");
        }
     }
     Dae5:
     TL(Windows);
     DRIVE_PRINTF(X,I,AD,BD,DD);
     drive_total=GetTotalDiskSpace(0);
     drive_free=GetAvailDiskSpace(0);
     D=(float)(drive_total-drive_free)/drive_total*100;
     textattr(127);
     gotoxy(1,24);
     cprintf("                                                                               ");
     if(drive_total/1000000<2){
        gotoxy(1,24);
        cprintf(" %3d File(s) %3d Dir(s) %7.0lu Bytes %4.0lu Bytefree(%2.1f%%)  ",FileN,fn,SIZE,drive_free,100-D);
        cprintf(" %lu(KB)",drive_total/1000);
        if(FileN==0){
           gotoxy(1,24);
           cprintf("                                                                               ");
           gotoxy(1,24);
           cprintf("    0 File(s) %3d Dir(s)    0 Bytes %4.0lu Bytefree(%2.1f%%)  ",fn,drive_free,100-D);
           cprintf(" %lu(KB)",drive_total/1000);
        }
     }
     if(drive_total/1000000>2){
        gotoxy(1,24);
        cprintf(" %3d File(s) %3d Dir(s) %7.0lu Bytes %4.0lu Bytefree(%2.1f%%)  ",FileN+S2,fn+S,SIZE,drive_free,100-D);
        cprintf(" %lu(MB)",drive_total/1000000);
        if(FileN==0){
           gotoxy(1,24);
           cprintf("                                                                               ");
           gotoxy(1,24);
           cprintf("    0 File(s) %3d Dir(s)  0 Bytes %4.0lu Bytefree(%2.1f%%)  ",fn,drive_free,100-D);
           cprintf(" %lu(MB)",drive_total/1000000);
        }
     }
     textattr(7);
}
int ENTER_ROOTINE(int Windows,int x,int y){
        char bs[100],fe[13],Mu[100];
        int a,root=0,fi,done2;
        mouseoff();
       if(newpath[3]==''){/*ROOT*/
         root=1;
       }
       if(x==1&&y==4){
            strcpy(bs,filename[y-4]);
           done2=findfirst(bs,&f,FA_DIREC|FA_RDONLY);
           if(f.ff_attrib==FA_DIREC||f.ff_attrib==FA_DIREC & FA_RDONLY){
            goto dir;
          }else{
           goto FILE;
          }
       }
       if(x==1&&y!=4){
         if(root==1){
            strcpy(bs,filename[y-4]);
          }else{
            strcpy(bs,filename[y-3]);
          }
          done2=findfirst(bs,&f,FA_DIREC|FA_RDONLY);
          if(f.ff_name[0]=='N'&&f.ff_name[1]=='P'&&f.ff_name[2]=='R'&&f.ff_name[3]=='O'&&f.ff_name[4]=='T'&&f.ff_name[5]=='E'&&f.ff_name[6]=='C'&&f.ff_name[7]=='T'){
              goto dir;
          }
          if(f.ff_name[0]=='R'&&f.ff_name[1]=='E'&&f.ff_name[2]=='C'&&f.ff_name[3]=='Y'&&f.ff_name[4]=='C'&&f.ff_name[5]=='L'&&f.ff_name[6]=='E'&&f.ff_name[7]=='D'){
            goto dir;
          }
          if(f.ff_name[0]=='P'&&f.ff_name[1]=='R'&&f.ff_name[2]=='O'&&f.ff_name[3]=='G'&&f.ff_name[4]=='R'&&f.ff_name[5]=='A'&&f.ff_name[6]=='~'&&f.ff_name[7]=='1'){
            goto dir;
          }
          if(f.ff_attrib==FA_DIREC||f.ff_attrib==FA_DIREC & FA_RDONLY){
            goto dir;
          }else{
           goto FILE;
          }
         }
         if(x==14){
          if(root==1){
            strcpy(bs,filename[15+y]);
          }else{
            strcpy(bs,filename[16+y]);
          }
          done2=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC||f.ff_attrib==FA_DIREC && f.ff_attrib==FA_RDONLY){
           goto dir;
          }else{
           goto FILE;
          }
         }
         if(x==27){
         if(root==1){
          strcpy(bs,filename[34+y]);
         }else{
          strcpy(bs,filename[35+y]);
         }
      done2=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         }
         if(x==40){
         if(root==1){
          strcpy(bs,filename[53+y]);
         }else{
          strcpy(bs,filename[54+y]);
         }
          done2=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         }
       if(x==53){
         if(root==1){
          strcpy(bs,filename[72+y]);
         }else{
          strcpy(bs,filename[73+y]);
         }
      done2=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
       }
       if(x==66){
         if(root==1){
          strcpy(bs,filename[91+y]);
         }else{
          strcpy(bs,filename[92+y]);
         }
      done2=findfirst(bs,&f,FA_DIREC);
          if(f.ff_attrib==FA_DIREC){
           goto dir;
          }else{
           goto FILE;
          }
         dir:
         /*directory*/
             chdir(bs);
             return 0;
           FILE:
           if(bs[0]=='A'&&bs[1]==':'){
               if(DRIVEA(Windows)==0){
                chde=0;
               }else{
                 DRIVEA(Windows);
               }
               mouseon();
               return 0;
           }
           if(bs[0]=='B'&&bs[1]==':'){
              if(DRIVEB(Windows)==0){
                 chde=1;
               }else{
                 DRIVEB(Windows);
               }
               mouseon();
               return 0;
           }
           if(bs[0]=='C'&&bs[1]==':'){
               chde=2;
               mouseon();
               return 0;
           }
           if(bs[0]=='D'&&bs[1]==':'){
               chde=3;
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
             if(bs[a+1]=='A'&&bs[a+2]=='R'&&bs[a+3]=='J'){
                textattr(7);
                clrscr();
                strcpy(Mu,"arj l ");
                strcat(Mu,bs);
                strcat(Mu,"|more");
                system(Mu);
                getch();
              }/*ARJ*/
             if(bs[a+1]=='R'&&bs[a+2]=='A'&&bs[a+3]=='R'){
                textattr(7);
                clrscr();
                strcpy(Mu,"rar l ");
                strcat(Mu,bs);
                strcat(Mu,"|more");
                system(Mu);
                getch();
              }/*RAR*/
             if(bs[a+1]=='Z'&&bs[a+2]=='I'&&bs[a+3]=='P'){
                textattr(7);
                clrscr();
                strcpy(Mu,"pkunzip -t ");
                strcat(Mu,bs);
                strcat(Mu,"|more");
                system(Mu);
                getch();
              }/*ZIP*/
           }/*FILE*/
          }/*FILENAME*/
        }/*ENTER*/
  mouseon();
}
void CTRL_T(){
  clrscr();
  puttext(1,1,80,24,SCR);
  gotoxy(1,25);
  textattr(62);
  cprintf("Press any key to Kwangsung Tools Ver 1.00 [100]");
}

int COPY2(int x,int y){
   char FM[200]="",FN[200]="",*CP;
   int CANCEL,mode=0;
   char bs[200];
    int root=0,done;
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
          strcpy(FM,bs);
        }
       if(x==14){
         if(root==1){
          strcpy(bs,filename[y+15]);
         }else{
          strcpy(bs,filename[y+16]);
         }
          strcpy(FM,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+15+18]);
         }else{
          strcpy(bs,filename[y+16+19]);
         }
          strcpy(FM,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+15+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+19]);
         }
          strcpy(FM,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+15+20+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+20+19]);
         }
          strcpy(FM,bs);
       }
    }
   Cu(1);
   CP=malloc(4000);
   gettext(5,10,75,21,CP);
   BOX(0,5,10,75,21,95,2);
   gotoxy(33,11);
   cputs("Copy");
   cline(6,11,68,127);
   gotoxy(8,12);
   textattr(95);
   cprintf("Source Directory & Filename : %s",FM);
   CANCEL=input_string(38,12,FM,44,95);
    if(CANCEL==0||FM=='\0'){
   Err:
     if(mode==0){
        gotoxy(10,13);
      }else{
        gotoxy(10,16);
        mode=0;
      }
       puttext(5,10,75,21,CP);
       free(CP);
       CP=malloc(4000);
       gettext(5,10,75,12,CP);
       BOX(0,5,10,75,12,95,2);
       gotoxy(8,11);
       cputs("Error : Directory & Filename is failed.");
       puttext(5,10,75,12,CP);
       getch();
       free(CP);
       return -1;
    }
   gotoxy(8,15);
   puts("  T o  Directory & Filename : ");
   CANCEL=input_string(38,15,FN,44,95);
    if(CANCEL==0||FN=='\0'){
      mode=1;
      goto Err;
    }
    Cu(0);
    COPY(FM,FN);
     puttext(5,10,75,21,CP);
     free(CP);
    return 0;
}
int COPY(char FM[200],char FN[200]){
 int ch,q,x,y;
 float Per;
 unsigned long ssize,tsize=0;
 FILE *source,*target;
 if((source=fopen(FM,"rb"))==NULL){ /* º“Ω∫ ∞≥πÊ Ω«∆–Ω√ √‚∑¬ */
    printf("Cannot open source file");
    fclose(source);
    return -1;
 }
 if((target=fopen(FN,"wb"))==NULL){ /* ≈∏∞Ÿ ∞≥πÊ Ω«∆–Ω√ √‚∑¬ */
    printf("Cannot open target file");
    fclose(source);
    return -1;
 }
   BOX(0,5,10,75,21,95,2);
  q=findfirst(FM,&f,FA_SYSTEM|FA_RDONLY|FA_ARCH|FA_HIDDEN);
   ssize=f.ff_fsize;
 ch=fgetc(source);                       /* ≠°Ω∫ 	Ò∑©∑Œ•Ò»· 	ı °ı∑ø∏¶ ∑™¥·µ± */
 x=wherex();
 y=wherey();
 gotoxy(6,11);
 textattr(112);
 DISK_PATH();
 cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
 gotoxy(33,11);
 textattr(0);
 cputs("Copy");
 cline(6,11,68,127);
 textattr(94);
 gotoxy(25,13);
 cprintf("To %s",newpath);
 textattr(95);
 gotoxy(7,14);
 cprintf("%12s                            %20lu bytes",FM,ssize);
 gotoxy(7,15);
 textattr(7);
      cputs("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
 gotoxy(7,17);
 textattr(95);
   cputs("<1/1>");
 textattr(7);
 gotoxy(7,18);
 textattr(7);
      cputs("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
 textattr(7);
 Cu(0);
 while(!feof(source)){                   /*     Ò∑©∂ﬂ ≥°∑•ª° ∞À´— */
       fputc(ch,target);                 /* ∑™¥·µ• °ı∑ø∏¶ «ø∞Ÿ 	Ò∑©≥˝ ¡Á∑¬ */
       ch=fgetc(source);                 /* ≠°Ω∫ 	Ò∑©∑Œ•Ò»· 	ı °ı∑ø∏¶ ∑™¥·µ± */
      tsize=tsize+1;
      gotoxy(7,15);
      Per=(float)tsize/ssize*100;
      textattr(94);
     if(Per>=0 && Per <= 5 ){
      cputs("€€€€");
      gotoxy(7,18);
      cputs("€€€€");
     }
     if(Per>=5 && Per <= 10 ){
      cputs("€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€");
     }
     if(Per>=11 && Per <= 15 ){
      cputs("€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€");
     }
     if(Per>=16 && Per <= 20 ){
      cputs("€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€");
     }
     if(Per>=21 && Per <= 25 ){
      cputs("€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€");
     }
     if(Per>=26 && Per <= 30 ){
      cputs("€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=31 && Per <= 35 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=35 && Per <= 40 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=41 && Per <= 45 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=46 && Per <= 50 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=51 && Per <= 55 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=56 && Per <= 60 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=61 && Per <= 65 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=66 && Per <= 70 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=71 && Per <= 80 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=81 && Per <= 85 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=86 && Per <= 90 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=91 && Per <= 95 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     if(Per>=96 && Per <= 99 ){
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
      gotoxy(7,18);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
     }
     gotoxy(7,15);
 }
 gotoxy(7,15);
 textattr(94);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
 gotoxy(7,18);
 textattr(94);
      cputs("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
 textattr(7);
 Cu(1);
 gotoxy(x,y);
 fclose(source);                         /* ≠°Ω∫ 	Ò∑© ÃÒ≠· */
 fclose(target);                         /* «ø∞Ÿ 	Ò∑© ÃÒ≠· */
 return 0;
}
FC(char FM[12],int color,int X,int I){
           textcolor(color);
           gotoxy(X,I-1);
           cputs(FM);
           return;
}
DISK_PATH(){
     setdisk(chde);
     savedisk=newdisk=getdisk();
     textattr(7);
     getcwd(savepath,MAXPATH);
     strcpy(newpath,savepath);
     strcpy(OldA,savepath);
     if(savepath[0]=='A')chde=0;
     if(savepath[0]=='B')chde=1;
     if(savepath[0]=='C')chde=2;
     if(savepath[0]=='D')chde=3;
     return chde;
}
MMOUSE_MENU(int HE){
 gotoxy(1,1);
 textattr(62);
 cprintf("F1");
 textattr(63);
 cprintf("HELP     ≥");
 if(HE==1){
  gotoxy(12,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F2");
 textattr(63);
 cprintf("CALENDAR  ≥");/*ªÔµπø°º≠ ∞≥πﬂ«— µµΩ∫*/
 if(HE==1){
  gotoxy(26,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F3");
 textattr(63);
 cprintf("SAMDOLSYS ≥");/*≥Ø¬• ∞Ìƒß,Ω√∞£ ∞Ìƒß,»Æ¿Œ*/
 if(HE==1){
  gotoxy(39,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F4");
 textattr(63);
 cprintf("ST GAME  ≥");
 if(HE==1){
  gotoxy(52,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F5");
 textattr(63);
 cprintf("EASY LINK≥");
 if(HE==1){
  gotoxy(65,1);
  textattr(48);
  cprintf("%c",5);
 }
 textattr(62);
 cprintf(" F6");
 textattr(63);
 cprintf("HEX VIEWER  ");
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
        case F1: return 1;/*µµøÚ∏ª*/
        case F2: return 2;/*ªÔµπµµΩ∫*/
        case F3: return 3;
        case F4: return 4;
        case F5: return 5;/*¿Ã¡ˆ∏µ≈© »£√‚*/
        case F6: return 6;
        case F7: return 7;/*µÓ∑œ¿⁄ ¡§∫∏*/
        case F8: return 8;
        case F10: return 910;
        case ESC : return 10;/*≥°≥ª±‚*/
        case UP : return 11;/*¿ß∑Œ*/
        case DN : return 12;/*æ∆∑°∑Œ*/
        case LT : return 13;/*øﬁ*/
        case RT : return 14;/*ø¿∏•*/
        case RET : return 15;/*Ω««‡*/
        case INS : return 20;/*Ω««‡*/
        case cRET : return 1500;/*Ω««‡*/
        case TAB : return 400;
        case _c1 : return 433;/*COPY ROOTINE*/
        case _C1 : return 403;/*∞Ê∑Œ πŸ≤ﬁ*/
        case _D :
        case _d : return 404;/*∞Ê∑Œ&∆ƒ¿œ ¡ˆøÚ*/
        case _M :
        case _m : return 413;/*∏∏µÈ±‚*/
        case _N :
        case _n : return 414;
        case _Q :
        case _q : return 416;
        case aA : return 101;/*µÂ∂Û¿Ã∫Í ø°¿ÃA*/
        case aB : return 102; /*µÂ∂Û¿Ã∫Í ¿Ãµø*/
        case aC : return 103;
        case aD : return 104;/*∆ƒ¿œ ¡ˆøÏ±‚*/
        case aF : return 106;/*∆ƒ¿œ ¡ˆøÏ±‚*/
        case aK : return 111;
        case aR : return 118;/*∏Æ≥◊¿”∏Ì∑…*/
        case aX : return 124;
        case aP : return 16;/*∆ƒ≈∑*/
        case aZ : return 126;/*»˜µÁ∞˙ ∫Ò»˜µÁ*/
        case cS : return 219;/*Ω««‡µ⁄ »≠∏È*/
        case cT : return 220;/*Ω««‡µ⁄ »≠∏È*/
        case cV : return 222;
        case cZ : return 226;
        case DeL : return 1000;/*Ω««‡µ⁄ »≠∏È*/
        case SPACE : return 1100;/*Ω««‡µ⁄ »≠∏È*/
        case Dote :
        case dote : return 2000;
        case _slu : return 3000;
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
   printf("\n\a %s∏¶ ∏¯√£¿Ω!",FMW);
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
    sprintf(D_str,"∆ƒ¿œ ¿Ã∏ß  : %s  1  ¿Â",FMW);
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
      if(c=='\a'||c=='\t'||c=='\r'||c=='\n'){sprintf(S_str,".");goto ext;}
         sprintf(S_str,"%s\n",c);
       ext:
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
   cprintf("*** Enter=¥Ÿ¿Ω¿Â  , ESC = ≥°  ***");
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
    sprintf(D_str,"∆ƒ¿œ ¿Ã∏ß  : %s    %d ¿Â",FMW,a);
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
 textattr(7);
}
      end:
     gotoxy(1,25);
     textattr(112);
      cprintf("*** End of File : Use Language TC 2.0 *");
      if(HAN==1){
      gotoxy(1,Y+1);
      cprintf("*** ∆ƒ¿œ¿« ≥°   : ªÁøÎææÓ : Turbo-C  *");
      }
     textattr(7);
     fclose(fp);
 getch();
     return;
}
SYSTEM(){/*Ω√Ω∫≈€ æ»≥ª ∑Á∆æ*/
  long drive_free;
  unsigned long drive_total;
  int a,x,y,ke=0,KEY_C;
  int year,mon,day;
  char *SCR;
    SCR=malloc(4000);
    gettext(1,1,80,25,SCR);
    Cu(0);
    textattr(7);
    Open_Screen();/*»≠∏È ∞•∂Û¡¸*/
    Q:
    drive_total=GetTotalDiskSpace(0);
    drive_free=GetAvailDiskSpace(0);
    D=(float)(drive_total-drive_free)/drive_total*100;
   for(y=1;y<=25;y++){
      for(x=1;x<=80;x++){
        textattr(8);
        gotoxy(x,y);
        cprintf("€");
      }
   }
    for(x=1;x<=80;x++){
        textattr(1);
        gotoxy(x,1);
        cprintf("€");
    }
    Cprintfxy(24,1,15,9,"System Infomation Ver 1.00          ");
    for(x=10;x<=70;x++){
        textattr(7);
        gotoxy(x,3);
        cprintf("€");
    }
    Cprintfxy(35,3,1,15,"System Summary");
  for(y=4;y<=20;y++){
    for(x=10;x<=70;x++){
        textattr(1);
        gotoxy(x,y);
        cprintf("€");
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
    cprintf("€");
   }
    Cprintfxy(20,18,4,7,"N");
    Cprintfxy(22,18,0,7,"e x t");

   for(x=47;x<=60;x++){
    textattr(0);
    gotoxy(x,18);
    cprintf("€");
   }
    Cprintfxy(50,18,4,0,"Q ");
    Cprintfxy(52,18,7,0,"u i t");
   }
  if(ke==1){
   for(x=17;x<=30;x++){
    textattr(0);
    gotoxy(x,18);
    cprintf("€");
   }
    Cprintfxy(20,18,4,0,"N");
    Cprintfxy(22,18,7,0,"e x t");

   for(x=47;x<=60;x++){
    textattr(7);
    gotoxy(x,18);
    cprintf("€");
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
       cprintf("€");
      }
      Cprintfxy(20,18,4,7,"N");
      Cprintfxy(22,18,0,7,"e x t");
      for(x=47;x<=60;x++){
        textattr(0);
        gotoxy(x,18);
        cprintf("€");
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
    cprintf("€");
   }
    Cprintfxy(20,18,4,0,"N");
    Cprintfxy(22,18,7,0,"e x t");

   for(x=47;x<=60;x++){
    textattr(7);
    gotoxy(x,18);
    cprintf("€");
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
        cprintf("€");
      }
   }
    for(x=1;x<=80;x++){
        textattr(1);
        gotoxy(x,1);
        cprintf("€");
    }
    Cprintfxy(24,1,15,9,"System Infomation Ver 1.00          ");
    for(x=10;x<=70;x++){
        textattr(7);
        gotoxy(x,3);
        cprintf("€");
    }
    Cprintfxy(35,3,1,15,"System Summary");
  for(y=4;y<=20;y++){
    for(x=10;x<=70;x++){
        textattr(1);
        gotoxy(x,y);
        cprintf("€");
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
       cprintf("€");
      }
      Cprintfxy(34,18,4,7,"N ");
      Cprintfxy(36,18,0,7,"e x t ");
    for(x=33;x<=45;x++){
      Cprintfxy(x,19,0,0,"a");
    }
      getch();
      for(x=32;x<=44;x++){
       textattr(1);
       gotoxy(x,18);
       cprintf("€");
      }
      for(x=34;x<=46;x++){
       textattr(7);
       gotoxy(x,18);
       cprintf("€");
      }
      Cprintfxy(36,18,4,7,"N ");
      Cprintfxy(38,18,0,7,"e x t ");
    for(x=33;x<=45;x++){
      Cprintfxy(x,19,1,1,"€");
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
          cprintf("   «œµÂ µΩ∫≈©∞° ∆ƒ≈∑ µ«æ˙Ω¿¥œ¥Ÿ.            ");
          }
          gotoxy(11,13);
          cprintf("         Turn off the Your Computer...       ");
          if(Windows==1){
          gotoxy(11,13);
          cprintf("     ƒƒ«ª≈Õ¿« ∆ƒøˆ∏¶ ≤Ùº≈µµ ¡¡Ω¿¥œ¥Ÿ.        ");
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
Cprintfxy(int x,int y,int foreground_color,int background_color,char *string)
{
 gotoxy(x,y);                      /* ƒ·¨·∂ﬂ ∂·√°∏¶ 	ı∞Ê */
 textcolor(foreground_color);      /* ∏Â∞Ê´Ú ¨È∏˜ */
 textbackground(background_color); /* £Ò∞Ê´Ú ¨È∏˜ */
 cprintf("%s",string);             /* °ı∑ø¥« ¡Á∑¬ */
 return 0;
}
EASYLINK(int Windows){
   int FN;
   ROOTINE();
   gotoxy(11,12);
   cprintf(" ST EasyLink Ver 2.0  Filename.ext          ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf(" ªÔµπ Ω¨øÓ ∆ƒ¿œø¨∞· πˆ¡Ø 2.0  ∆ƒ¿œ∏Ì.»Æ¿Â¿⁄ ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7); gotoxy(11,13);  Cu(1);
    cline(11,12,44,127);
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
            gotoxy(11,13);
            cprintf(" %s is I don't know file format",F);
            if(Windows==1){
               cprintf(" %s ¥¬ æÀºˆæ¯¥¬ ∆ƒ¿œ «¸Ωƒ ¿‘¥œ¥Ÿ. ",F);
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
      cprintf("         HWP ∆ƒ¿œ¿Ã∏ß¿ª ≥÷æÓ ¡÷ººø‰         ");
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
          strcpy(bs,filename[y+15]);
         }else{
          strcpy(bs,filename[y+16]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+34]);
         }else{
          strcpy(bs,filename[y+35]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+53]);
         }else{
          strcpy(bs,filename[y+54]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+72]); /*123*/
         }else{
          strcpy(bs,filename[y+73]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+91]);
         }else{
          strcpy(bs,filename[y+92]);
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
      cprintf("         ∆ƒ¿œ ¡ˆøÏ±‚ ∏∂π˝ªÁ                 ");
    }
   cline(11,12,44,127);
   cline(11,13,44,95);
    gotoxy(11,13);
    cprintf("%s",F);
    gotoxy(11,13);  Cu(1);
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
          strcpy(bs,filename[y+15]);
         }else{
          strcpy(bs,filename[y+16]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[35+y]);
         }else{
          strcpy(bs,filename[36+y]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[55+y]);
         }else{
          strcpy(bs,filename[56+y]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[75+y]);
         }else{
          strcpy(bs,filename[76+y]);
         }
          strcpy(F,bs);
       }
    }
   gotoxy(11,12);
   cputs("         Enter a Execute Filename           ");
   if(Windows==1){
      gotoxy(11,12);
      cputs("          ∆ƒ¿œ Ω««‡  ∏∂π˝ªÁ                 ");
   }
   gotoxy(43,13);
   cprintf("            ");
   gotoxy(11,13);
   cline(11,12,44,127);
    cprintf("%s",F);
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
    strcpy(F,"");
    gotoxy(11,12);
    cprintf("         Directory Make Wizard              ");
    if(Windows==1){
       gotoxy(11,12);
       cprintf("         ∞Ê∑Œ ∏∏µÈ±‚ ∏∂π˝ªÁ                 ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7);
    gotoxy(11,13);
    Cu(1);
    cline(11,12,44,127);
    input_string(11,13,F,44,95);
    textattr(15);
    if( mkdir(F) ) {
        cline(11,15,50,78);
        gotoxy(11,15);
        fprintf(stderr, "Failure : %s is not make\n", F);
        if(Windows==1){
        gotoxy(11,15);
        fprintf(stderr, "ø¿∑˘πﬂª˝: %s∏¶ ∏∏µÈ¡ˆ ∏¯«‘.\n", F);
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
   int CANCEL;
   ROOTINE();
   gotoxy(11,12);
   cprintf("         Directory Delete Wizard            ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf("         ∞Ê∑Œ ¡ˆøÏ±‚ ∏∂π˝ªÁ                 ");
   }
   gotoxy(43,13);
   cprintf("            ");
   textattr(7);
   gotoxy(11,13);
   Cu(1);
    cline(11,12,44,127);
    CANCEL=input_string(11,13,F,44,95);
    if(CANCEL==0||F=='\0'){
      strcpy(F," ");
    }
   textattr(15);
   if( rmdir(F) ) {
      cline(11,15,50,78);
      gotoxy(11,15);
      fprintf(stderr, "Failure : %s is not delete\n", F);
      if(Windows==1){
      gotoxy(11,15);
      fprintf(stderr, "ø¿∑˘πﬂª˝: %s∏¶ ¡ˆøÏ¡ˆ ∏¯«‘.\n", F);
      }
    getch();
   }
    DISK_PATH();
    puttext(10,11,56,14,SAT1);
    free(SAT1);
    Cu(0);
    return 0;
}
DRIVEB_ERR(){
int ERR,KEY_CODE,ACR=0;
clrscr();
  Cu(0);
 ERR=biosdisk(0x16);
 if(ERR!=0){
    ERR=0;
    ERR=biosdisk(0x4,1);
    printf("%d",ERR);
  }
  getch();
  return 0;
}
DRIVEB(int Windows){
int ERR,KEY_CODE,ACR=0;
  Cu(0);
 ERR=biosdisk(0x16);
 if(ERR!=0){
    ERR=0;
    ERR=biosdisk(0x4,1);
    if(ERR==10){
       ROOTINE();
       gotoxy(11,12);
       /*General error*/
       cprintf("\aGeneral Error Drive B Yes(Retry)/No(ignore)!");
       goto DAUM2;
    }
    if(ERR==128){
       ROOTINE();
       gotoxy(11,12);
       cprintf("\aDrive Not Ready in B: Yes(Retry)/No(ignore)!");
       if(Windows==1){
          gotoxy(11,12);
          cprintf("\aµÂ∂Û¿Ã∫Í B:ø° πÆ¿Ãø≠∏≤ Yes(¥Ÿ Ω√)/No(∆˜ ±‚)!");
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
   }else{
     return 0;
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
             cprintf("\aµÂ∂Û¿Ã∫Í A:ø° πÆ¿Ãø≠∏≤ Yes(¥Ÿ Ω√)/No(∆˜ ±‚)!");
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
    }/*else¥›∞≥*/
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
  fprintf(fp,"\ndel kt.bat");
  fclose(fp);
}
void STWBAT(char filena[200]){
  fp=fopen("KT.BAT","w");
  fprintf(fp,"cls>nul",filena);
  fprintf(fp,"\nCALL %s",filena);
  fprintf(fp,"\nC:\\_KTW_.BAT");
  fprintf(fp,"\ndel kt.bat");
  fclose(fp);
}
int DRIVE_PRINTF(int x,int y,int AD,int BD,int DD,int Root){
 int FN;
 FN=GetFloppyNo();
 if(x==62&&y>=18){
   return 0;
 }
 if(FN==0){
  goto CDE;
 }
 if(y>22){
    y=4;
    gotoxy(x+13,y);
    textattr(6);
  switch(AD){
     case 1 :
             cputs("[-A-] 5.25\"");
             break;
     case 2 :
             cputs("[-A-] 3.5\"");
             break;
     default :
             cputs("[-A-]     ");
             break;
  }
    x+=13;
    y+=1;
    wy=y;
    goto DAM;
 }
 gotoxy(x,y);
 textattr(6);
  switch(AD){
     case 1 :
             cputs("[-A-] 5.25\"");
             break;
     case 2 :
             cputs("[-A-] 3.5\"");
             break;
     default :
             cputs("[-A-]     ");
             break;
  }

 y+=1;
 DAM:
if(FN==2){
 if(y>22){
    y=4;
   gotoxy(x+13,y);
  switch(BD){
     case 1 :
             cputs("[-B-] 5.25\"");
             break;
     case 2 :
             cputs("[-B-] 3.5\"");
             break;
     default :
             cputs("[-B-]     ");
             break;
  }
   y+=1;x+=13;
   goto DAM2;
 }
   gotoxy(x,y);
  switch(BD){
     case 1 :
             cputs("[-B-] 5.25\"");
             break;
     case 2 :
             cputs("[-B-] 3.5\"");
             break;
     default :
             cputs("[-B-]     ");
             break;
  }
   y+=1;
}
 DAM2:
 CDE:
 if(y>22){
   y=4;
   x+=13;
   gotoxy(x,y);
   cputs("[-C-] HDD");
   y+=1;
   goto oooo;
 }
   gotoxy(x,y);
   cputs("[-C-] HDD");
   y+=1;
 oooo:
 if(y>22){
    x+=13;
    y=4;
   gotoxy(x,y);
  switch(DD){
     case 0 :
            y=y-1;x=x-13;
            break;
     case 1 :
             cputs("[-D-] HDD");
             break;
     case 2 :
             cputs("[-D-] CD-ROM");
             break;
  }
  goto DFG;
 }
  gotoxy(x,y);
  switch(DD){
     case 0 :
            y=y-1;
            break;
     case 1 :
             cputs("[-D-] HDD");
             break;
     case 2 :
             cputs("[-D-] CD-ROM");
             break;
  }
  DFG:
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
    int root=0,done,Dra=0;
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
          strcpy(bs,filename[y+15]);
         }else{
          strcpy(bs,filename[y+16]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+15+18]);
         }else{
          strcpy(bs,filename[y+16+19]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+15+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+19]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+15+20+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+20+19]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13+13){/*6 can*/
         if(root==1){
          strcpy(bs,filename[y+15+20+20+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+20+20+19]);
         }
          strcpy(F,bs);
       }
    done=findfirst(bs,&f,FA_LIST);

    textattr(63);
    gotoxy(67,9);
   if(bs[1]==':'){
     gotoxy(1,25);
     cprintf("  Drive %2s",bs);
  if(Windows==1){/*«—±€∏µÂ¿Ã∏È*/
      gotoxy(1,25);
     cprintf("%2sµÂ∂Û¿Ã∫Í",bs);
  }
     Dra=1;
     goto dadf;
   }
   if(bs[0]==''){
     gotoxy(1,25);
     cprintf("Free Shell");
     if(Windows==1){
       gotoxy(1,25);
     cprintf(" ∫Û ∞¯ ∞£ ");
     }
     Dra=1;
     goto dadf;
   }
   if(f.ff_attrib!=FA_DIREC){
      gotoxy(1,25);
      cprintf("%10ld",f.ff_fsize);     /* 9,999,999,999 Low*/

   }else{
    gotoxy(1,25);
    cprintf(" Directory");
   if(Windows==1){/*«—±€∏µÂ¿Ã∏È*/
      textattr(63);
      gotoxy(1,25);
      cprintf(" µ∑∫≈‰∏Æ     ");
    }
   }
  if(root!=1&&x==1&&y==4){
    gotoxy(1,25);
    cprintf(" Directory");
    if(Windows==1){/*«—±€∏µÂ¿Ã∏È*/
      textattr(63);
      gotoxy(1,25);
      cprintf(" µ∑∫≈‰∏Æ     ");
    }
   }
    dadf:
    gotoxy(11,25);
    textattr(48);
    cprintf("≥");
    textattr(63);
    cprintf("%4d-%02d-%02d",(f.ff_fdate>>9)+1980,     /* ≥‚ */
                                                  (f.ff_fdate>>5) & 0x000f, /* ∂© */
                                                   f.ff_fdate & 0x001f);    /* ∑© */
    if(Dra==1){
       gotoxy(12,25);
       textattr(48);
       cprintf("          ");
    }
    gotoxy(22,25);
    textattr(48);
    cprintf("≥");
    textattr(63);
    cprintf("%02d:%02d",f.ff_ftime>>11,                 /* Ω√ */
                                     (f.ff_ftime>>5) & 0x003f);      /* •ı */

    if(Dra==1){
       gotoxy(23,25);
       textattr(48);
       cprintf("     ");
    }
    gotoxy(28,25);
    textattr(48);
    cprintf("≥");
    textattr(63);
    cprintf(".....");
    textattr(48);
    cprintf("≥");
    if(f.ff_attrib & FA_ARCH){  gotoxy(29,25);textattr(63); cprintf("A");}
    if(f.ff_attrib & FA_DIREC){ gotoxy(30,25);textattr(60); cprintf("D");}
    if(f.ff_attrib & FA_SYSTEM){gotoxy(31,25);textattr(52); cprintf("S");}
    if(f.ff_attrib & FA_RDONLY){gotoxy(32,25);textattr(62); cprintf("R");}
    if(f.ff_attrib & FA_HIDDEN){gotoxy(33,25);textattr(58); cprintf("H");}
    if(Dra==1){
       gotoxy(29,25);
       textattr(48);
       cprintf("     ");
       Dra=0;
    }
    gotoxy(61,25);
    textattr(48);
    cprintf("≥");
    textattr(62);
    cprintf("F7");
    textattr(63);
    cprintf("=ABOUT");
    textattr(48);
    cprintf("≥");
    textattr(62);
    cprintf("F10");
    textattr(63);
    cprintf("=TREE ");
    textattr(7);
    return 0;
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
          strcpy(bs,filename[y+15]);
         }else{
          strcpy(bs,filename[y+16]);
         }
          strcpy(F,bs);
       }
       if(x==14+13){
         if(root==1){
          strcpy(bs,filename[y+15+18]);
         }else{
          strcpy(bs,filename[y+16+19]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13){
         if(root==1){
          strcpy(bs,filename[y+15+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+19]);
         }
          strcpy(F,bs);
       }
       if(x==14+13+13+13){
         if(root==1){
          strcpy(bs,filename[y+15+20+20+18]);
         }else{
          strcpy(bs,filename[y+16+20+20+19]);
         }
          strcpy(F,bs);
       }
    }

    gotoxy(11,12);
    cprintf("         Filename Change Wizard             ");
    if(Windows==1){
       gotoxy(11,12);
       cprintf("        ∆ƒ¿œ¿Ã∏ß πŸ≤Ÿ±‚ ∏∂π˝ªÁ              ");
    }
    gotoxy(43,13);
    cprintf("            ");
    textattr(7);
    gotoxy(11,13);
    Cu(1);
    cline(11,12,44,127);
    cline(11,13,15,95);
    gotoxy(11,13);
    cprintf("%s",F);
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
/*COPY2()*/
cbreak(){
  return 1;
}
unsigned char getcolorxy(int x,int y){
 unsigned char far *memory=(unsigned char far *)0xb8000001L;
 memory=memory+y*160+x*2;
 return(*memory); /* ¢Ö∏a∑Å ≠¢¨˜àt ü°»Â */
}
Cu(int onoff){/*ƒøº≠ ø¬ ø¿«¡*/
   union REGS r;
   r.h.ah=0x01;
   switch(onoff){
      case 1 : r.h.ch=0x0c;          /* CURSOR ON */
               r.h.cl=0x0d;
               int86(0x10,&r,&r);
               break;
      case 0 : r.h.ch=0x20;         /* CURSOR OFF */
               r.h.cl=0x0c;
               int86(0x10,&r,&r);
               break;
      default : r.h.ch=0x0c;         /* DEFAULT CURSOR */
                r.h.cl=onoff;
                int86(0x10,&r,&r);
                break;
   }
   return 0;
}
