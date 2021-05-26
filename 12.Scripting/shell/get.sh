#!/bin/bash
echo "Getting the value"

cat data.db | grep $1 | tail -n 1 |sed -e "s/$1,//"

