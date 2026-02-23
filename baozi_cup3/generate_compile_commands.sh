#!/bin/bash
DIR=$(cd $(dirname $0); pwd)
echo $DIR
rm -f $DIR/compile_commands.json && bazel run //:refresh_compile_commands