# Install dependencies
sudo apt update
sudo apt install xorg-dev libglu1-mesa-dev libglfw3-dev libsoil-dev libglm-dev cmake libglew-dev libstb-dev libeigen3-dev python-dev -y

cd ..

# Build GLFW
GLFW_VER="3.3.2"

echo "Unpacking zip file(s)"
cp lovelyGameEngine/ZIP_FILES/glfw-$GLFW_VER.zip .
7z x "glfw-$GLFW_VER.zip" -oglfw-$GLFW_VER


echo "Building glfw"
pushd glfw-$GLFW_VER/glfw-$GLFW_VER/
sudo cmake -G "Unix Makefiles"
sudo make
sudo make install
popd

# Build nanogui
echo "Building nanogui"
mkdir lovelyGameEngine/nanogui/build
pushd lovelyGameEngine/nanogui/build
cmake ..
make
sudo make install
sudo cp "../ext/nanovg/src/nanovg.h" "/usr/include/nanovg.h"
popd

sudo mv "/usr/include/eigen3/Eigen" "/usr/include/Eigen"
