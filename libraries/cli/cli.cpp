//
//  cli.cpp
//  cli
//
//  Created by 吴迪 on 2018/3/23.
//
#include <cli/cli.hpp>
#include <cli/wallet.hpp>


#include <fc/io/json.hpp>
#include <fc/io/stdio.hpp>
#include <fc/network/http/server.hpp>
#include <fc/network/http/websocket.hpp>
#include <fc/rpc/cli.hpp>
#include <fc/rpc/http_api.hpp>
#include <fc/rpc/websocket_api.hpp>
#include <fc/smart_ref_impl.hpp>

#include <graphene/wallet/wallet.hpp>
namespace kgt { namespace rpc {
    
    cli::cli() {
        _wallet = std::make_shared<kgt::rpc::wallet>();
    }
    int cli::init(std::string &chain_id, std::string &ws_server) {
        return _wallet->init(chain_id, ws_server);
    }
    
    int cli::runCommand(int api, std::string &command, std::string &result) {
        return _wallet->runCommand(api, command, result);
    }
    
    
}}

