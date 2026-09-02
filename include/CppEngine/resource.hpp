#pragma once

#include <filesystem>
namespace eng
{
    enum class ProjectType
    {
        Debug,
        App
    };

    class Resource
    {
    public:
        static std::filesystem::path getResourcePath(const std::string& path);

        static void setRoot(const ProjectType& projectType);
    private:
        static std::filesystem::path root;
    };
}
