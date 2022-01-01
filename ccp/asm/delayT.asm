assume cs:codesg

codesg segment
    start:

        mov ax,0
        mov es,ax

        push es:[4*9]
        pop ds:[0]
        push es:[4*9+2]
        pop ds:[2]

        mov word ptr es:[4*9],offset int9
        mov es:[4*9+2],cs

        mov ax,0b800h
        mov es,ax
        mov ah,'a'
        ; 存储int 9 中断

        s:
            mov es:[160],ah
            call delay
            inc ah
            cmp ah,'z'
            jna s

        ; 恢复中断
        push ds:[0]
        pop es:[4*9]
        push ds:[2]
        pop es:[4*9+2]
        ; end
        mov ax,4c00h
        int 21h
    int9:
        ; listen esc
        push ax
        push bx
        push es

        in al,60h
        pushf
        pushf
        pop bx
        and bh,11111100b
        push bx
        popf

        call dword ptr ds:[0]
        cmp al,1
        jne int9ret
        mov ax,0b800h
        mov es,ax
        inc byte ptr es:[161]
        int9ret:
            pop es
            pop bx
            pop ax
            iret
    delay:
        push dx
        push ax

        mov dx,1000h
        mov ax,0
        s1:
            sub ax,1
            sbb dx,0
            cmp ax,0
            jne s1
            cmp bx,0
            jne s1
        pop ax
        pop dx
        ret
codesg ends

end start