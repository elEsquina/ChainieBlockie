cmake_minimum_required(VERSION 3.16)

project(myapp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

 set(OPENSSL_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/openssl)
 set(OPENSSL_INCLUDE_DIR ${OPENSSL_ROOT_DIR}/include)
 set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libcrypto.lib)
 set(OPENSSL_SSL_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libssl.lib)


 set(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nlohmann/include)



# Find required packages
find_package(Qt6 REQUIRED COMPONENTS Quick)
#find_package(OpenSSL REQUIRED)  # Add OpenSSL dependency

qt_standard_project_setup(REQUIRES 6.5)

# Manually set OpenSSL paths (replace with your actual paths)


# Add OpenSSL include directories and other libraries
 include_directories(
     ${OPENSSL_INCLUDE_DIR}
     ${JSON_INCLUDE_DIR}
     # Add local OpenSSL headers if needed:
     # path/to/your/local/openssl/include
 )

qt_add_executable(appmyapp
    src/main.cpp
)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

qt_policy(SET QTP0004 NEW)

qt_add_qml_module(appmyapp
    URI myapp
    VERSION 1.0

    QML_FILES
        qml/Main.qml
        qml/Tab1.qml

    SOURCES
        ${SOURCE_FILES}
        ${HEADER_FILES}

    RESOURCES
        assets/logo.png
)




target_link_libraries(appmyapp
    PRIVATE
        Qt6::Quick
       ${OPENSSL_SSL_LIBRARY}
        ${OPENSSL_CRYPTO_LIBRARY}

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
set_target_properties(appmyapp PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS appmyapp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
