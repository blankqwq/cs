#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/SimpleFileSystem.h>
#include <Guid/FileInfo.h>

EFI_PHYSICAL_ADDRESS openFile(CHAR16 *filename, EFI_HANDLE ImageHandle);