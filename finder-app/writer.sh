#!/bin/bash

writefile='default_writefile'
writestr='default_writestr'

if [[ $# -lt 2 ]]; then
	echo "Wrong arguments"
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p $(dirname $writefile)

if [[ -f $writefile ]]; then
	echo $writestr > $writefile
	echo "Success"
	exit 0
else 
	touch $writefile
	echo "Touch a new file"
	echo $writestr > $writefile
	exit 0
fi

exit 0

