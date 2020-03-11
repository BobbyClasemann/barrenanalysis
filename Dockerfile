FROM cpp-build-base:0.1.0 AS build

WORKDIR /src

COPY CMakeLists.txt BarrenAnalysis.cc ./

RUN cmake . && make

FROM ubuntu:bionic

WORKDIR barren-analysis

COPY --from=build /src/barrenanalysis ./

CMD ["./barrenanalysis"]