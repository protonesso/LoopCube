#include "camera.hpp"

Camera::Camera() {

}

Camera::~Camera() {
    std::cout << "Camera deleted" << std::endl;
}

void Camera::set_pos(double x, double y) {
    x_pos = x;
    y_pos = y;
}

double Camera::get_x() {
    return x_pos;
}

double Camera::get_y() {
    return y_pos;
}
