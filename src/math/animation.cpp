#include "animation.hpp"

Animation::Animation(int maximum) : frame{0}, max_frames{maximum} {
}

int Animation::tick() {
    frame++;

    if (frame > max_frames) {
        frame = 0;
    }

    return frame;
}

int Animation::get_frame() {
    return frame;
}

Animation::~Animation() {}
