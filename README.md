# ModelTest

This is a program for testing the efficiency of the training model generated using the OpenCV library.

---

INSTALLING OpenCV IN VISUAL STUDIO

OpenCV (Open Source Computer Vision Library) is a library of programming functions mainly for real-time computer vision.
Originally developed by Intel, it was later supported by Willow Garage, then Itseez (which was later acquired by Intel).
The library is cross-platform and licensed as free and open-source software under Apache License 2

In order to get started with OpenCV go to the official website: [OpenCV](https://opencv.org/).
On the website go to the Library page and download the required version (I used OpenCV version 4.10.0).
Download the appropriate .exe file for the device and run it.

In order for OpenCV to work the project needs to be configured. In project properties configure the VC++ Directories, the Include Directories and Library Directories.
In the Include Directories the path to the include folder in OpenCV folder needs to be specified (.\opencv\build\include). In the Library Directories the path to the
lib files needs to be specified (.\opencv\build\x64\vc16\lib). After configuring the VC++ Directories the Linker also needs to be configured.
In Input add the required opencv.lib files (opencv_world4100.lib and opencv_world4100d.lib).

Before running the compiled .exe file, the opencv.lib files need to be added to the release or debug folders where the .exe was created.

---

MODEL DESCRIPTION

In the program we load an image of a handwritten numbers in the range 0-9. The images must be manually changed. The names of the images are img_0.jpg to img_9.jpg.
To change images just select a different number. Using the OpenCV library we process the image to the size and format for further analyzing.
With OpenCV we create a machine learning object (the mlp here). Using OpenCVs built in function: predict we analyze the input picture with the trained model. The outputs are the
statistical values of model predictions for the numbers. The number with the highest statistical value is what the model thinks is in the input image.
