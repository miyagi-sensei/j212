#!/bin/bash

# solution.cpp  solution you want to stress test
# brute.cpp    stupid solution for the problem
# gen.py       generates a new random test case for the problem

# compile all programs first
g++ demo.cpp
g++ brute.cpp -o brute
# g++ gen.cpp -o gen

for ((i = 1; ;i++)) do
  # generate a new test case in the file named "in"
  python3 gen.py > in
  # redirect the solution output to the "out" file
  ./a.out < in > out
  # redirect the stupid solution output to the "out-stupid" file
  ./brute < in > out-correct

  # compare both outputs.
  # if outputs are different, echo the 
  # corresponding message and break the loop.
  # failing test will be in the "in" file.
  if ! cmp -s out out-correct
  then
    echo 'Found failing test!'
    break
  fi

  # if outputs are the same, we echo "OK".
  # this is optional, but helps to see the progress of stress testing.
  echo 'OK'
done