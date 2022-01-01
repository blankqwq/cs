assume cs:code

code segment
    start:
        mov al,11100111b
        add al,11100111b

        mov ax,4c00h
        int 21h
code ends

end start