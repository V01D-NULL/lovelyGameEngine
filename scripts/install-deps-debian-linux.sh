sudo apt update
sudo apt install xorg-dev libglu1-mesa-dev libglfw3-dev libsoil-dev libglm-dev cmake libglew-dev -y

cd ..

echo "Unpacking zip file(s)"
cp lovelyGameEngine/ZIP_FILES/glfw-3.2.1.zip .
7z x "glfw-3.2.1.zip" -oglfw-3.2.1


echo "Building glfw"
cd ~/glfw-3.2.1/glfw-3.2.1/
sudo cmake -G "Unix Makefiles"
sudo make
sudo make install
