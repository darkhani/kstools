/*���A�� ���I*/
char * model_name[7] = {
                         "IBM PS/2 model 70/80",  /* F8H ���� */
                         "IBM PC Convertible",    /* F9H ���� */
                         "IBM PS/2 model 25/30",  /* FAH ���� */
                         "IBM XT",                /* FBH ���� */
                         "IBM AT or compatible",                /* FCH ���� */
                         "IBM XT",                /* FEH ���� */
                         "IBM PC" };              /* FFH ���� */
/*�a���a*/
char * mouse_type[5] = { "Bus Mouse",
                         "Serial Mouse",
                         "InPort Mouse",
                         "PS/2 Mouse",
                         "HP mouse" };

char * video_adaptor[9] =  { "VGA & monochrome ",
                             "VGA & color",
                             "MCGA & monochrome",
                             "MCGA & color",
                             "EGA & monochrome",
                             "EGA & color",
                             "CGA",
                             "HGC",
                             "MDA" };
char *video_mode[4] = { "EGA/PGA/VGA",
                        "40x25 Color",
                        "80x25 Color",
                        "80x25 Monochrom" };
union {
    unsigned int equip1;
    struct {
        unsigned int is_floppy       : 1;
        unsigned int is_coprocessor  : 1;
        unsigned int not_used        : 2;
        unsigned int video_mode      : 2;
        unsigned int floppy_number   : 2;
        unsigned int reserved        : 1;
        unsigned int serial_port     : 3;
        unsigned int is_game_port    : 1;
        unsigned int parallel_port   : 2;
    } equip2;
} Equipment;
/*ROM�e�e�i*/
void GetROMDate(int *year, int *month, int *day) {
    char far * date = (char far *)0xF000FFF5;
    char Year[3];
    char Month[3];
    char Day[3];
    Year[0]  = date[6]; Year[1]  = date[7]; Year[2] = '\0';
    Day[0]   = date[3]; Day[1]   = date[4]; Day[2]  = '\0';
    Month[0] = date[0]; Month[1] = date[1]; Month[2]= '\0';
    (*year)  = atoi(Year); /* ���a�i�i int�� �a�����e �q�� */
    (*month) = atoi(Month);
    (*day)   = atoi(Day);
}
/*  char * GetComputerName() �e�� ���A�᷁ ���q�i �i�a���e �q��*/
char * GetComputerName() {
    unsigned char computer_name = *(unsigned char far *)0xF000FFFE;
    return ( model_name[computer_name - 0xF8] );
}
/* char *GetKeyboardType() ǡ���a�� ���A�i ���a�a�e �q��*/
char * GetKeyboardType() {
    unsigned char info = *(unsigned char far *)0x00000496;
    if(info & 0x10)
        return "101 Or 103 or Better Key";
    else
        return "84 Or 86 Key";
}
/** int IsMouseDriver() �a���a �a�a����a �����a�e�� ���a�a�e �q��*/
int IsMouseDriver() {
     void interrupt(*mouse_vector)();
     mouse_vector = getvect(0x33);
     if(mouse_vector == 0)
         return 0;
     else
         return 1;
 }
/* char * GetMouseType()*/
 char * GetMouseType() {
     union REGS mouse;
     mouse.x.ax = 0x0024;
     int86(0x33, &mouse, &mouse);
     return ( mouse_type[ mouse.h.ch - 1] );
 }
/* unsigned GetMemorySize() ���� �A������ �a���i ���a�a�e �q��**/
 unsigned GetMemorySize() {
     union REGS memory;
     int86(0x12, &memory, &memory);
     return ( memory.x.ax );
 }
 /* int IsXMM()- ���a�E���a �A���� �ş����� �����i �i�a���e �q��*/
