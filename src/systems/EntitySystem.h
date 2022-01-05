#ifndef PSR_3D_RENDERER_ENTITYSYSTEM_H
#define PSR_3D_RENDERER_ENTITYSYSTEM_H

#include <glm/glm.hpp> // vec2, vec3, mat4, radians
#include <opencv2/opencv.hpp>
#include "../entities/EntityComponents.h"
#include "../systems/CameraSystem.h"
#include "../external-libraries/stl_reader.h"

class EntitySystem {
private:
    CameraSystem& cameraSystem;  // TODO: Should & be on first or second? Why does & make sense here?
    Positions positions;
    Orientations orientations;
    Scales scales;
    Meshes meshes;
    int64_t totalEntitiesAdded;
    std::vector<glm::mat3x4> MeshGenerator(std::string shape);
    Entities entities; // TODO?
public:
    enum Entity {
        SPHERE, CUBE, TORUS, PYRAMID, AXES
    };

    explicit EntitySystem(CameraSystem& cameraSystem1);

    void updateGame(int keycode);

    void addEntity(Entity entity, glm::vec3 position);

    void removeEntity(EntityID id);

    Positions getPositions();

    Orientations getOrientations();

    Scales getScales();

    Meshes getMeshes();

    void addEntityId(int id); // TODO?
};


#endif //PSR_3D_RENDERER_ENTITYSYSTEM_H
