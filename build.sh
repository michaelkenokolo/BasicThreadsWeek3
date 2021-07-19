echo "Building mythreads."
g++ mythreads.cpp -o mythreads -lpthread
echo "Running mythreads."
./mythreads $1
echo "Running deleteOldObj.sh"
#sh deleteOldObj.sh
echo "Terminating."
