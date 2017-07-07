#include <io.h>
#include <io.h>
#include <dir.h>
#include <fcntl.h>
#include <string.h>
#include <mem.h>
#include <sys\stat.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <bios.h>
#include <dos.h>
char *V3Run;
int X=30,Y=17;
char mem_dir[MAXPATH];
struct DxStr {                     /* ¢…¸aµi ¯aËaœâÁa ¸÷· */
    unsigned int iOffset;
    unsigned char cLen, sVirStr[10];
} MichDx = {                       /* »¥”e¶w ¢…¸aµi */
    0x000E,
    10,
    {0x1E, 0x50, 0x0A, 0xD2, 0x75, 0x1B, 0x33, 0xC0, 0x8E, 0xD8}
};
struct DxStr1 {                     /* ¢…¸aµi ¯aËaœâÁa ¸÷· */
    unsigned int iOffset;
    unsigned char cLen, sVirStr[10];
}AntiDx = {                       /* »¥”e¶w ¢…¸aµi */
    0x0052,
    10,
    {0x1E, 0x50, 0xF6, 0xC2, 0xF0, 0x75, 0x28, 0xD0, 0xEC, 0xFE}
};
struct DxStr2 {                     /* ¢…¸aµi ¯aËaœâÁa ¸÷· */
    unsigned int iOffset;
    unsigned char cLen, sVirStr[10];
}LbcDx = {                       /* »¥”e¶w ¢…¸aµi */
    0x17,
    10,
    {0x48, 0x48, 0x89, 0x07, 0xB1, 0x06, 0xD3, 0xE0, 0x8E, 0xC0}
};
struct DxStr3 {                     /* ¢…¸aµi ¯aËaœâÁa ¸÷· */
    unsigned int iOffset;
    unsigned char cLen, sVirStr[10];
} MonBDx = {                       /* »¥”e¶w ¢…¸aµi ¡·Ç¡§¡*/
    0x18,
    10,
    {0xEA, 0x1D, 0x06, 0x00, 0x00, 0xBE, 0xBE, 0x07, 0xFA, 0x2B}
};
struct DxStr4 {                     /* ¢…¸aµi ¯aËaœâÁa ¸÷· */
    unsigned int iOffset;
    unsigned char cLen, sVirStr[10];
} NiceDx = {                       /* »¥”e¶w ¢…¸aµi ¡·Ç¡§¡*/
    0xD3,
    10,
    {0xE7, 0xEE, 0xF9, 0xEA, 0x8F, 0xEE, 0xBF, 0xE1, 0xE6, 0xEC}
};
struct DxStr5 {                     /* ¢…¸aµi ¯aËaœâÁa ¸÷· */
    unsigned int iOffset;
    unsigned char cLen, sVirStr[10];
} DamaDx = {                       /* »¥”e¶w ¢…¸aµi */
    0x00AE,
    10,
    {0x59, 0xEC, 0x00, 0xF0, 0x05, 0x03, 0x01, 0x00, 0x01, 0x00}
};



unsigned int iOffOld132 = 0x18;     /* ¡·Ç¡§¡ º­¡ */
unsigned int iOffOld131 = 0x1E;     /* µ¡Ïa­U º­¡ */
unsigned int iOffOld13 = 0x0A;     /* µ¡Ïa­U º­¡ */

/*Jeru*/
unsigned int iVirLn    = 0x710;    /* ¤a·¡œá¯a ‹©·¡ */
unsigned int iEntStLn  = 0xC5;     /* ¯¡¸b¸ñ Àa·¡ ‹©·¡ */
unsigned int iOffOld21 = 0x17;     /* ¶¥œ ·¥ÈáœóËa ¸á¸w ¶áÃ¡ */
unsigned int iOffOldLn = 0x11;     /* ¶¥œ Ìa·© ‹©·¡ ¸á¸w ¶áÃ¡ */
unsigned int iOffCS    = 0x49;     /* ¶¥œ CS ˆt ¸á¸w ¶áÃ¡ */
unsigned int iOffIP    = 0x47;     /* ¶¥œ IP ˆt ¸á¸w ¶áÃ¡ */
unsigned int iOffSS    = 0x45;     /* ¶¥œ SS ˆt ¸á¸w ¶áÃ¡ */
unsigned int iOffSP    = 0x43;     /* ¶¥œ SP ˆt ¸á¸w ¶áÃ¡ */
/*************/
unsigned int iMemSize = 2;         /* ·©¤e ‹¡´â¸w­¡ ˆq­¡ Ça‹¡ */

