set PROGRAM= "%~1"
ECHO %~1

REM запуск программы c нулевой
%PROGRAM% matrix_1.txt > output1.txt
IF ERRORLEVEL 1 GOTO err
FC output1.txt matrix_1_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с матрицей общего вида
%PROGRAM% matrix_2.txt > output2.txt
IF ERRORLEVEL 1 GOTO err
FC output2.txt matrix_2_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с единичной матрицей
%PROGRAM% matrix_3.txt > output3.txt
IF ERRORLEVEL 1 GOTO err
FC output3.txt matrix_3_output.txt
IF ERRORLEVEL 1 GOTO err

REM для вырожденной

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
