file(GLOB SRC_LIST "*.c")
add_library(httpserver_demo ${SRC_LIST})
target_link_libraries(httpserver_demo pthread)

install(TARGETS httpserver_demo DEFINITIONS lib)
