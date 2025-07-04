#include <nodepp/nodepp.h>
#include <nodepp/limit.h>
#include <nmap/nmap.h>

using namespace nodepp;

void onMain(){ 

    nmap_port_t args; 
    args.host    = "google.com";
    args.IPPROTO = IPPROTO_TCP;
    args.maxport = 10000;
    args.minport = 0;
    args.maxconn = limit::get_soft_fileno();

    console::log( "Scanning Ports", args.host );
    auto scanner = nmap::port::scan( args );

    scanner.onClose([=](){
        console::log( "scanner closed" );
    });

    scanner.onPort([=]( uint port ){
        console::log( "->", port );
    });

}