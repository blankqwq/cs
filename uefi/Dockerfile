# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu:focal
# These commands copy your files into the specified directory in the image
# and set that as the working location
WORKDIR /data
COPY ./sources.list /etc/apt/sources.list
# This command compiles your app using GCC, adjust for your source code
# Install Software
RUN touch /etc/apt/apt.conf.d/99verify-peer.conf \
        && echo >>/etc/apt/apt.conf.d/99verify-peer.conf "Acquire { https::Verify-Peer false }"

RUN apt clean && apt-get update
RUN apt-get install build-essential -y
RUN apt-get install uuid-dev -y
RUN apt-get install make vim -y
RUN apt-get install iasl git -y
RUN apt-get install nasm -y
RUN apt-get install python3-distutils -y
RUN ln -s /usr/bin/python3.8 /usr/bin/python
# EXPOSE 8080
# RUN apt-get install clang -y
COPY init.sh init.sh
# This command runs your application, comment out this line to compile only
RUN bash init.sh

