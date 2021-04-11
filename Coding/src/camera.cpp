#include <utility>
#include "camera.hpp"
#include "constant.hpp"
#include "utils.hpp"


Camera::Camera(const Eigen::Vector3f& pos, float focal_len, float v_fov, const Eigen::Vector2i& film_res)
    : film(film_res)
    , vertical_fov(v_fov)
    , position(pos)
    , focal_length(focal_len)
    , forward(0, 0, 1)
    , right(1, 0, 0)
    , up(0, 1, 0)
{
}

void Camera::lookAt(const Eigen::Vector3f& look_at, const Eigen::Vector3f& ref_up)
{
    //// TODO
    UNREACHABLE;
}

Ray Camera::generateRay(float dx, float dy) const
{
    //// TODO
    UNREACHABLE;
}

void Camera::setPixel(int dx, int dy, Eigen::Vector3f value)
{
    film.pixel_array[dy * film.resolution.x() + dx] = value;
}

const Film& Camera::getFilm() const
{
    return film;
}