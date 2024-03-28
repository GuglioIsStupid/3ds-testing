#include <3ds.h>
#include <stdio.h>
#include "citro2d.h"
#include <citro3d.h>

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

	// init C2D
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();

    // Render targets (top and bottom) 
    C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

    // Main loop
    while(aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START) break;

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_TargetClear(top, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
        C2D_TargetClear(bottom, C2D_Color32(0x00, 0x00, 0x00, 0xFF));

        C2D_SceneBegin(top);
        C2D_DrawRectSolid(50, 50, 0, 50, 50, C2D_Color32(0xFF, 0x00, 0x00, 0xFF));
        C2D_DrawRectSolid(100, 100, 0, 50, 50, C2D_Color32(0x00, 0xFF, 0x00, 0xFF));

        C2D_SceneBegin(bottom);
        C2D_DrawRectSolid(50, 50, 0, 50, 50, C2D_Color32(0x00, 0x00, 0xFF, 0xFF));
        C2D_DrawRectSolid(100, 100, 0, 50, 50, C2D_Color32(0xFF, 0xFF, 0x00, 0xFF));

        C3D_FrameEnd(0);
    }

    gfxExit();
    return 0;
}
