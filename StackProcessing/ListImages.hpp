#pragma once
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include "VarTypeDef.hpp"

class ListImages
{
	///image directory
	boost::filesystem::path Imdir;
	///file extension
	std::string fileext;
public:
	///vector of paths with the path to each file
	files_path image_list;
	files_path GetList(void);

	ListImages(boost::filesystem::path indir, std::string inext);
	~ListImages();
};

