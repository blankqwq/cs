assume cs:codesg,ss:codesg

datasg segment
    db 'hello world!',0
datasg ends

codesg segment
    ; 将数据复制到指定位置
    start:
        mov ax,cs
        mov ds,ax
        mov si,offset do0
        mov ax,0
        mov es,ax
        mov cx,do0l-do0
        mov di,200h
        cld
        rep movsb
        ; trans
        mov word ptr es:[0*4],200h
        mov word ptr es:[0*4+2],0
        mov ax,4c00h
        int 21h
    do0:
        jmp short do0start
        db 'hello world',0
    do0start:
        mov ax,cs
        mov ds,ax
        ; 绝对地址定位数据字符串
        mov si,202h

        mov ax,0b800h
        mov es,ax

        mov di,160
        mov cx,11
        s: 
            mov al,[si]
            mov es:[di],al
            inc si
            add di,1
            mov al,02h
            mov es:[di],al
            add di,1
        loop s
        mov ax,4c00h
        int 21h
    do0l:nop
codesg ends
end start