unsigned char i, cDrive, sBuffer[0x200];
char far *lpcMem;
int  far *lpiMem;
union REGS r;
struct SREGS sr;
unsigned int iInfFile = 0;         /* ˆqµq Ìa·© ® */

   char JU[][10]={"É","Í","»","º","È","¼"};
char szPrgName[]  = "ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n\r"
            "º  Kwang-sung Boot Vaccine Ver. 7          º\n\r"
            "º                                          º\n\r"
            "º (C)Copyright 1999 by Hacker System (HIT) º\n\r"
            "ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\r";

char szMsg1[]    = "\nUsage : SV <drive> </option>\n"
                   "Option : /? This screen\n"
                   "         /V Virus List\n";
char szMsg2[]    = "Checking the Memory  : ";
char szMsg3[]    = "Checking Boot Sector : ";
char szMsg31[]    = "Checking Directory & Files : ";
char szMsg4[]    = "no Michelangelo virus\n";
char szMsg5[]    = "\aMichelangelo virus found";
char szMsg41[]    = "no Anti-coms virus\n";
char szMsg51[]    = "\aAnti-cmos virus found";
char szMsg42[]    = "no LBC virus\n";
char szMsg52[]    = "\aLBC virus found";
char szMsg43[]    = "no Monkey.B virus\n";
char szMsg53[]    = "\aMonkey.B virus found";
char szMsg44[]    = "no Nice_day virus\n";
char szMsg54[]    = "\aNice_day virus found";
char szMsg45[]    = "no Damanagi virus\n";
char szMsg55[]    = "\aDamanagi virus found";
char szMsg6[]    = " -> Cured\n";
char szErrMsg1[] = "\n\aERROR: disk read error\n";
char szErrMsg2[] = "\n\aERROR: disk write error\n";
char szErrMsg3[] = "\n\aERROR: file read error\n";
char szErrMsg4[] = "\n\aERROR: file write error\n";

CM(){
    printf("\nConventional Memory : %dKB\n", biosmemory());       /* ‹¡¥¥¡A¡¡Ÿ¡ Ça‹¡ Â‰b*/
    if(biosmemory()==640){
         return 1;
    }else{
        return -1;
    }
}
int cbreak(){
    puts(mem_dir);
    chdir(mem_dir);
    return 0;
}
Reg(){
    FILE *fp;
    fp=fopen("C:\\kt.cfg","r");
    if(fp!=NULL){
        return 1;
    }else{
        return -1;
    }
}

#define FA_LIST (FA_RDONLY|FA_HIDDEN|FA_SYSTEM|FA_DIREC|FA_ARCH)

