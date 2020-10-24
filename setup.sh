echo "Installing packages"
sudo pacman -Sy premake p7zip glm --noconfirm
sudo pip install cmake

cd ../

echo "Cloning SOIL repo"
git clone "https://github.com/kbranigan/Simple-OpenGL-Image-Library.git"

echo "Unpacking zip file(s)"
cp lovelyGameEngine/ZIP_FILES/glfw-3.2.1.zip .
7z x "glfw-3.2.1.zip" -oglfw-3.2.1


echo "Building glfw"
cd ~/glfw-3.2.1/glfw-3.2.1/
sudo cmake -G "Unix Makefiles"
sudo make
sudo make install

echo "Building SOIL"
cd ~/Simple-OpenGL-Image-Library/
make
sudo make install

echo "DONE"
