assume cs:codesg,ss:stack

stack segment
    db 5 dup(0)
stack ends

datasg segment
db 'hello',0
db 'hahh',0
db 'test',0
datasg ends


codesg segment
    start:mov ax,datasg
    mov ds,ax
    mov si,0
    mov cx,3
    mov ax,stack
    mov ss,ax
    ; 段间调用
    ddd:push cx
    ; 相对地址已经不行了
    call ToHigh
    pop cx
    add si,1
    loop ddd
    mov ax,4c00h
    int 21h
    ToHigh:mov cl,byte ptr [si]
    mov ch,0
    jcxz return
    and byte ptr [si],11011111b
    add si,1
    jmp ToHigh
    return:ret
codesg ends

end start