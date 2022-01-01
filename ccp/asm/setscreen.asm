assume cs:code

code segment
    start:
        call offset sub1
        mov ax,4c00h
        int 21h
    sub1:
        push bx
        push ax
        push es
        mov bx,0b800h
        mov es,bx
        mov bx,0
        mov cx,2000
        sub1s:
            mov byte ptr es:[bx],' '
            add bx,2
            loop sub1s
        pop es
        pop ax
        pop bx
        ret
    sub2:
        push bx
        push ax
        push es
        mov bx,0b800h
        mov es,bx
        mov bx,0
        mov cx,2000
        sub2s:
            and byte ptr es:[bx]+1,11111000b
            or es:[bx],al
            add bx,2
            loop sub2s
        pop es
        pop ax
        pop bx
        ret
    sub3:
        push bx
        push ax
        push es
        mov cl,4
        shr al,cl
        mov bx,0b800h
        mov es,bx
        mov bx,1
        mov cx,2000
        sub3s:
            and byte ptr es:[bx],10001111b
            or es:[bx],al
            add bx,2
            loop sub3s
        pop es
        pop ax
        pop bx
        ret
code ends

end start