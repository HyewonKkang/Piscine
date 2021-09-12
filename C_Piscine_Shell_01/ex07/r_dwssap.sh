#!/bin/sh
cat /etc/passwd | grep -v '^#' | awk '{if (NR%2==0) print $0}' | awk -F : '{print $1}' | rev | sort -r | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" '{if (NR >= FT_LINE1 && NR <= FT_LINE2) print $0}' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./' | tr -d '\n'
