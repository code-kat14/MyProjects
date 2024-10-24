# Welcome to My Ls
***

## Task
Recreate ls command with correct flags `-a` for printing all files (including hidden files) <br>
`-t` for printing files according for time modified(most recent first) <br>
$> ./my_ls -> for printing all none hidden files in dir in lexicographical order

## Description
Understanding how to open and manipulate files inside a directory, with sorting algorithms, string manipulation, and the use of stat and lstat, and becoming familiar with the memebers of the dirent struct that is returned on each file(information about the file). I decided to put my filenames and times into an array to be bubble sorted, then printed out based on criteria and flags entered by user. Recreating being able to use multiple flags and passing different dir into input.
*note* although I realize the bubble sort algorthim can be optimized, I wanted to understand what my code was doing under the hood before i went to optimizing.

## Installation
`$> make`
`$> ./my_ls -flag`

OR

`$> ./my_ls -flag directory`

## Usage
Various options are listed below:
``` 
1. ./ls 
2. ./ls -t
3. ./ls -a 
4. ./ls -ta 
5. ./ls -at
6. ./ls -flag flag directory
```


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>