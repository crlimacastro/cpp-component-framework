#include "pch.h"
#include "File.hpp"

RFE_API bool rfe::File::DirExists(std::string dirPath)
{
    return DirectoryExists(dirPath.c_str());
}

bool rfe::File::Exists(std::string fileName)
{
    return FileExists(fileName.c_str());
}

bool rfe::File::IsExtension(std::string fileName, std::string ext)
{
    return IsFileExtension(fileName.c_str(), ext.c_str());
}

std::string rfe::File::GetExtension(std::string fileName)
{
    return GetFileExtension(fileName.c_str());
}

std::string rfe::File::GetName(std::string filePath)
{
    return GetFileName(filePath.c_str());
}

std::string rfe::File::GetNameWithoutExt(std::string filePath)
{
    return GetFileNameWithoutExt(filePath.c_str());
}

std::string rfe::File::GetPath(std::string filePath)
{
    return GetDirectoryPath(filePath.c_str());
}

long rfe::File::GetLastModificationTime(std::string fileName)
{
    return GetFileModTime(fileName.c_str());
}

std::string rfe::File::GetPrevDirPath(std::string dirPath)
{
    return GetPrevDirectoryPath(dirPath.c_str());
}

std::string rfe::File::GetWorkingDir()
{
    return GetWorkingDirectory();
}

bool rfe::File::SetWorkingDir(std::string dir)
{
    return ChangeDirectory(dir.c_str());
}
