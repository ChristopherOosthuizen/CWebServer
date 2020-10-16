set(BINARY ${CMAKE_PROJECT_NAME}_runner)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp *.html)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES} ../example/main.cpp ../src/Server/Server.h ../src/Server/Server.cpp ../src/Sockets/ServSock.h ../src/Sockets/ServSock.cpp ../src/Model/Model.h ../src/Model/Model.cpp ../src/HTTP/HTTPRequest.h ../src/HTTP/HTTPRequest.cpp ../src/HTTP/HTTPResponse.h ../src/HTTP/HTTPResponse.cpp ../src/View/Template.h ../src/View/Template.cpp views.h)

add_test(NAME ${BINARY} COMMAND ${BINARY})
