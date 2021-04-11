#include "texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "utils.hpp"


Texture::Texture()
    : data(nullptr)
    , width(0)
    , height(0)
{
}

bool Texture::isNull() const
{
    return data == nullptr || width == 0 || height == 0;
}

Eigen::Vector2i Texture::getDimension() const
{
    return Eigen::Vector2i(width, height);
}

Eigen::Vector3f Texture::getPixel(float u, float v) const
{
    //// TODO
    UNREACHABLE;
}

void Texture::clear()
{
    width = 0;
    height = 0;
    delete data;
    data = nullptr;
}
    
Texture::~Texture()
{
    clear();
}

Texture Texture::loadFromPath(std::string path)
{
    int w, h, n;
    unsigned char* raw_data = stbi_load(path.c_str(), &w, &h, &n, 0);

    Texture tex;
    
    /* Only images with 1 or 3 channels are supported */
    if (raw_data && (n == 3 || n == 1))
    {
        tex.data = new float[w * h * 3];
        tex.width = w;
        tex.height = h;

        int ch_stride = n == 3 ? 1 : 0;
        for (int i = 0; i < w * h * n; i += n)
        {
            tex.data[i] = (float)raw_data[i] / 255.0f;
            tex.data[i + 1] = (float)raw_data[i + ch_stride] / 255.0f;
            tex.data[i + 2] = (float)raw_data[i + ch_stride * 2] / 255.0f;
        }

        stbi_image_free(raw_data);
    }

    return tex;
}

Texture Texture::generateCheckerboard(Eigen::Vector3f primary_rgb, Eigen::Vector3f secondary_rgb, unsigned int num_ckers)
{
    //// TODO
    UNREACHABLE;
}
