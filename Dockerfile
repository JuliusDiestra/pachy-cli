FROM ubuntu:20.04

ARG USER_ID
ARG GROUP_ID

RUN addgroup --gid $GROUP_ID user
RUN adduser --disabled-password --gecos '' --uid $USER_ID --gid $GROUP_ID user

# General
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y cmake \
                       git \
                       build-essential \
                       valgrind \
                       wget \
                       software-properties-common \
                       libtool \
                       libtool-bin \
                       apt-transport-https \
                       curl \
                       gnupg

# clang-format & clang-tidy
RUN wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc
RUN apt-add-repository "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-15 main"
RUN apt-get update
RUN apt-get install -y clang-15 \
                       clang-format-15 \
                       clang-tidy-15

# LibYaml
RUN git clone -q https://github.com/yaml/libyaml.git /libyaml \
  && cd /libyaml \
  && git checkout 0.2.5 \
  && ./bootstrap \
  && ./configure \
  && make \
  && make install

# Bazel
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
RUN mv bazel-archive-keyring.gpg /usr/share/keyrings
RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y bazel

# Google Test
RUN git clone -q https://github.com/google/googletest.git /googletest \
  && mkdir -p /googletest/build \
  && cd /googletest/build \
  && cmake .. && make && make install \
  && cd / && rm -rf /googletest

RUN apt-get clean && \
    rm -rf /var/lib/apt/lists

# Create working directory with applications
WORKDIR /tmp/workspace

USER user

