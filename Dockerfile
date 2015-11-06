FROM ubuntu

RUN apt-get update
RUN apt-get install -y build-essential

ADD . /projectroot

WORKDIR /projectroot

RUN make
