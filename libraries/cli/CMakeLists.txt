file(GLOB HEADERS "include/cli/*.hpp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")
find_package( Perl )
find_package( Doxygen )

add_library( cli cli.cpp wallet.cpp ${HEADERS} )
target_link_libraries( cli PRIVATE graphene_wallet graphene_app graphene_net graphene_chain graphene_utilities fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
target_include_directories( graphene_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( cli.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   cli

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION “headers” )
