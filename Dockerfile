FROM tomcat0x42/cppdev:latest AS builder

USER cppdev
WORKDIR /home/cppdev/aon

COPY --chmod=0755 --chown=cppdev:cppdev . ./

RUN xrepo install -y gtest
RUN xrepo install -y pybind11
RUN xmake build -y
RUN ls

FROM ubuntu:23.04 AS runner

WORKDIR /aon

COPY --from=builder \
    /home/cppdev/aon/aon \
    ./

ENTRYPOINT ["/aon/aon"]
