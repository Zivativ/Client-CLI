@echo off


xmake build
copy raylib.dll build\windows\x64\release\raylib.dll 
copy netlib.dll build\windows\x64\release\netlib.dll 

robocopy resources build\windows\x64\release\resources /s
xmake run