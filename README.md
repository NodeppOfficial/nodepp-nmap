# NODEPP-NMAP
A Nmap implementation using Nodepp.

## Usage

### IP scanning
```cpp
#include <nodepp/nodepp.h>
#include <nmap/nmap.h>

using namespace nodepp;

void onMain(){ 

    nmap_addr_t args; 
    args.from    = ptr_t<uchar>({ 127, 0, 0, 0   });
    args.to      = ptr_t<uchar>({ 127, 0, 0, 255 });
    args.IPPROTO = IPPROTO_TCP;
    args.maxconn = 1000;
    args.port    = 53;

    auto scanner = nmap::addr::scan( args );

    scanner.onClose([=](){
        console::log( "scanner closed" );
    });

    scanner.onAddress([=]( string_t addr ){
        console::log( "->", addr );
    });

}
```

### Port Scanning

```cpp
#include <nodepp/nodepp.h>
#include <nmap/nmap.h>

using namespace nodepp;

void onMain(){ 

    nmap_port_t args; 
    args.host    = "google.com";
    args.IPPROTO = IPPROTO_TCP;
    args.maxport = 10000;
    args.minport = 0;
    args.maxconn = 1000;

    console::log( "Scanning Ports", args.host );
    auto scanner = nmap::port::scan( args );

    scanner.onClose([=](){
        console::log( "scanner closed" );
    });

    scanner.onPort([=]( uint port ){
        console::log( "->", port );
    });

}
```

# Build & Run
```bash
🪟: g++ -o main main.cpp -I ./include -lws2_32 ; ./main
🐧: g++ -o main main.cpp -I ./include ; ./main
```
