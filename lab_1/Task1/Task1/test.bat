
set PROGRAM= "%~1"
ECHO %~1

REM запуск программы с одним включением строки в текстовом файле (английский язык)
%PROGRAM% poem.txt "sky" > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt poem_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним включением строки в текстовом файле (кириллица)
REM %PROGRAM% Onegin.txt "Онегин" > output.txt
REM IF ERRORLEVEL 1 GOTO err
REM FC output.txt Onegin_output.txt
REM IF ERRORLEVEL 1 GOTO err

REM запуск программы с файлом, не содержащим слово
REM %PROGRAM% not_found.txt "empty" > output.txt
REM IF ERRORLEVEL 1 GOTO err
REM FC output.txt not_found_output.txt
REM IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
