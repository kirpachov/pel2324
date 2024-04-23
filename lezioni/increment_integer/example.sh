echo "Not optimized:"

g++ increment_integer_inside_loop.cpp -o /tmp/gigi && time /tmp/gigi

echo "\n\nOptimized:"

g++ increment_integer_inside_loop.cpp -o /tmp/gigi -O3 && time /tmp/gigi
