#!/bin/sh
find . -name "*.sh" -exec basename {} \;| awk '{ print substr($1, 0, length-3) }'
