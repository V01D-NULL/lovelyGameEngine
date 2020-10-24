echo "Installing packages"
sudo pacman -Sy premake p7zip glm --noconfirm
sudo pip install cmake

cd ../

echo "Cloning SOIL2 repo"
git clone "https://github.com/SpartanJ/SOIL2.git"

echo "Unpacking zip file(s)"
cp lovelyGameEngine/ZIP_FILES/glfw-3.2.1.zip .
7z x "glfw-3.2.1.zip" -oglfw-3.2.1


echo "Building glfw"
cd ~/glfw-3.2.1/glfw-3.2.1/
sudo cmake -G "Unix Makefiles"
sudo make
sudo make install

echo "Building SOIL2"
cd ~/SOIL2/
premake5 gmake
cd make/linux
make

echo "DONE"
