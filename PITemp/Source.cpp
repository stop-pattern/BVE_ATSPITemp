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
	char path[MAX_PATH + 1];	//path
	if (0 != GetModuleFileName((HMODULE)hModule, path, sizeof(path) / sizeof(path[0]))) {	//path取得
		//path分解
		char path_drive[MAX_PATH + 1],	//ドライブ名
			path_dir[MAX_PATH + 1],	//ディレクトリ名
			path_fname[MAX_PATH + 1],	//ファイル名
			path_ext[MAX_PATH + 1];	//拡張子
		_splitpath(path, path_drive, path_dir, path_fname, path_ext);	//パス名を構成要素に分解
		string drive(path_drive),	//ドライブ名
			dir(path_dir),	//ディレクトリ名
			fname(path_fname),	//ファイル名
			ext(path_ext);	//拡張子


		//pathを格納
		dllPath = drive + dir + fname + ext;
		iniPath = drive + dir + fname + ".ini";
	}
	else {
		dllPath = "";
		iniPath = "";
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