/*
SPECIAL THANKS TO:
  - https://blog.csdn.net/u010499449/article/details/56671118
  - https://www.runoob.com/cprogramming/c-standard-library-time-h.html
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE hServiceStatusHandle;

using namespace std;

const int
r1150 = 11 * 60 + 50, //11:50
r1215 = 12 * 60 + 15, //12:15
r1810 = 18 * 60 + 10, //18:10
r2110 = 21 * 60 + 10; //21:10

char SERVICE_NAME[] = "fuck off the kid who plays the computer outside the specified time secretly";
bool r = false;

void WINAPI ServiceHandler(DWORD fdwControl)
{
    switch (fdwControl)
    {
    case SERVICE_CONTROL_STOP:
    case SERVICE_CONTROL_SHUTDOWN:
        r = false;
        ServiceStatus.dwWin32ExitCode = 0;
        ServiceStatus.dwCurrentState = SERVICE_STOPPED;
        ServiceStatus.dwCheckPoint = 0;
        ServiceStatus.dwWaitHint = 0;
        break;
    default:
        return;
    };
    if (!SetServiceStatus(hServiceStatusHandle, &ServiceStatus))
    {
        DWORD nError = GetLastError();
    }
}

void WINAPI service_main(int argc, char** argv)
{
    ServiceStatus.dwServiceType = SERVICE_WIN32;
    ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE;
    ServiceStatus.dwWin32ExitCode = 0;
    ServiceStatus.dwServiceSpecificExitCode = 0;
    ServiceStatus.dwCheckPoint = 0;
    ServiceStatus.dwWaitHint = 0;
    hServiceStatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceHandler);
    if (hServiceStatusHandle == 0)
    {
        DWORD nError = GetLastError();
    }
    ServiceStatus.dwCurrentState = SERVICE_RUNNING;
    ServiceStatus.dwCheckPoint = 0;
    ServiceStatus.dwWaitHint = 9000;
    if (!SetServiceStatus(hServiceStatusHandle, &ServiceStatus))
    {
        DWORD nError = GetLastError();
    }

    for (r=true;r;Sleep(10000)) // every 10s
    {
        struct tm t;
        time_t tt;
        time(&tt);
        localtime_s(&t, &tt);
        int mins = t.tm_hour * 60 + t.tm_min;
        cout << t.tm_hour << "h " << t.tm_min << "m: ";
        if ((mins >= r1150 && mins < r1215) || (mins >= r1810 && mins < r2110)) // mins in ([11:50, 12:15] || [18:10, 21:10])
        {
            cout << "shutdown" << endl;
            system("C:\\Windows\\System32\\shutdown.exe /s /f /t 0");
        }
        else
        {
            cout << "no operation" << endl;
        }
    }

}

int main()
{
    SERVICE_TABLE_ENTRY ServiceTable[2];
    ServiceTable[0].lpServiceName = SERVICE_NAME;
    ServiceTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)service_main;
    ServiceTable[1].lpServiceName = NULL;
    ServiceTable[1].lpServiceProc = NULL;
    StartServiceCtrlDispatcher(ServiceTable);
    return 0;
}
