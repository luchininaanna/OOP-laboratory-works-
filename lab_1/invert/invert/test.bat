set PROGRAM= "%~1"
ECHO %~1

REM запуск программы c нулевой
%PROGRAM% matrix_1.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt matrix_1_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с матрицей общего вида
%PROGRAM% matrix_2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt matrix_2_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с единичной матрицей
%PROGRAM% matrix_3.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt matrix_3_output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
