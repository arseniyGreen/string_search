#!/bin/sh

echo "Updating remote..."
git add -A
git commit -m Updated
git push
echo "Remote updated"