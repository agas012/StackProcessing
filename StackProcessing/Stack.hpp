#pragma once
#include "VarTypeDef.hpp"
#include "ListImages.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"

class Stack
{
public:
	///initial image index
	unsigned int iniImage;
	///Final image index
	unsigned int endImage;		

	//stack of images
	image_stack Data;
	image_stack DataHSV;

	Stack();
	Stack(unsigned int, unsigned int);
	~Stack();
	///Read the images to a stack
	image_stack ReadImages(ListImages *filepath);
	void StackBGRtoHSV();
	void OperateChannels();
};

