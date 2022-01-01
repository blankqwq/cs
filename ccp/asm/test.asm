assume cs:abc


abc segment
    start:  mov ax,2
            mov cx,11
            s:add ax,ax
            ; add ax,ax
            loop s
            mov ax,4c00H
            int 21H
abc ends

end start
; 结束入口地址