#ifndef NO_OMP
#include <omp.h>
#endif
#include "integrator.hpp"
#include "material.hpp"
#include "constant.hpp"
#include "light.hpp"
#include "utils.hpp"
#include "config.hpp"


extern Config conf;


/**
 * Integrator class
 */

Integrator::Integrator(Scene* scn, Camera* cam)
    : scene(scn)
    , camera(cam)
{
}


/**
 * PhongLightingIntegrator class
 */

PhongLightingIntegrator::PhongLightingIntegrator(Scene* scn, Camera* cam)
    : Integrator(scn, cam)
{
}

void PhongLightingIntegrator::render()
{
    int dx, dy;

#ifndef NO_OMP
    #pragma omp parallel for private(dy)
#endif
    for (dx = 0; dx < camera->getFilm().resolution.x(); ++dx)
    {
        for (dy = 0; dy < camera->getFilm().resolution.y(); ++dy)
        {
            //// TODO
            UNREACHABLE;
        }
    }
}

Eigen::Vector3f PhongLightingIntegrator::radiance(const Interaction& interaction, const Ray& ray) const
{
    /* If the ray hits a light source, return the light color */
    if (interaction.type == Interaction::Type::LIGHT)
    {
        return scene->getLight()->getColor();
    }

    /* Ambient component */
    Eigen::Vector3f amb_comp = scene->getAmbientLight();

    //// TODO
    UNREACHABLE;
}
