#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>



EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *systemTable
){
    // Long长字节
    EFI_STATUS status=EFI_SUCCESS;
    UINTN NO_HANDLES = 0;
    EFI_HANDLE *BUFFER =NULL;
    status = gBS->LocateHandleBuffer(
        ByProtocol, //通过Protocol
        &gEfiGraphicsOutputProtocolGuid,// GUID
        NULL,
        &NO_HANDLES,
        &BUFFER
    );
    Print(L"status = %d\n",status);
    if(EFI_ERROR(status)){
        Print(L"Faild to LocateHandleBuffer");
        return status;
    }
    Print(L"NO_HANDLES = %d\n",NO_HANDLES);
    EFI_GRAPHICS_OUTPUT_PROTOCOL *graph = NULL;
    status = gBS->OpenProtocol(
        BUFFER[0],
        &gEfiGraphicsOutputProtocolGuid,
        (void **)&graph,
        ImageHandle,
        NULL,
        EFI_OPEN_PROTOCOL_GET_PROTOCOL
    );
     Print(L"status = %d\n",status);
    Print(L"Hello world! --by blank\n");

    // 初始化打印
    UINTN sizeof_info = 0;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
    // EFI_GRAPHICS_OUTPUT_MODE_INFORMATION max;
    for(UINTN i=0;i<graph->Mode->MaxMode;i++){
        status = graph->QueryMode(
            graph,
            i,
            &sizeof_info,
            &info
        );
        if (EFI_ERROR(status)){
            Print(L"Error query mode");
            return status;
        }
        Print(L"Mode %d, Height = %d,Width = %d\n",i,info->HorizontalResolution,info->VerticalResolution);
        
    }


    return status;
}


