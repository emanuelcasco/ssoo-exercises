FROM ubuntu:16.04

RUN apt-get update && apt-get install -y aptitude gcc cmake gdb git vim libncurses5 valgrind tig make autotools-dev strace emacs nano libcunit1 libevent1-dev ssh libfuse-dev build-essential g++ libcunit1-dev curl htop tree wget libreadline6 libreadline6-dev

WORKDIR /usr/src/
RUN git clone https://github.com/sisoputnfrba/so-commons-library.git
RUN git clone https://github.com/mumuki/cspec.git
RUN cd /usr/src/so-commons-library && make && make install
RUN cd /usr/src/cspec && make && make install

WORKDIR /workspace