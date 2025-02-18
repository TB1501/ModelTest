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
In Input add the required opencv.lib files. For running the release version the opencv_world4100.lib needs to be added and for the debug version the opencv_world4100d.lib.

Before running the release or debug .exe file copy the opencv_world4100.dll to the location of the release .exe or the opencv_world4100d.dll to the location of the
debug .exe

---

MODEL DESCRIPTION

The program tests the efficiency of the trained model. In the first step the model and the image for classification are loaded. The trained model and image are loaded
to a format and preprocessed to comply with OpenCV standards. The solution outputs the statistical possibilities of classes on which it predicts the number in the image.
