#!/bin/sh
for ((i=1; i<=5; i++));
do
  $ARG="`ruby -e "puts (1...50).to_a.shuffle.join(' ')"`" ; 
  ./push_swap $ARG 
  echo $ARG
done