#include <stdio.h>
#include <windows.h>

int main(void) {
	
	STARTUPINFOA si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	if (!CreateProcessW(L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		printf("Error. Failed to create process: %ld", GetLastError());
		return EXIT_FAILURE;
	}

	DWORD TID = pi.dwThreadId;
	DWORD PID = pi.dwProcessId;
	HANDLE hThread = pi.hThread;
	HANDLE hProcess = pi.hProcess;

	printf("Process started! \n");
	printf("PID of created process: %ld\n", PID);
	printf("TID of created thread: %ld\n", TID);
	printf("Handle of Process: 0x%x\n", hProcess);
	printf("Handle of Thread: 0x%x\n", hThread);

	WaitForSingleObject(hProcess, INFINITE);
	printf("Finished process! Exiting...\n");

	CloseHandle(hThread);
	CloseHandle(hProcess);

	return EXIT_SUCCESS;
}