int IsXMM() {
    union REGS mem;
    mem.x.ax = 0x4300;
    int86(0x2F, &mem, &mem);
    if(mem.h.al == 0x80)
        return 1;
    else
        return 0;
}
/* int GetXMSMemorySize()- ���a�E���a �A������ �a���i ���a�a�e �q��**/
int GetXMSMemorySize() {
    int data;
    outportb(0x70, 0x31);
    data = inportb(0x71) * 256;
    outportb(0x70, 0x30);
    data += inportb(0x71);
    return data;
}
/* char *GetVideoAdaptor()- ������ �ᔓ�᷁ ���A�i ���a�a�e �q��*/
char *GetVideoAdaptor() {
    unsigned char monochrome = *(unsigned char far *)0x00400087;
    unsigned int iteration;
    unsigned char old, new;
    union REGS in;
    in.h.ah = 0x1A;
    in.h.al = 0x00;
    int86(0x10, &in, &in);
    if( in.h.al == 0x1A ) {
        if((in.h.bl>=0x07) && (in.h.bl<=0x08))
            return video_adaptor[in.h.bl - 0x07];
        if((in.h.bl>=0x0B) && (in.h.bl<=0x0C))
            return video_adaptor[in.h.bl - 0x09];
    }
    else {
        in.h.ah = 0x12;
        in.h.bl = 0x10;
        int86(0x10, &in, &in);
        if(in.h.bl != 0x10) {
            if( monochrome & 0x02 )
                 return video_adaptor[4];
            else
                 return video_adaptor[5];
        }
        else {
            in.h.ah = 0x0F;
            int86(0x10, &in, &in);
            if(in.h.al != 0x07)
                return video_adaptor[6];
            else {
                old = inportb(0x3BA) & 0x80;
                for(iteration=0; iteration<0x8000; iteration++) {
                    new = inportb(0x3BA) & 0x80;
                    if( new != old )
                        return video_adaptor[7];
                }
                return video_adaptor[8];
            }
        }
    }
  return 0;
}
/* int IsFloppyDrive()- �i��ϡ �a�a���a�a ���A��A ���aɩ�A�� ���e���i ��a�a�e �q��*/
int IsFloppyDrive() {
    Equipment.equip1 = *(unsigned int far *)0x00400010;
    return Equipment.equip2.is_floppy;
}

/* int IsCoprocessor()- š�a���A��a ���A��A ���aɩ�A�� ���e���i ��a�a�e �q��*/
int IsCoprocessor() {
    Equipment.equip1 = *(unsigned int far *)0x00400010;
    return Equipment.equip2.is_coprocessor;
}
/* char *GetVideoMode()- �e���� ������ ���a�i ���a�a�e �q��*/
char *GetVideoMode() {
    Equipment.equip1 = *(unsigned int far *)0x00400010;
    return video_mode[ Equipment.equip2.video_mode ];
}
/* int GetFloppyNo()- �i��ϡ �a�a���a�� ���i ���a�a�e �q��*/
int GetFloppyNo() {
    Equipment.equip1 = *(unsigned int far *)0x00400010;
    return Equipment.equip2.floppy_number+1;
}
/*int GetSerialNo()- ���i ͡�a�� ���a�i ���a�a�e �q��*/
int GetSerialNo() {
    Equipment.equip1 = *(unsigned int far *)0x00400010;
    return Equipment.equip2.serial_port;
}
/*int GetParallelNo() - �w�i ͡�a�� ���i ���a�a�e �q��*/
int GetParallelNo() {
    Equipment.equip1 = *(unsigned int far *)0x00400010;
    return Equipment.equip2.parallel_port;
}
long GetAvailDiskSpace(int drive) {/*�ϵ�뷮*/
    unsigned long availspace;
    union REGS disk;
    disk.h.ah = 0x36;
    disk.h.dl = drive;
    int86(0x21, &disk, &disk);
    if(disk.x.ax == 0xFFFF){
	return 0;
	} else {
        availspace = (long)disk.x.bx * (long)disk.x.ax * (long)disk.x.cx;
        return availspace;
    }
}
/*���A ���a�a �w��*/
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
