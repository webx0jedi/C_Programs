#include <stdio.h>
#include <windows.h>

int main(void) {
	
	//pointers to process information
	STARTUPINFOA si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	//loop that retrives last error if the process could not be created
	if (!CreateProcessW(L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		printf("Error. Failed to create process: %ld", GetLastError());
		return EXIT_FAILURE;
	}
	//variables that store the thread and Process IDs with pi pointer
	DWORD TID = pi.dwThreadId;
	DWORD PID = pi.dwProcessId;
	HANDLE hThread = pi.hThread;
	HANDLE hProcess = pi.hProcess;

	printf("Process started! \n");
	printf("PID of created process: %ld\n", PID);
	printf("TID of created thread: %ld\n", TID);
	printf("Handle of Process: 0x%x\n", hProcess); //prints the handles of process and thread in hex form
	printf("Handle of Thread: 0x%x\n", hThread);

	WaitForSingleObject(hProcess, INFINITE); //waits for process to be closed before exiting
	printf("Finished process! Exiting...\n");

	CloseHandle(hThread);
	CloseHandle(hProcess);

	return EXIT_SUCCESS;
}
