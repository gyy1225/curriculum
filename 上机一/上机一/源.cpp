
#include <windows.h>

#include <string>

#pragma warning(disable:4996)

int main()

{

	char timeContent[100] = { 0 };

	char readBuffer[1000] = { 0 };

	char command[10][100] = { 0 };       //���зֿ�������

	int commandNum = 0;		       //�������



	DWORD dwRead = 0;

	DWORD dwWrite = 0;

	HANDLE hFile = CreateFile("./CommandList.txt", GENERIC_WRITE | GENERIC_READ, 0,

		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);



	if (hFile == INVALID_HANDLE_VALUE)

	{

		printf("CreateFile failed!");

		CloseHandle(hFile);

		return -1;

	}



	//д��ʱ��

	FILETIME createTime, lastAccessTime, lastWriteTime;

	GetFileTime(hFile, &createTime, &lastAccessTime, &lastWriteTime);

	SYSTEMTIME st;

	memset(&st, 0x0, sizeof(st));

	FileTimeToSystemTime(&lastWriteTime, &st);//���ļ�ʱ���ʽת��Ϊϵͳʱ���ʽ(UTC��ʽ),���Կ���Сʱ������ʵ��С��8

	TIME_ZONE_INFORMATION tz;

	GetTimeZoneInformation(&tz);//��ȡ����ʱ����Ϣ

	SYSTEMTIME localST;

	SystemTimeToTzSpecificLocalTime(&tz, &st, &localST);//��UTCʱ���ʽת��Ϊ����ʱ���ʽ,��Ϊ�й��Ƕ�8��,����ת��ʱ��Сʱ�ϼ���8



	sprintf(timeContent, "���ļ����һ�δ򿪺�����������%4d%02d%02d\r\n", localST.wYear, localST.wMonth, localST.wDay);

	WriteFile(hFile, timeContent, strlen(timeContent), &dwWrite, NULL);



	//��ȡ�ı�

	DWORD fileSize = GetFileSize(hFile, NULL);

	ReadFile(hFile, readBuffer, fileSize, &dwRead, NULL);

	readBuffer[fileSize] = '\0';

	printf("%s", readBuffer);

	CloseHandle(hFile);



	//ѭ������ȡ������ָ�����

	char tmpBuffer[1000] = { 0 };

	for (int i = 0; i<fileSize; i++)

	{

		if ('\r' == readBuffer[i])

		{

			strncpy(command[commandNum], readBuffer, i);

			i = i + 2;

			commandNum++;

			strcpy(tmpBuffer, &readBuffer[i]);

			strcpy(readBuffer, tmpBuffer);

			i = 0;

		}
		else if ('\0' == readBuffer[i])

		{

			strncpy(command[commandNum], readBuffer, i);

			commandNum++;

			break;

		}

	}

	//ѭ����������

	for (int j = 0; j<commandNum; j++)

	{

		STARTUPINFO si = { sizeof(si) };

		PROCESS_INFORMATION pi;

		si.dwFlags = STARTF_USESHOWWINDOW; // ָ��wShowWindow��Ա��Ч

		si.wShowWindow = TRUE; // �˳�Ա��ΪTRUE�Ļ�����ʾ�½����̵�����

		BOOL bRet = CreateProcess(NULL,	// ���ڴ�ָ����ִ���ļ����ļ���

			command[j],// �����в���

			NULL,	// Ĭ�Ͻ��̰�ȫ��

			NULL,	// Ĭ�Ͻ��̰�ȫ��

			FALSE,	// ָ����ǰ�����ھ�������Ա��ӽ��̼̳�

			CREATE_NEW_CONSOLE,	// Ϊ�½��̴���һ���µĿ���̨����

			NULL,	// ʹ�ñ����̵Ļ�������

			NULL,	// ʹ�ñ����̵���������Ŀ¼

			&si, &pi);

		if (bRet)

		{ // ��ʹ�õľ����ùص�

			CloseHandle(pi.hThread);

			CloseHandle(pi.hProcess);

			printf("�½��̵�ID�ţ�%d\n", pi.dwProcessId);

			printf("�½��̵����߳�ID�ţ�%d\n", pi.dwThreadId);

		}

		Sleep(1000);

	}



	system("pause");

	return 0;

}
