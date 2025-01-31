# Copyright (c) 2023, Intel Corporation
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#     * Redistributions of source code must retain the above copyright notice,
#       this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of Intel Corporation nor the names of its contributors
#       may be used to endorse or promote products derived from this software
#       without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

cmake_minimum_required(VERSION 3.16)
project(intel-ipsec-mb)

# Ensure building entire project
if(NOT FULL_PROJECT_BUILD)
  message(FATAL_ERROR "Please run CMake from project root directory")
endif()

########################################
# set app and library names
########################################
set(TEST_APP imb-kat)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
set(TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)

########################################
# set imb-kat source files
########################################
set(TEST_APP_SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/gcm_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/ctr_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/customop_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/des_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/ccm_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/cmac_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha1_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha256_sha512_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_md5_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/aes_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/sha_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/chained_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/api_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/pon_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/ecb_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/zuc_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/kasumi_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/snow3g_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/direct_api_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/clear_mem_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hec_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/xcbc_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/aes_cbcs_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/crc_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/chacha_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/poly1305_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/chacha20_poly1305_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/null_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/snow_v_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/direct_api_param_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/quic_ecb_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha1.json.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha224.json.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha256.json.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha384.json.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_sha512.json.c
  ${CMAKE_CURRENT_SOURCE_DIR}/hmac_md5.json.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../common/utils.c
)

########################################
# set C compiler and NASM options
########################################
# add OS specific options
if(CMAKE_HOST_UNIX)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/unix.cmake)
else()
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/windows.cmake)
endif()

########################################
# add targets
########################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${LIB_DIR} ${TEST_INCLUDE_DIR})
link_directories(${LIB_DIR})

add_executable(${TEST_APP} ${TEST_APP_SRC_FILES})
target_link_libraries(${TEST_APP} PRIVATE ${IPSEC_MB_LIB})
target_compile_definitions(${TEST_APP} PRIVATE ${APP_DEFINES})

