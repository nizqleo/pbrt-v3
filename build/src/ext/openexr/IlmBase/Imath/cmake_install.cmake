# Install script for directory: /home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/openexr/IlmBase/Imath/libImath.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenEXR" TYPE FILE FILES
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathBoxAlgo.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathBox.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathColorAlgo.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathColor.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathEuler.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathExc.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathExport.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathForward.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFrame.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFrustum.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFrustumTest.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFun.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathGL.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathGLU.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathHalfLimits.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathInt64.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathInterval.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathLimits.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathLineAlgo.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathLine.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathMath.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathMatrixAlgo.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathMatrix.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathNamespace.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathPlane.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathPlatform.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathQuat.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathRandom.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathRoots.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathShear.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathSphere.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathVecAlgo.h"
    "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathVec.h"
    )
endif()

