@echo off 

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt" 
 
 :: searching for an argument
%PROGRAM% 101 > %OUT% || goto err
fc %OUT% out1.txt || goto err

%PROGRAM% 10111111 > %OUT% || goto err
fc %OUT% out2.txt || goto err

%PROGRAM% hello > %OUT% || goto err
fc %OUT% out3.txt || goto err

%PROGRAM% 202 > %OUT% || goto err
fc %OUT% out4.txt || goto err

%PROGRAM% 1111111111 > %OUT% || goto err
fc %OUT% out5.txt || goto err


%PROGRAM% 1111111111111111111111111111111 > %OUT% || goto err
fc %OUT% out7.txt || goto err

echo All tests passed 
exit /B 0

:err
echo Program testing failed
exit /B 1