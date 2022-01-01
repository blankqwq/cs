assume cs:codesg

stack segment
db 6 dup(0)
stack ends

codesg segment
mov ax,0
int 21h
start: mov ax,stack  
mov ss,ax
call s
s:  
mov ax,0
push ax
ret
codesg ends

end start