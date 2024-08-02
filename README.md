# HelloWorld_yojimbo

Quickstart for using the yojimbo network library for UDP client/server games written in C++

**Note: this guide is for Windows users.**

## Installation

For now, there are two options available for installing the yojimbo library:

- Windows
- Docker Desktop for Windows (Linux container)

## Install for Windows

Coming soon...

## Install for Docker (Linux container)

First install [Docker Desktop](https://www.docker.com/) for Windows.

Once installed, open a PowerShell terminal and do the following:

```
docker pull ubuntu
docker run -it ubuntu /bin/bash
```

You should now be logged on to a running Ubuntu container.

```
container# apt update
container# apt install -y wget tar
```
In a browser, navigate to the GitHub website for the official yojimbo library.

https://github.com/mas-bandwidth/yojimbo

Click on the Releases link and copy the URL for the latest stable release. E.g.

\<URL\> = https://github.com/mas-bandwidth/yojimbo/archive/refs/tags/v1.2.3.tar.gz



```
container# wget -P ~/ <URL>
container# cd ~
container# tar -xvzf v1.2.3.tar.gz
container# mkdir /deps
container# mv yojimbo-1.2.3 /deps
```

We are now close to being able to build yojimbo. The rest of the steps follow closely the yojimbo repo file `BUILDING.md` located here:

`/deps/yojimbo-1.2.3/BUILDING.md`

And the actual HelloWorld_yojimbo C++ example follows closely the `USAGE.md` repo file located here, with some tweaks:

`/deps/yojimbo-1.2.3/USAGE.md`

Next, install some common dev tools:

```
container# apr install -y cmake build-essential git
```

Then, download and install [premake 5](https://premake.github.io/download). You want the one, *Linux* under *Pre-Built Binaries*

Copy the download \<URL\> e.g.

https://github.com/premake/premake-core/releases/download/v5.0.0-beta2/premake-5.0.0-beta2-linux.tar.gz

```
container# cd /deps
container# wget <URL>
container# tar -xvzf premake-5.0.0-beta2-linux.tar.gz
container# mv premake5 /usr/local/bin
```
Next, install libsodium.

```
container# apt install libsodium-dev
```

Now go to the yojimbo directory in `/deps` and build the yojimbo library:

```
container# cd yojimbo
container# premake5 gmake
container# make -j
```

Run the unit tests:

```
container# .bin/test
```

Run the server test program on localhost on UDP port 40000

```
container# ./bin/server
```

Run the client test program that connects to the local server in a separate terminal. First, open another Windows PowerShell terminal and find the running Ubuntu \<CONTAINER_ID\> using `docker ps`:

```
docker ps
```

Now connect to it.

```
docker exec -it <CONTAINER_ID> /bin/bash
```

And run the client.

```
container# cd /deps/yojimbo-1.2.3
container# ./bin/client
```

## HelloWorld_yojimbo (Linux)

Clone the repo if you haven't already done so.

```
container# cd ~
container# git clone https://github.com/odinphillips/HelloWorld_yojimbo.git
```

## Build

```
cd HelloWorld_yojimbo
mkdir build
cd build
cmake ..
make -j
```

Two executable files should have been created in the current `build/` directory.

`HelloWorld_yojimbo_server`

`HelloWorld_yojimbo_client`

First, run the server HelloWorld program:

```
container ./HelloWorld_yojimbo_server
```

Then in the separate terminal, run the client HelloWorld program:

```
container# ./HelloWorld_yojimbo_client
```

The client program has the following key inputs:

- Press \<SPACE\> to send a UDP message to the server, that will bounce back to the client.
- Press \<Q\> to disconnect and quit the client program.

Then server program can be terminated with \<Ctrl-C\>.
