#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol.h>
EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *systemTable)
{
    EFI_PHYSICAL_ADDRESS bmpbuffer = openFile(L"\\logo2.bmp", ImageHandle);
    if (bmpbuffer)
    {
        Print(L"load success!\n");
    }

    // =================print
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
    // write to video
    status = graph->Blt(
        graph,
        (EFI_GRAPHICS_OUTPUT_BLT_PIXEL *)bmpbuffer+52,
        EfiBltBufferToVideo,
        0, 0,
        200, 200,
        540, 258,
        0);
    return EFI_SUCCESS;
}
