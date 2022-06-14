FROM golang:1.17-alpine

RUN apk add binutils git gcc build-base
RUN go install github.com/go-delve/delve/cmd/dlv@master
WORKDIR /data