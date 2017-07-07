COPY2(int x,int y){
    char *SOURCE,*TARGET;
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
          cprintf(" Enter a Source Filename     ");
          gotoxy(43,12);
          cprintf("            ");
          gotoxy(43,13);
          cprintf("            ");
          gotoxy(12,13);
          strcpy(SOURCE,F);
          input_string(11,13,SOURCE,44,95);
          gotoxy(11,12);
          cprintf(" Enter a Target Filename     ");
          gotoxy(43,12);
          cprintf("            ");
          gotoxy(43,13);
          cprintf("            ");
          gotoxy(12,13);
          strcpy(TARGET,"C:\\");
          input_string(11,13,TARGET,44,95);
          COPY(SOURCE,TARGET);
          return;
}
