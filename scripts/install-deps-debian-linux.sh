# Install dependencies
sudo apt update
sudo apt install xorg-dev libglu1-mesa-dev libglfw3-dev libsoil-dev libglm-dev cmake libglew-dev -y

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
