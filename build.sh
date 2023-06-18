docker build -t core-engine ./buildenv
docker run --rm -v "$PWD":/src -w /usr/src/ gcc:4.9 make