#include "Stack.hpp"



Stack::Stack()
{
}

Stack::Stack(unsigned int a, unsigned int b) {
	iniImage = a;
	endImage = b;
}

Stack::~Stack()
{
}

//stack creation, each image is read into a vector entry
image_stack Stack::ReadImages(ListImages *filepath) {
	unsigned int NumImages;
	if (endImage == 0) {
		NumImages = filepath->image_list.size();
		std::cout << "Number of images: " << NumImages;
		endImage = NumImages;
		//iterator
		for (files_path::const_iterator it(filepath->image_list.begin()); it != filepath->image_list.end(); ++it) {
			Data.push_back(cv::imread(it->string(), cv::IMREAD_COLOR));
		}
	}
	else {
		NumImages = endImage - iniImage;
		std::cout << "Number of images: " << NumImages;
		for (files_path::size_type i = iniImage; i <= endImage; i++) {
			Data.push_back(cv::imread(filepath->image_list[i].string(), cv::IMREAD_COLOR));
		}
	}
	return Data;
}

void Stack::StackBGRtoHSV() {
	cv::Mat temp_image;
	for (int i = 0; i < Data.size(); i++) {
		if (~Data[i].empty()) {
			cv::cvtColor(Data[i], temp_image, cv::COLOR_BGR2Lab);
			DataHSV.push_back(temp_image.clone());
		}
	}
}

void Stack::OperateChannels() {
	cv::Mat bands[3];
	for (int i = 0; i < DataHSV.size(); i++) {
		if (~DataHSV[i].empty()) {
			split(DataHSV[i], bands);
			std::vector<cv::Mat> channels = { bands[0],bands[1],bands[2] };
			bands[1].setTo(cv::Scalar(0));
			merge(channels, DataHSV[i]);
		}
	}
}