int main(int argc, char *argv[])
{
    char *F,Q[3];
    int a,b,C=0;
    unsigned char cOldDrive;
    char szOldDir[0x80] = {'\\',};
    char far *lpcMem;
    int i;
    int far *lpiMem;
    union REGS r;
    struct SREGS sr;

    clrscr();
    textattr(31);
    cprintf("%s", szPrgName);       /* Ïa¡‹aœ‘ ·¡Ÿq Â‰b */

    b=Reg();
     cDrive = toupper(*argv[1]) - 'A';
    if(b==1){
        printf("\nRegister : KT99-2500-2500-XXX\n");
    }else{
        printf("\n\07This program is not register!\n");
    }
    if(argv[1][0]=='/'||argv[2][0]=='/'){
         if(argv[1][1]=='V'||argv[1][1]=='v'||argv[2][1]=='V'||argv[2][1]=='v'){
            textattr(14);
            a=CM();
            if(a==1){
              printf("%sNo(Known) Computer Virus.\n",szMsg2);
            }else{
                goto Yes;
           }
            cprintf("\n      * Virus List * \n\n\r");
            textattr(10);
            cprintf("     Anti-Cmos    Virus   |      Damanagi  Virus\n\r");
            cprintf("             LBC  Virus   |   Michelangelo Virus\n\r");
            textattr(11);
            cprintf("        Monkey.B  Virus   |   Nice_day     Virus\n\r");
            cprintf("    V3res Trojan  Virus\n\r");
            textattr(7);
            exit(0);
        }
         if(argv[1][1]=='?'){
        a=CM();
        if(a==1)printf("%sNo(Known) Computer Virus.\n",szMsg2);
        printf("%s", szMsg1);
            exit(0);
        }
    }
          a=CM();
    if(a==1){
        printf("%sNo(Known) Computer Virus.",szMsg2);
        goto No;
    }else{

        goto Yes;
    }

    Yes:/*‹¡¥¥¡A¡¡Ÿ¡· Ça‹¡ˆa 640·¡ ´a“¥‰w¶*/
    textattr(7);
    /*MiCH*/
    printf("%s", szMsg2);          /* '‹¡´â¸w­¡ ˆñ¬a:' Â‰b */
    lpcMem = MK_FP(biosmemory() << 6, MichDx.iOffset);
    for (i = 0; i < MichDx.cLen; i++)
        if (lpcMem[i] != MichDx.sVirStr[i]) break;
    if (i != MichDx.cLen)
        printf("%s", szMsg4);      /* '¤a·¡œá¯a ´ô·q' Â‰b */
    else {
        printf("%s", szMsg5);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        r.x.ax = 0x2513;
        lpiMem = MK_FP(biosmemory() << 6, iOffOld13);
        r.x.dx = *lpiMem++;
        sr.ds  = *lpiMem;
        intdosx(&r, &r, &sr);      /* 13h¤å ·¥ÈáœóËa º­¡ ¥¢Š */
        lpiMem = MK_FP(0x0000, 0x0413);
        *lpiMem += iMemSize;       /* ·©¤e ‹¡´â¸w­¡· Ça‹¡ ¥¢Š */
        printf("%s", szMsg6);      /* '-> Ã¡a' Â‰b */
    }
    /* ANTI-CMOS ¤a·¡œá¯a Ë¥ */
    printf("%s", szMsg2);          /* '‹¡´â¸w­¡ ˆñ¬a:' Â‰b */
    lpcMem = MK_FP(biosmemory() << 6, AntiDx.iOffset);
    for (i = 0; i < AntiDx.cLen; i++)
        if (lpcMem[i] != AntiDx.sVirStr[i]) break;
    if (i != AntiDx.cLen)
        printf("%s", szMsg41);      /* '¤a·¡œá¯a ´ô·q' Â‰b */
    else {
        printf("%s", szMsg51);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        r.x.ax = 0x2513;
        lpiMem = MK_FP(biosmemory() << 6, iOffOld131);
        r.x.dx = *lpiMem++;
        sr.ds  = *lpiMem;
        intdosx(&r, &r, &sr);      /* 13h¤å ·¥ÈáœóËa º­¡ ¥¢Š */
        lpiMem = MK_FP(0x0000, 0x0413);
        *lpiMem += iMemSize;       /* ·©¤e ‹¡´â¸w­¡· Ça‹¡ ¥¢Š */
        printf("%s", szMsg6);      /* '-> Ã¡a' Â‰b */
    }
    /*LBC*/
    printf("%s", szMsg2);          /* '‹¡´â¸w­¡ ˆñ¬a:' Â‰b */
    lpcMem = MK_FP(biosmemory() << 6, AntiDx.iOffset);
    for (i = 0; i < LbcDx.cLen; i++)
        if (lpcMem[i] != LbcDx.sVirStr[i]) break;
    if (i != LbcDx.cLen)
        printf("%s", szMsg42);      /* '¤a·¡œá¯a ´ô·q' Â‰b */
    else {
        printf("%s", szMsg52);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        r.x.ax = 0x2513;
        lpiMem = MK_FP(biosmemory() << 6, iOffOld131);
        r.x.dx = *lpiMem++;
        sr.ds  = *lpiMem;
        intdosx(&r, &r, &sr);      /* 13h¤å ·¥ÈáœóËa º­¡ ¥¢Š */
        lpiMem = MK_FP(0x0000, 0x0413);
        *lpiMem += iMemSize;       /* ·©¤e ‹¡´â¸w­¡· Ça‹¡ ¥¢Š */
        printf("%s", szMsg6);      /* '-> Ã¡a' Â‰b */
    }
    /*** MONKEY.B ¤a·¡œá¯a***/

    printf("%s", szMsg2);          /* '‹¡´â¸w­¡ ˆñ¬a:' Â‰b */
    lpcMem = MK_FP(biosmemory() << 6, MonBDx.iOffset);
    for (i = 0; i < MonBDx.cLen; i++)
        if (lpcMem[i] != MonBDx.sVirStr[i]) break;
    if (i != MonBDx.cLen)
        printf("%s", szMsg43);      /* '¤a·¡œá¯a ´ô·q' Â‰b */
    else {
        printf("%s", szMsg53);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        r.x.ax = 0x2513;
        lpiMem = MK_FP(biosmemory() << 6, iOffOld13);
        r.x.dx = *lpiMem++;
        sr.ds  = *lpiMem;
        intdosx(&r, &r, &sr);      /* 13h¤å ·¥ÈáœóËa º­¡ ¥¢Š */
        lpiMem = MK_FP(0x0000, 0x0413);
        *lpiMem += iMemSize;       /* ·©¤e ‹¡´â¸w­¡· Ça‹¡ ¥¢Š */
        printf("%s", szMsg6);      /* '-> Ã¡a' Â‰b */
    }

    /*** Nice_day ¤a·¡œá¯a***/

    printf("%s", szMsg2);          /* '‹¡´â¸w­¡ ˆñ¬a:' Â‰b */
    lpcMem = MK_FP(biosmemory() << 6, NiceDx.iOffset);
    for (i = 0; i < NiceDx.cLen; i++)
        if (lpcMem[i] != NiceDx.sVirStr[i]) break;
    if (i != NiceDx.cLen)
        printf("%s", szMsg44);      /* '¤a·¡œá¯a ´ô·q' Â‰b */
    else {
        printf("%s", szMsg54);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        r.x.ax = 0x2513;
        lpiMem = MK_FP(biosmemory() << 6, iOffOld13);
        r.x.dx = *lpiMem++;
        sr.ds  = *lpiMem;
        intdosx(&r, &r, &sr);      /* 13h¤å ·¥ÈáœóËa º­¡ ¥¢Š */
        lpiMem = MK_FP(0x0000, 0x0413);
        *lpiMem += iMemSize;       /* ·©¤e ‹¡´â¸w­¡· Ça‹¡ ¥¢Š */
        printf("%s", szMsg6);      /* '-> Ã¡a' Â‰b */
    }
    /* DAMANAGI ¤a·¡œá¯a ¸s‹¡*/
    printf("%s", szMsg2);          /* '‹¡´â¸w­¡ ˆñ¬a:' Â‰b */
    lpcMem = MK_FP(biosmemory() << 6, DamaDx.iOffset);
    for (i = 0; i < DamaDx.cLen; i++)
        if (lpcMem[i] != DamaDx.sVirStr[i]) break;
    if (i != DamaDx.cLen)
        printf("%s", szMsg45);      /* '¤a·¡œá¯a ´ô·q' Â‰b */
    else {
        printf("%s", szMsg55);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        r.x.ax = 0x2513;
        lpiMem = MK_FP(biosmemory() << 6, iOffOld13);
        r.x.dx = *lpiMem++;
        sr.ds  = *lpiMem;
        intdosx(&r, &r, &sr);      /* 13h¤å ·¥ÈáœóËa º­¡ ¥¢Š */
        lpiMem = MK_FP(0x0000, 0x0413);
        *lpiMem += iMemSize;       /* ·©¤e ‹¡´â¸w­¡· Ça‹¡ ¥¢Š */
        printf("%s", szMsg6);      /* '-> Ã¡a' Â‰b */
    }


    No:/*¡A¡¡Ÿ¡µA ¤a·¡œá¯aˆa ´ô“e ‰w¶ JMP*/
    if (argc == 1) {               /* ·¥¸a ´ô·i ˜ •¡¶‘ i Â‰b */
        printf("%s", szMsg1);
        exit(0);
    }
    /* Boot Sector */
    cDrive = toupper(*argv[1]) - 'A';
    if (cDrive >= 2)
        cDrive += 0x7E;            /* ˆñ¬aĞi —aœa·¡§a ´i´a‘ */
    printf("\n\n\rChecking %s\n\n",argv[1]);

    /* ¦Ëa ­BÈá ·ª·q */

    printf("%s", szMsg3);          /* '¦Ëa ­BÈá ˆñ¬a:' Â‰b */

    r.h.ah = 0x0D;
    intdos(&r, &r);

    for (i = 0; i < 4; i++) {
        if (biosdisk(2, cDrive, 0, 0, 1, 1, sBuffer) == 0) break;
        biosdisk(0, cDrive, 0, 0, 1, 1, sBuffer);
    }
    if (i == 4) {
        printf("%s", szErrMsg1);   /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
        exit(0);
    }

    /* ¦Ëa ­BÈá ˆñ¬a */
    for (i = 0; i < MichDx.cLen; i++)
        if (sBuffer[MichDx.iOffset + i] != MichDx.sVirStr[i])
            break;
    if (i != MichDx.cLen)
        C+=1;
    else {
        printf("%s\n", szMsg5);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
        if (cDrive < 0x80) {       /* ¶¥œ ¦Ëa ­BÈá ·ª·q */
            if (biosdisk(2, cDrive, 1, sBuffer[0x9],
                          sBuffer[0x8], 1, sBuffer)) {
                printf("%s", szErrMsg1); /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
            exit(1);
         }
        }
        else {
            if (biosdisk(2, cDrive, 0, 0, 7, 1, sBuffer)) {
                printf("%s", szErrMsg1); /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
                exit(1);
        }
    }
        printf("\nCure it?(Y/n) : ");
        gets(F);
        if(F[0]=='Y'||F[0]=='y'){
        /* ¦Ëa ­BÈá Ã¡a */
        if (biosdisk(3, cDrive, 0, 0, 1, 1, sBuffer)) {
            printf("%s", szErrMsg2); /* —¡¯aÇa ³a‹¡ µ¡ŸA */
            exit(1);
        }
        r.h.ah = 0x0D;
        intdos(&r, &r);

        printf("%s\n", szMsg6);      /* '-> Ã¡a' Â‰b */
      }
      else{
         printf("Not Cure it!\07\nRun to V3 or TV Now!");
         printf("\nPress any key to V3 Run!");
         getch();
         strcpy(V3Run,"V3 ");
         strcat(V3Run,argv[1]);
         system(V3Run);
         exit(1);
      }
    }
    /* ¦Ëa ­BÈá ˆñ¬a ==ANTI-CMOS== */

    for (i = 0; i < AntiDx.cLen; i++)
        if (sBuffer[AntiDx.iOffset + i] != AntiDx.sVirStr[i])
            break;
    if (i != AntiDx.cLen)
       C+=1;
    else {
     printf("\07%s\n", szMsg51);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
         printf("\n\nNot Cure it!\nRun to V3...\nor SYS C: %s",argv[1]);
         printf("\nPress any key to V3 Run!");
         getch();
         strcpy(V3Run,"V3 ");
         strcat(V3Run,argv[1]);
         system(V3Run);
         exit(1);
        }

    /*LBC*/

    r.h.ah = 0x0D;
    intdos(&r, &r);

    for (i = 0; i < 4; i++) {
        if (biosdisk(2, cDrive, 0, 0, 1, 1, sBuffer) == 0) break;
        biosdisk(0, cDrive, 0, 0, 1, 1, sBuffer);
    }
    if (i == 4) {
        printf("%s", szErrMsg1);   /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
        exit(1);
    }

    /* ¦Ëa ­BÈá ˆñ¬a */

    for (i = 0; i < LbcDx.cLen; i++)
        if (sBuffer[LbcDx.iOffset + i] != LbcDx.sVirStr[i])
            break;
    if (i != LbcDx.cLen)
     C+=1;
    else {
     printf("\07%s\n", szMsg52);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
         printf("\nNot Cure it!\07\nRun to V3 or TV Now!\nSYS C: %s",argv[1]);
         printf("\nPress any key to V3 Run!");
         getch();
         strcpy(V3Run,"V3 ");
         strcat(V3Run,argv[1]);
         system(V3Run);

         exit(1);
        }
    /*Monkey.B */


    r.h.ah = 0x0D;
    intdos(&r, &r);

    for (i = 0; i < 4; i++) {
        if (biosdisk(2, cDrive, 0, 0, 1, 1, sBuffer) == 0) break;
        biosdisk(0, cDrive, 0, 0, 1, 1, sBuffer);
    }
    if (i == 4) {
        printf("%s", szErrMsg1);   /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
        exit(1);
    }

    /* ¦Ëa ­BÈá ˆñ¬a */

    for (i = 0; i < MonBDx.cLen; i++)
        if (sBuffer[MonBDx.iOffset + i] != MonBDx.sVirStr[i])
            break;
    if (i != MonBDx.cLen)
         C+=1;
    else {
     printf("\07%s\n", szMsg53);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
         printf("\nNot Cure it!\07\nRun to V3 or TV Now!\nSYS C: %s",argv[1]);
         printf("\nPress any key to V3 Run!");
         getch();
         strcpy(V3Run,"V3 ");
         strcat(V3Run,argv[1]);
         system(V3Run);

         exit(1);
        }
    /* Nice_day */


    r.h.ah = 0x0D;
    intdos(&r, &r);

    for (i = 0; i < 4; i++) {
        if (biosdisk(2, cDrive, 0, 0, 1, 1, sBuffer) == 0) break;
        biosdisk(0, cDrive, 0, 0, 1, 1, sBuffer);
    }
    if (i == 4) {
        printf("%s", szErrMsg1);   /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
        exit(1);
    }

    /* ¦Ëa ­BÈá ˆñ¬a */

    for (i = 0; i < NiceDx.cLen; i++)
        if (sBuffer[NiceDx.iOffset + i] != NiceDx.sVirStr[i])
            break;
    if (i != NiceDx.cLen){
   C+=1;
   }else {
     printf("\07%s\n", szMsg54);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
         printf("\nNot Cure it!\07\nRun to V3 or TV Now!\nSYS C: %s",argv[1]);
         printf("\nPress any key to V3 Run!");
         getch();
         strcpy(V3Run,"V3 ");
         strcat(V3Run,argv[1]);
         system(V3Run);
         exit(1);
        }

    /* Damanagi ¤a·¡œá¯a ¸s‹¡ */

    r.h.ah = 0x0D;
    intdos(&r, &r);

    for (i = 0; i < 4; i++) {
        if (biosdisk(2, cDrive, 0, 0, 1, 1, sBuffer) == 0) break;
        biosdisk(0, cDrive, 0, 0, 1, 1, sBuffer);
    }
    if (i == 4) {
        printf("%s", szErrMsg1);   /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
        exit(1);
    }

    /* ¦Ëa ­BÈá ˆñ¬a */

    for (i = 0; i < DamaDx.cLen; i++)
        if (sBuffer[DamaDx.iOffset + i] != DamaDx.sVirStr[i])
            break;
    if (i != DamaDx.cLen)
     C+=1;
    else {
        printf("%s\n", szMsg55);      /* '¤a·¡œá¯a ¹¥¸' Â‰b */
         printf("Not Cure it!\07\nRun to V3 or TV Now!");
         printf("\nPress any key to V3 Run!");
         getch();
         strcpy(V3Run,"V3 ");
         strcat(V3Run,argv[1]);
         system(V3Run);
         exit(1);
    }
    /* 5237 ¤a·¡œá¯a ¸s‹¡ */


    r.h.ah = 0x0D;
    intdos(&r, &r);

    for (i = 0; i < 4; i++) {
        if (biosdisk(2, cDrive, 0, 0, 1, 1, sBuffer) == 0) break;
        biosdisk(0, cDrive, 0, 0, 1, 1, sBuffer);
    }
    if (i == 4) {
        printf("%s", szErrMsg1);   /* —¡¯aÇa ·ª‹¡ µ¡ŸA */
        exit(1);
    }

   if(C==6){
    printf("No(Known) Computer Virus.");
  }
    exit(1);
 }
