@ECHO OFF
ECHO compiling....
TCC kT.C ktlib.lib
TCC kT.C ktlib.lib>kt.err
del kt.obj
del kt.bak
echo y|del *.bak>nul
copy kt.exe c:\Kt
copy kt.exe c:\Kt
ECHO End.
