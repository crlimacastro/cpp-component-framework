#pragma once

#include "Entity.h"

namespace rfe
{
    // Inherit to create your own Scenes
    // Override abstract protected OnLoad() to add entities to the scene
    // You may override virtual protected OnStart() to define functionality after everything has loaded
    class RFE_API Scene
    {
    public:
        friend class Application;
        friend class SceneManager;
    public:
        Scene() = default;
    public:
        void AddEntity(std::shared_ptr<Entity> entity);
        void RemoveEntity(std::shared_ptr<Entity> entity);
        void ClearEntities();
    protected:
        virtual void OnLoad() = 0;
        virtual void OnStart() {}

    private:
        std::unordered_set<std::shared_ptr<Entity>> entities;

        void Update();
        void Load();
    };
}