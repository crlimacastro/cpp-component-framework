#pragma once

#include "Entity.h"

namespace rfe
{
    // Inherit to create your own Scenes
    // Override protected OnLoad() to add entities to the scene
    class RFE_API Scene
    {
    public:
        friend class Application;
        friend class SceneManager;
    public:
        Scene() = default;
    public:
        void AddEntity(const Entity& entity);
        void RemoveEntity(const Entity& entity);
        void ClearEntities();
    protected:
        virtual void OnLoad() = 0;

    private:
        std::unordered_set<std::shared_ptr<Entity>> entities;

        void Update();
        void Load();
    };
}