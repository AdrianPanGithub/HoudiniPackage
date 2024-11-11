// Copyright (c) <2024> Yuzhe Pan (childadrianpan@gmail.com). All Rights Reserved.

#pragma once


function float polyparameter(const int op, prim; const float perimeter; const int from_end)
{
    int npts[] = primpoints(op, prim), numnpts = len(npts),
        closed = primintrinsic(op, "closed", prim);
    if (!from_end) {
        float cumulate_l = 0.0;
        vector prevpos = point(op, "P", npts[0]);
        for (int i = 1; i < numnpts + closed; ++i) {
            vector currpos = point(op, "P", npts[i == numnpts ? 0 : i]);
            float l = distance(prevpos, currpos);
            cumulate_l += l;
            if (perimeter <= cumulate_l)
                return (i - (cumulate_l - perimeter) / l) / (numnpts + closed - 1.0);
            prevpos = currpos;
        }
        return 1.0;
    }
    else {
        float cumulate_l = 0.0;
        vector prevpos = point(op, "P", npts[closed ? 0 : (numnpts - 1)]);
        for (int i = numnpts + closed - 2; i >= 0; --i) {
            vector currpos = point(op, "P", npts[i]);
            float l = distance(prevpos, currpos);
            cumulate_l += l;
            if (perimeter <= cumulate_l)
                return (i + (cumulate_l - perimeter) / l) / (numnpts + closed - 1.0);
            prevpos = currpos;
        }
        return 0.0;
    }
    return 0.0;
}
