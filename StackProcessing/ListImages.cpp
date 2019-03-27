#include "ListImages.hpp"



ListImages::ListImages(boost::filesystem::path indir, std::string inext)
{
	Imdir = indir;
	fileext = inext;
}


ListImages::~ListImages()
{
}

files_path ListImages::GetList(void) {
	try
	{
		if (boost::filesystem::exists(Imdir)) {// does Imdir actually exist?
			if (boost::filesystem::is_regular_file(Imdir))// is Imdir a regular file?   
				std::cout << Imdir << " size is " << boost::filesystem::file_size(Imdir) << '\n';
			else if (boost::filesystem::is_directory(Imdir)) {// is Imdir a directory?
				for (boost::filesystem::directory_iterator i(Imdir); i != boost::filesystem::directory_iterator(); ++i) {
					// Skip if not a file
					if (!boost::filesystem::is_regular_file(i->status())) continue;
					//skip if not image type
					if (!(i->path().extension() == fileext)) continue;
					image_list.push_back(i->path());
				}
				if (!image_list.empty()) {
					sort(image_list.begin(), image_list.end());
					return image_list;
				}
				else {
					std::cout << "no images file found on directory whith the provided extention ";
					exit(0);
				}
			}
			else
				std::cout << Imdir << " exists, but is neither a regular file nor a directory\n";
		}
		else {
			std::cout << Imdir << " does not exist\n";
			exit(0);
		}
	}
	catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << '\n';
	}
}