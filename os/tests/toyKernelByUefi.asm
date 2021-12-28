BITS 64
mov rdi,0x80000000
mov ecx,0x0013C680
xor eax,eax
mov eax,0xff18679A

write:
    mov [rdi],eax
    add rdi,4
    loop write

jmp $