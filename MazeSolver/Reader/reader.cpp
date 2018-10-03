#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv ) {
    if ( argc != 2 ) {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat maze;

    maze = imread( argv[1], 1 );
    if ( !maze.data ) {
        printf("No image data \n");
        return -1;
    }
	// Image loading done


	int arr[maze.rows][maze.cols];
	int src_i = -1, src_j = -1;
	int dst_i = -1, dst_j = -1;
	for(int i=0;i<maze.rows;i++) {
		for (int j=0;j<maze.cols;j++) {
			int  b = maze.at<cv::Vec3b>(i,j)[0] , g = maze.at<cv::Vec3b>(i,j)[1], r = maze.at<cv::Vec3b>(i,j)[2];

			if 		(b > 200 && g > 200 && r > 200 ) arr[i][j] = 0;
			else if (b < 10  && g < 10  && r < 10  ) arr[i][j] = 1;
			else if (g > 150 && b < 100 && r < 100 ) {arr[i][j] = 2; src_i = i; src_j = j;}		//source found
			else if (g < 100 && b > 150 && r < 100 ) {arr[i][j] = 3; dst_i = i; dst_j = j;}		//destination found
		}
	}

	if (src_i == -1 || src_j == -1 || dst_i == -1 || dst_j == -1) {
		cout << "EITHER SOURCE OR DESTINATION IS MISSING" << endl;
		return 0;
	}
	// array creation done
	FILE *fptr;
	fptr=fopen("maze.txt","w+");
	fprintf(fptr,"%d %d\n", maze.rows, maze.cols);

	int i=0, j=0;
	for (i=0; i<maze.rows; i++){
		for (j=0; j<maze.cols; j++){
			fprintf(fptr, "%d ", arr[i][j]);
		}
		fprintf(fptr, "\n");
	}
    return 0;
}
