#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
#include "roundNumber.h"

int main() {

	//Load the trained model
	cv::Ptr<cv::ml::ANN_MLP> mlp = cv::ml::ANN_MLP::load("C:\\Users\\Tin\\Desktop\\newtrainData\\trData3.xml");
	if (mlp.empty()) {
		std::cerr << "Error: Failed to load the model." << std::endl;
		return -1;
	}else {
	 std::cout << "Model loaded successfully." << std::endl;
	}

	if (!mlp.empty()) {
		cv::Mat layerSizes = mlp->getLayerSizes();
		std::cout << "Number of layers: " << layerSizes.rows << std::endl;
		std::cout << "Layer sizes: " << layerSizes << std::endl;
	}

	//Load the image you want to classify
	cv::Mat testImage = cv::imread("C:\\Users\\Tin\\Desktop\\Vsite\\3 godina\\Zavrsni\\ModelTest\\TestSamples\\img_9.jpg", cv::IMREAD_GRAYSCALE);

	//resize the image to the image size that we made the model from
	cv::resize(testImage, testImage, cv::Size(28, 28));



	//Flatten the image
	cv::Mat flattenedImage = testImage.reshape(1, 1);
	cv::Mat input;
	cv::Mat input_Normalized;
	flattenedImage.convertTo(input, CV_32F);


	for (int row = 0; row < input.rows; ++row)
	{
		for (int col = 0; col < input.cols; ++col)
		{
			float value = input.at<float>(row, col);
			// Rounding the value to 4 decimal places
			input.at<float>(row, col) = roundNumber(value, 10000);
		}
	}

	std::cout << input_Normalized.size;

	

	//Perform prediction
	cv::Mat output;
	mlp->predict(input, output);
	std::cout << output;

	//Find the class with the highest probability
	cv::Point classIdPoint;
	double confidence;
	cv::minMaxLoc(output, nullptr, &confidence, nullptr, &classIdPoint);

	int predictedClass = classIdPoint.x;

	//Display the result
	std::cout << "Predicted class: " << predictedClass << " With confidence: " << confidence << std::endl;

	return 0;

}