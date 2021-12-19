#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *systemTable)
{
    // Long长字节
    EFI_STATUS status = EFI_SUCCESS;
    UINTN NO_HANDLES = 0;
    EFI_HANDLE *BUFFER = NULL;
    status = gBS->LocateHandleBuffer(
        ByProtocol,                      //通过Protocol
        &gEfiGraphicsOutputProtocolGuid, // GUID
        NULL,
        &NO_HANDLES,
        &BUFFER);
    Print(L"status = %d\n", status);
    if (EFI_ERROR(status))
    {
        Print(L"Faild to LocateHandleBuffer");
        return status;
    }
    Print(L"NO_HANDLES = %d\n", NO_HANDLES);
    EFI_GRAPHICS_OUTPUT_PROTOCOL *graph = NULL;
    status = gBS->OpenProtocol(
        BUFFER[0],
        &gEfiGraphicsOutputProtocolGuid,
        (void **)&graph,
        ImageHandle,
        NULL,
        EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    Print(L"status = %d\n", status);
    Print(L"Hello world! --by blank\n");

    // 初始化打印
    UINTN sizeof_info = 0;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
    for (UINTN i = 0; i < graph->Mode->MaxMode; i++)
    {
        status = graph->QueryMode(
            graph,
            i,
            &sizeof_info,
            &info);
        if (EFI_ERROR(status))
        {
            Print(L"Error query mode");
            return status;
        }
        Print(L"Mode %d, Height = %d,Width = %d\n", i, info->HorizontalResolution, info->VerticalResolution);
    }

    // status = graph->SetMode(graph, 16);
    // if (EFI_ERROR(status))
    // {
    //     Print(L"Error set mode");
    //     return status;
    // }

    EFI_GRAPHICS_OUTPUT_BLT_PIXEL red = {0,0,255,0};

    status = graph->Blt(
        graph,
        &red,
        EfiBltVideoFill,
        0,0,
        0,0,
        100,100,
        0
    );
    if (EFI_ERROR(status))
    {
        Print(L"Error write");
        return status;
    }
     status = graph->Blt(
        graph,
        &red,
        EfiBltVideoToVideo,
        0,0,
        200,200,
        100,100,
        0
    );

    //BlueBuffer
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color = {1,1,1,0};
    EFI_PHYSICAL_ADDRESS  color_start = graph->Mode->FrameBufferBase + 
                            graph->Mode->Info->PixelsPerScanLine *100 * 4;
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL *video_handle = (EFI_GRAPHICS_OUTPUT_BLT_PIXEL *)color_start;
    UINTN no_pixels = graph->Mode->Info->PixelsPerScanLine * 100;
    for (int i = 0; i < 254; i++)
    {
        
        video_handle = (EFI_GRAPHICS_OUTPUT_BLT_PIXEL *)color_start;
       for (UINTN j = 0; j < no_pixels; j++)
       {
           *video_handle = color;
           video_handle++;
           //sleep
           for(int n=0;n<99999;n++){
             for(int m=0;m<100000;m++){

           }
        }
       }
       color.Blue++;
       color.Green++;
       color.Red++;
    }
    

    return status;
}
