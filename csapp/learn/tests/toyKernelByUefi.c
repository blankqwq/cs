int main(){
    char *bufferbase = (char *)(0x80000000);
    for (unsigned long long i = 0; i < 0x0011C680; i++)
    {
       *bufferbase=0xff;
       bufferbase+=1;
       *bufferbase=0x18;
       bufferbase+=1;
       *bufferbase=0x67;
       bufferbase+=1;
       *bufferbase=0x9A;
       bufferbase+=1;
    }
    while (1)
    {
        /* code */
    }
    
    return 0;
}




