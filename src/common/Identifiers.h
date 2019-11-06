//
// Created by leobellaera on 2/11/19.
//

#ifndef MICROMACHINES_IDENTIFIERS_H
#define MICROMACHINES_IDENTIFIERS_H

#define THROWABLE_OBJECTS_NUMBER 4

enum FloorIdentifier {
    GRASS_ID,
    THIRD_QUAD_CURVE_TRACK_ID,
    SECOND_QUAD_CURVE_TRACK_ID,
    FOURTH_QUAD_CURVE_TRACK_ID,
    FIRST_QUAD_CURVE_TRACK_ID,
    HORIZONTAL_TRACK_ID,
    HORIZONTAL_MIRRORED_TRACK_ID,
    VERTICAL_TRACK_ID,
    VERTICAL_MIRRORED_TRACK_ID,
    HOR_TRACK_CHECKPOINT_ID,
    VER_TRACK_CHECKPOINT_ID
};

enum EntityIdentifier {
    HEALTHBOOSTER,
    OIL,
    SPEEDBOOSTER,
    STONE,
    MUG,
    TRACK,
    CAR,
    CHECKPOINT
};

enum EntityStatus {
    ALIVE,
    SEVERALDAMAGED,
    DEAD
};

#endif //MICROMACHINES_IDENTIFIERS_H
