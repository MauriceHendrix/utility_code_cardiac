#!/bin/bash

# give image temporary tag, pull from docker hum & remove and replace original tag
keep_alive () {
    echo "tag $1 as docker-keepalive and remove tag $2"
    docker tag $1 docker-keepalive && docker rmi $2
    echo "pull $2 from docker hub and remove $2 again"
    docker pull $2 &&  docker rmi $2
    echo "retag $1 as $2 and remove docker-keepalive tag"
    docker tag $1 $2 && docker rmi docker-keepalive
    echo ""
}

# get cardiacmodelling images as array
readarray -t images_arr <<< $(docker image list --format "{{.ID}} {{.Repository}}:{{.Tag}}" | grep cardiacmodelling/)

# for each iamge apply keep alive
for image in "${images_arr[@]}"
do
    id_tag=($image) # split id and tag
    keep_alive ${id_tag[0]} ${id_tag[1]}
done