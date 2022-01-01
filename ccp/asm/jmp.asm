assume cs:start,ds:data
data segment
    db 'hello world!','$'
data ends

start segment
    s:mov dl,8
    mov dh,3
    mov cl,2
    mov ax,data
    mov ds,ax
    mov si,0

    call printf
    ; 128的时候不通过，因为超过short(128)长度
    mov ax,4c00h
    int 21h

    ; 过于简单的输出->
    printf:mov dx,0
    mov ah,9
    int 21h
    ret
start ends 

end s