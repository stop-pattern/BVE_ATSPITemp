#pragma once
#ifndef HEADER
#define HEADER

#include <Windows.h>
#include <string>
#include "ats.h"

using std::string;


extern string dllPath;	//.dllのpath
extern string iniPath;	//.iniのpath

extern int signal;	//信号インデックス

extern bool door;	//ドア状態
extern int LimitSpeed;	//制限速度

extern SpecPlus specific;	//車両性能
extern StatePlus Stat;	//車両状態(前フレーム)
extern Hand manual;	//手動ハンドル位置
extern Hand handle;	//ハンドル制御値

void getPath(HMODULE);	//path取得

#endif // !HEADER
