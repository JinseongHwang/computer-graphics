#!/usr/bin/env bash

FILE=$1
gcc ${FILE} -lglut -lGL -lGLU -lm -lstdc++
./a.out
echo ">>> RUN OpenGL Application : ${FILE}"
