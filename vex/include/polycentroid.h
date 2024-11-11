// Copyright (c) <2024> Yuzhe Pan (childadrianpan@gmail.com). All Rights Reserved.

#pragma once

#include <xz.h>


function vector2 polycentroid(const int op, prim)
{
    int npts[] = primpoints(op, prim);

    float area = 0.0;
    vector2 ct = { 0.0, 0.0 };
    vector2 prevpos = v2u(point(op, "P", npts[-1]));
    for (int vi = 0; vi < len(npts); ++vi) {
        vector2 currpos = v2u(point(op, "P", npts[vi]));
        float curr_area = (prevpos.x * currpos.y - prevpos.y * currpos.x) * 0.5;
        area += curr_area;
        ct += (prevpos + currpos) * curr_area / 3.0;
        prevpos = currpos;
    }
    return ct / area;
}

function vector2 polycentroid(const vector2 positions[])
{
    float area = 0.0;
    vector2 ct = { 0.0, 0.0 };
    for (int vi = 0; vi < len(positions); ++vi) {
        vector2 prevpos = positions[vi - 1];
        vector2 currpos = positions[vi];
        float curr_area = (prevpos.x * currpos.y - prevpos.y * currpos.x) * 0.5;
        area += curr_area;
        ct += (prevpos + currpos) * curr_area / 3.0;
    }
    return ct / area;
}
