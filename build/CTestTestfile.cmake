# CMake generated Testfile for 
# Source directory: C:/OOPLAB2
# Build directory: C:/OOPLAB2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(AllPolynomialTests "C:/OOPLAB2/build/Debug/run_tests.exe")
  set_tests_properties(AllPolynomialTests PROPERTIES  _BACKTRACE_TRIPLES "C:/OOPLAB2/CMakeLists.txt;30;add_test;C:/OOPLAB2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(AllPolynomialTests "C:/OOPLAB2/build/Release/run_tests.exe")
  set_tests_properties(AllPolynomialTests PROPERTIES  _BACKTRACE_TRIPLES "C:/OOPLAB2/CMakeLists.txt;30;add_test;C:/OOPLAB2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(AllPolynomialTests "C:/OOPLAB2/build/MinSizeRel/run_tests.exe")
  set_tests_properties(AllPolynomialTests PROPERTIES  _BACKTRACE_TRIPLES "C:/OOPLAB2/CMakeLists.txt;30;add_test;C:/OOPLAB2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(AllPolynomialTests "C:/OOPLAB2/build/RelWithDebInfo/run_tests.exe")
  set_tests_properties(AllPolynomialTests PROPERTIES  _BACKTRACE_TRIPLES "C:/OOPLAB2/CMakeLists.txt;30;add_test;C:/OOPLAB2/CMakeLists.txt;0;")
else()
  add_test(AllPolynomialTests NOT_AVAILABLE)
endif()
subdirs("googletest")
