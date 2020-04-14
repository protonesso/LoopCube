#ifndef ANIMATION_HPP
#define ANIMATION_HPP

class Animation {
public:
    Animation() {};
    Animation(int maximum);
    ~Animation();

    int tick();
    int get_frame();
private:
    int frame;
    int max_frames;
};


#endif // ANIMATION_HPP
