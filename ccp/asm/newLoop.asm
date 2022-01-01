assume cs:codesg

codesg segment
    start:
        mov ax,0
        mov es,ax
        mov ax,cs
        mov ds,ax
        mov si,offset do7
        mov di,200h

        ; 拷贝执行地址
        mov cx,do7end - do7
        cld
        rep movsb
        ; 中断执行地址
        mov word ptr es:[7ch*4],200h
        mov word ptr es:[7ch*4+2],0
        

        mov ax,0b800h
        mov es,ax
        mov di,160

        ; 设置循环跳转
        mov cx,80
        ; 地址放入奇怪的地方了
        mov bx,offset ls - offset se
        ; 中断
        ls:
            mov byte ptr es:[di],'!'
            add di,2
        int 7ch
        se:nop
        mov ax,4c00h
        int 21h
    do7:
        ; 根据cs IP 计算到ls的地址重复执行
        push bp
        mov bp,sp
        dec cx
        jcxz re
        ; 修改栈中偏移地址
        add [bp+2],bx
        ; 修改cs,ip
        re:
            pop bp
            ; 恢复 cs:ip
            iret
    do7end:nop
codesg ends

end start