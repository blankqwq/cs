#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/SimpleFileSystem.h>
#include <Guid/FileInfo.h>

#define NAX_BUFFER 1024*1024*20
EFI_PHYSICAL_ADDRESS openFile(CHAR16 *filename, EFI_HANDLE ImageHandle)
{
    EFI_STATUS status = EFI_SUCCESS;
    UINTN no_handle = 0;
    // 相当于全局复用 但是直接指针的指针家不行，估计是哪部判断NULL进行输出
    EFI_HANDLE *buffer = NULL;
    status = gBS->LocateHandleBuffer(
        ByProtocol,                        //通过Protocol
        &gEfiSimpleFileSystemProtocolGuid, // GUID
        NULL,
        &no_handle,
        &buffer);
    
    if (EFI_ERROR(status))
    {
        Print(L"Faild to LocateHandleBuffer.err = %d\n",status);
    }
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *file;

    status = gBS->OpenProtocol(
        buffer[0],
        &gEfiSimpleFileSystemProtocolGuid,
        (void **)&file,
        ImageHandle,
        NULL,
        EFI_OPEN_PROTOCOL_GET_PROTOCOL);

    if (EFI_ERROR(status))
    {
        Print(L"buffer count buffer=%d",sizeof(buffer));
        Print(L"Faild to open&getHandle err code=%d\n",status);
    }
    //操作handle 
    EFI_FILE_PROTOCOL *root,*target;
    file->OpenVolume(file,&root);
    // openFile 
    status = root->Open(root,&target,filename,EFI_FILE_MODE_READ,EFI_FILE_READ_ONLY);
    //getInfo
    if (EFI_ERROR(status))
    {
        /* code */
        Print(L"open error !!! err = %d\n",status);
    }
    UINTN buffer_size=NAX_BUFFER;
    // 获取数据
    EFI_FILE_INFO file_info;
    EFI_GUID infomationGuid = EFI_FILE_INFO_ID;
    // 需要指定最大操作
    status = target->GetInfo(target,&infomationGuid,&buffer_size,&file_info);
    if (EFI_ERROR(status))
    {
        /* code */
        Print(L"geinfo error !!! err = %d\n",status);
    }
    
    Print(L"Info:%d,Fsize:%d,Input:",
            file_info.CreateTime.Hour,file_info.FileSize);
    Print(file_info.FileName);
    Print(L"\n");
    // 指针不行，他不是返回而是操作这个结构体
    EFI_PHYSICAL_ADDRESS read_buffer=0;
    UINTN page_size = file_info.FileSize/(4*1024)+1;
    Print(L"page size = %d\n",page_size);
    status = gBS->AllocatePages(AllocateAnyPages,EfiBootServicesData,page_size,&read_buffer);
    
    if(EFI_ERROR(status)){
        Print(L"allocate error !!! err = %d\n",status);
    }
    UINTN read_size = file_info.FileSize;
    Print(L"get cal size = %d\n",read_size);


    status = target->Read(target,&read_size,(void *)read_buffer);
    Print(L"get read size = %d %p\n",read_size,read_buffer);
    if(EFI_ERROR(status)){
        Print(L"allocate error !!! err = %d\n",status);
    }
    return read_buffer;
}