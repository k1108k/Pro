cecho.cmd

@echo off
setlocal
if not defined color set color=c
md ___
pushd ___
<nul >"%*" cmd /k prompt $h
findstr /a:%color% "." "%*" nul
popd
rd /s /q ___