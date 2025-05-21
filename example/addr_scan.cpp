#include <nodepp/nodepp.h>
#include <nmap/nmap.h>

/*────────────────────────────────────────────────────────────────────────────*/

using namespace nodepp;

/*────────────────────────────────────────────────────────────────────────────*/

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

/*────────────────────────────────────────────────────────────────────────────*/