; 如果(ah)=(bh)则(ah)=( ah)+( ah)，否则( ah)=(ah)+(bh)

assume cs:codesg,ss:stacksg

stacksg segment
    db 0
stacksg ends

codesg segment
start: mov ah,11h
        mov bh,12h
        cmp ah,bh
        je el
        add ah,bh
        jmp $
el: add ah,ah
codesg ends
end start