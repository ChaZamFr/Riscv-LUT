FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update 
RUN apt-get upgrade -y

VOLUME /root/env
WORKDIR /root/env