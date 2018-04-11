
set PROGRAM= "%~1"
ECHO %~1

REM запуск программы с включением строки в текстовом файле (английский язык)
%PROGRAM% poem.txt "sky" > output1.txt
IF ERRORLEVEL 1 GOTO err
FC output1.txt poem_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с пустым файлом
%PROGRAM% empty.txt "sky" > output3.txt
IF ERRORLEVEL 1 GOTO err
FC output3.txt empty_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с текстовым файлом, не включающим искомое слово
%PROGRAM% not_found.txt "there is no this text in file" > output4.txt
IF ERRORLEVEL 1 GOTO err
FC output4.txt not_found_output.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с включением строки в текстовом файле (кириллица)
%PROGRAM% Onegin.txt "взгляд" > output2.txt
IF ERRORLEVEL 1 GOTO err
FC output2.txt Onegin_output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded
EXIT 0

:err
ECHO Program testing failed
EXIT 1
