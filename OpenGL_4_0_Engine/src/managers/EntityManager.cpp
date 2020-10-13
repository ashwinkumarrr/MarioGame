#include "EntityManager.h"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
    while (!m_entities.empty())
    {
        delete m_entities[m_entities.size() -1];
        m_entities.pop_back();
    }
    m_entities.clear();
}

void EntityManager::Intialize()
{
    for (int i = 0; i < (int)m_entities.size(); ++i) 
    {
        m_entities[i]->Initialize();
    }
}

void EntityManager::Update(float dt)
{
    for (int i = 0; i < (int)m_entities.size(); ++i)
    {
        if(!m_entities[i]->HasBeenInstialized())
           m_entities[i]->Initialize();

        m_entities[i]->Update(dt);
    }
}

void EntityManager::Render(SpriteBatch* spriteBatch, Camera* camera)
{
    for (int i = 0; i < (int)m_entities.size(); ++i)
    {
        if (!m_entities[i]->HasBeenInstialized())
            m_entities[i]->Initialize();

        m_entities[i]->render(spriteBatch, camera);
    }
}

Entity* EntityManager::AddEntity()
{
    Entity* entity = new Entity();
    m_entities.push_back(entity);

    return entity;
}

void EntityManager::RemoveEntity(Entity* entity)
{
    if (entity == NULL) return;

    int id = entity->GetID();
    delete m_entities[id];
    m_entities.erase(m_entities.begin() + id);

}