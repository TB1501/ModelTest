#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>


int main() {

	//Load the trained model
	cv::Ptr<cv::ml::ANN_MLP> mlp = cv::ml::ANN_MLP::load("./TrainedModel/trData1.xml");
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
	cv::Mat testImage = cv::imread("./TestSamples/img_0.jpg", cv::IMREAD_GRAYSCALE);

	//resize the image to the image size that we made the model from
	cv::resize(testImage, testImage, cv::Size(28, 28));


	//Flatten the image
	cv::Mat flattenedImage = testImage.reshape(1, 1);
	cv::Mat input;
	flattenedImage.convertTo(input, CV_32F);


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
	std::cout << "Predicted number: " << predictedClass << " With confidence: " << confidence << std::endl;

	return 0;

}