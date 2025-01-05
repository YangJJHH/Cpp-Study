#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <io.h>
#include <Windows.h>
#include <tchar.h>

using namespace std;

typedef vector<string> stringvec;
const string workDirPath = "C:\\Users\\didwo\\OneDrive\\바탕 화면\\work\\";
const string resouceDirPath = "C:\\Users\\didwo\\OneDrive\\바탕 화면\\Resouce\\";


const string pps = "*.pps";
const char ppi[] = ".ppi";
const string ppsToken = "key_info";			// ppi 파일 이름 구분용
const string ppiToken1 = "dress_image";		// 리소스 이름 구분용
const string ppiToken2 = "dress";	// 리소스 이름 구분용
stringvec notFoundPPI;
stringvec notFoundResouce;
//  string -> wstring 변환
//	파일 복사/ 붙여넣기 할때 인수로 LPCWSTR 형으로 전달해야함, LPCWSTR로 바꾸기전 중간과정
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
bool OpenDir(intptr_t& handle, struct _finddata_t& fd, const string& dir, const string& token)
{
	string fullpath = (dir + token);
	//폴더내 token확장자 파일 찾기
	if ((handle = _findfirst(fullpath.c_str(), &fd)) == -1L)
	{
		return false;
	}
	return true;
}
void Copy(string target, string dest)
{
	wstring tmp1 = s2ws(target);
	wstring tmp2 = s2ws(dest);
	LPCWSTR t = tmp1.c_str();
	LPCWSTR d = tmp2.c_str();
	CopyFile(t, d, false);
}
string Split(string::size_type startIdx,const string& data)
{
	string::size_type i = startIdx;
	while (i != data.size() && !isspace(data[i]))
	{
		++i;
	}
	return data.substr(startIdx+1, i - startIdx-2); // " " 는 제거
}
void OpenPPI(const string& filename)
{
	ifstream file;
	string data;
	
	string fullFileName = resouceDirPath + filename;

	
	
	//ppi파일 읽기
	file.open(fullFileName);
	if (file)
	{
		while (getline(file, data))
		{
			// dress로 시작하는 행 찾기
			string tmp = data.substr(0, ppiToken2.length());
			int startIdx = 0;
			if (tmp == ppiToken2 || tmp == ppiToken1)
			{
				startIdx = (data.substr(0, ppiToken1.length()) == ppiToken1) ? ppiToken1.length() + 2 : ppiToken2.length() + 2;	// 공백과 " 다음 리소스파일 이름 시작점부터
				string resouceFileName = data.substr(startIdx, data.length() - startIdx - 1);				// 문자열 마지막에서 "전까지
				
				//해당 이름 리소스 찾기
				struct _finddata_t fd;
				intptr_t handle;
				int result = 1;
				string fullpath = (resouceDirPath + resouceFileName);
				//폴더내 해당 리소스 파일 찾기
				if (!OpenDir(handle, fd, resouceDirPath, resouceFileName))
				{
					string tmp = resouceFileName + "("+ filename +")";
					notFoundResouce.push_back(tmp);
					continue;
				}
				Copy(fullpath, (workDirPath + resouceFileName));
				

			}
		}
		// 찾은 ppi 파일 타겟폴더에 복사, 붙여넣기
		Copy(fullFileName, (workDirPath + filename));
	}
	else 
	{
		cout << "파일을 열 수 없습니다" << endl;
		notFoundPPI.push_back(filename);
	}
}
void OpenPPS(const char* filedir)
{
	ifstream file;
	string data;
	//pps파일 읽기
	file.open(filedir);
	if (file)
	{
		while (getline(file, data))
		{
			// ppi 파일 이름이 있는 행 찾기
			if (data.substr(0, ppsToken.length()) == ppsToken)
			{
				// ppi 파일 이름 추출
				string::size_type startIdx = ppsToken.length() + 1; // 다음 공백까지 포함(+1)
				string ppiFileName = Split(startIdx,data);

				// ppi 파일 읽기
				OpenPPI(ppiFileName);
			}
		}
	}
	else
	{
		cout << "파일을 열 수 없습니다" << endl;
	}
	
	cout << endl;
	file.close();
}
void FindDir()
{
	
	struct _finddata_t fd;
	intptr_t handle;
	int result = 1;
	//폴더내 pps파일 읽기
	if (!OpenDir(handle, fd, workDirPath, pps))
	{
		return;
	}


	ifstream file;
	while (result != -1)
	{
		cout << fd.name<<endl;
		char filedir[256];
		strcpy_s(filedir, workDirPath.c_str());
		strcat_s(filedir, fd.name);
		
		OpenPPS(filedir);

		result = _findnext(handle, &fd);
	}
	_findclose(handle);
		
}
void PrintResult()
{
	cout << "=======================================" << endl << "못찾은 ppi 파일목록" << endl;
	for (auto& val : notFoundPPI)
	{
		cout << val << endl;
	}
	cout << endl << "못찾은 리소스 파일목록" << endl;
	for (auto& val : notFoundResouce)
	{
		cout << val << endl;
	}
}
int main()
{
	
	FindDir();
	PrintResult();
	return 0;
}