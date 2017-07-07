c:\tc\tcc ktlib.hh
c:\tc\tcc CAL.hh
c:\tc\tcc ktlib.hh>err
c:\tc\tcc CAL.hh>err2
del *.lib
del CAL.EXE
del STLIB.EXE
TLIB kTLIB.LIB+kTLIB.OBJ+CAL.OBJ>NUL
del *.obj
copy ktlib.lib c:\tc\compile\kdir
cd..
