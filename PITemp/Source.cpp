#include "Header.h"

string dllPath;	//.dllのpath
string iniPath;	//.iniのpath

int signal;	//信号インデックス

bool door;	//ドア状態
int LimitSpeed;	//制限速度

SpecPlus specific;	//車両性能
StatePlus Stat;	//車両状態(前フレーム)
Hand manual;	//手動ハンドル位置
Hand handle;	//ハンドル制御値


void getPath(HMODULE hModule) {	//path取得
	using std::string;

	//dll本体のpathを取得
	char path[MAX_PATH + 1];
	GetModuleFileName((HMODULE)hModule, path, sizeof(path));
	char* pt = path;
	string dllPath(pt);
	string iniPath = dllPath;

	//拡張子置換
	const string beforeExt = ".dll";
	const string afterExt = ".ini";
	string::size_type pos(iniPath.find_last_of(beforeExt));
	if (pos != string::npos) {
		iniPath.replace(pos, beforeExt.size(), afterExt);
	}
}


void SpecPlus::setData(Spec s) {	//設定値代入
	this->A = s.A;
	this->B = s.B;
	this->C = s.C;
	this->E = s.B + 1;
	this->J = s.J;
	this->P = s.P;
}

void StatePlus::setData(StatePlus b, State a) {	//設定値代入
	this->BC = a.BC;
	this->BP = a.BP;
	this->ER = a.ER;
	this->I = a.I;
	this->MR = a.MR;
	this->SAP = a.SAP;
	this->T = a.T;
	this->V = a.V;
	this->Z = a.Z;
	this->dV = (double)a.V - (double)b.V;
	this->dT = (double)a.T - (double)b.T;
	this->Zd = b.Z + (this->dV * this->dT);
	this->A = this->dV / this->dT;
}