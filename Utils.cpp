#include "Utils.h"

short Utils::coord2DTo1D(short in_X, short in_Y, short in_scrW) {
    return in_Y * in_scrW + in_X;
}
