set PROGRAM= "%~1"
ECHO %~1

REM запуск программы с не единичной матрицей
%PROGRAM% dictionary.txt> output.txt
IF ERRORLEVEL 1 GOTO err
output.txt dictionary_output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
