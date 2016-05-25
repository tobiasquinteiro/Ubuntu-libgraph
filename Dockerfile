# Ubuntu image with libgraph installed for Graphics programming

FROM ubuntu:latest
MAINTAINER trishnag <trishnaguha17@gmail.com>

RUN apt-get -y update
RUN apt-get -y install wget
RUN apt-get -y install g++
RUN apt-get -y install build-essential
RUN apt-get -y install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 \
 guile-1.8-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev \
 libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev \
 libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev \
 libslang2-dev libasound2 libasound2-dev

RUN wget http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz
RUN tar -xvzf libgraph-1.0.2.tar.gz
WORKDIR "/libgraph-1.0.2"
RUN ./configure
RUN make
RUN make install
RUN cp /usr/local/lib/libgraph.* /usr/lib
WORKDIR "/"
RUN mkdir /Demo
WORKDIR "/Demo"
RUN wget https://raw.githubusercontent.com/trishnaguha/Ubuntu-libgraph/master/test.c
WORKDIR "/"
