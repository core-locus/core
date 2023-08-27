#!/bin/bash

function build_linux()
{
    docker build -t core-engine ./buildenv
    docker run --rm -v "$PWD":/usr/core core-engine make
}

# Default values
TARGETS=()
PROJECT="Sandbox"

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    key="$1"
    case $key in
        -tp|--target-platforms)
            TARGETS="$2"
            shift
            shift
            ;;
        -p|--project)
            PROJECT="$2"
            shift 
            shift
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Check if target architectures are specified and call the appropriate build function
if [[ -n "${TARGETS[*]}" ]]; then
    if [[ "${TARGETS[*]}" == *"Linux"* ]]; then
        build_linux "${TARGETS[*]}"
    else
        echo "Unsupported target architecture: ${TARGETS[*]}"
        exit 1
    fi
else
    make PROJECT=$PROJECT
fi