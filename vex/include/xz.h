// Copyright (c) <2024> Yuzhe Pan (childadrianpan@gmail.com). All Rights Reserved.

#pragma once


function vector u2v(const vector2 u) { return set(u.x, 0.0, u.y); }

function vector2 v2u(const vector v) { return set(v.x, v.z); }

function vector2 p2u(const vector4 p) { return set(p.x, p.z); }
