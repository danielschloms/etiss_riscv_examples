TEST_FUNCS = {
    # 1. Add/Sub
    "vadd": {
        "modes": ["vv", "vx", "vi"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vsub": {
        "modes": ["vv", "vx"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vrsub": {
        "modes": ["vi", "vx"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    # 2. Widening Add/Sub
    "vwadd": {
        "modes": ["wvv", "wwv", "wvx", "wwx"],
        "signs": ["i"],
        "lmuls": ["m1", "m2", "m4"],
        "widths": [8, 16],
    },
    "vwsub": {
        "modes": ["wvv", "wwv", "wvx", "wwx"],
        "signs": ["i"],
        "lmuls": ["m1", "m2", "m4"],
        "widths": [8, 16],
    },
    # 3.
    "vand": {
        "modes": ["vv", "vi", "vx"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vor": {
        "modes": ["vv", "vi", "vx"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vxor": {
        "modes": ["vv", "vi", "vx"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vmul": {
        "modes": ["vv", "vx"],
        "signs": ["i", "u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vmulh": {
        "modes": ["vv", "vx"],
        "signs": ["i"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vmulhu": {
        "modes": ["vv", "vx"],
        "signs": ["u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    # Divide
    "vdiv": {
        "modes": ["vv", "vx"],
        "signs": ["i"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vdivu": {
        "modes": ["vv", "vx"],
        "signs": ["u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vrem": {
        "modes": ["vv", "vx"],
        "signs": ["i"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
    "vremu": {
        "modes": ["vv", "vx"],
        "signs": ["u"],
        "lmuls": ["m1", "m2", "m4", "m8"],
        "widths": [8, 16, 32],
    },
}
