// Copyright (c) <2024> Yuzhe Pan (childadrianpan@gmail.com). All Rights Reserved.

#pragma once


function float polyperimeter(const int op, prim; const float u)
{
    int npts[] = primpoints(op, prim), numnpts = len(npts),
        closed = primintrinsic(op, "closed", prim);
    
    float t = u * (numnpts + closed - 1.0),
        cl = 0.0;
    vector prevpos = point(op, "P", npts[0]);
    for (int i = 1; i < numnpts + closed; ++i) {
        vector currpos = point(op, "P", npts[(i == numnpts) ? 0 : i]);
        float segl = length(prevpos - currpos);
        if (float(i) < t)
            cl += segl;
        else
            return segl * (t - i + 1) + cl;
        prevpos = currpos;
    }
    return 0.0;
}
