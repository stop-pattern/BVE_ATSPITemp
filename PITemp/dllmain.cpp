/*BVE ATSプラグインテンプレート
 *Author : Tetsu Otter
 *SDK : ver10.0.17763.0
 *DLLは、プロジェクト名で出力されます。任意のプロジェクト名を付与してください。
 *プロジェクト名変更時は、dllmain.defの "LIBRARY" に設定された "PITemp" という文字列を新たなプロジェクト名に変更してください。
*/


#include "Header.h"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
		getPath(hModule);
        break;
    }
    return TRUE;
}

DE void SC Load() {
}
DE void SC Dispose() {
}
DE int SC GetPluginVersion() {
	return PI_VERSION;
}
DE void SC SetVehicleSpec(Spec s) {
	specific.setData(s);
}
DE void SC Initialize(int b) {
	b = InitialPosition::Service;
}
DE Hand SC Elapse(State S, int * p, int * s) {
	Stat.setData(Stat, S);
	handle.C = ConstSPInfo::Continue;
	//s[255] = SoundInfo::Continue;
	return handle;
}
DE void SC SetPower(int p) {
	handle.P = p;
}
DE void SC SetBrake(int b) {
	handle.B = b;
}
DE void SC SetReverser(int r) {
	handle.R = r;
}
DE void SC DoorOpen() {
}
DE void SC DoorClose() {
}


DE void SC KeyDown(int k) {
}
DE void SC KeyUp(int k) {
}
DE void SC HornBlow(int k) {

}
DE void SC SetSignal(int a) {
}
DE void SC SetBeaconData(Beacon b) {
}

