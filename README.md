# HelloWorld_yojimbo

Quickstart for using the yojimbo network library for UDP client/server games written in C++

**Note: this guide is for Windows users.**

## Installation

For now, we will consider two ways of installing the yojimbo library:

- Windows (msys ucrt)
- Docker Desktop for Windows (Linux Ubuntu container)

## Install for Windows (msys ucrt)

First, download and install [premake 5](https://premake.github.io/download) for windows.

Add its path to the PATH variable (e.g. in msys `ucrt` terminal, update the `~/.bash_profile` to include it in the PATH).

E.g. open an msys ucrt terminal.

```
~ vim .bash_profile
```

Then add to the PATH variable like this:

```
PATH=$PATH:"/c/Program Files (x86)/premake-5.0.0-beta2-windows"
```

Save and exit *vim*, then verify that everything is working correctly:

```
source .bash_profile
echo $PATH
premake5 --version
```

Now install the *sodium* library:

```
pacman -Ss sodium
pacman -S ucrt64/mingw-w64-ucrt-x86_64-libsodium
```

Next, download the *yojimbo* library:

(First, create a directory that we will store the yojimbo library in.)

```
mkdir /deps
```

In a browser, navigate to the GitHub website for the official yojimbo library.

https://github.com/mas-bandwidth/yojimbo

Click on the Releases link and download the latest stable release. E.g.
https://github.com/mas-bandwidth/yojimbo/archive/refs/tags/v1.2.3.zip

And copy it to `C:\msys64\deps\` so that you have something like this:

`C:\msys64\deps\yojimbo-1.2.3`

Now you can start building the library.

```
cd /deps/yojimbo-1.2.3
premake5 gmake
make -j
```
...

> WARNING!
>
> At this point, you may get a lot of compilation errors, like I did. :(
>

<details>
<summary><b><u>Error logs</u></b></summary>

```bash  
odinp@Moon UCRT64 /deps/yojimbo-1.2.3
$ make -j
==== Building sodium-builtin (debug) ====
==== Building netcode (debug) ====
==== Building reliable (debug) ====
==== Building tlsf (debug) ====
==== Building yojimbo (debug) ====
Creating obj/Debug/netcode
Creating bin/Debug
Creating obj/Debug/reliable
Creating bin/Debug
Creating obj/Debug/tlsf
Creating bin/Debug
netcode.c
reliable.c
tlsf.c
Creating obj/Debug/yojimbo
yojimbo.cpp
yojimbo_address.cpp
yojimbo_allocator.cpp
yojimbo_base_client.cpp
yojimbo_base_server.cpp
yojimbo_channel.cpp
yojimbo_client.cpp
yojimbo_connection.cpp
yojimbo_network_simulator.cpp
yojimbo_platform.cpp
yojimbo_reliable_ordered_channel.cpp
yojimbo_server.cpp
source/yojimbo_address.cpp:31: error: "NOMINMAX" redefined [-Werror]
   31 |     #define NOMINMAX
      |
In file included from C:/msys64/ucrt64/include/c++/13.2.0/x86_64-w64-mingw32/bits/c++config.h:679,
                 from C:/msys64/ucrt64/include/c++/13.2.0/cstdlib:41,
                 from C:/msys64/ucrt64/include/c++/13.2.0/stdlib.h:36,
                 from C:/msys64/ucrt64/include/assert.h:17,
                 from serialize/serialize.h:31,
                 from include/yojimbo_constants.h:28,
                 from include/yojimbo_config.h:28,
                 from include/yojimbo_address.h:28,
                 from source/yojimbo_address.cpp:25:
C:/msys64/ucrt64/include/c++/13.2.0/x86_64-w64-mingw32/bits/os_defines.h:45: note: this is the location of the previous definition
   45 | #define NOMINMAX 1
      |
yojimbo_unreliable_unordered_channel.cpp
yojimbo_utils.cpp
Linking tlsf
Linking reliable
source/yojimbo_platform.cpp:171: error: "NOMINMAX" redefined [-Werror]
  171 | #define NOMINMAX
      |
In file included from C:/msys64/ucrt64/include/c++/13.2.0/x86_64-w64-mingw32/bits/c++config.h:679,
                 from C:/msys64/ucrt64/include/c++/13.2.0/cstdlib:41,
                 from C:/msys64/ucrt64/include/c++/13.2.0/stdlib.h:36,
                 from C:/msys64/ucrt64/include/assert.h:17,
                 from serialize/serialize.h:31,
                 from Creating obj/Debug/sodium-builtin
include/yojimbo_constants.h:28,
                 from include/yojimbo_config.h:28,
                 from dummy.c
include/yojimbo_platform.h:28,
                 from sodium_aead_chacha20poly1305.c
sodium_aead_xchacha20poly1305.c
source/yojimbo_platform.cpp:25:
C:/msys64/ucrt64/include/c++/13.2.0/x86_64-w64-mingw32/bits/os_defines.h:45: note: this is the location of the previous definition
   45 | #define NOMINMAX 1
      |
sodium_blake2b-compress-avx2.c
sodium_blake2b-compress-ref.c
sodium_blake2b-compress-sse41.c
sodium_blake2b-compress-ssse3.c
source/yojimbo_address.cpp:36: error: ignoring '#pragma comment ' [-Werror=unknown-pragmas]
   36 |     #pragma comment( lib, "WS2_32.lib" )
      |
sodium_blake2b-ref.c
sodium_box_curve25519xchacha20poly1305.c
sodium_box_curve25519xsalsa20poly1305.c
sodium_box_seal_curve25519xchacha20poly1305.c
sodium_chacha20-ref.c
sodium_codecs.c
sodium_core.c
sodium_core_ed25519.c
sodium_core_hchacha20.c
sodium_core_hsalsa20.c
sodium_core_hsalsa20_ref2.c
sodium_core_salsa_ref.c
sodium_crypto_box.c
sodium_crypto_box_easy.c
netcode/netcode.c:151: error: ignoring '#pragma comment ' [-Werror=unknown-pragmas]
  151 |     #pragma comment( lib, "WS2_32.lib" )
      |
netcode/netcode.c:152: error: ignoring '#pragma comment ' [-Werror=unknown-pragmas]
  152 |     #pragma comment( lib, "IPHLPAPI.lib" )
      |
netcode/netcode.c:159: error: ignoring '#pragma comment ' [-Werror=unknown-pragmas]
  159 |     #pragma comment( lib, "IPHLPAPI.lib" )
      |
netcode/netcode.c:184:17: error: conflicting types for 'inet_ntop'; have 'const char *(int,  const void *, char *, socklen_t)' {aka 'const char *(int,  const void *, char *, int)'}sodium_crypto_generichash.c

  184 |     const char *inet_ntop(int af, const void *src, char *dst, socklen_t cnt)
      |                 ^~~~~~~~~
In file included from netcode/netcode.c:148:
C:/msys64/ucrt64/include/ws2tcpip.h:402:35: note: previous declaration of 'inet_ntop' with type 'const CHAR *(INT,  const void *, CHAR *, size_t)' {aka 'const char *(int,  const void *, char *, long long unsigned int)'}
  402 | WINSOCK_API_LINKAGE LPCSTR WSAAPI InetNtopA(INT Family, LPCVOID pAddr, LPSTR pStringBuf, size_t StringBufSize);
      |                                   ^~~~~~~~~sodium_crypto_kx.c

netcode/netcode.c:347:9: error: 'inet_pton' redeclared without dllimport attribute: previous dllimport ignored [-Werror=attributessodium_crypto_scalarmult.c
]
  347 |     int inet_pton(int af, const char *src, void *dst)sodium_crypto_secretbox.c

      |         ^~~~~~~~~sodium_crypto_secretbox_easy.c

netcode/netcode.c: In function 'netcode_socket_create':
netcode/netcode.c:645:20: error: comparison is always false due to limited range of data type [-Werror=type-limits]
  645 |     if ( s->handle == INVALID_SOCKET )
      |                    ^~
sodium_crypto_sign.c
sodium_dolbeau_chacha20-avx2.c
sodium_dolbeau_chacha20-ssse3.c
sodium_generichash_blake2.c
sodium_generichash_blake2b.c
sodium_hash_sha512.c
sodium_hash_sha512_cp.c
sodium_onetimeauth_poly1305.c
sodium_poly1305-sse2.c
cc1.exe: all warnings being treated as errorssodium_poly1305_donna.c

sodium_randombytes.c
sodium_randombytes_salsa20_random.c
make[1]: *** [netcode.make:129: obj/Debug/netcode/netcode.o] Error 1
make: *** [Makefile:51: netcode] Error 2
make: *** Waiting for unfinished jobs....
sodium_randombytes_sysrandom.c
sodium_ref10_ed25519.c
sodium_ref10_keypair.c
sodium_ref10_open.c
sodium_ref10_scalarmult_ed25519_ref10.c
sodium_ref10_sign.c
sodium_ref10_x25519.c
sodium_runtime.c
sodium_salsa20-ref.c
sodium_salsa20-xmm6.c
cc1plus.exe: all warnings being treated as errors
sodium_sandy2x_curve25519.c
sodium_sandy2x_fe51_invert.c
make[1]: *** [yojimbo.make:145: obj/Debug/yojimbo/yojimbo_address.o] Error 1
sodium_sandy2x_fe_frombytes.c
sodium_scalarmult_curve25519.c
sodium_secretbox_xchacha20poly1305.c
make[1]: *** Waiting for unfinished jobs....
sodium_secretbox_xsalsa20poly1305.c
sodium_sign_ed25519.c
sodium_stream_chacha20.c
sodium_stream_salsa20.c
sodium_stream_xchacha20.c
sodium_stream_xsalsa20.c
sodium_utils.c
sodium_verify.c
sodium_version.c
cc1plus.exe: all warnings being treated as errors
sodium_xmm6int_salsa20-avx2.c
sodium_xmm6int_salsa20-sse2.c
make[1]: *** [yojimbo.make:169: obj/Debug/yojimbo/yojimbo_platform.o] Error 1
make: *** [Makefile:69: yojimbo] Error 2
sodium/sodium_randombytes_salsa20_random.c:120:1: error: 'thread' attribute directive ignored [-Werror=attributes]
  120 | static TLS Salsa20Random stream;
      | ^~~~~~
cc1.exe: all warnings being treated as errors
make[1]: *** [sodium-builtin.make:303: obj/Debug/sodium-builtin/sodium_randombytes_salsa20_random.o] Error 1
make[1]: *** Waiting for unfinished jobs....
make: *** [Makefile:45: sodium-builtin] Error 2

odinp@Moon UCRT64 /deps/yojimbo-1.2.3
$
```

</details>

I managed to fix all these errors, albeit with some hacking in their codebase. Feel free to use the patch below to fix these errors. No guarantee that this will fix all your errors; there maybe other errors specific to your system.

*(**NOTE**: the patch file is available in `/patch` directory of this repo.)*

<details>
<summary><b><u>yojimbo_v1.2.3_windows_msys_ucrt.patch</u></b></summary>

```diff
diff --git a/netcode/netcode.c b/netcode/netcode.c
index e975614..e7dcef0 100755
--- a/netcode/netcode.c
+++ b/netcode/netcode.c
@@ -148,15 +148,17 @@ void netcode_default_free_function( void * context, void * pointer )
     #include <ws2tcpip.h>
     #include <ws2ipdef.h>
     #include <iphlpapi.h>
-    #pragma comment( lib, "WS2_32.lib" )
-    #pragma comment( lib, "IPHLPAPI.lib" )
+    // NOTE(odin)
+    // #pragma comment( lib, "WS2_32.lib" )
+    // #pragma comment( lib, "IPHLPAPI.lib" )
 
     #ifdef SetPort
     #undef SetPort
     #endif // #ifdef SetPort
 
     #include <iphlpapi.h>
-    #pragma comment( lib, "IPHLPAPI.lib" )
+    // NOTE(odin)
+    // #pragma comment( lib, "IPHLPAPI.lib" )
     
 #elif NETCODE_PLATFORM == NETCODE_PLATFORM_MAC || NETCODE_PLATFORM == NETCODE_PLATFORM_UNIX
 
@@ -180,7 +182,9 @@ void netcode_default_free_function( void * context, void * pointer )
 
 // ----------------------------------------------------------------
 
-#ifdef __MINGW32__
+// NOTE(odin)
+// #ifdef __MINGW32__
+#if 0
     const char *inet_ntop(int af, const void *src, char *dst, socklen_t cnt)
     {
         if ( af == AF_INET )
@@ -642,7 +646,9 @@ int netcode_socket_create( struct netcode_socket_t * s, struct netcode_address_t
     s->handle = socket( ( address->type == NETCODE_ADDRESS_IPV6 ) ? AF_INET6 : AF_INET, SOCK_DGRAM, IPPROTO_UDP );
 
 #if NETCODE_PLATFORM == NETCODE_PLATFORM_WINDOWS
-    if ( s->handle == INVALID_SOCKET )
+    // NOTE(odin)
+    // if ( s->handle == INVALID_SOCKET )
+    if ( s->handle == (netcode_socket_handle_t)(INVALID_SOCKET) )
 #else // #if NETCODE_PLATFORM == NETCODE_PLATFORM_WINDOWS
     if ( s->handle <= 0 )
 #endif // #if NETCODE_PLATFORM == NETCODE_PLATFORM_WINDOWS
diff --git a/premake5.lua b/premake5.lua
index f2f1f71..aec4235 100644
--- a/premake5.lua
+++ b/premake5.lua
@@ -61,38 +61,58 @@ project "yojimbo"
 project "client"
     files { "client.cpp", "shared.h" }
     filter "system:windows"
-        links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
     filter "system:not windows"
-        links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+        -- NOTE(odin)
+		-- links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+		links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
 
 project "server"
     files { "server.cpp", "shared.h" }
     filter "system:windows"
-        links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
     filter "system:not windows"
-        links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+        -- NOTE(odin)
+		-- links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+		links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
 
 project "loopback"
     files { "loopback.cpp", "shared.h" }
     filter "system:windows"
-        links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
     filter "system:not windows"
-        links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
 
 project "soak"
     files { "soak.cpp", "shared.h" }
     filter "system:windows"
-        links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
     filter "system:not windows"
-        links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
 
 project "test"
     files { "test.cpp" }
     defines { "SERIALIZE_ENABLE_TESTS=1" }
     filter "system:windows"
-        links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+		-- links { "yojimbo", "sodium-builtin", "tlsf", "netcode", "reliable" }
+		links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi"}
     filter "system:not windows"
-        links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+		-- NOTE(odin)
+        -- links { "yojimbo", "sodium", "tlsf", "netcode", "reliable" }
+        links { "yojimbo", "sodium-builtin", "sodium", "tlsf", "netcode", "reliable", "WS2_32", "iphlpapi" }
 
 newaction
 {
diff --git a/sodium/sodium_randombytes_salsa20_random.c b/sodium/sodium_randombytes_salsa20_random.c
index 2cf65f5..d3bbf37 100644
--- a/sodium/sodium_randombytes_salsa20_random.c
+++ b/sodium/sodium_randombytes_salsa20_random.c
@@ -91,7 +91,9 @@ BOOLEAN NTAPI RtlGenRandom(PVOID RandomBuffer, ULONG RandomBufferLength);
 
 #ifndef TLS
 # ifdef _WIN32
-#  define TLS __declspec(thread)
+// NOTE(odin)
+// #  define TLS __declspec(thread)
+#  define TLS __thread
 # else
 #  define TLS
 # endif
diff --git a/source/yojimbo_address.cpp b/source/yojimbo_address.cpp
index e06d3f0..59e2f5b 100644
--- a/source/yojimbo_address.cpp
+++ b/source/yojimbo_address.cpp
@@ -28,12 +28,15 @@
 
 #if YOJIMBO_PLATFORM == YOJIMBO_PLATFORM_WINDOWS
 
+    // NOTE(odin): I added #ifndef
+    #ifndef NOMINMAX
     #define NOMINMAX
+    #endif
     #define _WINSOCK_DEPRECATED_NO_WARNINGS
     #include <winsock2.h>
     #include <ws2tcpip.h>
     #include <ws2ipdef.h>
-    #pragma comment( lib, "WS2_32.lib" )
+    // #pragma comment( lib, "WS2_32.lib" )  // NOTE(odin): I commented this out!
 
     #ifdef SetPort
     #undef SetPort
diff --git a/source/yojimbo_platform.cpp b/source/yojimbo_platform.cpp
index ba28537..638a0a1 100644
--- a/source/yojimbo_platform.cpp
+++ b/source/yojimbo_platform.cpp
@@ -168,7 +168,10 @@ double yojimbo_time()
 //             Windows
 // ===============================
 
+// NOTE(odin): I added #ifndef
+#ifndef NOMINMAX
 #define NOMINMAX
+#endif
 #include <windows.h>
 
 void yojimbo_sleep( double time )

```

</details>

... After it successfully builds. You can run the following unit tests and sample server and client programs.

Run the unit tests:

```
./bin/test
```

Run the server test program (defaults to localhost on UDP port 40000)

```
./bin/server
```

And in a separate terminal run the client program

```
./bin/client
```

## HelloWorld_yojimbo (Windows)

**NOTE:** The actual HelloWorld_yojimbo C++ example follows closely the `USAGE.md` repo file located here, with some tweaks:

`/deps/yojimbo-1.2.3/USAGE.md`


Clone the repo if you haven't already done so.

```
git clone https://github.com/odinphillips/HelloWorld_yojimbo.git
```

## Build

```
cd HelloWorld_yojimbo
mkdir build
cd build
cmake ..
ninja -j 4
```

Two executable files should have been created in the current `build/` directory.

`HelloWorld_yojimbo_server`

`HelloWorld_yojimbo_client`

First, run the server HelloWorld program:

```
./HelloWorld_yojimbo_server
```

Then in the separate terminal, run the client HelloWorld program:

```
./HelloWorld_yojimbo_client
```

The client program has the following key inputs:

- Press \<SPACE\> to send a UDP message to the server, that will bounce back to the client.
- Press \<Q\> to disconnect and quit the client program.

Then server program can be terminated with \<Ctrl-C\>.

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
container# ./bin/test
```

Run the server test program (defaults to localhost on UDP port 40000)

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

The actual HelloWorld_yojimbo C++ example follows closely the `USAGE.md` repo file located here, with some tweaks:

`/deps/yojimbo-1.2.3/USAGE.md`

Clone the repo if you haven't already done so.

```
container# cd ~
container# git clone https://github.com/odinphillips/HelloWorld_yojimbo.git
```

## Build

```
container# cd HelloWorld_yojimbo
container# mkdir build
container# cd build
container# cmake ..
container# make -j
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

## Connecting a Windows Client to a Linux (container) Server

```bash
docker run -it -p 40000:40000/udp helloworld_yojimbo:3 /bin/bash
```

TODO: flesh out this section some more...