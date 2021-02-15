sudo apt update
sudo apt install xorg-dev libglu1-mesa-dev libglfw3-dev libsoil-dev libglm-dev cmake libglew-dev libstb-dev libeigen3-dev -y

cd ..

echo "Unpacking zip file(s)"
cp lovelyGameEngine/ZIP_FILES/glfw-3.2.1.zip .
7z x "glfw-3.2.1.zip" -oglfw-3.2.1


echo "Building glfw"
pushd ~/glfw-3.2.1/glfw-3.2.1/
sudo cmake -G "Unix Makefiles"
sudo make
sudo make install
popd

echo "Building nanogui"
pushd nanogui/build
cmake ..
make nanogui
sudo make install
popd

echo "NOTE: You have to move /usr/include/eigen3/Eigen to /usr/include/Eigen in order for nanogui to work"