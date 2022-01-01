assume cs:codesg,ds:datasg,ss:stack

datasg segment
    dw 0,0,0,0,0,0,0,0
    dw 1,2,3,4,5,6,7,8
datasg ends

stack segment
    dw 0,0,0,0,0,0
stack ends

codesg segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
    start:  mov bx,0
            mov ax,0
            mov cx,8
            s:  add ax,cs:[bx]
            add bx,2
            loop s
            mov ax,4c00H
            int 21H
codesg ends
end start