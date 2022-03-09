# This doesn't serve any purpose, will look into it in later releases
gcc -O2 -Wall $(pkg-config --cflags vte-2.91) term.c -o term $(pkg-config --libs vte-2.91) & ./term