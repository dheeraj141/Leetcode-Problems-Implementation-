#!/bin/sh
 
FIRST_ARGUMENT="$1"
echo "Hello, world $FIRST_ARGUMENT!"

git add --all 
git commit -m $FIRST_ARGUMENT
git push -u origin master
