#include "pos_compensation.h"

using namespace cv;

// origin_image : input 
// 
cv::Point2i find_position_in_image(cv::Mat origin_image, double roll, double pitch, double altitude)
{
	////DEBUG_MSG("Function loaded\n");
	Mat tmp_img = origin_image;

	/*
	//getting roll & pitch 
	roll = 0.0175 * roll;
	pitch = 0.0175 * pitch;
	////DEBUG_MSG("roll/pitch loaded, r:%f, p:%f\n", roll, pitch);

	//pixel coordinate calculation
	pos_pxl_x = 159 + (int) (265.23 * (roll + roll * roll * roll / 3 + 2 * roll * roll * roll * roll * roll / 15)); //tan(roll);
	pos_pxl_y = 119 + (int) (264.53 * (pitch + pitch * pitch * pitch / 3 + 2 * pitch * pitch * pitch * pitch * pitch / 15)); //tan(pitch);
	////DEBUG_MSG("Pixel calculated, r:%f, p:%f\n", pos_pxl_x, pos_pxl_y);

	//satuation
	if(pos_pxl_x>319) pos_pxl_x=319;
	else if(pos_pxl_x<0) pos_pxl_x=0;
	if(pos_pxl_y>239) pos_pxl_y=239;
	else if(pos_pxl_y<0) pos_pxl_y=0;
	////DEBUG_MSG("Pixel calculated, r:%f, p:%f\n", pos_pxl_x, pos_pxl_y);

	//ptr method to make a black dot in desired point //ref) opencv lecture.6
	uchar * row_line = tmp_img.ptr<uchar>( pos_pxl_y );
	row_line[3 * pos_pxl_x + 0] = 0; 
	row_line[3 * pos_pxl_x + 1] = 0; 
	row_line[3 * pos_pxl_x + 2] = 0; 
	////DEBUG_MSG("Image dotted\n");

	//output
	//output->pointed_image = tmp_img;
	//output->pos_pix_x = pos_pxl_x;
	//output->pos_pix_y = pos_pxl_y;
	//DEBUG_MSG("Data transmitted\n");
	*/

	static int x, y;
	int height = origin_image.rows;
	int width = origin_image.cols;

	x = (x+1) % width;
	y = (y+1) % height;
	return Point2i(x, y);
}
