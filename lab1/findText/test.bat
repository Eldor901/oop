@echo off 

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt" 
 
 :: searching for an argument
%PROGRAM% sometext1.txt "eldor" > %OUT% || goto err
fc %OUT% out1.txt || goto err

:: searching for an argument that not found
%PROGRAM% sometext1.txt "eldorPower" > %OUT%
fc %OUT% out2.txt || goto err

:: searching for an unfound text
%PROGRAM% sometext.txt "eldorPower" > %OUT%
fc %OUT% erropenfile.txt || goto err

%PROGRAM% sometext2.txt "little horse"> %OUT%
fc %OUT% out3.txt || goto err


echo All tests passed 
exit /B 0

:err
echo Program testing failed
exit /B 1