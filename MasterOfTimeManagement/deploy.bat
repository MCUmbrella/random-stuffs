copy prntctrl.exe C:\Windows\System32\
sc create ParentControl binpath= "C:\Windows\System32\prntctrl.exe" start= delayed-auto displayname= "Microsoft Parent Control"
@echo off
sc start ParentControl
pause
