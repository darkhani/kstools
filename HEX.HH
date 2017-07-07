HEX_FILE(int Windows,int x,int y){
 char bs[200];
 char FM[200]="";
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
   gotoxy(11,12);
   cprintf("         Enter a HEX-VIEW Filename          ");
   if(Windows==1){
      gotoxy(11,12);
      cprintf("         HEX ¸ðµå º¸±â ¸¶¹ý»ç               ");
    }
   cline(11,12,44,127);
   cline(11,13,44,95);
    gotoxy(11,13);
    cprintf("%s",FM);
    gotoxy(11,13);  Cu(1);
    CANCEL=input_string(11,13,FM,44,95);
    if(CANCEL==0||F=='\0'){
      strcpy(FM," ");
    }
     HEX(FM);
    puttext(10,11,56,14,SAT1);
    free(SAT1);
    Cu(0);
    return 0;

}
HEX(char *FM){
    unsigned char monja[40];
    int i,j,ji=0,q,key,de;
    unsigned long size;
    FILE *fp;
    fp=fopen(FM,"rb");
    if(fp==NULL){
          goto end;
    }
    textattr(31);
    clrscr();
         gotoxy(1,1);
        DISK_PATH();
          de=findfirst(FM,&f,FA_ARCH);
        size=f.ff_fsize;
        textattr(123);
        cprintf("[Û] Filename : %25s\\%s     %20lubytes\r",newpath,FM,size);
         gotoxy(1,2);
         textattr(127);
        cputs("Offset  00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F   0123456789ABCDEF     \r\n\r");
    textattr(31);
    while(!feof(fp)){
         cprintf("\n%05x : ",ftell(fp));
         for(i=0;i<16;i++){
             monja[i]=fgetc(fp);
             cprintf("%02X ",(unsigned char)monja[i]);
             if(feof(fp)) break;
         }
         cprintf("  ");
         for(j=0;j<i;j++){
             if(monja[j]=='\t'||monja[j]=='\n'||monja[j]=='\r'||monja[j]=='\a') monja[j]='.';
             cprintf("%c",monja[j]);
            }
            cputs("\r");
            ji++;
           if(ji>20){
              while(!bioskey(1));
              key=bioskey(0);
              switch(key){
                case 283 : goto end;
                default :
                 break;
            }
           clrscr();
         gotoxy(1,1);
        textattr(123);
        cprintf("[Û] Filename : %25s\\%s     %20lubytes\r",newpath,FM,size);
         gotoxy(1,2);
         textattr(127);
        cputs("Offset  00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F   0123456789ABCDEF     \r\n\r");
          textattr(31);
              ji=1;
              }
        }
   printf("\n\r*** End of File ***");
   getch();
 end:
   textattr(7);
   clrscr();
}
