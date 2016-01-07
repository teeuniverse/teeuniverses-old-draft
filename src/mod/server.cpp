#include <mod/server.h>

#include <modapi/server/modcreator.h>

CMod_Server::CMod_Server() :
	CModAPI_Server("mod") //Name of the mod
{
	
}

int CMod_Server::CreateModFile(IStorage* pStorage, const char* pFilename)
{
	CModAPI_ModCreator ModCreator;
	
	if(ModCreator.AddImage(Storage(), "modapi/objects.png") != MODAPIEXAMPLE_IMAGE_OBJECTS) return false;
	if(ModCreator.AddSpriteExternal(MODAPIEXAMPLE_IMAGE_OBJECTS, 0, 0, 2, 2, 32, 32) != MODAPIEXAMPLE_SPRITE_TARGET) return false;

	if(ModCreator.Save(pStorage, pFilename) < 0) return false;
	else return true;
}
