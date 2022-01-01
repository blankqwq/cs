assume cs:codesg

datasg segment
    db "AbCdEf"
    dd 100001
    dw 100
    dw 0
datasg ends

codesg segment
start:
    ; mov ax,datasg
    ; mov ds,ax
    ; mov bx,0
    ; mov cx,6
    ; s1: 
    ;     mov al,[bx]
    ;     and al,11011111b
    ;     mov [bx],al
    ;     inc bx
    ; loop s1
    mov ax,datasg
    mov ds,ax
    mov dx,word ptr ds:[0+6]
    mov ax,[2+6]
    div word ptr ds:[4+6]
    mov ds:[6+6],ax
    int 21H
codesg ends
end start