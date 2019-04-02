@echo off 

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt" 
 
 
%PROGRAM% input1.txt output1.txt > %OUT% || goto err
fc %OUT% output1.txt || goto err

%PROGRAM% input2.txt output2.txt > %OUT% || goto err
fc %OUT% output2.txt || goto err

echo All tests passed 
exit /B 0

:err
echo Program testing failed
exit /B 1