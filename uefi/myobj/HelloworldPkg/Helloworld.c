#include <Uefi.h>
#include <Library/UefiLib.h>

EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *systemTable
){
    // Long长字节
    Print(L"Hello world! --by blank\n");
    return 0;
}