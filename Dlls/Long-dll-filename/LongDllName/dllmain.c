// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>

VOID MsgBoxPayload() {
    MessageBoxA(NULL, "Injected successfully", "Wow !", MB_OK | MB_ICONINFORMATION);
}






BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
	case DLL_PROCESS_ATTACH:
		OutputDebugStringA("DLL: In DllMain\n");
		// Create a thread
		{
			HANDLE hThread = CreateThread(NULL, 0, MsgBoxPayload, NULL, 0, NULL);
			if (hThread) {
				CloseHandle(hThread);
			}
			else {
				OutputDebugStringA("DLL: CreateThread failed\n");
			}
		}
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

