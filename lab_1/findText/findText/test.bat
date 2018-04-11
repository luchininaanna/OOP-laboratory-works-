
set PROGRAM= "%~1"
ECHO %~1

REM запуск программы с включением строки в текстовом файле (английский язык)
REM %PROGRAM% poem.txt "sky" > output.txt
REM IF ERRORLEVEL 1 GOTO err
REM FC output.txt poem_output.txt
REM IF ERRORLEVEL 1 GOTO err

REM запуск программы с включением строки в текстовом файле (кириллица)
%PROGRAM% Onegin.txt "сомненья" > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt Onegin_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с пустым файлом
REM %PROGRAM% empty.txt "sky" > output.txt
REM IF ERRORLEVEL 1 GOTO err
REM FC output.txt empty_output.txt
REM IF ERRORLEVEL 1 GOTO err

REM запуск программы с текстовым файлом, не включающим искомое слово
REM %PROGRAM% not_found.txt "there is no this text in file" > output.txt
REM IF ERRORLEVEL 1 GOTO err
REM FC output.txt not_found_output.txt
REM IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
