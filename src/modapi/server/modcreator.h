#ifndef MODAPI_MOD_H
#define MODAPI_MOD_H

#include <base/tl/array.h>
#include <base/vmath.h>
#include <modapi/moditem.h>

class IStorage;

class CModAPI_ModCreator
{
public:
	class CModAPI_LineStyleCreator : public CModAPI_ModItem_LineStyle
	{
	public:
		CModAPI_LineStyleCreator& SetOuter(int Width, const vec4& Color);
		CModAPI_LineStyleCreator& SetInner(int Width, const vec4& Color);
		CModAPI_LineStyleCreator& SetLineRepeatedSprite(int SpriteId1, int SpriteSizeX, int SpriteSizeY);
		CModAPI_LineStyleCreator& SetStartPointSprite(int SpriteId1, int X, int Y, int W, int H);
		CModAPI_LineStyleCreator& SetStartPointAnimatedSprite(int SpriteId1, int SpriteId2, int X, int Y, int W, int H, int Speed);
		CModAPI_LineStyleCreator& SetEndPointSprite(int SpriteId1, int X, int Y, int W, int H);
		CModAPI_LineStyleCreator& SetEndPointAnimatedSprite(int SpriteId1, int SpriteId2, int X, int Y, int W, int H, int Speed);
		CModAPI_LineStyleCreator& SetLineAnimation(int Type, int Speed);
	};

	class CModAPI_SkinModifierCreator : public CModAPI_ModItem_SkinModifier
	{
	public:
		CModAPI_SkinModifierCreator& SetDefault();

		CModAPI_SkinModifierCreator& SetBodyColor(const vec4& Color);
		CModAPI_SkinModifierCreator& SetBodyInternalSkin(int ImageId);
		CModAPI_SkinModifierCreator& SetBodyExternalSkin(int ImageId);

		CModAPI_SkinModifierCreator& SetMarkingColor(const vec4& Color);
		CModAPI_SkinModifierCreator& SetMarkingInternalSkin(int ImageId);
		CModAPI_SkinModifierCreator& SetMarkingExternalSkin(int ImageId);

		CModAPI_SkinModifierCreator& SetDecorationColor(const vec4& Color);
		CModAPI_SkinModifierCreator& SetDecorationInternalSkin(int ImageId);
		CModAPI_SkinModifierCreator& SetDecorationExternalSkin(int ImageId);

		CModAPI_SkinModifierCreator& SetHandsColor(const vec4& Color);
		CModAPI_SkinModifierCreator& SetHandsInternalSkin(int ImageId);
		CModAPI_SkinModifierCreator& SetHandsExternalSkin(int ImageId);

		CModAPI_SkinModifierCreator& SetFeetColor(const vec4& Color);
		CModAPI_SkinModifierCreator& SetFeetInternalSkin(int ImageId);
		CModAPI_SkinModifierCreator& SetFeetExternalSkin(int ImageId);

		CModAPI_SkinModifierCreator& SetEyesColor(const vec4& Color);
		CModAPI_SkinModifierCreator& SetEyesInternalSkin(int ImageId);
		CModAPI_SkinModifierCreator& SetEyesExternalSkin(int ImageId);
	};

private:
	array<void*> m_ImagesData;
	array<CModAPI_ModItem_Image> m_Images;
	array<CModAPI_ModItem_Sprite> m_Sprites;
	array<CModAPI_LineStyleCreator> m_LineStyles;
	array<CModAPI_SkinModifierCreator> m_SkinModifiers;
	
	int AddSprite(int ImageId, int x, int External, int y, int w, int h, int gx, int gy);
	
public:
	CModAPI_ModCreator();
	
	int AddImage(IStorage* pStorage, const char* Filename);
	int AddSpriteInternal(int ImageId, int x, int y, int w, int h, int gx, int gy);
	int AddSpriteExternal(int ImageId, int x, int y, int w, int h, int gx, int gy);
	CModAPI_LineStyleCreator& AddLineStyle();
	CModAPI_SkinModifierCreator& AddSkinModifier();
	
	int Save(class IStorage *pStorage, const char *pFileName);
};

#endif
