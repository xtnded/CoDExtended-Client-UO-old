#include "shared.h"
#include "client.h"
#include <mmsystem.h>

DWORD cgame_mp;

/*
void CG_DrawFPS(float y) {
	cvar_t* xui_fps = Cvar_Get("cg_xui_fps", "1", CVAR_ARCHIVE);

	if (xui_fps->integer) {
		cvar_t* x = Cvar_Get("cg_xui_fps_x", "597", CVAR_ARCHIVE); // uh this x y values just look good with my hp bar
		cvar_t* y = Cvar_Get("cg_xui_fps_y", "8", CVAR_ARCHIVE);

		#define	FPS_FRAMES 4
		static int previousTimes[FPS_FRAMES];
		static int index;
		int	i, total;
		int	fps;
		static int previous;
		int	t, frameTime;

		t = timeGetTime();
		frameTime = t - previous;
		previous = t;
		previousTimes[index % FPS_FRAMES] = frameTime;
		index++;

		if (index > FPS_FRAMES) {
			total = 0;
			for (i = 0; i < FPS_FRAMES; i++) {
				total += previousTimes[i];
			}
			if (!total) {
				total = 1;
			}
			fps = 1000 * FPS_FRAMES / total;

			M_DrawShadowString(x->integer, y->integer, 1, .20, vColorWhite, va("FPS: %d", fps), NULL, NULL, NULL);
		}
	} else {
		void(*call)(float);
		*(int*)&call = CGAME_OFF(0x30014A00);
		call(y);
	}
}
*/

/*
void CG_Obituary(int* ent) {
	if (!Cvar_VariableIntegerValue("cg_x_obituary")) return;

	void(*call)(int*);
	*(int*)(&call) = CGAME_OFF(0x3001D6C0);
	call(ent);
}
*/

int JumpHeightCrap(float height) {
	char* x_jump_height = Info_ValueForKey(cs1, "x_jump_height");
	if (strlen(x_jump_height)) {
		height = atof(x_jump_height);
	}

	int(*call)(float);
	*(int*)(&call) = CGAME_OFF(0x30008C70);
	int result = call(height);
	return result;
}

double JumpSlowdownCrap() {
	return 1.0;
}

void CG_Init(DWORD base) {
	cgame_mp = base;
	
	/*
	__call(CGAME_OFF(0x3001509E), (int)CG_DrawFPS);
	__call(CGAME_OFF(0x3001E6A1), (int)CG_Obituary);
	*/

	__call(CGAME_OFF(0x30008D72), (int)JumpHeightCrap);
	__jmp(CGAME_OFF(0x30008410), (int)JumpSlowdownCrap);
}