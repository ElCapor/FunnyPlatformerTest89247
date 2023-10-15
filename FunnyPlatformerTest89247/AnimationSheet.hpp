#ifndef ANIMATIONSHEET_HPP
#define ANIMATIONSHEET_HPP
#include <pugixml.hpp>
#include <raylib.h>
#include "SysLog.hpp"
#include <filesystem>

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

	std::vector<Texture2D> GetTextures(pugi::xml_node rootNode)
	{
		std::vector<Texture2D> result;
		
		for (pugi::xml_node child : rootNode.children())
		{
			int x = child.attribute("x").as_int();
			int y = child.attribute("y").as_int();
			int width = child.attribute("width").as_int();
			int height = child.attribute("height").as_int();

			DrawTexturePro()

		}
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
			return;
		}

		


	}
};

#endif