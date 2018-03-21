set PROGRAM= "%~1"

REM запуск программы с одним включением строки в текстовом файле
%PROGRAM% < Onegin.txt "Я к Вам пишу" > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt Onegin_output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
