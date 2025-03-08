@ECHO OFF
SetLocal EnableDelayedExpansion

IF NOT EXIST bin MKDIR bin
IF NOT EXIST obj MKDIR obj

SET assembly=picon

SET compilerFlags=/W1 /Zi
SET defines=/DSDL_MAIN_HANDLED /D_DEBUG /D_CRT_SECURE_NO_WARNINGS
SET includeFlags=/IC:\libs\SDL2-2.32.2\include /IC:\libs\SDL2_image-2.8.8\include /IC:\libs\SDL2_ttf-2.24.0\include /IC:\libs\SDL2_mixer-2.8.1\include
SET linkerFlags=/link /LIBPATH:C:\libs\SDL2-2.32.2\lib\x64 /LIBPATH:C:\libs\SDL2_image-2.8.8\lib\x64 /LIBPATH:C:\libs\SDL2_ttf-2.24.0\lib\x64 /LIBPATH:C:\libs\SDL2_mixer-2.8.1\lib\x64 SDL2.lib SDL2main.lib SDL2_image.lib SDL2_ttf.lib SDL2_mixer.lib 

ECHO Building %assembly%...

cl %compilerFlags% %defines% %includeFlags% src\all.c /Fo"obj\\" /Fe"bin\%assembly%.exe" %linkerFlags%

IF %ERRORLEVEL% EQU 0 (
    ECHO %assembly% build success
    REM gfx folder to bin directory
    xcopy /E /I /Y gfx bin\gfx
) ELSE (
    ECHO ERROR: Build fail, error code %ERRORLEVEL%
)
EndLocal
