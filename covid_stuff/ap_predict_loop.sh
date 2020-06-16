#!/bin/bash

p1=('--model 8' '--model 5' '--model 1')
p2=('--ic-50herg 5.62' '--ic-50herg 0.38' '--ic-50herg 70.8')
p3=('--ic50-cal 26.9' '--ic50-cal 1.9' '--ic50-ito 88.8')
p4=('--ic50-iks 9.33' '--ic50-na 331.2' '--ic50-iks 470')

mkdir -p ~/appredict

for index in ${!p1[@]}; do
    mkdir -p ~/appredict/testoutput$index
    docker run -it -d -v ~/appredict/testoutput$index:/home/appredict/apps/ApPredict/testoutput appredict-with-emulators:two_drugs apps/ApPredict/ApPredict.sh ${p1[index]} ${p2[index]} ${p3[index]} ${p4[index]} --plasma-conc-high 100 --plasma-conc-count 9 --plasma-conc-logscale True --no-downsampling True
done
