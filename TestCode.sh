#!/bin/sh
for i in {0..11}
    do
    mkdir -p Result
    touch Result/Result$i.csv
    echo "hour,minute,degree" >> Result/Result$i.csv
    for j in {0..59}
        do
        ./3-1-2 $i $j >> Result/Result$i.csv
        done
    done

