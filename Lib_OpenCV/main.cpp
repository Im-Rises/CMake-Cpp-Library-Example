#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Create a black window
    Mat window = Mat::zeros(512, 512, CV_8UC3);

    // Draw a rectangle on the window
    rectangle(window, Point(100, 100), Point(400, 400), Scalar(0, 0, 255), 2);

    // Display the window
    imshow("Window", window);

    // Wait for a key press
    waitKey(0);

    // Close all windows
    destroyAllWindows();

    return 0;
}
