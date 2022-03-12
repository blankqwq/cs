void _str_write(char *str){
    char *vga_ptr=(char*)(0xb8000);
    while (*str)
    {
        *vga_ptr=*str++;
        vga_ptr+=2;
    }
    return;
}

void printf(char *str, ...){
    _str_write(str);
    return;
}