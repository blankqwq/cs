typedef struct BOOT_CONFIG
{
    unsigned long VideoBufferBase;
    unsigned long VideoBufferSzie;
    int data;
}BOOT_CONFIG;


void DxeVideo(unsigned long color,unsigned long buffer,unsigned long size){
    unsigned int *bufferBase;
    bufferBase = (unsigned int *)buffer;
    for(unsigned long i = 0;i<size;i++){
        *bufferBase = color;
        bufferBase++;
    }
}

// 打印
int _start(BOOT_CONFIG *t){
    DxeVideo(0xff18679A,t->VideoBufferBase,t->VideoBufferSzie);
    return 1;
}




