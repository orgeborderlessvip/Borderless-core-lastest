#pragma once


#include <iostream>

namespace kgt { namespace rpc {
    
    class wallet;
    /**
     *  Provides a simple wrapper for RPC calls to a given interface.
     */
    class cli
    {
    public:
        cli();
        int init(std::string& chain_id, std::string& ws_server);
        int runCommand(int api,std::string& command,std::string& result);
        
    private:
        std::shared_ptr<kgt::rpc::wallet> _wallet;
    };
} }


