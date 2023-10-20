#ifndef ANIMATIONSHEET_HPP
#define ANIMATIONSHEET_HPP
#include <pugixml.hpp>
#include <raylib.h>
#include <Core/Sys/SysLog.hpp>
#include <filesystem>

/*
Simple Implementation of a format to handle animation sheets

TODO : Add more error catching stuff , Refactor it (it's really ugly rn)

*/
class AnimationSheet {
public:
	pugi::xml_document doc; // the xml that represents this
	Texture2D self;
public:
	AnimationSheet()
	{

	}

	bool CheckRootNode(std::string filePath, pugi::xml_node rootNode)
	{
		namespace fs = std::filesystem;
		
		pugi::xml_attribute fileName = rootNode.attribute("file");
		if (fileName.empty())
		{
			ERROR("There is no linked files");
			return false;
		}
		fs::path path = filePath;
		fs::path directory = path.parent_path();
		fs::path imagePath = directory / fileName.as_string();
		if (!fs::exists(imagePath)) {
			ERROR("Image doesnt exist at path : %s ", imagePath.string());
			return false;
		}
		Texture2D tex = LoadTexture(imagePath.string().c_str());
		self = tex;
		return true;
	}

	std::vector<Texture2D> GetTextures()
	{
		INFO("GetTextures");
		std::vector<Texture2D> result;
		pugi::xml_node rootNode = doc.first_child();
		for (pugi::xml_node child : rootNode.children())
		{
			INFO("Hello");
			int x = child.attribute("x").as_int();
			int y = child.attribute("y").as_int();
			int width = child.attribute("width").as_int();
			int height = child.attribute("height").as_int();

			Image img = LoadImageFromTexture(self);
			Rectangle cropRect = { x, y, width, height }; // Replace x, y, width, and height with your desired values.
			ImageCrop(&img, cropRect);
			Texture2D croppedTexture = LoadTextureFromImage(img);
			result.push_back(croppedTexture);
		}
		return result;
	}
	void FromXml(std::string filePath)
	{
		pugi::xml_document temp;
		if (!temp.load_file(filePath.c_str()))
		{
			ERROR("Failed to load animation sheet xml at path : %s ", filePath.c_str());
			return;
		}
		if (CheckRootNode(filePath, temp.first_child()))
		{
			doc.load_file(filePath.c_str());
			return;
		}

		


	}
};

#endif