//
//  wallet.hpp
//  fc
//
//  Created by 吴迪 on 2018/3/23.
//

#ifndef wallet_hpp
#define wallet_hpp
#include <fc/io/stdio.hpp>
#include <fc/io/json.hpp>
#include <fc/io/buffered_iostream.hpp>
#include <fc/io/sstream.hpp>
#include <fc/rpc/api_connection.hpp>
#include <fc/thread/thread.hpp>
#include <fc/network/http/server.hpp>
#include <fc/network/http/websocket.hpp>
#include <fc/rpc/cli.hpp>
#include <fc/rpc/http_api.hpp>
#include <fc/rpc/websocket_api.hpp>
#include <fc/smart_ref_impl.hpp>

#include <graphene/wallet/wallet.hpp>

#include <iostream>


namespace kgt { namespace rpc {
    typedef std::string string;
    typedef fc::variant variant;
    typedef std::vector<variant> variants;
    typedef uint32_t api_id_type;
    typedef graphene::wallet::wallet_data wallet_data;
    typedef graphene::wallet::wallet_api wallet_api;
    typedef fc::http::websocket_connection websocket_connection;
    typedef std::shared_ptr<websocket_connection> websocket_connection_ptr;
    /**
     *  Provides a simple wrapper for RPC calls to a given interface.
     */
    class wallet : public fc::api_connection
    {
    public:
        wallet();
        ~wallet();
        
        virtual variant send_call( api_id_type api_id, string method_name, variants args = variants() );
        virtual variant send_callback( uint64_t callback_id, variants args = variants() );
        virtual void    send_notice( uint64_t callback_id, variants args = variants() );
        
        void setShowError(int showError);
        int init(std::string& chain_id, std::string& ws_server);
        void start();
        void format_result( const string& method, std::function<string(variant,const variants&)> formatter);
        int runCommand(api_id_type api,string& command,string& result);
        
        virtual void getline( const fc::string& prompt, fc::string& line );
        
        void set_prompt( const string& prompt );
        void set_wapiptr (wallet_api wapiptr);
    private:
        int _showError = 0;
        std::string _prompt = ">>>";
        std::map<string,std::function<string(variant,const variants&)> > _result_formatters;
        fc::future<void> _run_complete;
        websocket_connection_ptr con;
        std::shared_ptr<wallet_data> wdata;
        std::shared_ptr<fc::http::websocket_client> client;
        std::shared_ptr<wallet_api> wapiptr;
        std::shared_ptr<fc::api<wallet_api>> wapi;
        std::shared_ptr<fc::rpc::websocket_api_connection> apic;
    };
} }

#endif /* wallet_hpp */
