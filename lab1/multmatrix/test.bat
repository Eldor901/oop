@echo off 

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt" 
 
 :: searching for an argument
%PROGRAM% matrix1.txt matrix2.txt > %OUT% || goto err
fc %OUT% out12.txt || goto err

%PROGRAM% matrix3.txt matrix1.txt > %OUT% || goto err
fc %OUT% out31.txt || goto err

%PROGRAM% matrix4.txt matrix2.txt > %OUT% || goto err
fc %OUT% out42.txt || goto err

echo All tests passed 
exit /B 0

:err
echo Program testing failed
exit /B 1