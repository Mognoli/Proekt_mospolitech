FROM ubuntu

WORKDIR /usr/src/
COPY resources /usr/src/


RUN apt update && apt -y install build-essential apt-utils && apt -y install gcc-snapshot g++ wget git
# зависимости QT
RUN DEBIAN_FRONTEND=noninteractive apt -y install libdbus-1-dev libx11-dev libx11-xcb-dev libfontconfig

RUN bash auth

# используется актуальная версия сервера
RUN git clone --branch release https://github.com/Mognoli/Proekt_mospolitech

# добавляет QT в $PATH (/bin/sh -c : qmake: not found ???, echo $PATH > )
ENV PATH="${PWD}/Qt/5.9.4/gcc_64/bin:${PATH}"
RUN ${PWD}/Qt/5.9.4/gcc_64/bin/qmake -makefile -o Makefile Proekt_mospolitech/ClientServerApp.pro && make

ENTRYPOINT ./ClientServerApp
