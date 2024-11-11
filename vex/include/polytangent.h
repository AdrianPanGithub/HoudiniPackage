// Copyright (c) <2024> Yuzhe Pan (childadrianpan@gmail.com). All Rights Reserved.

#pragma once


function vector polytangent(const int op, primnum; const float u)
{
    int closed = primintrinsic(op, "closed", primnum),
        npts[] = primpoints(op, primnum),
        numnpts = len(npts);
    float fvi = u * (numnpts + closed - 1);
    int vi = int(fvi);
    if (fvi == vi) {
        vector currpos = point(op, "P", npts[vi]);
        if (closed) {
            int nextvi = (vi == numnpts - 1) ? 0 : (vi + 1),
                prevvi = (vi == 0) ? numnpts - 1 : (vi - 1);
            vector nextpos = point(op, "P", npts[nextvi]),
                prevpos = point(op, "P", npts[prevvi]);
            return normalize(normalize(nextpos - currpos) + normalize(currpos - prevpos));
        }
        else {
            if (vi == 0) {
                vector nextpos = point(op, "P", npts[1]);
                return normalize(nextpos - currpos);
            }
            else if (vi == numnpts - 1) {
                vector prevpos = point(op, "P", npts[-2]);
                return normalize(currpos - prevpos);
            }
            else {
                vector nextpos = point(op, "P", npts[vi + 1]),
                    prevpos = point(op, "P", npts[vi - 1]);
                return normalize(normalize(nextpos - currpos) + normalize(currpos - prevpos));
            }
        }
    }
    else {
        vector pos0 = point(op, "P", npts[vi]),
            pos1 = point(op, "P", npts[(closed && vi == numnpts - 1) ? 0 : (vi + 1)]);
        return normalize(pos1 - pos0);
    }
}
