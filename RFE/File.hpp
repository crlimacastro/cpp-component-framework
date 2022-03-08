#pragma once

namespace rfe::File
{
	RFE_API bool DirExists(std::string dirPath);
	RFE_API bool Exists(std::string fileName);
	RFE_API bool IsExtension(std::string fileName, std::string ext);
	RFE_API std::string GetExtension(std::string fileName);
	RFE_API std::string GetName(std::string filePath);
	RFE_API std::string GetNameWithoutExt(std::string filePath);
	RFE_API std::string GetPath(std::string filePath);
	RFE_API long GetLastModificationTime(std::string fileName);
	RFE_API std::string GetPrevDirPath(std::string dirPath);
	RFE_API std::string GetWorkingDir();
	RFE_API bool SetWorkingDir(std::string dir);
};

