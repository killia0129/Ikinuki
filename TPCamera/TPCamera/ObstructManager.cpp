#include "ObstructManager.h"


ObstructManager* ObstructManager::instance = nullptr;

void ObstructManager::Update(float delataTime)
{
}

void ObstructManager::Add(ObstructBase* newObs)
{
    instance->obsBuff.emplace_back(newObs);
}

void ObstructManager::Clear()
{
    while (!instance->obsBuff.empty())
    {
        delete instance->obsBuff.back();
    }
    while (!instance->obstructs.empty())
    {
        delete instance->obstructs.back();
        instance->obstructs.pop_back();
    }
}

void ObstructManager::Remove(ObstructBase* dltObs)
{
    auto iter = std::find(instance->obsBuff.begin(), instance->obsBuff.end(), dltObs);
    if (iter != instance->obsBuff.end())
    {
        std::iter_swap(iter, instance->obsBuff.end() - 1);
        instance->obsBuff.pop_back();
        return;
    }

    iter = std::find(instance->obstructs.begin(), instance->obstructs.end(), dltObs);
    if (iter != instance->obstructs.end() - 1)
    {
        std::iter_swap(iter, instance->obstructs.end() - 1);
        delete instance->obstructs.back();
    }
}

void ObstructManager::Draw()
{
}

void ObstructManager::Finalize()
{
}

void ObstructManager::Init()
{
    if (!instance)
    {
        instance = new ObstructManager;
    }
}

ObstructManager::ObstructManager()
    :obstructs()
{
    instance = nullptr;
}

ObstructManager::~ObstructManager()
{
    Clear();
}
