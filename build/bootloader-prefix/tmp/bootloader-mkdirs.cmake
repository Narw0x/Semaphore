# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Applications/IOT/esp-idf/components/bootloader/subproject"
  "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader"
  "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix"
  "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix/tmp"
  "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix/src/bootloader-stamp"
  "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix/src"
  "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Applications/IOT/esp-idf/Trafic_lights_cpp/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
