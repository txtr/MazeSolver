#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv ) {
    FILE *solution;
    solution = fopen ("maze.txt", "r");
    int rows = 0, cols = 0;
    fscanf(solution, "%d %d", &rows, &cols);
    int arr[rows][cols];

    int row, col;
    for (row = 0; row < rows; row++){
        for (col = 0; col < cols; col++){
            char space;
            fscanf(solution, "%d", &arr[row][col]);
            fscanf(solution, "%c", &space);
        }
    }

    Mat maze = Mat::zeros(rows, cols, CV_8UC1);

	for(int i=0;i<maze.rows;i++) {
		for (int j=0;j<maze.cols;j++) {
		    if (arr[i][j] == 0) maze.at<cv::Vec3b>(i,j/2)[0] = 255;   maze.at<cv::Vec3b>(i,j/2)[1] = 255; maze.at<cv::Vec3b>(i,j/2)[2] = 255;
		    if (arr[i][j] == 1) maze.at<cv::Vec3b>(i,j/2)[0] = 0  ;   maze.at<cv::Vec3b>(i,j/2)[1] = 0  ; maze.at<cv::Vec3b>(i,j/2)[2] = 0  ;
		    if (arr[i][j] == 2) maze.at<cv::Vec3b>(i,j/2)[0] = 0  ;   maze.at<cv::Vec3b>(i,j/2)[1] = 255; maze.at<cv::Vec3b>(i,j/2)[2] = 0  ;
		    if (arr[i][j] == 3) maze.at<cv::Vec3b>(i,j/2)[0] = 255;   maze.at<cv::Vec3b>(i,j/2)[1] = 0  ; maze.at<cv::Vec3b>(i,j/2)[2] = 0  ;
		    if (arr[i][j] == 4) maze.at<cv::Vec3b>(i,j/2)[0] = 0  ;   maze.at<cv::Vec3b>(i,j/2)[1] = 0  ; maze.at<cv::Vec3b>(i,j/2)[2] = 255;
		}
	}

	namedWindow("SOLUTION", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "SOLUTION", maze);                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
