#include <iterator>
#include <vector>
#include <algorithm>
#include <boost/filesystem.hpp>
#include "opencv2/core/core.hpp"

#include "Stack.hpp"
#include "ListImages.hpp"

int main(int argc, char* argv[]) {
	///Generate stack container
	Stack ImS;

	ListImages ImList("C:/Users/Alfonso/Pictures/Samus/", ".png");
	ImList.GetList();
	ImS.ReadImages(&ImList);
	ImS.StackBGRtoHSV();
	ImS.OperateChannels();
	int a = 0;
}
