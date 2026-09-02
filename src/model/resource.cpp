#include "resource.hpp"
#include <mach-o/dyld.h>
#include <vector>

using namespace eng;

std::filesystem::path Resource::getResourcePath(const std::string& path)
{
    return root / path;
}

void Resource::setRoot(const ProjectType& projectType)
{
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size);

    std::vector<char> buffer(size);

    if(_NSGetExecutablePath(buffer.data(), &size) != 0)
    {
        throw std::runtime_error("Failed to set root.");
    }

    switch(projectType)
    {
        case ProjectType::Debug:
            root = std::filesystem::canonical(buffer.data()).parent_path().parent_path().parent_path() / "resources";
            break;
        case ProjectType::App:
            root = std::filesystem::canonical(buffer.data()).parent_path().parent_path() / "Resources";
    }
}

std::filesystem::path Resource::root;
