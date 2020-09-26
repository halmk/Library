g++ -std=c++14 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_DEBUG -o $1.out $1.cpp
echo Done Build $1.cpp. $(date)
./$1.out
