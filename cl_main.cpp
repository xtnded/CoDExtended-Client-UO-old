#include "shared.h"
#include "client.h"
#include "version_info.h"

cvar_t* cl_running;

/*
void CL_FOVLimit() {
	int fov = Cvar_VariableIntegerValue("cg_fov");
	int cheats = atoi(Info_ValueForKey(cs1, "sv_cheats"));

	char* sv_fov_min = Info_ValueForKey(cs1, "sv_fov_min");
	char* sv_fov_max = Info_ValueForKey(cs1, "sv_fov_max");
	int fovMin = strlen(sv_fov_min) ? atoi(sv_fov_min) : 80;
	int fovMax = strlen(sv_fov_max) ? atoi(sv_fov_max) : 95;

	if ((fov < fovMin || fov > fovMax) && cheats != 1) {
		Com_Printf("cg_fov \"%d\" is invalid. Allowed values: \"%d\" - \"%d\".\n", fov, fovMin, fovMax);
		Cvar_Set("cg_fov", "80");
	}
}
*/

/*
void Disconnect_IfEsc() {
	if (*cls_state == CA_CONNECTING || *cls_state == CA_CHALLENGING || *cls_state == CA_CONNECTED) {
		if (GetFocus() && GetKeyState(VK_ESCAPE) & 0x8000)
		{
			((void(*)())0x40F5F0)(); //CL_Disconnnect 
		}
	}
}
*/

void CL_Frame(int msec) {
	void(*call)(int);
	*(DWORD*)&call = 0x413870;

	if (!cl_running->integer) return;
	
	void CL_DiscordFrame();
	CL_DiscordFrame();

	// CL_FOVLimit();
	// Disconnect_IfEsc();

	call(msec);
}

void CL_Init(void) {
	void(*oCL_Init)();
	*(int*)(&oCL_Init) = 0x414500;
	oCL_Init();

	cl_running = Cvar_Get("cl_running", "0", 64);

	Cvar_Set("version", va("CODUO MP 1.51x build %d %s %s win-x86", BUILDNUMBER, __DATE__, __TIME__));
	Cvar_Set("shortversion", "1.51x");
}