echo "Building mythreads."
g++ mythreads.cpp -o mythreads -g -lpthread
echo "Running mythreads."
gdb ./mythreads $1
echo "Running deleteOldObj.sh"
sh deleteOldObj.sh
echo "Terminating."
