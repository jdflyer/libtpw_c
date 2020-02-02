#include <stdio.h>
#include "controller.h"
#include "gcn/gfx.h"
#include "gcn/gu.h"
#include "inventory.h"
#include "system.h"
#include "tp.h"

static bool visible = false;

void render() {
    if (Controller::B.is_pressed()) {
        visible = false;
        tp_osReport("Goodbye!");
        return;
    }
    tp_osReport("Hello!");
}

extern "C" void game_loop() {
    bool rt_down = Controller::R.is_down();
    bool lt_down = Controller::L.is_down();
    bool d_down = Controller::DPAD_DOWN.is_down();

    char buffer[218];
    sprintf(buffer, "%d", sizeof(TP::GameInfo));
    tp_osReport(buffer);

    if (visible) {
        render();
    } else if (rt_down && d_down && lt_down && !visible) {
        visible = true;
    } else {
        //something
    }
}

static float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

extern "C" void draw() {
    GX_ClearVtxDesc();
    GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
    GX_SetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_F32, 0);
    GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

    GX_Begin(GX_TRIANGLES, GX_VTXFMT0, 3);
    {
        GX_Position3f32(-0.5f, -0.5f, 0.0f);
        GX_Position3f32(0.5f, -0.5f, 0.0f);
        GX_Position3f32(0.0f, 0.5f, 0.0f);
        GX_Color1u32(0xFFFFFFFF);
    }
    GX_End();
}