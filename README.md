# ModelTest

This is a program for testing the efficiency of the training model generated using the OpenCV library.

---

INSTALLING OpenCV IN VISUAL STUDIO

OpenCV (Open Source Computer Vision Library) is a library of programming functions mainly for real-time computer vision.
Originally developed by Intel, it was later supported by Willow Garage, then Itseez (which was later acquired by Intel).
The library is cross-platform and licensed as free and open-source software under Apache License 2

In order to get started with OpenCV go to the official website: [OpenCV](https://opencv.org/).
On the website go to Library and install the requiered version (in this code i used OpenCv version 4.10.0).
Click on tha appropriate device you are downloading for (I'm using windows).
OpenCV willcdownload as an exe file. You only need to click on the file and file will autoconfigure.
When setting the path it is best to set a path that is at the begginig of your disk.

In order for OpneCV to work Visual Studio we need to configure the project. Create a new Visual Studio project and go to project properties.
In properties go to VC++ Directories -> Include Directories -> edit the static path to the .\opencv\build\include folder. Don't forget
to click on the box "Inherit from parent or project defaults". Next got to VC++ Directories -> Library Directories -> edit the static path lib folder
.\opencv\build\x64\vc16(or some other compiled binary)\lib. Also, click on "Inherit from parent or project defaults". Next go to
Linker -> Input -> Additional Dependencies -> edit the lib data. Here you have to add the lib files in the vc16\lib folder.
I added the opencv_world4100.lib and opencv_world4100d.lib files. It is important that the file without d at the end (debug) goes second becaus
when building there could be issues. Again, click on "Inherit from parent or project defaults".

In the last step you have to edit the system variables. Type in searc Edit the system environment variables. Go to page Advanced and clik on
Environmet Variables.... Next go to System variables -> Path and click Edit. Add the paths to .\opencv\build\x64\vc16\lib and
.\opencv\build\x64\vc16\bin.

It is useful to restart the VS project so the setup gets properly loaded.

---

MODEL DESCRIPTION

In the program we load an image of a handwritten numbers in the range 0-9. The images must be manually changed. The names of the images are img_0.jpg to img_9.jpg.
To change images just select a different number. Using the OpenCV library we process the image to the size and format for further analyzing.
With OpenCV we create a machine learning object (the mlp here). Using OpenCVs built in function: predict we analyze the input picture with the trained model. The outputs are the
statistical values of model predictions for the numbers. The number with the highest statistical value is what the model thinks is in the input image.
