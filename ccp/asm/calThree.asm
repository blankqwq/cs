assume cs:codesg,ds:datasg

datasg segment
    db 1,2,3,4,5,6,7,8,9
datasg ends


codesg segment
    start:mov ax,datasg
    mov ds,ax
    mov si,0
    s:mov bx,[si]
    call word ptr cube
    mov [si],bx
    add si,2
    loop s
    mov ax,4c00h
    int 21h
codesg ends

cube segment
    mov ax,bx
    mul bx
    mul bx
    ret
cube ends

end start