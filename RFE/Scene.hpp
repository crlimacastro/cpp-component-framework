#pragma once

#include "Entity.hpp"

namespace rfe
{
    // Inherit to create your own Scenes
    // Overrides:
    // protected OnLoad() [Required] -> Define entities added to the Scene
    // protected OnStart() -> Define functionality for after every Component has Loaded but before they Start
    // protected OnUnload() -> Define clean up functionality after every Component has been Unloaded (no need to remove entities, it is done automagically)
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
        virtual void OnUnload() {}

    private:
        std::unordered_set<std::shared_ptr<Entity>> entities;

        bool loaded = false;

        void Update();
        void Draw3D();
        void Draw2D();
        void DrawScreen();
        void PostDrawUpdate();
        void Load();
        void Unload();
    };
}