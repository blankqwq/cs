; 在显存中写入字符串
assume cs:code,ds:data

data segment
    db 'hello world!',0
data ends


code segment
    start:
        mov dl,8
        mov dh,3
        mov cl,2
        mov ax,data
        mov ds,ax
        mov si,0
        call printf
        mov ax,4c00h
        int 21h
    printf:
        ;填充行
        push cx
        push si
        ;填充列
        mov al,0B0h

        dec dh
        mul dh
        mov bx,ax

        mov al,2
        mul dl
        sub ax,2
        add bx,ax

        ; 初始化现存地址
        mov ax,0b800h
        mov es,ax
        mov al,cl
        mov di,0
        write:
            ; 将字符串和颜色写入
            mov cl,[si]
            mov ch,0
            jcxz return
            ; 写入字符串 需要计算页号
            mov byte ptr es:[bx+di],cl
            ; 写入颜色
            mov byte ptr es:[bx+di+1],al
            ; 每一位都有不同的含义,属于双字型数据
            add di,2
            inc si
            ; 继续写入
            jmp write
        return:
            pop si
            pop cx
        ret
code ends
end start