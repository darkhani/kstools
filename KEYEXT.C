   modifiers=bioskey(2);
   if (modifiers){
      if (modifiers & RIGHT) key3=0;
      if (modifiers & LEFT)  key3=1;
      if (modifiers & CTRL)  key3=2;
      if (modifiers & ALT)   key3=3;
   }
   if (key3==''|isalnum(key & 0xFF)){

   }else{
      printf("%#02x\n", key);
   }
