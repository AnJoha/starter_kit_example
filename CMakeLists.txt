# This CMake script is written to work with minimum CMake version 3.10.
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

# Forcing CMake to generate a Win32 project since the HMS Transport Provider DLL used
# is 32-bit.
set(CMAKE_GENERATOR_PLATFORM Win32)

# Creating a user host application project.
project(host_application_project)

# Sanity check that this is ran in a supported environment.
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
else()
  message(WARNING "Host ${CMAKE_SYSTEM_NAME} is not supported to build host_application.")
endif()

# Creating a user host application executable target.
add_executable(host_application
  ${PROJECT_SOURCE_DIR}/src/main.c
)

# Changing the default startup project into the executable target.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT host_application)

# Source (.c) files to add to the executable target. These are 'user unique'. Some are
# related to the CompactCom Driver.
set(host_application_SRCS
  ${PROJECT_SOURCE_DIR}/src/example_application/application_data_instance_mapping_speed_example.c
  ${PROJECT_SOURCE_DIR}/src/example_application/impl_attr_cfb.c
  ${PROJECT_SOURCE_DIR}/src/abcc_adaptation/abcc_software_port.c
  ${PROJECT_SOURCE_DIR}/src/abcc_adaptation/abcc_hardware_abstraction.c
  ${PROJECT_SOURCE_DIR}/src/abcc_adaptation/pctransportprovider/imp_tp.c
  ${PROJECT_SOURCE_DIR}/stdafx.cpp
)

# Adding the 'user unique' sources to the user host application executable target.
target_sources(host_application PRIVATE ${host_application_SRCS})

# Directories containing include (.h) files unrelated to the CompactCom Driver.
set(HOST_APPLICATION_INCLUDE_DIRS
  ${PROJECT_SOURCE_DIR}/src/
)

# Directories containing 'user unique' include (.h) files related to the CompactCom
# Driver.
set(ABCC_DRIVER_INCLUDE_DIRS
  ${PROJECT_SOURCE_DIR}/src/abcc_adaptation/
  ${PROJECT_SOURCE_DIR}/src/abcc_adaptation/pctransportprovider/
)

# The directory containing the Anybus CompactCom Driver repository.
set(ABCC_DRIVER_DIR ${PROJECT_SOURCE_DIR}/lib/abcc_driver)

# Including the Anybus CompactCom Driver's CMake module file.
include(${ABCC_DRIVER_DIR}/abcc_driver.cmake)

# Adding both the Anybus CompactCom Driver related and unrelated include (.h) files
# to the user host application executable target.
target_include_directories(host_application PRIVATE
  ${HOST_APPLICATION_INCLUDE_DIRS}
  ${ABCC_DRIVER_INCLUDE_DIRS}
)

# Linking the Anybus CompactCom Driver library to the executable target.
target_link_libraries(host_application abcc_driver)