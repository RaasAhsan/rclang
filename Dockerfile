FROM gcc:11

RUN apt update && \
    apt install -y lsb-release wget software-properties-common flex bison && \
    bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
