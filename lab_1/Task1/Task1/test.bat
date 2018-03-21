
set PROGRAM= "%~1"
ECHO %~1

REM запуск программы с одним включением строки в текстовом файле
%PROGRAM% poem.txt "sky" > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt poem_output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
