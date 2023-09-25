#!/bin/bash

filesdir='default_filesdir'
searchstr='default_searchdir'

if [[ $# -lt 2 ]]; then
	echo "Wrong arguments"
	exit 1
fi

filesdir=$1
searchstr=$2

if [[ ! -d "$filesdir" ]]; then
	echo "Wrong file directory"
	exit 1
fi

filenum=$(find -P $filesdir -type f | wc -l)
matchnum=$(grep -r $filesdir -e $searchstr | wc -l)

echo "The number of files are $filenum and the number of matching lines are $matchnum"
exit 0

