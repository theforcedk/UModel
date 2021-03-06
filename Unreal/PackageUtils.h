#ifndef __PACKAGE_UTILS_H__
#define __PACKAGE_UTILS_H__


class UnPackage;
extern TArray<UnPackage*> GFullyLoadedPackages;

// Virtual interface which could be used for progress indication.
class IProgressCallback
{
public:
	// Stop operating when these functions returns 'false'.
	virtual bool Progress(const char* package, int index, int total)
	{
		return true;
	}
	virtual bool Tick()
	{
		return true;
	}
};


bool LoadWholePackage(UnPackage* Package, IProgressCallback* progress = NULL);
void ReleaseAllObjects();


// Package scanner

struct FileInfo
{
	int		Ver;
	int		LicVer;
	int		Count;
	char	FileName[512];
};

bool ScanPackages(TArray<FileInfo>& info, IProgressCallback* progress = NULL);


#endif // __PACKAGE_UTILS_H__
