/*±¤¼º Tools ¹öÁ¯ 1.50 ÇÁ·ÎÁ§Æ®¸í : ÇØÄ¿*/
/*F6 King in*/
#include <conio.h>   /*Æ÷ÇÔÆÄÀÏ*/
#include <dos.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include "kT.HH"
#include "HEX.HH"

char *SCR,*BARIC;
int Windows=0,Re,End,BarI=4,BarX=1,Y=0,a;

char *PAGE[2],*T="";
char *CopyName="Kwang Sung ";
char *CopyName1="Tools ";
char *CopyName2="Copy ";
char *CopyName3="Ver 2.00\n";
char *Error="\rError : ";
char *Error1="KT/C [Source file] [Target file]";

main(int argc,char **argv){
  union REGS reg;
  char savepath[MAXPATH],newpath[MAXPATH],OldA[MAXPATH];
  char *FILENAM="*.*",FM[12],*MON="\0",*SOURCE,*TARGET;
  FILE *fp;
  int MOUSE,Hiddon=0,KEY_CODE,BarI,BX,BY;
  rename("hwp2txt.dat","hwp2txt.exe");
 /*µî·ÏÆÇÀÎ°¡?,¿µÇÑ¸ðµå*/
  fp=fopen("c:\\kt.cfg","r");
  if(fp==NULL){
    fclose(fp);
    printf("Please Wait... Check the Registry.\n\r");
     fp=fopen("c:\\kt.cfg","w");
    printf("You! Only Used.... Waitting...\n\r");
    delay(400);
    fprintf(fp,"Kwangsung Tools\n");
    fprintf(fp,"KT99-2500-2500-415\n");
    fprintf(fp,"1\n");
    fprintf(fp,"1\n");
    fprintf(fp,"0");
    fclose(fp);
  }
  if(argc==1){
   Windows=0;
   goto Start;
  }
  if(argc==2){/*¿É¼ÇÃ³¸®*/
     switch(argv[1][1]){
        case '?' :  OPTION(0);
                    exit(1);
        case 'H' :
        case 'h' :  OPTION(1);
                    exit(1);
        case 'V' :
                   printf("\n%s\n",Ver);
                   exit(1);

        case 'v' :
                   printf("\n%s\n",VerH);
                   exit(1);
        case 'W' :
        case 'w' :
                   system("chcp 949");
                   Windows=1;
                   strcpy(FILENAM,"*.*");
                   goto Start;

        case 'E' :
        case 'e' :
                   system("chcp 437");
                   Windows=0;
                   strcpy(FILENAM,"*.*");
                   goto Start;
        case 'C' :
        case 'c' :
                   textcolor(10);cputs(CopyName);
                   textcolor(11);cputs(CopyName1);
                   textcolor(14);cputs(CopyName2);
                   textcolor(15);cputs(CopyName3);
                   textattr(7); cputs(Error);
                   puts(Error1);
                   exit(0);
         case 'D' :
         case 'd' :
                   SDIR();
                   exit(1);
         case 'S' :
         case 's' :
                   SYSTEM();
                   exit(1);
         case 'G' :
         case 'g' :
                      Windows=1;
                      ERRA();
                      gotoxy(11,12);
                      cprintf(" ±¤¼º ¹®¼­ ÀÐ°³ ÇÑ±ÛÆÇ 2.00 ");
                      gotoxy(43,12);
                      cprintf("            ");
                      gotoxy(43,13);
                      cprintf("            ");
                      gotoxy(12,13);
                      input_string(11,13,MON,44,95);
                      SWP(1,MON);
                      Windows=0;
                      exit(1);
         case 'X' :
         case 'x' :
                          ERRA();
                          gotoxy(11,12);
                          cprintf(" Kwang Sung Text Reader Ver 2.00 ");
                          gotoxy(43,12);
                          cprintf("            ");
                          gotoxy(43,13);
                          cprintf("            ");
                          gotoxy(12,13);
                          input_string(11,13,MON,44,95);
                          SWP(0,MON);
                          clrscr();
                          textattr(7);
                          exit(1);
         case 'U' :
         case 'u' :
                          Re_Install();
                          goto Start;
         case 'P' :
         case 'p' :
                          puts("\a\nKwang Sung File Code Changer Ver 1.00 ");
                          puts("\nUsage > KT /P Filename\n");
                          exit(1);
         case 'F' :
         case 'f' :

                          if(Is_Reg()==0){
                           SDIR();
                           printf("\aError : C:\\KT.CFG not found!\n\rPlease KTSET.EXE Run....");
                           exit(0);
                          }
                          Re=1;
                          setdisk(DISK_PATH());
                          chde=chde;
                          MAKE_ST_BAT(newpath);
                          SCR=malloc(4000);
                          gettext(1,1,80,25,SCR);
                           DDR=DDRIVE_IFO();
                          textattr(7);
                        if(ismouse()==0){
                             MOUSE=0;
                         }
                        if(ismouse()==1){
                              MOUSE=1;
                         }
                          goto Jaegi;
         default :
           Windows=0;
     }
   }/*¿É¼Ç2ÀÌ¸é ´Ý±â*/
    if(argc==3){/*¿É¼Ç 3°³¸é*/
     switch(argv[1][1]){
      case 'C' :
      case 'c' :
       if(argv[2]!=NULL){/*TextÇÑ±ÛÆÄÀÏ ÆÄÀÏÀ» µ½¼Ç¿¡ ÀÔ·ÂÇÏ¸é*/
         textcolor(10);
         cputs(CopyName);
         textcolor(11);
         cputs(CopyName1);
         textcolor(14);
         cputs(CopyName2);
         textcolor(15);
         cputs(CopyName3);
         textattr(7);
         cputs(Error);
         puts(Error1);
         exit(0);
       }

      case 'X' :
      case 'x' :
      if(argv[2]!=NULL){/*TextÇÑ±ÛÆÄÀÏ ÆÄÀÏÀ» µ½¼Ç¿¡ ÀÔ·ÂÇÏ¸é*/
           strcpy(MON,argv[2]);
            SWP(1,MON);
           exit(1);
       }

      case 'P' :
      case 'p' :
      if(argv[2]!=NULL){
        printf("\nKwangsung File Code Changer Ver 1.00");
        fp=fopen("KFCC.FCC","r");
        strcpy(MON,"KFCC.FCC");
        if(fp!=NULL){
          fclose(fp);
          MON="\0";
          fp=fopen("KFCC.FC1","r");
          strcpy(MON,"KFCC.FC1");
          fclose(fp);
        }
        code(argv[2],MON);
        printf("\n%s->%s",argv[2],MON);
        exit(1);
      }

     }/*switch*/
    }
    if(argc==4){
      if(argv[1][0]=='/'){
        switch(argv[1][1]){
            case 'C' :
            case 'c' :
             if(argv[2]!=NULL&&argv[3]!=NULL){
               COPY(argv[2],argv[3]);
               exit(0);
             }else{
               puts("\a\n Usage> KT /C SOURCENAME TARGETNAME");
               exit(0);
             }
            case 'P' :
            case 'p' :
             if(argv[2]!=NULL&&argv[3]!=NULL){
               puts("Kwangsung File Code Changer Ver 1.00 ");
               code(argv[2],argv[3]);
               exit(0);
             }else{
               puts("\a\n Usage> KT /P KFCC.FC?(Filename) Target name");
               exit(0);
            }
      }/*SWITCH*/
    }
    }/*Argc*/
 Start:
  FASTKEY();
 fp=fopen("kvb.exe","r");
 if(fp==NULL){
   fclose(fp);
   goto RRR;
 }else{
  system("kvb.exe c:");
  fclose(fp);
 }
  RRR:
  DISK_PATH();
  chde=chde;
     setdisk(chde);     savedisk=newdisk=getdisk(); textattr(7);
     getcwd(savepath,MAXPATH);  strcpy(newpath,savepath); strcpy(OldA,savepath);
  MAKE_ST_BAT(newpath);
  SCR=malloc(4000);
  gettext(1,1,80,25,SCR);
  Cu(0);
  Open_Screen(); Is_Reg();
     textattr(7);
     if(ismouse()==0){
       MOUSE=0;
     }
     if(ismouse()==1){
       MOUSE=1;
     }
  BarI=4;
  MMOUSE_MENU(Windows);
  DDR=DDRIVE_IFO();
  FILE_PRINTF(Windows,Hiddon,ADR,BDR,DDR);
  Date(35,25,Windows);
  Time(50,25,Windows);
   FINFO2(Windows,BarX,BarI);
  ADR=ADRIVE_IFO();
  BDR=BDRIVE_IFO();
  cline(1,4,9,31);
  ABOUT(Windows);
  ADR=ADRIVE_IFO();
  BDR=BDRIVE_IFO();
  DDR=DDRIVE_IFO();
  FILE_PRINTF(Windows,Hiddon,ADR,BDR,DDR);
  Re=0;
 BARIC=malloc(4000);
 gettext(1,4,80,22,BARIC);
 cline(1,4,12,31);
 Jaegi:
  ADR=ADRIVE_IFO();
  BDR=BDRIVE_IFO();
  if(Re==1){
   Time(50,25);
   free(BARIC);
   textattr(7);
   clrscr();
  MMOUSE_MENU(Windows);
  FILE_PRINTF(Windows,Hiddon,ADR,BDR,DDR);
   Re=0;
   BarX=1;BarI=4;
   BARIC=malloc(4000);
   gettext(1,4,80,22,BARIC);
   cline(1,4,12,31);
  }
 BarX=1;BarI=4;
 Cu(0);
DA:
if(MOUSE==1){
     mouseon();
     mouseinput();
     reg.x.ax = 4;
     int86( 0x33, &reg, &reg );   /*  ¸¶µß½º ¹Á	ðœ ¤áÊÕ «çÇß  */
     reg.x.cx=0;
     reg.x.dx=0;
     reg.x.ax = 3;
     int86( 0x33, &reg, &reg );   /*  ¸¶µß½º ¹Á	ðœ ¤áÊÕ «çÇß  */
}
      Date(35,25,Windows);
      Time(50,25,Windows);
      HOK(Windows,78,24,Hiddon);
  FINFO2(Windows,BarX,BarI);
 while(!kbhit()){
      Time(50,25);
      HOK(Windows,78,24,Hiddon);
      gotoxy(68,7);
    if(MOUSE==1){
     mouseon();
     mouseinput();
     reg.x.ax = 6;
     int86( 0x33, &reg, &reg );   /*  ¸¶µß½º ¹Á	ðœ ¤áÊÕ «çÇß  */

     if(mousex()+1>=1&&mousex()+1<=12&&mousey()+1>3&&mousey()+1<23){/*1 can*/
        puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<23){
        BarI=mousey()+1;
        BarX=1;
         cline(BarX,BarI,12,31);
       }
     }
     if(mousex()+1>=14&&mousex()+1<=26&&mousey()+1>3&&mousey()+1<23){/* 2 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<23){
        BarI=mousey()+1;
        BarX=14;
        cline(BarX,BarI,12,31);
       }
     }
     if(mousex()+1>=27&&mousex()+1<=39&&mousey()+1>3&&mousey()+1<23){/* 3 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<23){
        BarI=mousey()+1;
        BarX=27;
        cline(BarX,BarI,12,31);
       }
     }
     if(mousex()+1>=40&&mousex()+1<=53&&mousey()+1>3&&mousey()+1<23){/* 4 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<23){
        BarI=mousey()+1;
        BarX=40;
        cline(BarX,BarI,12,31);
       }
     }
     if(mousex()+1>=53&&mousex()+1<=64&&mousey()+1>3&&mousey()+1<23){/* 5 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<23){
        BarI=mousey()+1;
        BarX=53;
        cline(BarX,BarI,12,31);
       }
     }
     if(mousex()+1>=65&&mousex()+1<=80&&mousey()+1>3&&mousey()+1<23){/* 6 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<23){
        BarI=mousey()+1;
        BarX=66;
        cline(BarX,BarI,12,31);
       }
     }
    if(reg.x.bx & 1){
     /*MENU ROOTINE*/
     if(mousex()+1>=60&&mousex()+1<=80&&mousey()+1==2){/*ctrl+V*/
       goto Vol;
     }
     if(mousex()+1>=1&&mousex()+1<=11&&mousey()+1==1){/*F1*/
         goto F1_KEY;
     }
     if(mousex()+1>=13&&mousex()+1<=25&&mousey()+1==1){/*F2*/
         goto F2_KEY;
     }
     if(mousex()+1>=27&&mousex()+1<=39&&mousey()+1==1){/*F3*/
         goto F3_KEY;
     }
     if(mousex()+1>=41&&mousex()+1<=52&&mousey()+1==1){/*F4*/
         goto F4_KEY;
     }
     if(mousex()+1>=54&&mousex()+1<=65&&mousey()+1==1){/*F5*/
         goto F5_KEY;
     }
     if(mousex()+1>=62&&mousex()+1<=69&&mousey()+1==25){/*F7*/
         goto F7_KEY;
     }
     if(mousex()+1>=71&&mousex()+1<=80&&mousey()+1==25){/*F10*/
         goto F10_KEY;
     }
     if(mousex()+1>=1&&mousex()+1<=10&&mousey()+1==4){/*CD..*/
        puttext(1,4,80,22,BARIC);
        cline(1,4,12,31);
        delay(40);
        textattr(7);
        clrscr();
        system("cd..>nul");
        DISK_PATH();
        Re=1;
        goto Jaegi;
     }
    if(reg.x.bx & 1){
     if(mousex()+1>=1&&mousex()+1<=12&&mousey()+1>3){/*1 can*/
        puttext(1,4,80,22,BARIC);
       if(mousey()+1>4&&mousey()+1<22){
        BarI=mousey()+1;
        BarX=1;
         ENTER_ROOTINE(Windows,BarX,BarI);
         Re=1;
         goto Jaegi;
       }
     }
     if(mousex()+1>=14&&mousex()+1<=26&&mousey()+1>3){/* 2 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<22){
        BarI=mousey()+1;
        BarX=14;
        cline(BarX,BarI,12,31);
         ENTER_ROOTINE(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;
       }
       goto DA;
     }
     if(mousex()+1>=27&&mousex()+1<=39&&mousey()+1>3){/* 3 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<22){
        BarI=mousey()+1;
        BarX=27;
        cline(BarX,BarI,12,31);
         ENTER_ROOTINE(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;
       }
       goto DA;
     }
     if(mousex()+1>=40&&mousex()+1<=53&&mousey()+1>3){/* 4 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<22){
        BarI=mousey()+1;
        BarX=40;
        cline(BarX,BarI,12,31);
         ENTER_ROOTINE(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;
       }
       goto DA;
     }
     if(mousex()+1>=53&&mousex()+1<=66&&mousey()+1>3){/* 5 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<22){
        BarI=mousey()+1;
        BarX=53;
        cline(BarX,BarI,12,31);
         ENTER_ROOTINE(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;
       }
       goto DA;
     }
     if(mousex()+1>=66&&mousex()+1<=80&&mousey()+1>3){/* 6 can*/
       puttext(1,4,80,22,BARIC);
       if(mousey()+1>3&&mousey()+1<22){
        BarI=mousey()+1;
        BarX=66;
        cline(BarX,BarI,12,31);
         ENTER_ROOTINE(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;
       }
       goto DA;
     }
    }
     if(mousex()+1==80&&mousey()+1==25){/*end*/
        goto EWND;
      }
    }
         cline(BarX,BarI,12,31);
   }/*if(mouse on);close*/
}
    KEY_CODE=KEY();
  ctrlbrk(cbreak);
  switch(KEY_CODE){
    case 1:   /*F1*/
          F1_KEY:
          Help(Windows);
          KEY_CODE=0;
          goto Jaegi;

    case 2: /*F2*/
        F2_KEY:
        KEY_CODE=0;
        CRD_MAIN(Windows);
        mouseoff();
        Re=1;
         goto Jaegi;

    case 3:/*F3*/
        F3_KEY:
        KEY_CODE=0;
        Cu(0);
        mouseoff();
        SYSTEM();
        Re=0;
        goto Jaegi;

    case 4:/*F4*/
        F4_KEY:
        KEY_CODE=0;
        Cu(0);
        mouseoff();
        Game();
        Re=1;
        goto Jaegi;

    case 5:/*F5*/
     F5_KEY:
      KEY_CODE=0;
      EASYLINK(Windows);
      Re=1;
      goto Jaegi;

    case 6:/*F6*/

      KEY_CODE=0;
      Re=1;
      HEX_FILE(Windows,BarX,BarI);
      goto Jaegi;

    case 7:/*F7*/
     F7_KEY:
      KEY_CODE=0;
      ABOUT(Windows);
      Re=0;
      BarI=BarI;
      goto Jaegi;

    case 910:/*F10*/
     F10_KEY:
      KEY_CODE=0;
      KDIR();
      Re=1;
      goto Jaegi;

    case 10:/**/
    case 124:/**/
           goto EWND;
    case 11:/*UP*/
    puttext(1,4,80,22,BARIC);
    BarI--;
    if(BarX==14&&BarI<4){
     BarX=1;BarI=22;
     goto TC;
    }
    if(BarX==27&&BarI<4){
     BarX=14;BarI=22;
     goto TC;
    }
    if(BarX==40&&BarI<4){
     BarX=27;BarI=22;
     goto TC;
    }
    if(BarX==53&&BarI<4){
     BarX=40;BarI=22;
     goto TC;
    }
    if(BarX==66&&BarI<4){
     BarX=53;BarI=22;
     goto TC;
    }
    if(BarX==1&&BarI<4)BarI=4;
    TC:
     cline(BarX,BarI,12,31);
    break;

    case 12:/*DOWN*/
       puttext(1,4,80,22,BARIC);
       BarI++;
       if(BarX==1&&BarI>22){
        BarX=14;BarI=4;
        goto TC2;
       }
       if(BarX==14&&BarI>22){
        BarX=27;BarI=4;
        goto TC2;
       }
       if(BarX==27&&BarI>22){
        BarX=40;BarI=4;
        goto TC2;
       }
       if(BarX==40&&BarI>22){
        BarX=53;BarI=4;
        goto TC2;
       }
       if(BarX==53&&BarI>22){
        BarX=66;BarI=4;
        goto TC2;
       }
       if(BarI>22)BarI=22;
       TC2:
       cline(BarX,BarI,12,31);
       break;

    case 13:/*LT*/
       puttext(1,4,80,22,BARIC);
       if(BarX==14){BarX=1;goto R;}
       if(BarX==27){BarX=14;goto R;}
       if(BarX==40){BarX=27;goto R;}
       if(BarX==53){BarX=40;goto R;}
       if(BarX==66){BarX=53;goto R;}
       if(BarX==1&&BarI>4){BarX=1;BarI=BarI-1;}
       R:
       cline(BarX,BarI,12,31);
       break;

    case 14:/*RT*/
       puttext(1,4,80,22,BARIC);
       if(BarX==1){BarX=14;goto RE;}
       if(BarX==14){BarX=27;goto RE;}
       if(BarX==27){BarX=40;goto RE;}
       if(BarX==40){BarX=53;goto RE;}
       if(BarX==53){BarX=66;goto RE;}
       if(BarX==66&&BarI<22){BarX=66;BarI++;goto RE;}
       RE:
       cline(BarX,BarI,12,31);
       break;

    case 15:
    case 400:/*ENTER*/
       KEY_CODE=0;
       if(BarX==1&&BarI==4){
         chdir("..");
         Re=1;
         goto Jaegi;
       }
        ENTER_ROOTINE(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;

    case 16:/*ÆÄÅ·ºÎºÐ*/
      KEY_CODE=0;
      Park(Windows);
      goto Jaegi;

    case 101:
      KEY_CODE=0;
      while(DRIVEA(Windows)!=0){
       chde=0;
       Re=1;
       goto Jaegi;
      }
    case 102:
      KEY_CODE=0;
      if(DRIVEB(Windows)==0){
       chde=1;
       Re=1;
       goto Jaegi;
      }else{
       break;
      }

    case 103:/*¾ËÆ®+C*/
      chde=2;
      DISK_PATH();
      textattr(7);
      Re=1;
      goto Jaegi;

    case 219:/*cS*/
      KEY_CODE=0;
      fp=fopen("SNOW.EXE","r");
      if(fp==NULL){
        textattr(7);
        clrscr();
        system("_SCSAVE_.BAT");
        Re=1;
        goto Jaegi;
      }
      system("SNOW.EXE");
      Re=1;
      goto Jaegi;

    case 220:/*cT*/
      KEY_CODE=0;
      CTRL_T();
      getch();
      Re=1;
      goto Jaegi;
   Vol:
    case 222:/*cV*/
         KEY_CODE=0;
         SOURCE="\0";
          ERRA();
          Cu(1);
          gotoxy(11,12);
          cprintf("Enter a Volume Label        ");
          gotoxy(43,12);
          cprintf("            ");
          gotoxy(43,13);
          cprintf("            ");
          gotoxy(12,13);
    findfirst("*.*",&f,FA_LABEL);
     parsfnm(f.ff_name,&fcb,0);
       cline(11,12,44,127);
     if(fcb.fcb_name[0]=='A'&&fcb.fcb_name[1]=='P'){
          printf("\a");
          cprintf("Windows '95 Mode Please...");
          getch();
          Cu(0);
          Re=1;
          goto Jaegi;
     }
          a=input_string(11,13,SOURCE,9,95);
          if(a!=-1){
           strcpy(T,"LABEL ");
           strcat(T,SOURCE);
           system(T);
          }
          Cu(0);
          Re=1;
          goto Jaegi;


    Ckey:
      case 226:
       if(COPY2(BarX,BarI)==0){
          Re=1;
          goto Jaegi;
       }else{
          break;
       }
   Dkey:
    case 404:/*D*/
      KEY_CODE=0;
      DEL_DIR(Windows);
      Re=1;
      goto Jaegi;

    case 413:
    case 111:/*M,alt+K*/
      DMAKE_ROOTINE:
      KEY_CODE=0;
      DMAKE(Windows);
      Re=1;
      goto Jaegi;

    case 104:
    case 1000:/*D,DELETE*/
     KEY_CODE=0;
     DFILE(Windows,BarX,BarI);
     Re=1;
     goto Jaegi;

    aRkey:
    case 118:/*aR*/
       KEY_CODE=0;
       RENAME(Windows,BarX,BarI);
       Re=1;
       goto Jaegi;

    case 1100:/*Space*/
    DRIVEB_ERR();
       break;

    case 1500:/*ctrl+enter*/
     KEY_CODE=0;
     EXE_ROOTINE(Windows,BarX,BarI);
     Re=1;
     goto Jaegi;

    case 2000:/*.*/
     KEY_CODE=0;
      chdir("..");
     Re=1;
     goto Jaegi;

    case 3000: /*/*/
     KEY_CODE=0;
      system("cd\\");
     Re=1;
     goto Jaegi;

    case 126:/*aZ*/
     KEY_CODE=0;
     if(Hiddon==0){Hiddon=1;goto DAM;}
     if(Hiddon==1){Hiddon=0;goto DAM;}
     DAM:
     DISK_PATH();
     Re=1;
     goto Jaegi;

    default:
     break;
   }/*switch(KEY_CODE);*/

   goto DA;
    EWND:
    End=END();
    if(End==10){
     mouseon();
     Re=1;
     goto Jaegi;
    }
   if(End==1){
      textattr(7);
      clrscr();
      textattr(7);
      puttext(1,1,80,25,SCR);
      gotoxy(1,25);
      free(BARIC);
      free(SCR);
      Cu(1);
      rename("hwp2txt.exe","hwp2txt.dat");
      textattr(7);
      cprintf("Bye!");
      mouseoff();
      exit(1);
   }
}
ERRA(){
          BOX(Windows,10,11,56,14,95,0);
          textattr(95);
          SHADOW=malloc(4000);
          gettext(12,15,53,16,SHADOW);
          cline(12,15,53,8);
          return 0;
}
ERRB(){
          BOX(Windows,10,8,52,16,95,0);
          textattr(95);
          SHADOW=malloc(4000);
          gettext(12,17,53,17,SHADOW);
          cline(12,17,53,8);
          return 0;
}
END(){
  int a,ACR=1,KEY_CODE;
  char *EndMsg;
   Cu(0);
   mouseoff();
   ERRA();
   gotoxy(11,12);
   cprintf("KwangSung Tools Exit! Yes(Exit)/No(Cancel) ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf(" ±¤¼º ÅøÁî ³¡³¿!       Yes( ³¡ )/No(Ãë ¼Ò)  ");
   }
   cline(11,12,44,78);
  Me:
   Cu(0);
   if(ACR==0){
      textattr(7);
      gotoxy(27,13);
      cprintf("   Yes   ");
      gotoxy(37,13);
      textattr(95);
      cprintf("   No    ");
      gotoxy(45,13);
      cprintf("          ");
   }
   if(ACR==1){
      textattr(95);
      gotoxy(27,13);
      cprintf("   Yes   ");
      gotoxy(37,13);
      textattr(7);
      cprintf("   No    ");
      textattr(95);
      gotoxy(45,13);
      cprintf("          ");
      textattr(7);
   }
   KEY_CODE=KEY();
   if(KEY_CODE==11){goto Me;}
   if(KEY_CODE==12){goto Me;}
   if(KEY_CODE==13){ACR=KEY_CODE=0;goto Me;}
   if(KEY_CODE==14){ACR=1;KEY_CODE=0;goto Me;}
   if(KEY_CODE==10){puttext(10,11,56,14,SAT1);return 10;}
   if(KEY_CODE==15){
      if(ACR==0){
         return 1;
      }else{
          puttext(10,11,56,14,SAT1);
          return 10;
      }
  }
  return 0;
}
