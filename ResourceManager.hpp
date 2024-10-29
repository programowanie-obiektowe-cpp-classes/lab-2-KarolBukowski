#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource{new Resource{}} {}

    ResourceManager(const ResourceManager& rm) : resource{new Resource{*rm.resource}} {}
    ResourceManager(ResourceManager&& rm) noexcept : resource(rm.resource)
    {
        rm.resource = nullptr;
    }
    ResourceManager& operator=(const ResourceManager& rm)
    {
        if (this != &rm) {
            delete resource;
            resource = new Resource(*rm.resource);
        }
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& rm) noexcept
    {
        if (this != &rm) {
            delete resource;
            resource    = rm.resource;
            rm.resource = nullptr;
        }
        return *this;
    }
    ~ResourceManager() { delete resource; }

    double get() const { return resource->get(); }

private:
    Resource* resource;
};
