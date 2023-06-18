#!/bin/bash
bash build.sh "$@"

# Determine the operating system
unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     os=Linux;;
    Darwin*)    os=Mac;;
    CYGWIN*)    os=Windows;;
    MINGW*)     os=Windows;;
    *)          os="UNKNOWN:${unameOut}"
esac

dist/$os/core-engine