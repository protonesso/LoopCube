#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <iostream>

class Camera {

public:
    Camera();
    ~Camera();

    void set_pos(double x, double y);
    double get_x();
    double get_y();

private:
    double x_pos;
    double y_pos;
};


#endif // CAMERA_HPP
